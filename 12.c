#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	    if(argc < 2) {
		printf("Enter the file name\n");
		return 1;
	    } 
	    const char *file = argv[1];
	    int fd = open(file, O_RDWR | O_APPEND, 0666);

	    if (fd == -1) {
	        perror("Error opening file");
		return 1;
	    }

	    int flags = fcntl(fd, F_GETFL);
	    if (flags == -1) {
	        perror("Error getting file flags");
	        return 1;
	    }
	    if (flags & O_RDONLY) printf("Read-only ");
	    if (flags & O_WRONLY) printf("Write-only ");
	    if (flags & O_RDWR) printf("Read-write ");
	    if (flags & O_APPEND) printf("Append ");
	    if (flags & O_CREAT) printf("Create ");

	    printf("\n");
	    close(fd);
	    return 0;
}

