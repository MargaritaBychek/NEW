#pragma once
#include"iterat.h"
#include"list.h"

template<class T>
class algoritm
{
	iterat<T> *iter;
public:
	algoritm();
	static void poisk(iterat<T> *iter,T& obj);
	static void sortFioUp(iterat<T> *it, list<T> &tmp);
	static void sortFioDown(iterat<T> *it, list<T> &tmp);
	static void sortIndUp(iterat<T> *it, list<T> &tmp);
	static void sortIndDown(iterat<T> *it, list<T> &tmp);
};