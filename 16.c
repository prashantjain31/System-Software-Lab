#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		perror("Please enter the file name\n");
		return 1;
	}

	char *file = argv[1];

	int fd = open(file, O_RDWR);
	if(fd == -1) {
		perror("Some error occurred\n");
		return 1;
	}

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	printf("Before locking the file\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");
	printf("Press enter to come out of critical section\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	
	printf("Outside of critical section\n");

	return 0;
}
