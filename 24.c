#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main() {
	if(!fork()) {
		printf("Child is executing and going in sleep for 40 sec and its pid is: %d\n", getpid());
		sleep(40);
		printf("Parent-ID: %d\n", getppid());
		return 0;
	} else {
		printf("Parent is executing and its pid is: %d\n", getpid());
		sleep(20);
		printf("Parent is coming out of execution\n");
		return 0;
	}
}
