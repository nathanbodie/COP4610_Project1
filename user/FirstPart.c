#include "types.h"
#include "stat.h"
#include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"

// Returns the number of times the getpid() process has been called
int main(void)
{
    int count = FirstPart();
    // int count = pidCallCount;
    // printf(2, "getpid() has been called %d times\n", count);
    return count;
}