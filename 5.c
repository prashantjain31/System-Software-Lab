#include<stdio.h>
#include<fcntl.h>
int main(){
	creat("myFirstFileFor5", 0666);
	creat("mySecondFileFor5", 0666);
	creat("myThirdFileFor5", 0666);
	creat("myFourthFileFor5", 0666);
	creat("myFifthFileFor5", 0666);
	while(1);
	return 0;
}
