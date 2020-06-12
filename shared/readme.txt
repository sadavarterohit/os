gcc -fPIC -c add.c sub.c
gcc -shared -o sharedlibname.so add.o sub.o
gcc -o outputexec new.c sharedlibname.so
sudo mv sharedlibname.so /usr/lib

//put password, lab password is cse

sudo ldconfig

//execute outputexec and then say "ls -l ouputexec" in both shared and static on seperate terminals and show them that shared executable takes lesser space


//also, i've done everything once, if you wanna do again, delete everything but 5 files
1. add.c
2. sub.c
3. main.h
4. readme.txt
5. new.c
gcc -o outputexec new.c sharedlibname.so

