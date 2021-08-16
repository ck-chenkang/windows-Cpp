#include <iostream>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <stdio.h>
#include <Windows.h>

#define MAX 10

pthread_t thread[2]; //�����̺߳�����������
pthread_mutex_t mut; //����������
int number = 0, i;

void* thread1(void *) //�̺߳���
{
    printf("thread1 : I'm thread 1\n");

    for (i = 0; i < MAX; i++)
    {
        printf("thread1 : number = %d\n", number);
        pthread_mutex_lock(&mut); //���������ڶԹ����������
        number++;
        pthread_mutex_unlock(&mut); //����
        Sleep(2000);
    }


    printf("thread1 :�������ڵ������������\n");
    pthread_exit(NULL);
    return NULL;
}

void* thread2(void *)
{
    printf("thread2 : I'm thread 2\n");

    for (i = 0; i < MAX; i++)
    {
        printf("thread2 : number = %d\n", number);
        pthread_mutex_lock(&mut);
        number++;
        pthread_mutex_unlock(&mut);
        Sleep(3000);
    }


    printf("thread2 :�������ڵ������������\n");
    pthread_exit(NULL);
    return NULL;
}

void thread_create(void)
{
    /*�����߳�*/
    pthread_create(&thread[0], NULL, thread1, NULL);
    printf("�߳�1������\n");
    pthread_create(&thread[1], NULL, thread2, NULL);
    printf("�߳�2������\n");
}

void thread_wait(void)
{
    /*�ȴ��߳̽���*/
    pthread_join(thread[0], NULL);
    printf("�߳�1�Ѿ�����\n");
    pthread_join(thread[1], NULL);
    printf("�߳�2�Ѿ�����\n");
}

int main()
{
    /*��Ĭ�����Գ�ʼ��������*/
    pthread_mutex_init(&mut, NULL);

    printf("����������Ŷ�������ڴ����̣߳��Ǻ�\n");
    thread_create();
    printf("����������Ŷ�������ڵȴ��߳�������񰢣��Ǻ�\n");
    thread_wait();

    return 0;
}