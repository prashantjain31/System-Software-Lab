#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int main() {
	int pid = getpid();
	printf("Id is: %d\n", pid);
	int policy;
	policy = sched_getscheduler(pid);
	printf("Current scheduling policy: ");
    	switch (policy) {
        	case SCHED_FIFO: printf("SCHED_FIFO\n");
            		 break;
        	case SCHED_RR: printf("SCHED_RR\n");
            		 break;
        	case SCHED_OTHER: printf("SCHED_OTHER\n");
            		 break;
        	default: printf("Unknown\n");
        	    	 break;
    	}
	sleep(30);
	struct sched_param param;
    	param.sched_priority = 99;
	int ch;
	printf("1. for RR 2. for FIFO: ");
	scanf("%d", &ch);
	if(ch == 1) {
		policy = SCHED_RR;
	} else if(ch == 2) {
		policy = SCHED_FIFO;
	} else {
		return 1;
	}
	sched_setscheduler(pid, policy, &param);
	policy = sched_getscheduler(pid);
        printf("New scheduling policy: ");
        switch (policy) {
                case SCHED_FIFO: printf("SCHED_FIFO\n");
                         break;
                case SCHED_RR: printf("SCHED_RR\n");
                         break;
                case SCHED_OTHER: printf("SCHED_OTHER\n");
                         break;
                default: printf("Unknown\n");
                         break;
        }
	sleep(30);
	return 0;
}
