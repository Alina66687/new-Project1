#include <iostream>
#include <vector>
#include <Windows.h>
#include<fstream>
using namespace std;
struct Contact
{
	string name;
	string number;
};
Contact create_contact();
void autoload(vector<Contact>&);
void autosave(vector<Contact>&);
void output_book(vector<Contact>&);
void edit_contact_in_book(vector<Contact>&, int);
void output_contact_in_book(vector<Contact>&, int);
void main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int input;
	vector<Contact> book;
	autoload(book);
	do
	{
		cout << "1 - Создать контакт " << endl
			<< "2 - Просмотреть книгу  " << endl
			<< "3 - Редактировать контакт" << endl
			<< "4 - Очистить книгу" << endl
			<< "0 - Выход " << endl;
		
		cin >> input;
		switch (input)
		{
		case 1:
			book.push_back(create_contact());
			break;
		case 2:
			output_book(book);
			system("pause");
			break;
		case 3:
			cout << "Введите № контакта: " << endl;
			int num;
			cin >> num;
			if (num > 0 && num <= book.size())
			{
				edit_contact_in_book(book, num - 1);
			}
			else
			{
				cerr << "Error " << endl;
			}
			break;
		case 4:
			book.clear();
			break;
		default:
			break;
		}
		autosave(book);
	} while (input != 0);

}


Contact create_contact()
{
	Contact contact;
	cout << "Введите имя: " << endl;
	cin >> contact.name;
	cout << "Введите номер: " << endl;
	cin >> contact.number;
	return contact;
}

void output_book(vector<Contact>& book)
{
	for (int i = 0; i < book.size(); i++)
	{
		output_contact_in_book(book, i);
	}
}

void edit_contact_in_book(vector<Contact>& book, int index) //редактировать
{
	output_contact_in_book(book, index);
	int a;
	cout << "Если вы хотите поменять имя, введите 1 " << endl
		<< "Если вы хотите поменять номер, введите 2 " << endl
		<< "Eсли вы передумали, введите любое другое число " << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Введите новое имя: ";
		cin >> book[index].name;
		break;
	case 2:
		cout << "Ввeдите новый номер: ";
		cin >> book[index].number;
	default:
		break;
	}
}
void output_contact_in_book(vector<Contact>& book, int index)
{
	cout << "№ " << index + 1 << " Имя: " << book[index].name << " Номер: " << book[index].number << endl;
}
void autosave(vector<Contact>& book)
{
	ofstream tbook;
	tbook.open("book.txt");
	for (int a = 0; a < book.size(); a++)
	{
		tbook << book[a].name << endl << book[a].number;
		if (a < book.size() - 1)
		{
			tbook << endl;
		}
	}
	tbook.close();
}
void autoload(vector<Contact>& book)
{
	ifstream ibook;
	ibook.open("book.txt");
	while (!ibook.eof())
	{
		Contact contact;
		ibook >> contact.name >> contact.number;
		book.push_back(contact);
	}
}