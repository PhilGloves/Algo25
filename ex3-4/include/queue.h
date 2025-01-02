#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Defines a queue structure to store generic pointers.
 *
 * The queue uses a circular buffer.
 */
typedef struct queue {
  void** data; /**< Pointer to the array storing queue elements. */
  int head;    /**< Index of the oldest element in the queue. */
  int tail;    /**< Index where the next element will be inserted. */
  int size;    /**< Maximum number of elements the queue can hold. */
} Queue;

/**
 * @brief Creates a new queue of the given max size.
 *
 * @param size The maximum number of elements the queue can hold.
 *
 * @return Pointer to the newly created queue, NULL if the allocation fails
 *         or the size is not positive.
 */
Queue* queue_create(int size);

/**
 * @brief Adds an element to the queue.
 *
 * @param queue Pointer to the queue.
 * @param element Pointer to the element to be added.
 *
 * @note If the queue is full, this function will overwrite the oldest element.
 *       If the queue or element is NULL, an error message is printed.
 */
void queue_enqueue(Queue* queue, void* element);

/**
 * @brief Removes and returns the oldest element from the queue.
 *
 * @param queue Pointer to the queue.
 *
 * @return Pointer to the dequeued element, NULL if the queue is empty
 *         or the queue pointer is NULL.
 */
void* queue_dequeue(Queue* queue);

/**
 * @brief Checks if the queue is empty.
 *
 * @param queue Pointer to the queue.
 *
 * @return Non-zero value if the queue is empty, 0 if it contains elements.
 *         If the queue pointer is NULL, prints an error and returns 1.
 */
int queue_empty(Queue* queue);

/**
 * @brief Frees the memory allocated for the queue.
 *
 * @param queue Pointer to the queue to be freed.
 *
 * @note If the queue pointer is NULL, this function does nothing.
 */
void queue_free(Queue* queue);
#endif //QUEUE_H
