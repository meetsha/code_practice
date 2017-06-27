#include <iostream>
#include <unistd.h>

char **get_input(char *input) {
    
}

int main() {
    char *argv[] = {"ls", "-l", "-h", "-a", NULL};
    execvp(argv[0], argv);

    return 0;
}