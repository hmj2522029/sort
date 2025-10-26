#include "QuickSort.h"

void QuickSort::Exec(int* array, int size)
{
	int left = 0;           //�z��̈�ԍ��̃C���f�b�N�X
	int right = size - 1;  //�z��̈�ԉE�̃C���f�b�N�X
	int pivot = array[0]; //��l��z��̈�ԍ��ɐݒ�


	while (left <= right)	//left��right����������܂ŌJ��Ԃ�
	{
		//��l���傫���l��������܂ŉE�Ɉړ�
		while (array[left] < pivot)
		{
			left++;
		}
		//��l��菬�����l��������܂ō��Ɉړ�
		while (array[right] > pivot)
		{
			right--;
		}
		//left��right���������Ă��Ȃ��ꍇ�A�l������
		if (left <= right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}

	//�ċA�I�ɃN�C�b�N�\�[�g��K�p
	if (0 < right)
	{
		QuickSort::Exec(array, right + 1);
	}
	if (left < size - 1)
	{
		QuickSort::Exec(&array[left], size - left);
	}

}