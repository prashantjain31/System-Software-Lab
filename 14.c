#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Please enter the file name\n");
		return 1;
	}
	char *file = argv[1];
	struct stat info;

	stat(file, &info);

	printf("File type: ");

        switch (info.st_mode & S_IFMT) {
	        case S_IFBLK:  printf("block device\n");            break;
	        case S_IFCHR:  printf("character device\n");        break;
	        case S_IFDIR:  printf("directory\n");               break;
	        case S_IFIFO:  printf("FIFO/pipe\n");               break;
	        case S_IFLNK:  printf("symlink\n");                 break;
	        case S_IFREG:  printf("regular file\n");            break;
        	case S_IFSOCK: printf("socket\n");                  break;
  	        default:       printf("unknown?\n");                break;
        }

	
	return 0;
}
