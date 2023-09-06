#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	int old = nice(0);
	int pid = getpid();
	printf("Process id is: %d\n", pid);
	printf("\nOld priority value: %d", old);
	getchar();
	int new = nice(-10);
	printf("\nNew Priority value: %d\n", new);
	getchar();
	return 0;
}
