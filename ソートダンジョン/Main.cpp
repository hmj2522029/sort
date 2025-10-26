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

	//�����̏�����
	srand((unsigned int)time(NULL)); 

	// �z��쐬
	vector<int> array(Size);
	for (int i = 0; i < Size; i++)
	{
		array[i] = rand() % 100;
	}
 	ShowArray(array.data(), Size);

	// ���Ԍv���J�n
	auto start = std::chrono::system_clock::now();

	// �\�[�g���s
	
	//�o�u���\�[�g
	cout << typeid(*BeSort).name() << endl;
	BeSort->Exec(array.data(), Size);
	delete BeSort;

	// ���Ԍv���I��
	auto end = std::chrono::system_clock::now();
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�

	ShowArray(array.data(), Size);
	// ���v���Ԃ�\��
	cout << elapsed / 1000.0 << "sec" << endl;
}
