#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>

int main() {
	int policy, max_priority, min_priority;
       	policy = SCHED_FIFO; 
    	max_priority = sched_get_priority_max(policy);
   	min_priority = sched_get_priority_min(policy);
    	printf("Maximum real-time priority FIFO: %d\n", max_priority);
    	printf("Minimum real-time priority FIFO: %d\n", min_priority);
	policy = SCHED_RR;
        max_priority = sched_get_priority_max(policy);
        min_priority = sched_get_priority_min(policy);
        printf("Maximum real-time priority RR: %d\n", max_priority);
        printf("Minimum real-time priority RR: %d\n", min_priority);
	return 0;
}
