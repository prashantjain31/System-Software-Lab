#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>

void makeDaemon(time_t now, time_t actual) {
	setsid();
	chdir("/");
	umask(0);
	printf("Childs pid is: %d and parents id is: %d\n", getpid(), getppid());
	printf("It is going to wait until correct time\n");
	do {
		time(&now);
	} while (difftime(actual, now) > 0);
	printf("Time matched\n");
	exit(0);
}

int main() {
	time_t now, actual;
	struct tm *deadline;
	time(&now);
        deadline = localtime(&now);

        deadline->tm_hour = 22;
        deadline->tm_min = 55;
        deadline->tm_sec = 0;
	actual = mktime(deadline);
	if(!fork()) {
		makeDaemon(now, actual);
	}
	else {
		printf("Parent %d is going to exit\n", getpid());
	}
	return 0;
}
