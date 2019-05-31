#include"human.h"

human::human(int m_index,string m_fio, string m_year)
{
	index = m_index;
	fio = m_fio;
	year = m_year;
}

human::human(const human& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
}
void human::setIndex(int m_index)
{
	index = m_index;
}
void human::setFio(string m_fio)
{
	fio = m_fio;
}
void human::setYear(int m_year)
{
	year = m_year;
}
int human::getIndex()
{
	return index;
}
string human::getFio() const
{
	return fio;
}
string human::getYear() const
{
	return year;
}
void human::showTitle()
{
	cout << "|"<< setw(3) << "№" << "|" << setw(30) << "Фамилия" << "|" << setw(10) << "Год" << "|" ;
}
istream& operator>>(istream& is, human& obj)
{
	cout << "ВВедите №" << endl;
	obj.index = inputNumber(0,1000);
	cout << "Введите ФИО\n";
	obj.fio=inputString();
	cout << "Введите дату рождения\n";
	obj.year= inputDate();
	return is;
}
ifstream& operator>>(ifstream& is, human& obj)
{
	is >> obj.index;
	getline(is, obj.fio,'*');
	is >> obj.year;
	return is;
}
fstream& operator>>(fstream& is, human& obj)
{
	is.read(reinterpret_cast<char*>(&obj.index), sizeof(obj.index));
	is.read(const_cast<char*>(obj.fio.c_str()), sizeof(obj.fio));
	is.read(const_cast<char*>(obj.year.c_str()), sizeof(obj.year));
	return is;
}
fstream& operator<<(fstream& os, human& obj)
{
	os.write(reinterpret_cast<char*>(&obj.index), sizeof(obj.index));
	os.write(obj.fio.c_str(), sizeof(obj.fio));
	os.write(obj.year.c_str(), sizeof(obj.year));
	return os;
}
ofstream& operator<<(ofstream& os, human& obj)
{
	os <<obj.index <<" "<< obj.fio
		<< '*' << obj.year;
	return os;
}
ostream& operator<<(ostream& os, const human& obj)
{

	os << "|" << setw(3) << obj.index
		<< "|" << setw(30) << obj.fio << "|";
	os << setw(10) << obj.year << "|";
	return os;
}
human& human::operator=(const human& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	return *this;
}