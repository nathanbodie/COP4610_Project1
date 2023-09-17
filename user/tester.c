// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    printf(1, "PID count before getpid(): %d\n", FirstPart());
    getpid();
    printf(1, "PID count after getpid(): %d\n", FirstPart());
    exit();
}
