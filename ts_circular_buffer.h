/*
 * ts_circular_buffer.h
 */

#ifndef TS_CIRCULAR_BUFFER_H_
#define TS_CIRCULAR_BUFFER_H_

#include <stdint.h>

typedef struct {
    size_t head;
    size_t tail;
    size_t queue_size;
    uint32_t * data;
} ts_circular_buffer_st_t;

int thread_safe_enqueue(ts_circular_buffer_st_t *queue, int32_t val);
int32_t thread_safe_dequeue(ts_circular_buffer_st_t *queue);

#endif // TS_CIRCULAR_BUFFER_H_
