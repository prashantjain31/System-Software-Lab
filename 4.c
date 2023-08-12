#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int fd = open("myFileFor4.txt", O_CREAT|O_EXCL, 0666);
	if(fd == -1) {
		printf("Failed");
		return 1;
	}
	printf("File Created Exclusively");

	fd = open("myFileFor4.txt", O_RDWR);
	if(fd == -1) {
		printf("Failed");
		return 1;
	}
	printf("File open in Read Write mode");

	return 0;
}
