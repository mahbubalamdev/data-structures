#include<stdio.h>
#include<stdlib.h>

int main(){
    int rc;
    printf("P1");
    rc = fork();
    if (rc==0){
        printf("P2");
    }
    else{
        waitpid(rc, NULL, 0);
        rc = fork();
        if (rc == 0){
            printf("P3");
            rc = fork();
            if(rc==0){
                printf("P5");
            }
            else{
                waitpid(rc, NULL, 0);
            }
        }else{
            waitpid(rc, NULL, 0);
            rc = fork();
            if(rc == 0){
                printf("P4");

            }else{
                waitpid(rc, NULL, 0);
            }
        }
    }
}