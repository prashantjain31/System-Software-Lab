#include<stdio.h>
#include<fcntl.h>

int main() {
	int fd = creat("myFileFor3", 0666);
	printf("File discriptor value: %d", fd);
	return 0;
}
