#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t child_pid;
    pid_t wait_result;
    int statlock;

    child_pid = fork();

    if(child_pid == 0) {
        cout << "### Child ###\n Current PID: " << getpid()
             << " Child PID: " << child_pid << endl;
        sleep(1);
    } else {
        wait_result = waitpid(child_pid, &statlock, WUNTRACED);
        cout << "### Parent ###\n Current PID: " << getpid()
             << " Child PID: " << child_pid << endl;
    }

    return 0;
}