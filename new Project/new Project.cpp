#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

struct Contact
{
	string name;
	string number;
};
Contact create_contact();
void output_book(vector<Contact>&);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int input;
	vector<Contact> book;
	do
	{
		cout << "1 - Создать контакт " << endl
			<< "2 - Просмотреть книгу  " << endl
			<< "0 - Выход " << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			book.push_back(create_contact());
			break;
		case 2:
			output_book(book);
			break;
		default:
			break;
		}
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
		cout << "Имя: " << book[i].name << " Номер: " << book[i].number << endl;
	}
}
