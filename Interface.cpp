#include"Interface.h"

template <class T>
void Interface<T>::menu()
{
	int n;
	bool flag = true;
	while (flag) {
		system("cls"); 
		cout << "\t\tМЕНЮ\n";
		cout << "\t1-Работа с предпринимателями"
			<< "\n\t2-Работа с туристами"
			<< "\n\t3-Работа с бизнесом\n\t"
			<< "0-Выход\n->";
		n=inputNumber(0, 3);
		switch (n)
		{
		case 0:flag = false; break;
		case 1:
		{Interface<entrepreneur>entr;
		entr.fun(); }	break;
		case 2:
		{Interface<tourist>tour;
		tour.fun(); } break;
		case 3:
		{Interface<business>busi;
		busi.fun(); } break;
		default:cout << "Неверный ввод!\n";
			break;
		}
	}
}


template <class T>
void Interface<T>::fun()
{
	list<T>*l = new list<T>;
	iterat<T> it(l);
	T value;
	int k;
	bool flag = true;
	while (flag)
	{
		//system("cls");
		cout << "\n\t1-Прочитать из txt файла"
			<<"\n\t2-Прочитать из bin файла"
			<<"\n\t3-Добавить"
			<< "\n\t4-Просмотреть++"
			<< "\n\t5-Редактировать"
			<< "\n\t6-Поиск"
			<< "\n\t7-Удалить элемент"
			<< "\n\t8-Сохранить в txt файл"
			<<"\n\t9-Сохранить в bin файл"
			<<"\n\t10-sortFioDown"
			<< "\n\t11-sortIndexDown"
			<< "\n\t12-sortFioUp"
			<< "\n\t13-Просмотреть--"
			<< "\n\t14-sortIndexUp"
			<< "\n\t0-Выход\n\t->";
		k = inputNumber(0, 15);
		//system("cls");
		switch (k)
		{
		case 0:l->Delete();
			flag = false; break;
		case 1:l->ReadFile(*l,value);
			value.showTitle();
			l->Show();
			break;
		case 2:{ 
			FileBIN<T> binn(value.FILE_OF_BIN);
			T obj;
			l->Delete();
			if (binn.open())
			{
				while (true)
				{
					binn.readBin(obj);
					if (binn.eof())
						break;
					l->Push(obj);
				}
			}
			cout << "Прочитано" << endl;
			value.showTitle();
			l->Show();
			//binn.close();
		}
			break;
		case 3:cin >> value;
			l->Push(value);
			break;			
		case 4: {
			value.showTitle();
			if (it.begin() == true)
			{
				do
				{
					cout << *it;
				} while ((it++) == true);
			}
			else
				cout << "error" << endl;
		}break;
		case 5:l->Edit();
			break;		
		case 6: {//List<T> *t;
			cin >> value;
			algoritm<T>::poisk(&it,value);
			/*value.showTitle();
			t = l->Search(value);*/ }
				break;
		case 7:l->DeleteEl();
			break;
		case 8:l->WriteFile(*l, value); 
			break;
		case 9:
		{
			FileBIN<T> binn(value.FILE_OF_BIN);
			if (binn.open())
			{
				while (l->Empty()) //пока вершина не в NULL
				{
					value = l->Ret();
					binn.writeBin(value);
					rewind(stdin);
				}
			}
			cout << "Записано" << endl;
		}
			break;
		case 10: {
			algoritm<T>::sortFioDown(&it, *l);
			value.showTitle();
			if (it.begin() == true)
			{
				do
				{
					cout << *it;
				} while ((it++) == true);
			}
			break;
		}
		case 11: {
			algoritm<T>::sortIndDown(&it, *l); 
			value.showTitle();
			if (it.begin() == true)
			{
				do
				{
					cout << *it;
				} while ((it++) == true);
			}
			break; }
		case 12: {
			algoritm<T>::sortFioUp(&it,*l);
			value.showTitle();
			if (it.begin() == true)
			{
				do
				{
					cout << *it;
				} while ((it++) == true);
			}
			break; }
		case 13: {
			value.showTitle();
			if (it.end() == true)
		{
			do
			{
				cout << *it;
			} while ((it--) == true);
		}
				 else
			cout << "error" << endl;
		}
		 break;
		case 14: {
			algoritm<T>::sortIndUp(&it, *l);
			value.showTitle();
			if (it.begin() == true)
			{
				do
				{
					cout << *it;
				} while ((it++) == true);
			}
			break; }
		default:cout << "Неверный ввод!\n";
			break;
		}
		//system("pause");
}
}

