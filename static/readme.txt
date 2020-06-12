gcc -c add.c sub.c
ar -cvq -o staticlibname.a add.o sub.o
gcc -o outputexec new.c staticlibname.a

//remember, order matters in most of these commands


// since all 4 files are same in static and shared libraries, make those files only once and copy them into the other folder



//execute outputexec and then say "ls -l ouputexec" in both shared and static on seperate t
erminals and show them that shared executable takes lesser space


//also, i've done everything once, if you wanna do again, delete everything but 5 files
1. add.c
2. sub.c
3. main.h
4. readme.txt
5. new.c
gcc -o outputexec new.c sharedlibname.so


