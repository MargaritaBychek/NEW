#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include<windows.h>
#include"functions.h"
#include"FileBIN.h"

using namespace std;

template <class T>
struct List
{
	T data;
	List *prev, *next;
};

template <class T>
class list
{
	List<T> *top, *bottom,*last;
	template <class T>
	friend class iterat;
public:
	list();
	~list();
	list(const T& obj);
	void Push(T tmp);
	void Show();
	bool Empty();
	T Ret();
	void Delete();
	void DeleteEl();
	void Edit();
	List<T>* Search(T obj);
	void WriteFile(list<T> &tmp, T obj);//запись листа в файл
	void ReadFile(list<T> &tmp, T obj);//чтение из файла в лист
	void WriteFileB(list<T> &tmp, T obj);
	void ReadFileB(list<T> &tmp, T obj);
	List<T>* begin();
	List<T>*end();
};
