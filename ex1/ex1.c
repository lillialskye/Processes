// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    		int x = 100;
		int child = fork();
    if (child < 0) {
			fprintf(stderr, "fork failed\n");
			exit(1);
    } else if (child == 0) {
			x = 75;
			printf("(child x: %d) \n", x); 
		} else {
			x = 50;
			printf("(parent x: %d) \n", x);	
			printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), child);
    }
		printf("(parent x: %d) \n", x);	
    return 0;
}

  
