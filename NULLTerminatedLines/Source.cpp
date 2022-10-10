#include <iostream>
#include <Windows.h>
using namespace std; 
//#define ASCII

int StringLength(const char str[]);
void upper_case(char str[]); 
void lower_case(char str[]); 
void shrink(char str[]); 
bool is_palindrom(char str[]); 
void remove_symbol(char str[], const char symbol); 
bool is_int_number(const char str[]);

void main()
{
setlocale (LC_ALL, ""); 
#ifdef EXAMPLE_1
//ASCII-символ с кодом 0 - '\0'
//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
char str[] = "Hello";
//str[]   - строковая переменная
//"Hello" - строковая константа
cout << str << endl;
cout << typeid(str).name() << endl;
cout << typeid("Hello").name() << endl;
#endif // EXAMPLE_1
#if ASCII
for (int i = 0; i < 256; i++)
{
	cout << (int)i << "\t" << (char)i << endl;
}
#endif // ASCII

const int SIZE = 256;
char str[SIZE] = {};
//cout << (int)'\0' << endl;
//cout << (int)'0' << endl;
cout << "Введите строку: ";
cin >> str;
SetConsoleCP(1251);
//cin.getline(str, SIZE);
//SetConsoleCP(866);
//cout << str << endl;
//cout << "длина строки: " << StringLength(str) << endl;
//cout << "длина строки: " << strlen(str) << endl;
//cout << "Длина строки в байтах: " << sizeof(str) << endl;
//upper_case(str); 
//cout << str << endl; 
//lower_case(str); 
//cout << str << endl; 
//shrink(str); 
//cout << (is_palindrom(str) ? "" : "Не ") << "является палиндромом!" << endl;
cout << (is_int_number(str) ? "Число десятичное)" : "Число не десятичное!") << endl;
cout << str << endl;
}

int StringLength(const char str[])
{
	int i = 0; 
	for (; str[i]; i++);
	return i; 
}
void upper_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= ' ';*/
		str[i] = toupper(str[i]); 
	}
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]); 
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1]; 
			}
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
bool is_palindrom(char str[])
{
	char* buffer = new char[strlen(str) + 1]{}; 
	strcpy(buffer, str); //копируем строку в буфер
	lower_case(buffer); 
	remove_symbol(buffer, ' '); 
	int size = strlen(buffer); 
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[]buffer;
			return false;
		}
		return true;
	}
	delete[] buffer; 
}
bool is_int_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((int)str[i] == 48 || (int)str[i] == 49 || (int)str[i] == 50 || (int)str[i] == 51 || (int)str[i] == 52 || (int)str[i] == 53 || (int)str[i] == 54 || (int)str[i] == 55 || (int)str[i] == 56 || (int)str[i] == 57)continue;
		else return false; 
	}
	return true; 
}