#include"human.h"
#include"entrepreneur.h"
#include"tourist.h"
#include"business.h"
#include"exeption.h"
#include"functions.h"
#include"list.cpp"
#include"Interface.cpp"
#include"FileBIN.cpp"
#include"iterat.cpp"
#include"algoritm.cpp"
#include<Windows.h>
#include<set>
#include<iterator>
#include<algorithm>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Interface<human> obj;
	obj.menu();
	system("pause");
	return 0;
}


