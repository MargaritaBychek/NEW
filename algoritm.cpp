#include"algoritm.h"

template<class T>
algoritm<T>::algoritm()
{
	iter = NULL;
}

template<class T>
inline void algoritm<T>::poisk(iterat<T> *it,T& obj)
{
	list<T> temp;
	it->begin();
	int k = 1;
	do
	{
		if (obj == **it)
		{
			temp.Push(**it);
			k = 0;
		}
	} while (((*it)++)==true);
	if (k)
		cout << "Ёлемент не найден\n";
	else
	{
		obj.showTitle();
		temp.Show();
	}
}

template<class T>
void algoritm<T>::sortIndDown(iterat<T> *it, list<T> &tmp)
{
	T temp;
	it->begin();
	iterat<T>it1 = tmp.begin();
	//temp.showTitle();
	do
	{
		cout << "it1\n" << *it1 << endl;
		system("pause");
		it->begin();
		do
		{
			//cout << "it\n" << **it << endl;
			if (*it1 > (**it))
			{
				temp = *it1;
				*it1 = **it;
				**it = temp;
				cout << "change\n";
			}
		} while (((*it)++) == true);
	} while ((it1++) == true);//tmp.Show();

}

template<class T>
void algoritm<T>::sortIndUp(iterat<T> *it,list<T> &tmp)
{
	T temp;
	it->begin();
	iterat<T>it1 = tmp.begin();
	//temp.showTitle();
	do
	{
		cout << "it1\n" << *it1 << endl;
		system("pause");
		it->begin();
		do
		{
			//cout << "it\n" << **it << endl;
			if (*it1 < (**it))
			{
				temp = *it1;
				*it1 = **it;
				**it = temp;
				cout << "change\n";
			}
		} while (((*it)++) == true);
	} while ((it1++) == true);
	//tmp.Show();
}

template<class T>
void algoritm<T>::sortFioDown(iterat<T> *it, list<T> &tmp)
{
	T temp;
	it->begin();
	iterat<T>it1 = tmp.begin();;
	//temp.showTitle();
	do
	{
		cout << "it1\n" << *it1 << endl;
		system("pause");
		it->begin();
		do
		{
			//cout << "it\n" << **it << endl;
			if (*it1 >= (**it))
			{
				temp = *it1;
				*it1 = **it;
				**it = temp;
				cout << "change\n";
			}
		} while (((*it)++) == true);
	} while ((it1++) == true);
}

template<class T>
void algoritm<T>::sortFioUp(iterat<T> *it, list<T> &tmp)
{
	T temp;
	it->begin();
	iterat<T>it1 = tmp.begin();
	//temp.showTitle();
	do
	{
		cout << "it1\n" << *it1 << endl;
		it->begin();
		do
		{
			//cout << "it\n" << **it << endl;
			//system("pause");
			if (*it1 <= (**it))
			{
				temp = *it1;
				*it1 = **it;
				**it = temp;
				cout << "change\n";
			}
		} while (((*it)++) == true);
	} while ((it1++) == true);
	//tmp.Show();
}

//template<class T>
//void algoritm<T>::sortFioMore(iterat<T> *it, list<T> &tmp)
//{
//	T temp;
//	it->begin();
//	iterat<T>it1 = tmp.begin();
//	//temp.showTitle();
//	do
//	{
//		do
//		{
//			if ((**it).getFio().compare((*it1).getFio()) == 1)
//			{
//				temp = **it;
//				**it = *it1;
//				*it1 = temp;
//			}
//		} while ((it1++) == true);
//	} while (((*it)++) == true);
//	//tmp.Show();
//}

//template<class T>
//void algoritm<T>::sortFioLess(iterat<T> *it, list<T> &tmp)
//{
//	T temp;
//	it->begin();
//	iterat<T>it1 = tmp.begin();
//	//temp.showTitle();
//	do
//	{
//		do
//		{
//			if ((**it).getFio().compare((*it1).getFio()) == -1)
//			{
//				temp = **it;
//				**it = *it1;
//				*it1 = temp;
//			}
//		} while ((it1++) == true);
//	} while (((*it)++) == true);
//	//tmp.Show();
//}