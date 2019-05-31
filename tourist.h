#pragma once
#include"human.h"

struct Broad
{
	string date;
	string country;
};
class tourist : virtual public human
{
protected:
	string passport;
	Broad broad[2];
public:
	string const FILE_OF_TXT = "Tourists.txt";
	string const FILE_OF_BIN = "Tourists1.txt";
	tourist()
	{
		passport = "0";
		for (int i = 0; i < 2; i++)
		{
			broad[i].date= "";
		}
	}
	tourist(int m_index,string m_fio, string m_year, string m_pass, Broad m[]);
	~tourist(){}
	tourist(const tourist& obj);
	void showTitle();
	void setPass(string m_pass);
	void setBroad(Broad m[]);
	string getPass()const;
	string getBroad();
	friend istream& operator>>(istream& is, tourist& obj);
	friend ifstream& operator>>(ifstream& is, tourist& obj);
	friend fstream& operator >>(fstream& is, tourist&obj);
	friend fstream& operator <<(fstream& os, tourist&obj);
	friend ostream& operator<<(ostream& os, const tourist& obj);
	friend ofstream& operator<<(ofstream& os, tourist& obj);
	tourist& operator=(const tourist& obj);
	bool operator==(tourist& obj);
	bool operator>=(tourist& obj);
	bool operator<=(tourist& obj);
	bool operator>(tourist& obj);
	bool operator<(tourist& obj);
};