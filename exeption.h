#pragma once
#include<iostream>
#include<string>
using namespace std;

class exeption
{
protected:
	string message;
public:
	exeption(string m_message)
	{
		message = m_message;
	}
	~exeption(){}
	void show()
	{
		cout << message << endl;
	}
};

class exp_input:public exeption
{
protected:
	string type;
	double kod;
public:
	exp_input(string m_message, string m_type, double m_kod) :exeption(m_message)
	{
		type = m_type;
		kod = m_kod;
	}
	~exp_input(){}
	void show()
	{
		cout <<type<< kod <<" ";
		exeption::show();
	}
};

/*class exp_file :public exeption
{
protected:
public:
	exp_file(string m_message);
	~exp_file(){}
};

class exp_container :public exeption
{
protected:
public:
	exp_container(string m_message);
	~exp_container() {}
};*/