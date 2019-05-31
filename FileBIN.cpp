#include"FileBIN.h"

template <class T>
FileBIN<T>::FileBIN(string m_FileName)
{
	FileName = m_FileName;
	file_stream.open(FileName, ios::out | ios::in | ios::binary);
}

template <class T>
FileBIN<T>::~FileBIN()
{
	cout << "closed\n";
	file_stream.close();
}
template<class T>
bool FileBIN<T>::is_empty()
{
	file_stream.open(FileName, ios::in);
	if (file_stream.eof()) return true;
	return false;
}
template <class T>
void FileBIN <T>::writeBin(T&obj)
{
	file_stream << obj;
}

template <class T>
bool FileBIN <T>::readBin(T&obj)
{
	if (file_stream.eof()) return false;
	if (file_stream >> obj) return true;
	return false;
}

template <class T>
void FileBIN <T>::Remote()
{
	file_stream.seekg(0, ios::beg);
	file_stream.seekp(0, ios::beg);
}

template <class T>
void FileBIN <T>::close()
{
	cout << "closed\n";
	file_stream.close();
}

template <class T>
bool FileBIN <T>::eof()
{
	if (file_stream.eof())
	{
		cout << "end\n";
		return true;
	}
	return false;
}
template <class T>
bool FileBIN <T>::open()
{
	if(!file_stream.is_open())
	{
		cout << "Файл " << FileName << " не открыт" << endl;
		return false;
	}
		cout << "Файл " << FileName <<  endl;
		Remote();
		return true;
}

//| ios::trunc