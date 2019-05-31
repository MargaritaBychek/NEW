#pragma once
#include"entrepreneur.h"
#include"tourist.h"

struct Address
{
	string street;
	int no;
};
class business :public entrepreneur, public tourist
{
protected:
	Address address[2];
public:
	string const FILE_OF_TXT = "Bisiness.txt";
	string const FILE_OF_BIN = "Bisiness1.txt";
	business() {
		for (int i = 0; i < 2; i++)
		{
			address[i].street = "";
			address[i].no = 0;
		}
	}
	business(int m_index,string m_fio, string m_year, int m_licens, Tax m_tax[3], string m_pass, Broad m_broad[], Address m_address[]);
	~business() {}
	business(const business& obj);
	void showTitle();
	void setAddr(Address m_address[]);
	string getAddr();
	friend istream& operator>>(istream& is, business& obj);
	friend ifstream& operator>>(ifstream& is, business& obj);
	friend fstream& operator >>(fstream& is, business&obj);
	friend fstream& operator <<(fstream& os, business&obj);
	friend ostream& operator<<(ostream& os,const business& obj);
	friend ofstream& operator<<(ofstream& os, business& obj);
	business& operator=(const business& obj);
	bool operator==(business& obj);
	bool operator>=(business& obj);
	bool operator<=(business & obj);
	bool operator>(business& obj);
	bool operator<(business& obj);
};