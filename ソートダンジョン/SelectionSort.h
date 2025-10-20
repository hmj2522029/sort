#pragma once
#include "Sort.h"

class SelectionSort : public Sort
{
public:
	virtual void Exec(int* array, int size) override;
};