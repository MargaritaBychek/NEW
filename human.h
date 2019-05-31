#pragma once
#include<iostream>
#include <fstream>
#include <sstream>
#include<iomanip>
#include<string>
#include"functions.h"

using namespace std;

class human
{
protected:
	int index;
	string fio;
	string year;
public:
	human() {
		index = 0;
		fio = "";
		year = "0";
	}
	human(int m_index,string m_fio, string m_year);
	~human() {}
	human(const human& obj);
	void setIndex(int m_index);
	void setFio(string m_fio);
	void setYear(int m_year);
	int getIndex();
	string getFio() const;
	string getYear() const;
	void showTitle();
	friend ostream& operator<<(ostream& os,const human& obj);
	friend ofstream& operator<<(ofstream& os, human& obj);
	friend fstream& operator <<(fstream& os, human&obj);
	friend istream& operator>>(istream& is, human& obj);
	friend ifstream& operator>>(ifstream& is, human& obj);
	friend fstream& operator >>(fstream& is, human&obj);
	human& operator=(const human& obj);
};
