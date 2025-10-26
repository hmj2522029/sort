#include "RadixSort.h"
#include <vector>

void RadixSort::Exec(int* array, int size)
{
	int maxValue = array[0]; //配列内の最大値を見つける
	for (int i = 1; i < size - 1; i++) 
	{
		if (array[i] > maxValue)
		{
			maxValue = array[i];
		}
	}

	//基数ソートのメインループ
	for (int exp = 1; maxValue / exp > 0; exp *= 10)	//位ごとに処理
	{
		std::vector<int> output(size);	//出力配列
		int count[10] = { 0 };			//各桁の出現回数を格納する配列

		//各桁の出現回数をカウント
		for(int i = 0; i < size - 1; i++)
		{
			int digitValue = (array[i] / exp) % 10; //現在の位の値を取得	例: 値が 345 の場合、digit = 10(十の位)なら digitValue = 4
			count[digitValue]++;
		}	

		//出現回数を累積和に変換
		//どの桁が何番目に来るかを決めるため
		for (int i = 1; i < 10; i++) 
		{
			count[i] += count[i - 1];
		}

		//出力配列に値を配置
		for (int i = size - 1; i >= 0; i--) //安定ソートのために逆順で処理
		{
			int digitValue = (array[i] / exp) % 10;
			output[count[digitValue] - 1] = array[i];
			count[digitValue]--;
		}

		//出力配列を元の配列にコピー
		for (int i = 0; i < size; i++) 
		{
			array[i] = output[i];
		}
	}
}