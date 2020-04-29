#include "vector.h"
#include <new>
#include <iostream>
#include <math.h>

vector::vector()
{
	ptr = new (std::nothrow) int[2];
	if (ptr == 0)
	{
		std::cout << "Nema memory";
		getchar();
		exit(1);
	}
	*(ptr) = 0;
	sizeVec = 0;
	capacityVec = 2;
}

vector::~vector()
{
	delete[capacityVec] ptr;
}

void vector::resise(int x)
{
	int* tempPtr = new (std::nothrow) int[x];
	if (ptr == 0)
	{
		std::cout << "Nema memory";
		getchar();
		exit(1);
	}
	if (x == capacityVec)
	{
		delete[x] tempPtr;
	}
	if (x > capacityVec)
	{
		for (int i(0); i < x; i++)
		{
			if (*(ptr + i))*(tempPtr + i) = *(ptr + i);
			else *(tempPtr + i) = 0;
		}
		delete[capacityVec] ptr;
		capacityVec = x;
		ptr = tempPtr;
		return;
	}
	else
	{
		for (int i(0); i < x; i++)
		{
			*(tempPtr + i) = *(ptr + i);
		}
		delete[capacityVec] ptr;
		capacityVec = x;
		sizeVec = x;
		ptr = tempPtr;
		return;
	}
}

void vector::print()
{
	for (int i(0); i < sizeVec; i++)
	{
		std::cout << *(ptr + i) << ' ';
	}
	std::cout << std::endl;
}

void vector::push(int x)
{
	if (sizeVec + 1 > capacityVec)
	{
		this->resise(sizeVec + 1 + sqrt(sizeVec));
		capacityVec = sizeVec + 1 + sqrt(sizeVec);
	}
	*(ptr + sizeVec) = x;
	sizeVec++;
}

void vector::pop()
{
	if(sizeVec == 0) return;
	int x = *(ptr + sizeVec - 1);
	sizeVec--;
}
int vector::get()
{
	if (sizeVec == 0)
	{
		std::cout << "Vector empty ";
		return -1;
	}
	else return *(ptr + sizeVec - 1);
}