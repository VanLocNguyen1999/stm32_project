/*
 * fifo_queue.h
 *
 *  Created on: Dec 20, 2024
 *      Author: vanlo
 */

#ifndef SERVICES_FIFO_QUEUE_FIFO_QUEUE_H_
#define SERVICES_FIFO_QUEUE_FIFO_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 		5

typedef struct Fifo_queue_t Fifo_queue;
struct Fifo_queue_t {
	uint32_t buffer[BUFFER_SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t size;
};

Fifo_queue* fifo_queue_created(void);
void fifo_queue_init(Fifo_queue *fifo_queue);
static void fifo_queue_enqueue(Fifo_queue *fifo_queue, uint32_t data);
static uint32_t fifo_queue_peek(Fifo_queue *fifo_queue);
static void fifo_queue_dequeue(Fifo_queue *fifo_queue);
static bool fifo_queue_is_exists(Fifo_queue *fifo_queue, uint32_t data);

static inline bool fifo_queue_is_empty(Fifo_queue *fifo_queue) {
    return  fifo_queue->size == 0;
}

static inline bool fifo_queue_is_full(Fifo_queue *fifo_queue) {

	return fifo_queue->size == BUFFER_SIZE;
}

static inline bool fifo_queue_is_exists(Fifo_queue *fifo_queue,uint32_t data) {

	uint8_t current = fifo_queue->head;
	for (int i = 0; i < fifo_queue->size; i++) {
		if (fifo_queue->buffer[current] == data) {
			return 1;  //data already exists in the queue
		}
		current = (current + 1 >= BUFFER_SIZE) ? 0 : current + 1;
	}
	return 0;  //data doesn't exist in the queue
}

static inline void fifo_queue_enqueue(Fifo_queue *fifo_queue, uint32_t data) {
    if (fifo_queue_is_full(fifo_queue)) {
        fifo_queue->head = (fifo_queue->head + 1 >= BUFFER_SIZE) ? 0 : fifo_queue->head + 1;
    } else {
        fifo_queue->size++;
    }
    fifo_queue->buffer[fifo_queue->tail] = data;
    fifo_queue->tail = (fifo_queue->tail + 1 >= BUFFER_SIZE) ? 0 : fifo_queue->tail + 1;
}

static inline uint32_t fifo_queue_peek(Fifo_queue *fifo_queue) {
    if (fifo_queue_is_empty(fifo_queue)) {

        return 0;
    }
    uint32_t data = fifo_queue->buffer[fifo_queue->head];
    return data;
}

static inline void fifo_queue_dequeue(Fifo_queue *fifo_queue){

	if(!fifo_queue_is_empty(fifo_queue)){

		fifo_queue->size --;
		fifo_queue->head = (fifo_queue->head + 1 >= BUFFER_SIZE) ? 0 : fifo_queue->head + 1;
	}
}

#endif /* SERVICES_FIFO_QUEUE_FIFO_QUEUE_H_ */
