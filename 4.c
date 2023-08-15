#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	const char *filename = (argc > 1) ? argv[1] : ".";
	int fd = open(filename, O_CREAT|O_EXCL, 0666);
	if(fd == -1) {
		printf("File already exists\n");
		
	} else
		printf("File Created Exclusively\n");

	fd = open(filename, O_RDWR);
	if(fd == -1) {
		printf("Failed to open file\n");
		return 1;
	} else
		printf("File open in Read Write mode\n");
	int pid = getpid();
        char command[100];
        snprintf(command, sizeof(command), "%s%d%s", "ls -l /proc/", pid, "/fd");
        system(command);

	return 0;
}
