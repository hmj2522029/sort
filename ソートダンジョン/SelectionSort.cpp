#include "SelectionSort.h"

void SelectionSort::Exec(int* array, int size)
{

	for (int i = 0; i < size - 1; i++)	//最小候補
	{
		int MinimalCandidate = i; //一旦確定していない一番左の値はを最小候補に入れておく(インデックス)

		for (int j = i + 1; j < size; j++)
		{
			//比較候補のほう最小候補よりも値が小さい場合
			if (array[j] < array[MinimalCandidate])
			{
				MinimalCandidate = j; 
			}
		}

		int temp = array[i];
		array[i] = array[MinimalCandidate];
		array[MinimalCandidate] = temp;
	}
}