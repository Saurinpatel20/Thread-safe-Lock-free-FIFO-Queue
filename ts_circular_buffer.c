#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "ts_circular_buffer.h"

int thread_safe_enqueue(ts_circular_buffer_st_t *queue, int32_t val) {
	assert(queue);
	// This is handling for overrun by the head.
    if (((queue->head + 1) % queue->queue_size) == queue->tail) return -1;

    // inserts the value into the queue and progresses the head.
    queue->data[queue->head] = val;
    queue->head = (queue->head + 1) % queue->queue_size;
    return 0;
}

int32_t thread_safe_dequeue(ts_circular_buffer_st_t *queue) {
	assert(queue);
	// This handlers underrun and when the queue is empty.
    if (queue->tail == queue->head) return -1;

    int32_t handle = queue->data[queue->tail];
    queue->data[queue->tail] = 0;
    queue->tail = (queue->tail + 1) % queue->queue_size;
    return handle;
}
