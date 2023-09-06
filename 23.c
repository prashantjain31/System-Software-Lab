#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	if(!fork()) {
		printf("Child's pid is: %d and its parent's pid is: %d\n", getpid(), getppid());
		return 0;
	} else {
		printf("Parent's pid is: %d\n", getpid());
		sleep(60);
		printf("Parent is coming out of the sleep\n");
		wait(0);
	}

	return 0;
}
