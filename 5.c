#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int count = 0, pid = getpid();
	while(1) {
		if(count < 5) {
			char filename[100];
			snprintf(filename, sizeof(filename), "%s%d%s", "file", count, ".txt");
			creat(filename, 0666);
			count++;
		}
        	char command[100];
        	snprintf(command, sizeof(command), "%s%d%s", "ls -l /proc/", pid, "/fd");
	        system(command);

	}
	return 0;
}
