#pragma once
#define CAPACITY_DEFAULT 10

template<typename T>
class Vector{
private:
	T *_elm;
	int _size;
	int _capacity;
public:
	//拷贝构造
	Vector(int size = 0, T val = 0, int capacity = CAPACITY_DEFAULT){
		_elm = new T[_size = size];
		for (int i = 0; i < _size;i++){
			_elm[i] = val;
		}
	}
	Vector(Vector &v, int lo, int hi){
		FromCopy(v, lo, hi);
	}
	Vector(Vector &v, int hi){
		FromCopy(v, 0, hi);
	}
	/*Vector(const Vector &v){
		FromCopy(v, 0, v._size);
	}*/
	~Vector(){  
		delete[] _elm; }
	int Size() const{
		return _size;
	}
	int Capacity() const{
		return _capacity;
	}
	int remove(int lo, int hi);  //Remove Vector[lo,hi)
	int remove(int rank);
	T insert(int rank, T value);
	T append(T value); //向Vector末尾追加value
	int find(T value,int lo,int hi) const; //无序向量查找 Find Vector[lo,hi) 查找不到则返回-1
	int find(T value) const; //无序向量查找
	int search(T value, int lo, int hi) const; //无序向量查找  Search Vector[lo,hi)
	int search(T value) const; //有序向量查找
	void bubblesort(int lo, int hi); //冒泡排序O(n2) Vector[lo,hi)
	void bubblesort();
	void mergesort(int lo, int hi);  //归并排序O(nlogn) Vector[lo,hi)
	void mergesort();
	int unique();  //有序向量唯一化
	int depulicate(); //无序向量唯一化
	T &operator[](int rank){   //not-const Vector[]重载运算符
		return _elm[rank];
	}
	T operator[](int rank) const{  //const Vector[]重载运算符
		return _elm[rank];
	}
	Vector &operator=(const Vector &v);
private:
	void FromCopy(const Vector &v, int lo, int hi); //Copy From Vector[lo,hi)
	void expand(); //扩容
	void swap(T &t1, T &t2);
	void merge(int lo, int mid, int hi);
};
template<typename T>
void Vector<T>::expand(){
	if (_size < _capacity){
		return;
	}
	if (_capacity < CAPACITY_DEFAULT) {
		_capacity = CAPACITY_DEFAULT;
	}
	T *oldelm = _elm;
	_elm = new T[_capacity <<= 1];  //扩容2倍
	for (int i = 0; i < _size; i++){
		_elm[i] = oldelm[i];
	}
	delete[] oldelm;
}
#include "Vector_Constructor.h"
#include "Vector_Operator.h"
#include "Vector_Search.h"
#include "Vector_Order.h"