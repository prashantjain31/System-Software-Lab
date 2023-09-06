#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	int cid1, cid2, cid3;
	if(!(cid1 = fork())) {
		printf("Inside fork 1\n");
		sleep(30);
		printf("Child 1 completes execution\n");
		return 0;
	} else if(!(cid2 = fork())) {
                printf("Inside fork 2\n");
                sleep(40);
                printf("Child 2 completes execution\n");
		return 0;
        } else if(!(cid3 = fork())) {
                printf("Inside fork 3\n");
                sleep(20);
                printf("Child 3 completes execution\n");
		return 0;
        } else{
		printf("Inside parent\n");
		sleep(4);
		printf("fork 1 id: %d\n", cid1);
		printf("fork 2 id: %d\n", cid2);
		printf("fork 3 id: %d\n", cid3);
		int x;
		printf("Enter the fork number to wait for: ");
		scanf("%d", &x);
		printf("\n");
		int status, wid;
		switch(x) {
			case 1: wid = cid1;
				break;
			case 2: wid = cid2;
				break;
			case 3: wid = cid3;
				break;
			deafult : printf("Wrong choice\n");
				  break;
		}
		waitpid(wid, &status, 0);
		printf("Parent also completes the execution\n");
		return 0;
	}
}
