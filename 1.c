#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main() {
	int v = symlink("employee_records.txt", "employeeRecordsSoft");
	if(v < 0) {
		perror("failed");
		return 1;
	}
	int f = link("employee_records.txt", "employeeRecordsHard");
	if(f < 0) {
		perror("failed"); 
		return 1;
	}
	int e = mknod("myFIFO", S_IFIFO, 0);
	if(e<0) {
		perror("Failed");
		return 1;
	}	
	return 0;
}
