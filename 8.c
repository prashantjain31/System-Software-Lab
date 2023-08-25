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
	int i = 0;
	char b;
	char buf[1000];
	while(1) {
		int c = read(fd, &b, 1);
		if(c!=0 && b == '\n') {
			buf[i++] = b;
			buf[i++] = '\0';
		}
		else if(c!=0) {
			buf[i++] = b;
			continue;
		} 
		write(1, &buf, i);
		i=0;
		if(c==0) break;
	}
	close(fd);
	return 0;
}
