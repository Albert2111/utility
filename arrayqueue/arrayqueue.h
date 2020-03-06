#pragma once

#define QLENGTH 10
#define QITEMLENGTH 13

typedef struct
{
	int head;
	int rear;
	int data[QLENGTH][QITEMLENGTH];
}QueueType_t;


int initQueue(QueueType_t* Q);

int clearQueue(QueueType_t* Q);

int queueLength(QueueType_t* Q);

int enQueue(QueueType_t* Q, int* item);

int deQueue(QueueType_t* Q, int* item);

void queueTest(void);