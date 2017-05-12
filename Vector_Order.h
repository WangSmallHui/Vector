#pragma once
#include "Vector.h"
template<typename T>
void Vector<T>::swap(T &t1, T &t2){
	T temp = t1;
	t1 = t2;
	t2 = temp;
}
template<typename T>
void Vector<T>::bubblesort(int lo, int hi){
	bool flag = false;
	for (int i = lo; i < hi - 1 && !flag; i++){
		flag = true;
		for (int j = i + 1; j < hi; j++){
			if (_elm[i] > _elm[j]){
				swap(_elm[i], _elm[j]);
				flag = false;
			}
		}
	}
}
template<typename T>
void Vector<T>::bubblesort(){
	bubblesort(0, _size);
}
template<typename T>
void Vector<T>::mergesort(int lo, int hi){
	if (hi - lo < 2) return;
	int mid = (lo + hi) >> 1;
	mergesort(lo, mid);
	mergesort(mid, hi);
	merge(lo, mid, hi);
}
template<typename T>
void Vector<T>::mergesort(){
	mergesort(0, _size);
}
template<typename T>
void Vector<T>::merge(int lo, int mid, int hi){
	T *ele = _elm + lo;
	T *le = new T[mid - lo]; //left array
	for (int i = 0; i < mid - lo; i++){
		le[i] = ele[i];
	}
	T *re = _elm + mid; //right array
	for (int i = 0, j = 0, k = 0; i < mid - lo || j < hi - mid; k++){
		//左半部分数组未处理完的情况下
		//1 左半部分数组＜右半部分数组
		//2 有半部分数组已经处理完毕
		if (i < mid - lo && (le[i] < re[j] || !(j < hi - mid))){
			ele[k] = le[i++];
		}
		if (j < hi - mid && (re[j] <= le[i] || !(i < mid - lo))){
			ele[k] = re[j++];
		}
	}
}
template<typename T>
int Vector<T>::depulicate(){
	int size = _size;
	for (int i = 1; i < _size;){
		int rank = find(_elm[i], 0, i);
		if (rank > -1){
			remove(rank);
		}
		else{
			i++;
		}
	}
	return size - _size;
}
template<typename T>
int Vector<T>::unique(){
	int j = 0, i = 1;
	while (i < _size){ //i==_size break
		if (_elm[i] != _elm[j]){
			_elm[++j] = _elm[i]; 
		}
		i++;
	}
	_size = ++j;
	return i - j;
}