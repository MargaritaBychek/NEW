#include"functions.h"

string inputString()
{
	string str;
	string type="������ ����� ������ ";
	int flag;
	do
	{
		try
		{
			flag = 0;
			rewind(stdin);
			cout << "������� ������(������ ������ ���� �� �������, ����� ��������� �����,�������, ',' , '.' , '-') " << endl;
			getline(cin, str);
			for (int i = 0; str[i]; i++)
			{
				if(i> StringMax)
					throw exp_input("������� ������� ������!", type, 1.1);
				if (str[0] == '.' || str[0] == ',' || str[0] == ' ' || str[0] == '-' 
					|| str[0] == '='|| str[0] == '+' || str[0] == '*' || str[0] == '/' 
					|| (str[0] > '0'&&str[0] < '9'))
					throw exp_input("������������ ������ ������!", type, 1.2);
				if ((str[i]<'�' || str[i]>'�') && (str[i] < '�' || str[i] > '�') 
					&& (str[i] != ' ') && (str[i] != '.') && (str[i] != ',') 
					&& (str[i] != '-')&& (str[i] < '0'||str[i] > '9'))
					throw exp_input("������ ������ ���� ������ �� �������!", type, 1.3);
				if ((str[i] == '-') && (str[i+1] == '-'))
					throw exp_input("��������� ������� ������!", type, 1.4);
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
			cout << "�������������� ������\n";
			rewind(stdin);
		}
	} while (flag);
	return str;
}

int inputNumber(int min, int max)
{
	int i;
	string type = "������ ����� ����� ";
	int flag;
	do
	{
		try
		{
			flag = 0;
			rewind(stdin);
			cout << "������� �����(�� " <<min<<" �� "<<max<<")"<< endl << "-->";
			cin >> i;
			if (!cin.good() || cin.peek() != '\n')
				throw exp_input("�� �����!", type, 2.1);
			if ((i < min || i > max)&&i!=0)
				throw exp_input("����� �� ���������� �������!", type, 2.2);
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
			cout << "�������������� ������\n";
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