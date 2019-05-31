#pragma once
#include"human.h"

struct Tax
{
	string date;
	int money;
};

class entrepreneur : virtual public human
{
protected:
	int licensia;
	Tax tax[3];
public:
	string const FILE_OF_TXT = "Entrepreneur.txt";
	//string const FILE_OF_BIN = "Entrepreneur1.txt";
	string const FILE_OF_BIN = "Entrepreneur3.txt";
	entrepreneur() {
		licensia = 0;
		for (int i = 0; i < 2; i++)
		{
			tax[i].date = "0";
			tax[i].money = 0;
		}
	}
	entrepreneur(int m_index,string m_fio, string m_year, int m_licens, Tax m_tax[3]);
	entrepreneur(const entrepreneur& obj);
	~entrepreneur(){}
	void setLisens(int m_licens);
	void setTax(Tax m_tax[2]);
	int getLisens()const;
	string getTax();
	int getIndex();
	void showTitle();
	friend istream& operator>>(istream& is, entrepreneur& obj);
	friend ifstream& operator>>(ifstream& is, entrepreneur& obj);
	friend fstream& operator >>(fstream& is, entrepreneur&obj);
	friend fstream& operator <<(fstream& os, entrepreneur&obj);
	friend ostream& operator<<(ostream& os, const entrepreneur& obj);
	friend ofstream& operator<<(ofstream& os, entrepreneur& obj);
	entrepreneur& operator=(const entrepreneur& obj);
	bool operator==(entrepreneur& obj);
	bool operator>=(entrepreneur& obj);
	bool operator<=(entrepreneur& obj);
	bool operator>(entrepreneur& obj);
	bool operator<(const entrepreneur& obj)const;
};