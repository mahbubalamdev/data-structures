#include<stdio.h>
#include<unistd.h>
#include<fctnl.h>

int main(){
    int fd1, fd2, rc;
    fd1 = open("file.txt", O_RDONLY);
    fd2 = open("file.txt", O_RDONLY);

    rc = lseek(fd1, 50, SEEK_SET);

    fc = fork();
    if (rc < 0){
        exit(1);
    }
    else if (rc == 0){
        fd2 = open("file.txt", O_RDONLY);

        rc = lseek(fd1, 20, SEEK_CUR);
        printf("Child: fd1 %d offset %d\n", fd1, rc);

    }
    else {
        (void) wait(NULL);
        rc = lseek(fd1, 0, SEEK_CUR);
        printf("Parent: fd1 %d offset %d\n", fd1, rc);

        rc = lseek(fd2, 10, SEEK_CUR);
        printf("Parent: fd2 %d offset %d\n", fd2, rc);
    }
    return 0;
}