#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    int val = 5;
    int proc_id;
    printf("Hello!\n");
    proc_id = fork();
    if (proc_id){
        waitpid(proc_id, NULL); 
    }
    else {
        printf("Value of val = % d\n",val);
        char *args[] = {"/bin/date", NULL};
        /*
        char *args[2];
        args[0] = strdup("/bin/date");
        args[1] = NULL;
        */
        execvp(args[0], args);
    }
    val++;
    printf ("Goodbye! Value of val = %d\n", val);
    return(val);
}
