// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    //Testing part A
    printf(1, "PID count before getpid(): %d\n", FirstPart());
    getpid();
    printf(1, "PID count after getpid(): %d\n", FirstPart());
    printf(1, "\n\n");

    //Testing part B
    printf(1, "There are %d system calls.\n", SecondPart());
    exit();
}
