#include<stdio.h>
#include<stdlib.h>

int main(){
    int rc;
    printf("P1\n");
    rc = fork();
    if (rc==0){
        printf("P2\n");
    }
    else{
        waitpid(rc, NULL, 0);
        rc = fork();
        if (rc == 0){
            printf("P3\n");
            rc = fork();
            if(rc==0){
                printf("P5\n");
            }
            else{
                waitpid(rc, NULL, 0);
            }
        }else{
            waitpid(rc, NULL, 0);
            rc = fork();
            if(rc == 0){
                printf("P4\n");

            }else{
                waitpid(rc, NULL, 0);
            }
        }
    }
}