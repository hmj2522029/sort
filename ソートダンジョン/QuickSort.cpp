#include "QuickSort.h"

void QuickSort::Exec(int* array, int size)
{
	int left = 0;           //配列の一番左のインデックス
	int right = size - 1;  //配列の一番右のインデックス
	int pivot = array[0]; //基準値を配列の一番左に設定


	while (left <= right)	//leftとrightが交差するまで繰り返す
	{
		//基準値より大きい値が見つかるまで右に移動
		while (array[left] < pivot)
		{
			left++;
		}
		//基準値より小さい値が見つかるまで左に移動
		while (array[right] > pivot)
		{
			right--;
		}
		//leftとrightが交差していない場合、値を交換
		if (left <= right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}

	//再帰的にクイックソートを適用
	if (0 < right)
	{
		QuickSort::Exec(array, right + 1);
	}
	if (left < size - 1)
	{
		QuickSort::Exec(&array[left], size - left);
	}

}