#pragma once
#include "Vector.h"
template<typename T>
T Vector<T>::insert(int rank, T value){
	expand();
	int hi = _size;
	while (hi > rank)
	{
		_elm[hi] = _elm[hi - 1];
		hi--;
	}
	_size++;
	return _elm[rank] = value;
}
template<typename T>
T Vector<T>::append(T value){
	return insert(_size, value);
}
template<typename T>
int Vector<T>::remove(int lo, int hi){
	while (hi < _size){
		_elm[lo++] = _elm[hi++];
	}
	_size -= hi - lo;
	return hi - lo;
}
template<typename T>
int Vector<T>::remove(int rank){
	return remove(rank, rank + 1);
}
template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &v){
	if (_elm) {
		delete[] _elm;  //»Ù_elm“—¥Ê‘⁄£¨‘Ú…æ≥˝
	}
	FromCopy(v, 0, v._size);
	return *this;
}