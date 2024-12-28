#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
  void** data;
  int head;
  int tail;
  int size;
} Queue;

Queue* queue_create(int size);

void queue_enqueue(Queue* queue, void* element);

void* queue_dequeue(Queue* queue);

int queue_empty(Queue* queue);

void queue_free(Queue* queue);
#endif //QUEUE_H
