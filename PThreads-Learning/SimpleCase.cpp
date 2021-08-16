#include <iostream>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

using namespace std;

void *thread(void *) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("this is a pthread.\n");
    }
    return NULL;
}

int main1() {

    pthread_t id;
    int i, ret;
    ret = pthread_create(&id, NULL, thread, NULL);
    if (ret != 0) {
        printf("Create pthread error!\n");
        return -1;
    }
    pthread_join(id, NULL);

    for (i = 0; i < 3; i++) {
        printf("this is the main process.\n");
    }
    return 0;
}