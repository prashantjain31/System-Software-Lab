#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/select.h>

int main() {
	fd_set rfds;
	struct timeval tv;
	int retval;
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_sec = 10;
	// 1 represent the highest fd number in out set + 1 so in out set highest number was 0 for stdin and +1
	retval = select(1, &rfds, NULL, NULL, &tv);
	if(retval) printf("Data was available in 10 seconds\n");
	else printf("Data was not available in 10 seconds\n");
	return 0;
}
