#include "InsertionSort.h"

void InsertionSort::Exec(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int InsertValue = array[i]; //�}���������l
		int j = i - 1;				//�}���������l�̈�O�̃C���f�b�N�X

		//�z��̍��̒l�𒲂ׁA�傫���Ȃ���בւ�(�z��̈�ԍ��ɍs���܂ł����̒l�����̒l�����������Ȃ�J��Ԃ�)
		while(j >= 0 && array[j] > InsertValue)
		{
			array[j + 1] = array[j];
			j--;
		}

		//�Ō�̓��ւ̂Ƃ��ɂł���󂢂��ꏊ�ɓ����
		array[j + 1] = InsertValue;
	}
}