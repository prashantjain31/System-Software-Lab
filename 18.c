#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

struct ticket{
	int id;
	int number;
};

int main(int argc, char *argv[]) {
	if(argc < 2) {
		perror("Please enter the file name\n");
		return 1;
	}
	char *file = argv[1];
	int fd = open(file, O_RDWR, 0666);
	if(fd == -1) {
		perror("Some error occurred\n");
		return 1;
	}
	int no;
	printf("Enter the Train number (1,2,3) you want to modify or see: ");
	scanf("%d", &no);
	printf("1. If you want to modify the train id\n2. If you want to book ticket.\n3.If you want to print the details only\n");
	int ch;
	scanf("%d", &ch);
	if(ch > 3 || ch < 1 || no < 1 || no > 3) {
		perror("Wrong choices\n");
		return 1;
	}

	struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start =(no-1)*sizeof(struct ticket) ;
        lock.l_len = sizeof(struct ticket);
        lock.l_pid = getpid();
	struct ticket t;
	if(ch == 1) {
		int nid;
		printf("Enter the new train id: ");
		scanf("%d", &nid);
		lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
		fcntl(fd, F_SETLKW, &lock);
		read(fd, &t, sizeof(t));
		t.id = nid;
		lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
		printf("Changing the ticket id in system\n");
		write(fd, &t, sizeof(t));
		printf("Changed successfully please press enter to continue.\n");
		getchar();
		getchar();
		lock.l_type = F_UNLCK;
        	fcntl(fd, F_SETLK, &lock);
	        printf("Id has been changed.\n");
	} else if(ch == 2) {
		printf("Trying to access the details\n");
                lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
                fcntl(fd, F_SETLKW, &lock);
                read(fd, &t, sizeof(t));
                t.number = t.number+1;
		printf("Booked ticket number %d in the train with id %d \n", t.number, t.id);
                lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
                write(fd, &t, sizeof(t));
                printf("Booked successfully please press enter to continue.\n");
                getchar();
                getchar();
                lock.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lock);
                printf("Thank you.\n");
        } else if(ch == 3) {
		printf("Trying to access the details\n");
		lock.l_type = F_RDLCK;
                lseek(fd, (no-1)*sizeof(struct ticket), SEEK_SET);
                fcntl(fd, F_SETLKW, &lock);
		printf("Reading the details.\n");
                read(fd, &t, sizeof(t));
                printf("Train id %d has %d tickets booked.\nPress Enter to Continue.\n", t.id, t.number);
                getchar();
                getchar();
                lock.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lock);
                printf("Read successfully.\n");
        }
	return 0;
}
