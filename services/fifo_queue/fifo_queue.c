/*
 * fifo_queue.c
 *
 *  Created on: Dec 20, 2024
 *      Author: vanlo
 */


#include "fifo_queue.h"

Fifo_queue* fifo_queue_created(void) {

	Fifo_queue *fifo_queue = (Fifo_queue*) malloc(sizeof(Fifo_queue));
	while (fifo_queue == NULL) {

	};
	fifo_queue_init(fifo_queue);
	return fifo_queue;
}

void fifo_queue_init(Fifo_queue *fifo_queue) {

    fifo_queue->head = 0;
    fifo_queue->tail = 0;
    fifo_queue->size = 0;
}
