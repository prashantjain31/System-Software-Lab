#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
struct ticket {
	int id;
	int number;
};


int main(int argc, char *argv[]) {
	if(argc < 2) {
		perror("Please enter the file name\n");
		return 1;
	}
	char *file = argv[1];
	int fd = open(file, O_RDWR | O_CREAT);
	if(fd == -1) {
		perror("Some error occurred while file opening\n");
		return 1;
	}
	int i = 1;
	while(i <= 3) {
		struct ticket t;
		printf("\nPlease enter train id: ");
		scanf("%d", &t.id);
		printf("\nPlease enter the ticket number: ");
		scanf("%d", &t.number);
		write(fd, &t, sizeof(t));
		printf("\n");
		i++;
	}
	i=1;
	lseek(fd, 0, SEEK_SET);
	while(i<=3) {
		struct ticket t;
		read(fd, &t, sizeof(t));
		printf("The train with id %d has current ticket number: %d\n", t.id, t.number);
		i++;
	}
	return 0;
}
