#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* =====================
 * 共享资源
 * ===================== */
static int data_ready = 0;

/* 互斥锁 + 条件变量 */
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

/* =====================
 * 消费者线程
 * ===================== */
void *consumer_thread(void *arg)
{
    pthread_mutex_lock(&mutex);

    /* 条件不满足就等待 */
    while (data_ready == 0) {
        printf("[Consumer] no data, wait...\n");
        pthread_cond_wait(&cond, &mutex);
        /* 被唤醒后，mutex 已经重新加锁 */
    }

    printf("[Consumer] got data!\n");
    data_ready = 0;

    pthread_mutex_unlock(&mutex);
    return NULL;
}

/* =====================
 * 生产者线程
 * ===================== */
void *producer_thread(void *arg)
{
    sleep(1);  // 模拟准备数据

    pthread_mutex_lock(&mutex);

    printf("[Producer] prepare data\n");
    data_ready = 1;

    /* 通知等待线程 */
    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&mutex);
    return NULL;
}

/* =====================
 * main
 * ===================== */
int main(void)
{
    pthread_t consumer, producer;

    pthread_create(&consumer, NULL, consumer_thread, NULL);
    pthread_create(&producer, NULL, producer_thread, NULL);

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
