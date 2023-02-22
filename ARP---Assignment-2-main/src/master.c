#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>


//Log file
int FDlog;
char LogBuffer[100];

//Get time for Log file
time_t rawtime;
struct tm *info;

//Write log file function
void WriteLog(char *msg){
  time(&rawtime);
  info=localtime(&rawtime);

  sprintf(LogBuffer, msg);
  sprintf(LogBuffer + strlen(LogBuffer), asctime(info));

  if(write(FDlog, LogBuffer, strlen(LogBuffer))==-1){
    close(FDlog);
    perror("Error in writing function");
    }
}

int spawn(const char * program, char * arg_list[]){

  pid_t child_pid = fork();

  if(child_pid < 0){
    perror("Error while forking...");
    WriteLog("Error while forking...");
    return 1;
  } else if(child_pid != 0){
    return child_pid;
  } else{
    if(execvp (program, arg_list) == 0);
    perror("Exec failed");
    WriteLog("Exec failed");
    return 1;
  }
}

int main() {
  if((FDlog = open("log/master.log",O_WRONLY|O_CREAT|O_APPEND, 0666))==-1){
    perror("Error opening master log file");
    return 1;
  }
  
  WriteLog("Master process started.");

  char * arg_list_A[] = { "/usr/bin/konsole", "-e", "./bin/processA", NULL };
  char * arg_list_B[] = { "/usr/bin/konsole", "-e", "./bin/processB", NULL };

  pid_t pid_procA = spawn("/usr/bin/konsole", arg_list_A);
  pid_t pid_procB = spawn("/usr/bin/konsole", arg_list_B);

  WriteLog("A & B processes spawned.");

  int status;
  waitpid(pid_procA, &status, 0);
  waitpid(pid_procB, &status, 0);

  WriteLog("Master process terminated.");

  close(FDlog);
  
  printf ("Main program exiting with status %d\n", status);
  return 0;
}

