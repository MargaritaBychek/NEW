#include"entrepreneur.h"

entrepreneur::entrepreneur(int m_index,string m_fio, string m_year, int m_licens, Tax m_tax[2]) : human(m_index,m_fio,m_year)
{
	licensia = m_licens;
	for (int i = 0; i < 2; i++)
	{
		tax[i].date = m_tax[i].date;
		tax[i].money = m_tax[i].money;
	}
}
entrepreneur::entrepreneur(const entrepreneur& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	this->licensia = obj.licensia;
	for (int i = 0; i < 2; i++)
	{
		this->tax[i].date = obj.tax[i].date;
		this->tax[i].money = obj.tax[i].money;
	}
}

int entrepreneur::getIndex()
{
	return index;
}

void entrepreneur::setLisens(int m_licens)
{
	licensia = m_licens;
}

void entrepreneur::setTax(Tax m_tax[2])
{
	for (int i = 0; i < 2; i++)
	{
		tax[i].date = m_tax[i].date;
		tax[i].money = m_tax[i].money;
	}
}

int entrepreneur::getLisens() const
{
	return licensia;
}

string entrepreneur::getTax()
{
	for (int i = 0; i < 2; i++)
	{
		return tax[i].date;
	}
}
void entrepreneur::showTitle()
{
	human::showTitle();
	cout  << setw(10) << "№ лицензии" << "|" 
		<< setw(22) << "налоги" << "|" << endl;
	cout << "|"  << setw(57) << " " << setw(11) << "Дата" << "|"
		<< setw(10) << "№ счета" << "|" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
}
istream& operator>>(istream& is, entrepreneur& obj)
{
	is >> dynamic_cast<human&>(obj);
	cout << "Введите № лицензии\n";
	obj.licensia = inputNumber(0, 1000);
	cout << "Введите данные о налоговых платежах\n";
	for (int i = 0; i < 2; i++)
	{
		cout << "Дата\n";
		obj.tax[i].date=inputDate();
		cout << "№ счета\n";
		obj.tax[i].money = inputNumber(0, 1000);
	}
	return is;
}
ifstream& operator>>(ifstream& is, entrepreneur& obj)
{
	is >> dynamic_cast<human&>(obj);
	is >> obj.licensia;
	for (int i = 0; i < 2; i++)
	{
		is >> obj.tax[i].date
			>> obj.tax[i].money;
	}
	return is;
}
fstream& operator>>(fstream& is, entrepreneur& obj)
{
	is.read(reinterpret_cast<char*>(&obj.index), sizeof(obj.index));
	is.read(const_cast<char*>(obj.fio.c_str()), sizeof(obj.fio));
	is.read(const_cast<char*>(obj.year.c_str()), sizeof(obj.year));
	is.read(reinterpret_cast<char*>(&obj.licensia), sizeof(obj.licensia));
	for (int i = 0; i < 2; i++)
	{
		is.read(const_cast<char*>(obj.tax[i].date.c_str()), sizeof(obj.tax[i].date));
		is.read(reinterpret_cast<char*>(&obj.tax[i].money), sizeof(obj.tax[i].money));
	}
	return is;
}
fstream& operator<<(fstream& os, entrepreneur& obj)
{
	os.write(reinterpret_cast<char*>(&obj.index), sizeof(obj.index));
	os.write(obj.fio.c_str(), sizeof(obj.fio));
	os.write(obj.year.c_str(), sizeof(obj.year));
	os.write(reinterpret_cast<char*>(&obj.licensia), sizeof(obj.licensia));
	for (int i = 0; i < 2; i++)
	{
		os.write(obj.tax[i].date.c_str(), sizeof(obj.tax[i].date));
		os.write(reinterpret_cast<char*>(&obj.tax[i].money), sizeof(obj.tax[i].money));
	}
	return os;
}
ostream& operator<<(ostream& os,const entrepreneur& obj)
{
	os << "|" << setw(3) << obj.index
		<< "|" << setw(30) << obj.fio << "|";
	os << setw(10) << obj.year << "|";
	os << setw(10) << obj.licensia << "|";
	for (int i = 0; i < 2; i++)
	{
		os << setw(11) << obj.tax[i].date << "|"
			<< setw(10) << obj.tax[i].money << "|\n";
		if (i != 1)
			os <<  setw(57) << "  " << "|";
	}
	cout << "---------------------------------------------------------------------------------" << endl;
	return os;
}
ofstream& operator<<(ofstream& os, entrepreneur& obj)
{
	os<<dynamic_cast<human&>(obj);
	os << " " << obj.licensia << " ";
	for (int i = 0; i < 2; i++)
	{
		os << obj.tax[i].date << " "
			<< obj.tax[i].money << " ";
	}
	os << endl;
	return os;
}
entrepreneur& entrepreneur ::operator=(const entrepreneur& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	this->licensia = obj.licensia;
	for (int i = 0; i < 2; i++)
	{
		this->tax[i].date = obj.tax[i].date;
		this->tax[i].money = obj.tax[i].money;
	}
	return *this;
}

bool entrepreneur ::operator==(entrepreneur& obj)
{
	if (this->getIndex() != 0 && this->getIndex() != obj.getIndex())
		return false;
	if(this->getFio() != "0" && this->getFio() != obj.getFio())
		return false;
	if (this->getYear() != "00.00.0" && this->getYear() != obj.getYear())
		return false;
	if (this->getLisens() != 0 && this->getLisens() != obj.getLisens())
		return false;
	for (int i = 0; i < 2; i++)
	{
		if (this->tax[i].date != "00.00.0" && this->tax[i].date != obj.tax[i].date)
			return false;
		if (this->tax[i].money != 0 && this->tax[i].money != obj.tax[i].money)
			return false;
	}
	return true;
}
bool entrepreneur ::operator>=(entrepreneur& obj)
{
	if (this->getFio().compare(obj.getFio()) == -1)
		return true;
	else return false;
}
bool entrepreneur ::operator<=(entrepreneur& obj)
{
	if (this->getFio().compare(obj.getFio()) == 1)
		return true;
	else return false;
}
bool entrepreneur ::operator>(entrepreneur& obj)
{
	if (this->getIndex() > obj.getIndex())
		return true;
	else return false;
}
bool entrepreneur ::operator<(const entrepreneur& obj)const
{
	if (this->index < obj.index)
		return true;
	else return false;
}