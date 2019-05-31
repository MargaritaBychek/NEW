#include"functions.h"

string inputString()
{
	string str;
	string type="Ошибка ввода строки ";
	int flag;
	do
	{
		try
		{
			flag = 0;
			rewind(stdin);
			cout << "Введите строку(Строка должна быть на русском, может содержать цифры,пробелы, ',' , '.' , '-') " << endl;
			getline(cin, str);
			for (int i = 0; str[i]; i++)
			{
				if(i> StringMax)
					throw exp_input("Слишком длинная строка!", type, 1.1);
				if (str[0] == '.' || str[0] == ',' || str[0] == ' ' || str[0] == '-' 
					|| str[0] == '='|| str[0] == '+' || str[0] == '*' || str[0] == '/' 
					|| (str[0] > '0'&&str[0] < '9'))
					throw exp_input("Недопустимый первый символ!", type, 1.2);
				if ((str[i]<'А' || str[i]>'Я') && (str[i] < 'а' || str[i] > 'я') 
					&& (str[i] != ' ') && (str[i] != '.') && (str[i] != ',') 
					&& (str[i] != '-')&& (str[i] < '0'||str[i] > '9'))
					throw exp_input("Строка должна быть только на русском!", type, 1.3);
				if ((str[i] == '-') && (str[i+1] == '-'))
					throw exp_input("Несколько дефисов подряд!", type, 1.4);
			}
		}
		catch (exp_input obj)
		{
			flag = 1;
			obj.show();
			rewind(stdin);
		}
		catch (...)
		{
			flag = 1;
			cout << "Непредвиденная ошибка\n";
			rewind(stdin);
		}
	} while (flag);
	return str;
}

int inputNumber(int min, int max)
{
	int i;
	string type = "Ошибка ввода числа ";
	int flag;
	do
	{
		try
		{
			flag = 0;
			rewind(stdin);
			cout << "Введите число(от " <<min<<" до "<<max<<")"<< endl << "-->";
			cin >> i;
			if (!cin.good() || cin.peek() != '\n')
				throw exp_input("Не число!", type, 2.1);
			if ((i < min || i > max)&&i!=0)
				throw exp_input("Выход за допустимые пределы!", type, 2.2);
		}
		catch (exp_input obj)
		{
			flag = 1;
			obj.show();
			cin.clear();
			rewind(stdin);
		}
		catch (...)
		{
			flag = 1;
			cout << "Непредвиденная ошибка\n";
			cin.clear();
			rewind(stdin);
		}
	} while (flag);
	return i;
}

string inputDate()
{
	int day, month, year;
	string ss,d,m;
	stringstream outd, outm, outy;
	year = inputNumber(YearMin, YearMax);
	month= inputNumber(1, 12);
	if(month == 2 && year % 4 == 0)
		day = inputNumber(1, 29);
	else if(month == 2 && year % 4 != 0)
		day = inputNumber(1, 28);
	else if((month < 8 && month % 2 == 0)|| (month > 7 && month % 2 == 1))
		day = inputNumber(1, 30);
	else if((month < 8 && month % 2 == 1)|| (month > 7 && month % 2 == 0))
		day = inputNumber(1, 31);			
	outy << year;
	outm << month;
	outd << day;
	if (month < 10)
		m = "0" + outm.str();
	else m = outm.str();
	if(day < 10)
		d = "0" + outd.str();
	else d = outd.str();
	ss= d+"."+m + "." + outy.str();
	return ss;
}