#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Please pass the files\n");
		return 1;
	}
	char *file1 = argv[1];
	char *file2 = argv[2];
	int fd1 = open(file1, O_RDONLY);
	int fd2 = open(file2, O_WRONLY | O_CREAT | O_EXCL);
	if(fd1 == -1 || fd2 == -1) {
		printf("Couldn't open the files\n");
		return 1;
	}
	char buf;
	while(1) {
		int char_read = read(fd1, &buf, 1);
		if(char_read == 0) break;
		int char_write = write(fd2, &buf, 1);
	}

	int fd1_close = close(fd1);
	int fd2_close = close(fd2);
	if(fd1_close == -1 || fd2_close == -1) {
                printf("Couldn't close the files\n");
                return 1;
        }
	return 0;
}
