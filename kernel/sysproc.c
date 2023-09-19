#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"

int sysCallTotal = 0;

extern int sys_fork(void)
{
    sysCallTotal++;
    return fork();
}

extern int sys_exit(void)
{
    sysCallTotal++;
    exit();
    return 0; // not reached
}

extern int sys_wait(void)
{
    sysCallTotal++;
    return wait();
}

extern int sys_kill(void)
{
    int pid;
    sysCallTotal++;
    if (argint(0, &pid) < 0)
        return -1;
    return kill(pid);
}

int pidCallCount = 0;

extern int sys_getpid(void)
{
    sysCallTotal++;
    pidCallCount++;
    return proc->pid;
}

extern int sys_sbrk(void)
{
    int addr;
    int n;
    sysCallTotal++;
    if (argint(0, &n) < 0)
        return -1;
    addr = proc->sz;
    if (growproc(n) < 0)
        return -1;
    return addr;
}

extern int sys_sleep(void)
{
    int n;
    uint ticks0;
    sysCallTotal++;
    if (argint(0, &n) < 0)
        return -1;
    acquire(&tickslock);
    ticks0 = ticks;
    while (ticks - ticks0 < n)
    {
        if (proc->killed)
        {
            release(&tickslock);
            return -1;
        }
        sleep(&ticks, &tickslock);
    }
    release(&tickslock);
    return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
extern int sys_uptime(void)
{
    uint xticks;
    sysCallTotal++;
    acquire(&tickslock);
    xticks = ticks;
    release(&tickslock);
    return xticks;
}

extern int sys_FirstPart(void)
{
    sysCallTotal++;
    return pidCallCount;
}

extern int sys_SecondPart(void) {
    sysCallTotal++;
    return sysCallTotal;
}