#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]) {
	if(argc < 2) {
		perror("Enter the file name\n");
		return 1;
	}
	char *file = argv[1];

	int fd = open(file, O_RDWR|O_CREAT, 0666);
	if(fd == -1) {
		perror("Couldn't open the file for some reason\n");
		return 1;
	}
	if(!fork()) {
		char buf[] = "This is written by the child\n";
		write(fd, &buf, sizeof(buf));
		return 0;
	} else {
		char buf[] = "This is written by parent\n";
		write(fd, &buf, sizeof(buf));
	}
	wait(0);
	lseek(fd, 0, SEEK_SET);
	while(1) {
		char buf[1024];
	       	int c = read(fd, &buf, sizeof(buf));
		if(c==0) break;
		write(1, &buf, c);
	}

	close(fd);
	return 0;
}
