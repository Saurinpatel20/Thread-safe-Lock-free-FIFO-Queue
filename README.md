# Thread-safe-Lock-free-FIFO-Queue
A Thread-safe Lock-free implementation of a FIFO queue.

Features:
* Ensures there's no buffer overrun or underrun
* Allows for larger/smaller sized queues
* Thread-safe and lock-free implementation

## Dependencies:
- C or C++

## Usage:
* Include both .h and .c files in your project
* Initialize a structure for `ts_circular_buffer_st_t` (queue head location, queue tail location, queue size, pointer to data array)
* Utilize the implemented enqeue and deqeue to utilize a thread-safe lock-free FIFO Queue

Example usage:
```C
ts_circular_buffer_st_t circular_buf;
circular_buf = (ts_circular_buffer_st_t) {.head = 0, .tail = 0, .queue_size = 10, .data = malloc(sizeof(uint32_t) * 10)};

uint32_t data = 5;

// Queue's data to buffer
thread_safe_enqueue(&circular_buf, data);

// Dequeue's data from buffer
int32_t dequeued_data = thread_safe_dequeue(&circular_buf);
```

## Additional Notes:
* If different data types are needed in the queue, simply modify the structure in the .h file
* The return value will be `-1` in case of error. This may need modification depending on the data in the queue

## Contact me
[Email](mailto:saurinpatel222@gmail.com)
