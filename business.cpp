#include"business.h"

business::business(int m_index,string m_fio, string m_year, int m_licens, Tax m_tax[2], string m_pass, Broad m_broad[], Address m_address[]) :
	entrepreneur(m_index,m_fio, m_year, m_licens, m_tax), tourist(m_index,m_fio, m_year, m_pass, m_broad), human(m_index,m_fio, m_year)
{
	for (int i = 0; i < 2; i++)
	{
		address[i].street = m_address[i].street;
		address[i].no = m_address[i].no;
	}
}

void business::setAddr(Address m_address[])
{
	for (int i = 0; i < 2; i++)
	{
		address[i].street = m_address[i].street;
		address[i].no = m_address[i].no;
	}
}
string business::getAddr()
{
	for (int i = 0; i < 2; i++)
	{
		return address[i].street;
	}
}

business::business(const business& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	this->licensia = obj.licensia;
	this->passport = obj.passport;
	for (int i = 0; i < 2; i++)
	{
		this->tax[i].date = obj.tax[i].date;
		this->tax[i].money = obj.tax[i].money;
	}
	for (int i = 0; i < 2; i++)
	{
		this->broad[i].country = obj.broad[i].country;
		this->broad[i].date = obj.broad[i].date;
	}
	for (int i = 0; i < 2; i++)
	{
		this->address[i].street = obj.address[i].street;
		this->address[i].no = obj.address[i].no;
	}
}
void business::showTitle()
{
	human::showTitle();
	cout << setw(10) << "№ лицензии" << "|" 
		<< setw(11) << "№ пасспорта" << "|" 
		<< setw(21) << "налоги" << "|" 
		<< setw(23) << "Туризм" << "|" 
		<< setw(14) << "Адреса" << "|" << endl;
	cout << setw(65) << " " << setw(10) << "Дата" << "|" 
		<< setw(10) << "№ счета" << "|" 
		<< setw(10) << "Страна" << "|" 
		<< setw(12) << "Дата" << "|" << endl;
	//cout << setw(127) << setfill('-')<<" "<<endl;
}

istream& operator>>(istream& is, business& obj)
{
	is >> dynamic_cast<entrepreneur&>(obj);
	cout << "Введите № пасспорта\n";
	obj.passport=inputNumber(0,10000);
	cout << "Введите данные о поездках за границу\n";
	for (int i = 0; i < 2; i++)
	{
		cout << "Страна\n";
		obj.broad[i].country = inputString();
		cout << "День\n";
		obj.broad[i].date = inputDate();
	}
	cout << "Введите список адресов\n";
	for (int i = 0; i <2; i++)
	{
		cout << "Улица\n";
		obj.address[i].street = inputString();
		cout << "№ дома\n";
		obj.address[i].no = inputNumber(0,1000);
	}
	return is;
}
ifstream& operator>>(ifstream& is, business& obj)
{
	is >> dynamic_cast<human&>(obj);
	is >> obj.licensia
		>> obj.passport;
	for (int i = 0; i < 2; i++)
	{
		is >> obj.tax[i].date
			>> obj.tax[i].money
			>> obj.broad[i].country
			>> obj.broad[i].date
			>> obj.address[i].street
			>> obj.address[i].no;
	}
	return is;
}
fstream& operator>>(fstream& is, business& obj)
{
	is >> dynamic_cast<human&>(obj);
	is.read(reinterpret_cast<char*>(&obj.licensia), sizeof(obj.licensia));
	is.read(const_cast<char*>(obj.passport.c_str()), sizeof(obj.passport));
	for (int i = 0; i < 2; i++)
	{
		is.read(const_cast<char*>(obj.tax[i].date.c_str()), sizeof(obj.tax[i].date));
		is.read(reinterpret_cast<char*>(obj.tax[i].money), sizeof(obj.tax[i].money));
		is.read(const_cast<char*>(obj.broad[i].date.c_str()), sizeof(obj.broad[i].date));
		is.read(const_cast<char*>(obj.broad[i].country.c_str()), sizeof(obj.broad[i].country));
		is.read(const_cast<char*>(obj.address[i].street.c_str()), sizeof(obj.address[i].street));
		is.read(reinterpret_cast<char*>(obj.address[i].no), sizeof(obj.address[i].no));
	}
	return is;
}
fstream& operator<<(fstream& os, business& obj)
{
	os << dynamic_cast<human&>(obj);
	os.write(reinterpret_cast<char*>(&obj.licensia), sizeof(obj.licensia));
	os.write(obj.passport.c_str(), sizeof(obj.passport));
	for (int i = 0; i < 2; i++)
	{
		os.write(obj.tax[i].date.c_str(), sizeof(obj.tax[i].date));
		os.write(reinterpret_cast<char*>(&obj.tax[i].money), sizeof(obj.tax[i].money));
		os.write(obj.broad[i].date.c_str(), sizeof(obj.broad[i].date));
		os.write(obj.broad[i].country.c_str(), sizeof(obj.broad[i].country));
		os.write(obj.address[i].street.c_str(), sizeof(obj.address[i].street));
		os.write(reinterpret_cast<char*>(&obj.address[i].no), sizeof(obj.address[i].no));
	}
	return os;
}

ostream& operator<<(ostream& os,const business& obj)
{
	os << "|" << setw(3) << obj.index
		<< "|" << setw(30) << obj.fio << "|";
	os << setw(10) << obj.year << "|";
	os << setw(10) << obj.licensia << "|"
		<< setw(11) << obj.passport << "|";
	for (int i = 0; i < 2; i++)
	{
		os << setw(10) << obj.tax[i].date << "|"
			<< setw(10) << obj.tax[i].money << "|"
			<< setw(10) << obj.broad[i].country << "|"
			<< setw(3) << obj.broad[i].date << "|"
			<< setw(10) << obj.address[i].street << ","
			<< setw(3) << obj.address[i].no << "|\n"
			<< setw(59) << "   ";
	}
	//cout << endl;
	//cout << setw(121) << setfill('-') << " " << endl;
	return os;
}
ofstream& operator<<(ofstream& os, business& obj)
{
	os << obj.fio 
		<<'*' << obj.year 
		<< " " << obj.licensia << " " << obj.passport << " ";
	for (int i = 0; i < 2; i++)
	{
		os << obj.broad[i].country << " "
			<< obj.broad[i].date << " "
			<< obj.tax[i].date << " "
			<< obj.tax[i].money << " "
			<< obj.address[i].street << " "
			<< obj.address[i].no << " ";
	}
	os << "\n";
	return os;
}
business& business::operator=(const business& obj)
{
	this->index = obj.index;
	this->fio = obj.fio;
	this->year = obj.year;
	this->licensia = obj.licensia;
	this->passport = obj.passport;
	for (int i = 0; i < 2; i++)
	{
		this->tax[i].date = obj.tax[i].date;
		this->tax[i].money = obj.tax[i].money;
	}
	for (int i = 0; i < 2; i++)
	{
		this->broad[i].country = obj.broad[i].country;
		this->broad[i].date = obj.broad[i].date;
	}
	for (int i = 0; i < 2; i++)
	{
		this->address[i].street = obj.address[i].street;
		this->address[i].no = obj.address[i].no;
	}
	return *this;
}

bool business::operator==(business& obj)
{
	if (this->getIndex() != 0 && this->getIndex() != obj.getIndex())
		return false;
	if (this->getFio() != "0" && this->getFio() != obj.getFio())
		return false;
	if (this->getYear() != "0" && this->getYear() != obj.getYear())
		return false;
	if (this->getLisens() != 0 && this->getLisens() != obj.getLisens())
		return false;
	if (this->getTax() != "0" && this->getTax() != obj.getTax())
		return false;
	if (this->getPass() != "0" && this->getPass() != obj.getPass())
		return false;
	for (int i = 0; i < 2; i++)
	{
		if (this->broad[i].country != "0" && this->broad[i].country != obj.broad[i].country)
			return false;
		if (this->broad[i].date !=  "0" && this->broad[i].date != obj.broad[i].date)
			return false;
	}
	for (int i = 0; i < 2; i++)
	{
		if (this->address[i].street != "0" && this->address[i].street != obj.address[i].street)
			return false;
		if (this->address[i].no != 0 && this->address[i].no != obj.address[i].no)
			return false;
	}
	for (int i = 0; i < 2; i++)
	{
		if (this->tax[i].date != "0" && this->tax[i].date != obj.tax[i].date)
			return false;
		if (this->tax[i].money != 0 && this->tax[i].money != obj.tax[i].money)
			return false;
	}
	return true;
}

bool business::operator>=(business & obj)
{
	if (this->getFio().compare(obj.getFio()) == -1)
		return true;
	return false;
}

bool business::operator<=(business & obj)
{
	if (this->getFio().compare(obj.getFio()) == 1)
		return true;
	 return false;
}

bool business::operator>(business & obj)
{
	if (this->getIndex() > obj.getIndex())
		return true;
	return false;
}

bool business::operator<(business & obj)
{
	if (this->getIndex() < obj.getIndex())
		return true;
	return false;
}
