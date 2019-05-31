#include"tourist.h"

tourist::tourist(int m_index,string m_fio, string m_year, string m_pass, Broad m[]) :
	human(m_index,m_fio,m_year)
{
	passport = m_pass;
	for (int i = 0; i < 2; i++)
	{
		broad[i].date = m[i].date;
		broad[i].country = m[i].country;
	}
}

tourist::tourist(const tourist& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	this->passport = obj.passport;
	for (int i = 0; i < 2; i++)
	{
		this->broad[i].country = obj.broad[i].country;
		this->broad[i].date = obj.broad[i].date;
	}
}

void tourist::setPass(string m_pass)
{
	passport = m_pass;
}

void tourist::setBroad(Broad m[])
{
	for (int i = 0; i < 2; i++)
	{
		broad[i].date = m[i].date;
		broad[i].country = m[i].country;
	}
}
string tourist::getPass() const
{
	return passport;
}
string tourist::getBroad()
{
	for (int i = 0; i < 2; i++)
	{
		return broad[i].country;
	}
}
void tourist::showTitle()
{
	human::showTitle();
	cout << setw(11) << "№ пасспорта" << "|" 
		<< setw(21) << "Туризм" << "|" << endl;
	cout << setw(54) << " " 
		<< setw(10) << "страна" << "|" 
		<< setw(10) << "дата" << "|" << endl;
	//cout << setw(77) << setfill('-') <<" "<< endl;
}
istream& operator>>(istream& is, tourist& obj)
{
	is >> dynamic_cast<human&>(obj);
	cout << "Введите № пасспорта\n";
	obj.passport = inputString();
	cout << "Введите данные о поездках за границу\n";
	for (int i = 0; i < 2; i++)
	{
		cout << "Страна\n";
		obj.broad[i].country = inputString();
		cout << "День\n";
		obj.broad[i].date = inputDate();
	}
	return is;
}
ifstream& operator>>(ifstream& is, tourist& obj)
{
	is >> dynamic_cast<human&>(obj);
	is >> obj.passport;
	for (int i = 0; i < 2; i++)
	{
		is>>obj.broad[i].country
		 >> obj.broad[i].date;
	}
	return is;
}
fstream& operator>>(fstream& is, tourist& obj)
{
	is >> dynamic_cast<human&>(obj);
	is.read(const_cast<char*>(obj.passport.c_str()), sizeof(obj.passport));
	for (int i = 0; i < 2; i++)
	{
		is.read(const_cast<char*>(obj.broad[i].date.c_str()), sizeof(obj.broad[i].date));
		is.read(const_cast<char*>(obj.broad[i].country.c_str()), sizeof(obj.broad[i].country));
	}
	return is;
}
fstream& operator<<(fstream& os, tourist& obj)
{
	os << dynamic_cast<human&>(obj);
	os.write(obj.passport.c_str(), sizeof(obj.passport));
	for (int i = 0; i < 2; i++)
	{
		os.write(obj.broad[i].date.c_str(), sizeof(obj.broad[i].date));
		os.write(obj.broad[i].country.c_str(), sizeof(obj.broad[i].country));
	}
	return os;
}
ostream& operator<<(ostream& os, const tourist& obj)
{
	os << "|" << setw(3) << obj.index
		<< "|" << setw(30) << obj.fio << "|";
	os << setw(10) << obj.year << "|";
	os 	<< setw(11) << obj.passport << "|";
	for (int i = 0; i < 2; i++)
	{
		os << setw(10) << obj.broad[i].country << "|";
		os << setw(2) << obj.broad[i].date <<  "|\n";
		if (i != 1)
			os << "|" << setw(54) << " " << "|";
	}
	//cout << endl;
	//cout << setw(77) << setfill('-') << " " << endl;
	return os;
}

ofstream& operator<<(ofstream& os, tourist& obj)
{
	os << dynamic_cast<human&>(obj);
	os <<" "<< obj.passport<<" ";
	for (int i = 0; i < 2; i++)
	{
		os <<  obj.broad[i].country <<" "
		 <<  obj.broad[i].date << " ";
	}
	//os << "\n";
	return os;
}

tourist& tourist::operator=(const tourist& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	this->passport = obj.passport;
	for (int i = 0; i < 2; i++)
	{
		this->broad[i].country = obj.broad[i].country;
		this->broad[i].date = obj.broad[i].date;
	}
	return *this;
}


bool tourist:: operator==( tourist& obj)
{
	if (this->getIndex() != 0 && this->getIndex() != obj.getIndex())
		return false;
	if (this->getFio() != "0" && this->getFio() != obj.getFio())
		return false;
	if (this->getYear() != "0" && this->getYear() != obj.getYear())
		return false;
	if (this->getPass() != "0" && this->getPass() != obj.getPass())
		return false;
	for (int i = 0; i < 2; i++)
	{
		if (this->broad[i].country != "0" && this->broad[i].country != obj.broad[i].country)
			return false;
		if (this->broad[i].date != "0" && this->broad[i].date != obj.broad[i].date)
			return false;
	}
	return true;
}

bool tourist::operator>=(tourist & obj)
{
	if (this->getFio().compare(obj.getFio()) == -1)
		return true;
	else return false;
}

bool tourist::operator<=(tourist & obj)
{
	if (this->getFio().compare(obj.getFio()) == 1)
		return true;
	else return false;
}
bool tourist::operator>(tourist & obj)
{
	if (this->getIndex() > obj.getIndex())
		return true;
	else return false;
}

bool tourist::operator<(tourist & obj)
{
	if (this->getIndex() < obj.getIndex())
		return true;
	else return false;
}