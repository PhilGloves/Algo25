#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
  void** data;
  void* start;
  void* end;
  int size;
} Queue;

Queue* queue_create(int size);

void queue_enqueue(Queue* queue, void* data);

void* queue_dequeue(Queue* queue);

void* queue_free(Queue* queue);
#endif //QUEUE_H
