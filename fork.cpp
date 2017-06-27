#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    pid_t child_pid = fork();

    if(child_pid == 0) {
        sleep(1);
        cout << "### Child ###\n Current PID: " << getpid()
             << " Child PID: " << child_pid << endl;
    }

    else {
        cout << "### Parent ###\n Current PID: " << getpid()
             << " Child PID: " << child_pid << endl;
    }

    return 0;
}