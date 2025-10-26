#include "RadixSort.h"
#include <vector>

void RadixSort::Exec(int* array, int size)
{
	int maxValue = array[0]; //�z����̍ő�l��������
	for (int i = 1; i < size - 1; i++) 
	{
		if (array[i] > maxValue)
		{
			maxValue = array[i];
		}
	}

	//��\�[�g�̃��C�����[�v
	for (int exp = 1; maxValue / exp > 0; exp *= 10)	//�ʂ��Ƃɏ���
	{
		std::vector<int> output(size);	//�o�͔z��
		int count[10] = { 0 };			//�e���̏o���񐔂��i�[����z��

		//�e���̏o���񐔂��J�E���g
		for(int i = 0; i < size - 1; i++)
		{
			int digitValue = (array[i] / exp) % 10; //���݂̈ʂ̒l���擾	��: �l�� 345 �̏ꍇ�Adigit = 10(�\�̈�)�Ȃ� digitValue = 4
			count[digitValue]++;
		}	

		//�o���񐔂�ݐϘa�ɕϊ�
		//�ǂ̌������Ԗڂɗ��邩�����߂邽��
		for (int i = 1; i < 10; i++) 
		{
			count[i] += count[i - 1];
		}

		//�o�͔z��ɒl��z�u
		for (int i = size - 1; i >= 0; i--) //����\�[�g�̂��߂ɋt���ŏ���
		{
			int digitValue = (array[i] / exp) % 10;
			output[count[digitValue] - 1] = array[i];
			count[digitValue]--;
		}

		//�o�͔z������̔z��ɃR�s�[
		for (int i = 0; i < size; i++) 
		{
			array[i] = output[i];
		}
	}
}