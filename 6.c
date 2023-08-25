#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	char buf;
	while(1) {
		read(0, &buf, 1);
		if(buf == '.') break;
		write(1, &buf, 1);
	}
	write(1, &"\n", 1);
	return 0;
}
