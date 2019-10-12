#include <stdio.h>
#include "sort.h"

/**	
	@brief Sort from small to large.
	@param - a[] array, - len array length.
	@return none
 **/


void bubbleSort(int a[], int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


/**
	@brief	Sort from small to large founction test.
	@param	none.
	@return	none.
 **/

void bubbleSortTest(void)
{
	int test_number[] = { 3, 5, 12, 16, 7, 98, 56, 2, 1, 33 };
	for (int i = 0; i < sizeof(test_number) / sizeof(test_number[0]); i++)
	{
		printf_s("%d \t", test_number[i]);
	}
	printf_s("\n");

	bubbleSort(test_number, sizeof(test_number) / sizeof(test_number[0]));
	for (int i = 0; i < sizeof(test_number) / sizeof(test_number[0]); i++)
	{
		printf_s("%d \t", test_number[i]);
	}
}


/**
	@brief Sort from small to large.
	@param - a[] array, - len array length.
	@return none
 **/
void selectSort(int a[], int len)
{
	int i, j, min, temp;
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}

	}
}

void selectSortTest(void)
{
	int test_number[] = { 3, 5, 12, 16, 7, 98, 56, 2, 1, 33 };
	for (int i = 0; i < sizeof(test_number) / sizeof(test_number[0]); i++)
	{
		printf_s("%d \t", test_number[i]);
	}
	printf_s("\n");

	selectSort(test_number, sizeof(test_number) / sizeof(test_number[0]));
	for (int i = 0; i < sizeof(test_number) / sizeof(test_number[0]); i++)
	{
		printf_s("%d \t", test_number[i]);
	}
}






int main()
{
	selectSortTest();
	return 0;
}

