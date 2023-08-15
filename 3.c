#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[]) {
	const char *filename = (argc > 1) ? argv[1] : ".";
	int fd = creat(filename, 0666);
	printf("File discriptor value: %d\n", fd);
	int pid = getpid();
	char command[100];
	snprintf(command, sizeof(command), "%s%d%s", "ls -l /proc/", pid, "/fd");
	system(command);
	return 0;
}
