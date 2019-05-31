#include"iterat.h"

template <class T>
iterat<T>::iterat()
{
	q = new list<T>;
	current = NULL;
}
template <class T>
iterat<T>::iterat(list<T>* list)
{
	q = list;
}
template<class T>
iterat<T>::iterat(List<T>*List)
{
	current = List;
}
template <class T>
iterat<T>::~iterat()
{
	delete q;
}
template <class T>
bool iterat<T>::begin()
{
	if (q->top)
	{
		current = q->top;
		return true;
	}
	else return false;
}
template <class T>
bool iterat<T>::end()
{
	if (q->bottom)
	{
		current = q->bottom;
		return true;
	}
	else return false;
}
template <class T>
bool iterat<T>::operator++(int i)
{
	if (current->next)
	{
		current = current->next;
		return true;
	}
	else return false;
}
template <class T>
bool iterat<T>::operator+=(int n)
{
	if(current->next)
	{
	for (int i = 0; i < n; i++)
	{
		if (current->next)
		{
			current = current->next;
		}
	}
	return true;
	}
	else return false;
}
template <class T>
bool iterat<T>::operator--(int i)
{
	if (current->prev)
	{
		current = current->prev;
		return true;
	}
	else return false;
}
template <class T>
bool iterat<T>::operator==(List<T>*item)
{
	if (current == item)
		return true;
	else return false;
}
//template<class T>
//bool iterat<T>::operator!=(T info)
//{
//	return false;
//}
//template <class T>
//bool iterat<T>::operator!=(T info)
//{
//	if (current->data != info)
//		return true;
//	else return false;
//}
template <class T>
T& iterat<T>::operator*()
{
	if (current)
		return current->data;
	else
	{
		cout << "error\n";
		//return 0;
	}
}

template <class T>
inline bool iterat<T>::operator!=(List<T>*item)
{
	if (current != item)
		return true;
	else return false;
}

