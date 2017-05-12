#include "Vector.h"
#include <iostream>

int main()
{
	Vector<int>  v;
	for (int i = 10; i > -1; i--)
	{
		v.append(1);
	}
	v.unique();
	for (int i = 0; i < v.Size(); i++)
	{
		std::cout << "the " << i << " is: " << v[i] << std::endl;
		//std::cout << "the value " << i * 10 << " index is : " << v.search(i * 10) << std::endl;
	}
}
