#include <iostream>
#include <vector>
#include <chrono>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
//#include "SelectionSort.h"
//#include "InsertionSort.h"
//#include "QuickSort.h"
//#include "RadixSort.h"
using namespace std;

void ShowArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main()
{
	constexpr int Size = 10;
	Sort* BeSort = new QuickSort();

	//乱数の初期化
	srand((unsigned int)time(NULL)); 

	// 配列作成
	vector<int> array(Size);
	for (int i = 0; i < Size; i++)
	{
		array[i] = rand() % 100;
	}
 	ShowArray(array.data(), Size);

	// 時間計測開始
	auto start = std::chrono::system_clock::now();

	// ソート実行
	
	//バブルソート
	cout << typeid(*BeSort).name() << endl;
	BeSort->Exec(array.data(), Size);
	delete BeSort;

	// 時間計測終了
	auto end = std::chrono::system_clock::now();
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換

	ShowArray(array.data(), Size);
	// 所要時間を表示
	cout << elapsed / 1000.0 << "sec" << endl;
}
