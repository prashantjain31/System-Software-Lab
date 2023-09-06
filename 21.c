#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main() {
	int pid, cpid, c;
	if(!(c=fork())) {
		cpid = getpid();
		printf("Child's process id is: %d\n", cpid);
	} else {
		pid = getpid();
		printf("Parent's process id is: %d\n", pid);
	}
	wait(0);
	return 0;
}
