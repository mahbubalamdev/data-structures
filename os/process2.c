#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    int val = 5;
    int proc_id;
    printf("Hello!\n");
    proc_id = fork();
    if (proc_id){
        waitpid(proc_id); 
    }
    else {
        printf("Value of val = % d\n",val);
        char *args[] = {"/bin/date", "0", NULL};
        execvp(args[0], args);
    }
    val++;
    printf ("Goodbye! Value of val = %d\n", val);
    return(val);
}
