#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern char **environ;

int main() {
    char **env = environ;

    while (*env) {
	if (strncmp(*env, "USER", 4) == 0) printf("%s\n", *env);
        env++;
    }

    return 0;
}

