#include "BubbleSort.h"

void BubbleSort::Exec(int* array, int size)
{
	for (int round = 0; round < size - 1; round++)
	{
		for (int i = 0; i < size - 1 - round; i++)
		{
			if (array[i] > array[i + 1])
			{
				int memory = array[i];
				array[i] = array[i + 1];
				array[i + 1] = memory;
			}
		}
	}
}