#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Pass the file name\n");
		return 1;
	}
	char *file = argv[1];
	int fd = open(file, O_RDONLY);
	if(fd == -1) {
		printf("Couldn't open the files\n");
		return 1;
	}
	
	char buf[1000];
	while(1) {
		int c = read(fd, &buf, sizeof(buf));
		if(c == 0) break;
		for(int i = 0; i < c; i++) {

			write(1, &buf[i], 1);

			if(buf[i] == '\n') write(1, &"\n", 1);
		}
	}
	close(fd);
	return 0;
}
