#pragma once
#include"human.h"
#include"entrepreneur.h"
#include"tourist.h"
#include"business.h"
#include"list.h"
#include"functions.h"
#include"FileBIN.h"
#include"iterat.h"
#include"algoritm.h"
#include<set>
#include<iterator>
#include<algorithm>

template <class T>
class Interface
{
	T obj;
public:
	void menu();
	void fun();
	void start();
	void iter();
	void cont();
};