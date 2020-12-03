#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *start_thread(void *message)
{
    printf("%s\n", (const char *)message);
    return message;

}


int main(void)
{
    pthread_t thing1, thing2;
    const char *msg1 = "Thing 1";
    const char *msg2 = "Thing 2";

    pthread_create(&thing1, NULL, start_thread, (void *)msg1);
    pthread_create(&thing1, NULL, start_thread, (void *)msg1);

    pthread_join(thing1, NULL);
    pthread_join(thing2, NULL);
	return 0;

}
