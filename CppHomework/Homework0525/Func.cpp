#include "Func.h"


int global_func::StringCount(const char* _Arr)
{
	// ���� �����ڵ带 �����ϼ���
	int ChCount = 0;
	while (_Arr[ChCount])
	{
		++ChCount;
	}

	return ChCount;
}