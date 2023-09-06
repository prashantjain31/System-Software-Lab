#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int ch;
	printf("1. execl 2. execlp 3. execle 4. execv 5. execvp\nEnter the choice: ");
	scanf("%d", &ch);
	switch(ch) {

		case 1: printf("Using execl:\n");
    			if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
				perror("execl");
        			exit(EXIT_FAILURE);
    			}
			break;
		case 2: printf("\nUsing execlp:\n");
    			if (execlp("ls", "ls", "-Rl", NULL) == -1) {
        			perror("execlp");
        			exit(EXIT_FAILURE);
    			}
			break;
		case 3: printf("\nUsing execle:\n");
    			char *envp[] = {NULL}; 
    			if (execle("/bin/ls", "ls", "-Rl", NULL, envp) == -1) {
        			perror("execle");
        			exit(EXIT_FAILURE);
    			}
			break;
		case 4: printf("\nUsing execv:\n");
    			char *args[] = {"ls", "-Rl", NULL};
    			if (execv("/bin/ls", args) == -1) {
        			perror("execv");
        			exit(EXIT_FAILURE);
    			}
			break;
		case 5: printf("\nUsing execvp:\n");
    			if (execvp("ls", args) == -1) {
        			perror("execvp");
        			exit(EXIT_FAILURE);
    			}
			break;
		default: printf("Wrong choice\n");
			 break;
	}
    	return 0;
}

