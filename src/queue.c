#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size<MAX_QUEUE_SIZE){
		q->proc[q->size]=proc;
		q->size++;
	}
	else 
		return;

}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	//case: queue empty
	if(empty(q)){
		return NULL;
	}

	//case: queue not empty
	int index=0;
	uint32_t priotity=q->proc[0]->priority;
	int k;
	
	//find process has highest priority
	for(k=0;k<q->size;k++){
		if(q->proc[k]->priority>priotity){
			priotity=q->proc[k]->priority;
			index=k;
		}
	}
	struct pcb_t * proc= q->proc[index];

	//remove process in queue
	for(k=index;k< q->size-1;k++){
		q->proc[k]=q->proc[k+1];
	}
	q->proc[q->size-1]=NULL;
	q->size--;

	return proc;
}

