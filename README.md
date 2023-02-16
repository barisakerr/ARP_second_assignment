# ARP_second_assignment


## Project made by:

Claudio Tomaiuolo S5630055

Barış Aker S5430437

## ncurses installation
To install the ncurses library, simply open a terminal and type the following command:
```console
sudo apt-get install libncurses-dev
```
## libbitmap library installation

Download the this repository : https://github.com/draekko/libbitmap after downloaading the repository please command the following lines respectively. 
For making the configuration
```console
./configure 
```

For compiling
```console
make
```

For installing the required data
```console
sudo make install
```

After following these steps you need to find libmbp.so inside of the /usr/local/lib, if you can find previous steps had been done correctly. 
As a last step command to the terminal:
```console
nano .bashrc
```
And add export `LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"` as a last line. 

## Explaination 

The aim of the Project to creating to separated programs which are in communication with the shared memory. 

In the the src folder there are three main files, one of them is processA, the other one is processB and the last file is master file. 

When the user will run the program they need to see two consoles, processA and processB. The user should control the object which is inside of the processA by using the right, left, upper and down buttons on the keyboard. Depends on these user inputs the object will be move on the processA console. On the processA console there is P button for printing the image and when the user will push that button image will be save to the .bmp file. During these processes happening the user can follow the object’s entire movement with the 0’s. On the process window all the movement can be seen as a real time and the previous movements will not be disappear that why all movements can be visible. The processA and process are in connection with the shared memory by using semaphores. 

Inside of the master file there is child process creation, processA and processB console creations had been done. 



