#include "InsertionSort.h"

void InsertionSort::Exec(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int InsertValue = array[i]; //挿入したい値
		int j = i - 1;				//挿入したい値の一個前のインデックス

		//配列の左の値を調べ、大きいなら並べ替え(配列の一番左に行くまでか左の値が今の値よりも小さいなら繰り返し)
		while(j >= 0 && array[j] > InsertValue)
		{
			array[j + 1] = array[j];
			j--;
		}

		//最後の入替のときにできる空いた場所に入れる
		array[j + 1] = InsertValue;
	}
}