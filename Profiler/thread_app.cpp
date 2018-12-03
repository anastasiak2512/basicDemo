#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <vector>

#define NAMELEN (size_t)16

#define errExitEN(en, msg) \
do { errno = en; perror(msg); exit(EXIT_FAILURE); \
} while (0)

static void * thread_fun(void *name) {
    sleep(1);

#ifdef __APPLE__
    int rc = pthread_setname_np(
            (!name) ? "THREADFOO" : (char *)name);
    if (rc != 0)
        errExitEN(rc, "pthread_setname_np");
#endif

    std::vector<int> v;
    for (int i = 0; i < 1e6; ++i)
        v.push_back(i);

    return nullptr;
}

int main(int argc, char **argv)
{
    for (int i = 0; i < 5; ++i)
    {
        pthread_t thread;
        int rc;
        char thread_name[NAMELEN];

        rc = pthread_create(&thread, nullptr, thread_fun, (argc > 1) ? argv[1] : nullptr);
        if (rc != 0)
            errExitEN(rc, "pthread_create");

#ifndef __APPLE__
        rc = pthread_setname_np(thread, (argc > 1) ? argv[1] : "THREADFOO");
        if (rc != 0)
            errExitEN(rc, "pthread_setname_np");
#endif

        rc = pthread_join(thread, nullptr);
        if (rc != 0)
            errExitEN(rc, "pthread_join");

        printf("Done\n");
    }
    exit(EXIT_SUCCESS);
}

