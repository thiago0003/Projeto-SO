
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_identity 440

long identity_syscall(void)
{
    return syscall(__NR_identity);
}

int main(int argc, char *argv[])
{
    long activity;
    activity = identity_syscall();

    if(activity < 0)
    {
        perror("Sorry, Jasper. Your system call appears to have failed.");
    }

    else
    {
        printf("Congratulations, Jasper! Your system call is functional. Run the command dmesg in the terminal and find out!\n");
    }

    return 0;
}
