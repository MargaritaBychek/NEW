#include"list.h"

template <class T>
list<T>::list()
{
	top = NULL;
	bottom = NULL;
	last = NULL;
}

template <class T>
list<T>::list(const T& obj)
{
	this->top = obj.top;
	this->bottom = obj.bottom;
	this->last = obj.last;
}

template <class T>
list<T>::~list()
{
	if (top == NULL)
		return;
	List<T> *temp;
	while (top != NULL) {
		temp = top;
		top = top->next;
		delete temp;
	}
	top = bottom =last= NULL;
	//cout << "������ ������!\n";
}

template <class T>
void list<T>::Push(T tmp)
{
	List<T> *temp = new List<T>;
	temp->data = tmp;
	if (top == NULL)
	{
		temp->next = temp->prev = NULL;
		top = bottom = temp;
		last = temp->prev;
	}
	else
	{
		temp->prev = NULL;
		temp->next = top;
		top->prev = temp;
		top = temp;
	}
}

template <class T>
void list<T>::Show()
{

	if (top == NULL)
	{
		cout << "������ ����!\n";
		return;
	}
	else
	{
		List<T> *temp = top;
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->next;
		}
	}
}

template <class T>
bool list<T>::Empty()
{
	if (top == NULL)
		return false;
	else
		return true;
}

template <class T>
void list<T>::DeleteEl()
{
	List<T> *temp = top;
	List<T> *key = NULL;
	string search;
	cout << "������� ������� ��� ��������->->";
	search=inputString();
	while (temp != NULL) {
		if ((temp->data).getFio() == search)
		{
			key = temp;
			break;
		}
		temp = temp->next;
	}
	if (key == NULL)
	{
		cout << "������� �� ������\n";
		return;
	}
	else
	{
		if (key == top)
		{
			top = top->next;
			top->prev = NULL;
		}
		else
		{
			if (key == bottom)
			{
				bottom = bottom->prev;
				bottom->next = NULL;
			}
			else
			{
				(key->prev)->next = key->next;
				(key->next)->prev = key->prev;
			}
		}
		delete key;
		cout << "\n��� ������� ������!\n\n";
	}
}

template <class T>
void list<T>::Delete()
{
	List<T> *temp;
	while (top != NULL) {
		temp = top;
		top = top->next;
		delete temp;
	}
}

template <class T>
void list<T>::Edit()
{
	List<T> *temp = top;
	T obj;
	cout << "������� �������:" << endl;
	string surname;
	surname = inputString();
	while (temp != NULL)
	{
		if ((temp->data).getFio() == surname)
		{
			cin >> obj;
			temp->data = obj;
			return;
		}
		temp = temp->next;
	}
}

template <class T>
T list<T>::Ret()
{
	T obj;
	List<T> *tmp = top;
		top = top->next;
		obj = tmp->data;
		delete tmp;
		return obj;
}

template <class T>
List<T>* list<T>::Search(T obj)
{
	list<T> tempList;
	List<T> *tmp = top;
	while (tmp != NULL)
	{
		if (obj == tmp->data)
			tempList.Push(tmp->data);
		tmp = tmp->next;
	}
	tempList.Show();
	return tmp;
}

template <class T>
void list<T>::WriteFile(list<T> &tmp, T obj)
{
	ofstream fout(obj.FILE_OF_TXT, ios::out); //������� ���� ��� ������
	while (tmp.Empty()) //���� ������� �� � NULL
	{
		obj = tmp.Ret();
		fout << obj;
	}
	fout.close();//������� �������� ����
}

template <class T>
void list<T>::ReadFile(list<T> &tmp, T obj)
{
	ifstream fin(obj.FILE_OF_TXT, ios::in); //������� ���� ��� ������
	if (!fin.is_open())//���� ���� ���������� �������
	{
		cout << "��������� ���� �� ����������!" << endl;
		return;
	}
	while (true)
		{
			fin >> obj;
			if (fin.eof())
				break;
			tmp.Push(obj);
		}
	fin.close(); //������� �������� ����
}

template <class T>
void list<T>::WriteFileB(list<T> &tmp, T obj)
{
	FileBIN<T> binn(obj.FILE_OF_BIN);
	binn.open();
	while (Empty()) //���� ������� �� � NULL
	{
		obj = Ret();
		binn.writeBin(obj);
		rewind(stdin);
	}
	cout << "��������" << endl;
	binn.close();//������� �������� ����
}

template <class T>
void list<T>::ReadFileB(list<T> &tmp, T obj)
{
	FileBIN<T> binn(obj.FILE_OF_BIN);
	if (!binn.open())//���� ���� ���������� �������
	{
		fstream obj1;
		obj1.open(obj.FILE_OF_BIN, ios::in);
		obj1.close();
		binn.open();
	}
	tmp.Delete();
		while (true)
		{
			binn.readBin(obj);
			if (binn.eof())
				break;
			tmp.Push(obj);
		}
		/*obj.showTitle();
		tmp.Show();
		system("pause");*/
	binn.close();
}

template<class T>
List<T>* list<T>::begin()
{
	return top;
}

template<class T>
List<T>* list<T>::end()
{
	return last;
}
