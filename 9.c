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

	printf("inode: %lu\n", info.st_ino);
	printf("number of hard links: %lu\n", info.st_nlink);
	printf("uid: %d\n", info.st_uid);
	printf("gid: %d\n", info.st_gid);
	printf("size: %ld\n", info.st_size);
	printf("block size: %ld\n", info.st_blksize);
	printf("number of blocks: %ld\n", info.st_blocks);
	printf("time of last access: %ld seconds %ld nanoseconds\n", (long)info.st_atime, (long)info.st_atim.tv_nsec);
	printf("time of last modification: %ld seconds %ld nanoseconds\n", (long)info.st_mtime, (long)info.st_mtim.tv_nsec);
	printf("time of last status change: %ld seconds %ld nanoseconds\n", (long)info.st_ctime, (long)info.st_ctim.tv_nsec);
	
	return 0;
}
