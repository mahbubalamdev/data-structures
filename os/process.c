#include<stdio.h>
#include<unistd.h>

/*
3!=3*2*1=6
P C1 C2
P C2 C1
C1 P C2
C1 C2 P
C2 P C1
C2 C1 P
*/
int main (int argc, char **argv) {
    int proc_id = fork();
    int x=5;
    if (proc_id == 0) { 
        x = x + 5;
    }
    else
    {
        proc_id = fork();
        x = x + 10;
        if(proc_id){
            sleep(1);
            x = x + 7;
        }
    }
    printf("Value of x = %d\n", x);
    return 0;
}