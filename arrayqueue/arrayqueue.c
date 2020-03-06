#include <stdio.h>
#include <string.h>
#include "arrayqueue.h"

/**
	@brief Init a queue.
	@param -Q Queue to init.
	@return  
 **/
int initQueue(QueueType_t* Q)
{
	Q->head = 0;
	Q->rear = 0;
	
	return 1;
}

/**
	@brief Clear a queue.
	@param -Q Queue to clear.
	@return
 **/
int clearQueue(QueueType_t* Q)
{
	
	Q->head = 0;
	Q->rear = 0;
	
	return 1;
}

/**
	@brief qurey queue current length.
	@param - Q Queue to qurey.
	@return qurey length
 **/
int queueLength(QueueType_t* Q)
{

	return ((Q->rear - Q->head + QLENGTH) % QLENGTH);

}

/**
	@brief Put an item into the queue.
	@param - Q Which queue to put.
	       - item data to put.
	@return 0 no more space.
			1 put success.
 **/
int enQueue(QueueType_t* Q, int* item)
{
	if ((Q->rear + 1) % QLENGTH == Q->head)
	{
		return 0;
	}

	memset(Q->data[Q->rear], 0, sizeof(item) * QITEMLENGTH);
	memcpy(Q->data[Q->rear], item, sizeof(item) * QITEMLENGTH);
	
	Q->rear = (Q->rear + 1) % QLENGTH;
	
	return 1;
}

/**
	@brief An item remove from the queue.
	@param - Q Which queue.
		   - item data output.
	@return 0 no item.
			1 remove success.
 **/
int deQueue(QueueType_t* Q, int* item)
{
	if (Q->head == Q->rear)
	{
		return 0;
	}

	memcpy(item, Q->data[Q->head], sizeof(item) * QITEMLENGTH);
	
	Q->head = (Q->head + 1) % QLENGTH;
	
	return 1;
}

void queueTest()
{
	QueueType_t testQ;
	int testdata1[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int testdata2[13] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int dataout[13] = {0};

	initQueue(&testQ);
	printf_s("init OK\n");

	enQueue(&testQ, testdata1);
	printf_s("enQueue testdata1\n");

	enQueue(&testQ, testdata2);
	printf_s("enQueue testdata2\n");

	printf_s("queueLength = %d\n", queueLength(&testQ));

	deQueue(&testQ, dataout);
	for (int i = 0; i < 13; i++)
	{
		printf_s(" %d ", dataout[i]);
	}
	printf_s("\n");
	printf_s("queueLength = %d\n", queueLength(&testQ));

	printf_s("\n");

	deQueue(&testQ, dataout);
	for (int i = 0; i < 13; i++)
	{
		printf_s(" %d ", dataout[i]);
	}
	printf_s("\n");
	printf_s("queueLength = %d\n", queueLength(&testQ));
}

int main()
{
	queueTest();
	return 0;
}


