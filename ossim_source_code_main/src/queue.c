#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	int queue_counter = 0;

	//check priority
	for(int i = 0; i < q->size; i++)
	{
		if(proc->priority < q->proc[i]->priority)
		{
			break;
		}
		queue_counter++;
	}

	//push lower priority process back
	for(int i = q->size; i > queue_counter; i--)
	{
		q->proc[i] = q->proc[i - 1];
	}

	//put process to queue
	q->proc[queue_counter] = proc;
	q->size++;	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	
	//check empty queue
	if(empty(q))
	{
		return NULL;
	}
	else
	{
		q->size--;
		return q->proc[q->size];
	}
}

