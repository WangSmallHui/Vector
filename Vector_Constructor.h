#pragma once
#include "Vector.h"

template<typename T>
void Vector<T>::FromCopy(const Vector &v, int lo, int hi){
	_elm = new T[hi - lo];
	_size = 0;
	while (lo < hi){
		_elm[_size++] = v[lo++];
	}
	_capacity = _size << 1;
}