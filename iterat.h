#pragma once
#include"list.h"

template <class T>
class iterat
{
	list<T> *q;
	List<T> *current;
public:
	iterat();
	iterat(list<T>*);
	iterat(List<T>*);
	~iterat();
	bool begin();
	bool end();
	bool operator++(int);
	bool operator+=(int);
	bool operator--(int);
	bool operator==(List<T>*item);
	//bool operator!=(T info);
	bool operator!=(List<T>*item);
	T& operator*();
};