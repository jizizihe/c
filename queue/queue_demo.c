#include <stdio.h>

#define QUEUE_SIZE 8

struct queue {
    int buf[QUEUE_SIZE];
    int head;
    int tail;
    int count;
};

void queue_init(struct queue *q)
{
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

int queue_is_empty(struct queue *q)
{
    return q->count == 0;
}

int queue_is_full(struct queue *q)
{
    return q->count == QUEUE_SIZE;
}

int queue_enqueue(struct queue *q, int val)
{
    if (queue_is_full(q)) {
        return -1;
    }

    q->buf[q->tail] = val;
	//如果已经到数组末尾，就回到开头（形成一个“环”)
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->count++;
    return 0;
}

int queue_dequeue(struct queue *q, int *val)
{
    if (queue_is_empty(q)) {
        return -1;
    }

    *val = q->buf[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count--;
    return 0;
}

int main(void)
{
    struct queue q;
    int val;

    queue_init(&q);

    /* 入队 */
    for (int i = 0; i < 5; i++) {
        queue_enqueue(&q, i);
        printf("enqueue %d\n", i);
    }

    /* 出队 */
    while (!queue_is_empty(&q)) {
        queue_dequeue(&q, &val);
        printf("dequeue %d\n", val);
    }

    return 0;
}
