#pragma once
#include<fstream>
#include"human.h"
#include"entrepreneur.h"
#include"tourist.h"
#include"business.h"
#include"list.h"
#include"functions.h"


template<class T>
class FileBIN 
{
protected:
	string FileName;
	fstream file_stream;
public:
	FileBIN(string m_FileName);
	~FileBIN();
	bool open();
	bool is_empty();
	void Remote();
	bool eof();
	void writeBin(T&obj);
	bool readBin(T&obj);
	void close();
};