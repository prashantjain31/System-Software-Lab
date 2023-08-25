#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
	if(argc < 2) {
		perror("Please enter the file name\n");
		return 1;
	}
	char *file = argv[1];
	int fd = open(file, O_RDWR|O_CREAT, 0666);
	if(fd==-1) {
		perror("Some error ocurred\n");
		return 1;
	}
	int x;
	printf("Please enter the starting ticket value: ");
	scanf("%d", &x);
	write(fd, &x, sizeof(x));
	return 0;
}
