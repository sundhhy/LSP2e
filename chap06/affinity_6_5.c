#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>

#define MAX_CPU 8

int main(void)
{
    cpu_set_t set;
    int ret, i;
    CPU_ZERO(&set);
    ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
    if (ret == -1)
        perror("sched_getaffinity");
    for (i=0; i<MAX_CPU; i++)
    {
        int cpu;
        cpu = CPU_ISSET(i, &set);
        printf("cpu=%i is %s\n", i, cpu?"set":"unset");
    }

	CPU_CLR(1, &set);
	CPU_CLR(2, &set);
	CPU_CLR(3, &set);
	ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
	if (ret == -1)
	{
		perror("sched_setaffinity");
		exit(-1);
	}

    ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
    if (ret == -1)
        perror("sched_getaffinity");
	printf("====== after set sched ================= \n");
    for (i=0; i<MAX_CPU; i++)
    {
        int cpu;
        cpu = CPU_ISSET(i, &set);
        printf("cpu=%i is %s\n", i, cpu?"set":"unset");
    }
	return 0;
}
