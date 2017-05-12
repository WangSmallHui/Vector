#pragma once
#include "Vector.h"

template<typename T>
int Vector<T>::find(T value, int lo, int hi) const{
	while (hi-- > lo && _elm[hi] != value){
	}
	return hi < lo ? -1 : hi;
}
template<typename T> 
int Vector<T>::find(T value) const{
	return find(value, 0, _size);
}
template<typename T>
int Vector<T>::search(T value, int lo, int hi) const{ //二分法查找
	while (1 < hi - lo){
		int mid = (lo + hi) >> 1;
		if (value < _elm[mid]) hi = mid;
		else lo = mid;
	}
	return _elm[lo] == value ? lo : -1;
}
template<typename T>
int Vector<T>::search(T value) const{
	return search(value, 0, _size);
}