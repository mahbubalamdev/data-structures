#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv){

    printf("Process ID: %d\n", getpid());
    int rc = fork();
    if (rc == 0) // child
    {
        execvp(argv[0], argv);
    }
    else{
        waitpid(rc);
    }
    return 0;
}