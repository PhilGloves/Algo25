#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* queue_create(int size){
  if(size <= 0)
    return NULL;
  Queue* queue = calloc(1, sizeof(Queue));
  if(!queue){
    printf("Error allocating memory for queue\n");
    return NULL;
  }
  queue->data = calloc(size, sizeof(void*));
  queue->size = size;
  queue->head = 0;
  queue->tail = 0;
  return queue;
}

void queue_enqueue(Queue* queue, void* element){
  if (!queue || !element){
    printf("Error enqueuing element\n");
    return;
  }
  queue->data[queue->tail++] = element;
  if(queue->tail == queue->size)
    queue->tail = 0;
}

void* queue_dequeue(Queue* queue){
  if (!queue){
    printf("Error dequeuing element\n");
    return NULL;
  }
  void* result = queue->data[queue->head++];
  if(queue->head == queue->size)
    queue->head = 0;
  return result;
}

int queue_empty(Queue* queue){
  if (!queue){
    printf("Error empty queue\n");
  }
  return queue->head == queue->tail;
}

void queue_free(Queue* queue){
  if (!queue){
    printf("Error dequeuing element\n");
  }
  free(queue->data);
  free(queue);
}