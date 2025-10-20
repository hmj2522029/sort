#include "SelectionSort.h"

void SelectionSort::Exec(int* array, int size)
{

	for (int i = 0; i < size - 1; i++)	//�ŏ����
	{
		int MinimalCandidate = i; //��U�m�肵�Ă��Ȃ���ԍ��̒l�͂��ŏ����ɓ���Ă���(�C���f�b�N�X)

		for (int j = i + 1; j < size; j++)
		{
			//��r���̂ق��ŏ��������l���������ꍇ
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