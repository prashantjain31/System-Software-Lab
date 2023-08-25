#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Please enter the file name\n");
		return 1;
	}
	const char *file = argv[1];
	int fd = open(file, O_RDWR | O_CREAT, 0666);

	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}

	char data1[] = "prashant31";
	char data2[] = "PRASHANTJN";
	write(fd, &data1, 10);
	int seek_result = lseek(fd, 10, SEEK_CUR);
	printf("lseek result after writing first 10 bytes and moving 10 bytes ahead: %ld\n", (long)seek_result);
	write(fd, data2, 10);
	close(fd);
    	return 0;
}

