#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		perror("Please enter the arguments\n");
		return 1;
	}
	char *command = argv[1];  
	char *args[argc];
	for(int i = 0; i < argc-1; i++) {
		args[i] = argv[i+1];
	}
	args[argc-1] = NULL;
	printf("Before executing another program.\n");
	if (execvp(command, args) == -1) {
		perror("execvp");
		exit(EXIT_FAILURE);
    	}

    	printf("This line will be replaced.\n");

    	return 0;
}

