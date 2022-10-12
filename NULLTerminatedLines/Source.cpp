#include <iostream>
#include <Windows.h>
using namespace std;
#define EXAMPLE_1
//#define ASCII

int StringLength(const char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void shrink(char str[]); //удаляет лишние пробелы
bool is_palindrom(char str[]);
void remove_symbol(char str[], const char symbol);
bool is_int_number(const char str[]);
int  to_int_number(char str[]);
int power(int a, int b);
bool is_bin_number(const char str[]);
int  bin_to_dec(char str[]);
bool is_hex_number(char str[]);
int  hex_to_dec(char str[]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXAMPLE_1
	//ASCII-символ с кодом 0 - '\0'
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	//str[]   - строковая переменная
	//"Hello" - строковая константа
	/*cout << str << endl;
	cout << typeid(str).name() << endl;
	cout << typeid("Hello").name() << endl;*/
#endif // EXAMPLE_1
#ifdef ASCII
	for (int i = 0; i < 256; i++)
	{
		cout << (int)i << "\t" << (char)i << endl;
	}
#endif // ASCII
	const int SIZE = 256;
	char str[SIZE] = {};
	SetConsoleCP(1251);
	cout << "Введите строку: ";
	SetConsoleCP(866);
	cin >> str;
	/*cout << (int)'\0' << endl;
	cout << (int)'0' << endl;*/
	//cin.getline(str, SIZE);
	cout << str << endl;
	/*cout << "длина строки: " << StringLength(str) << endl;
	cout << "длина строки: " << strlen(str) << endl;
	cout << "Длина строки в байтах: " << sizeof(str) << endl;*/

	//upper_case(str); 
	//cout << str << endl; 
	//lower_case(str); 
	//shrink(str); 
	//cout << (is_palindrom(str) ? "" : "Не ") << "является палиндромом!" << endl;
	//cout << (is_int_number(str) ? "Число десятичное)" : "Число не десятичное!") << endl;
	//cout << str << endl;
	cout << to_int_number(str) << endl;
	//cout << (is_bin_number(str) ? "Число двоичное!" : "Не двоичное 100 пудов!") << endl; 
	//cout << bin_to_dec(str) << endl; 
	//cout << (is_hex_number(str)? "Is HEX number": "Is not HEX number") << endl;
	//cout << hex_to_dec(str) << endl; 
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
		//if ((int)str[i] == 48 || (int)str[i] == 49 || (int)str[i] == 50 || (int)str[i] == 51 || (int)str[i] == 52 || (int)str[i] == 53 || (int)str[i] == 54 || (int)str[i] == 55 || (int)str[i] == 56 || (int)str[i] == 57)continue;
		/*if (str[i]>='0' && str[i]<='9')continue;
		else return false;*/
		if (!(str[i] >= '0' && str[i] <= '9'))return false;
		//if (str[i] < '0' || str[i]>'9')return false;
	}
	return true;
}
int  to_int_number(char str[])
{
	int* buffer = new int[strlen(str)]{};
	if (is_int_number(str))
	{
		for (int i = 0; str[i]; i++)
		{
			buffer[i] = str[i] - '0';//changing char to int and recording to array
			//cout << buffer[i] << "\t"; 
		}
		int result_of_is_num = 0; //var for result number
		for (int i = 0; i < strlen(str); i++)
		{
			result_of_is_num += buffer[i] * power(10, strlen(str) - (i + 1));
		}
		delete[] buffer;
		return result_of_is_num;
	}
	delete[]buffer;
	return false;
}
int power(int a, int b)
{
	if (b == 0)return 1;
	else if (b == 1)return a;
	else
	{
		int result = a;
		while (b > 1)
		{
			result *= a; b--;
		}
		return result;
	}
}
bool is_bin_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] == 48 || str[i] == 49) continue;
		else return false;*/
		if (str[i] != '0' && str[i] != '1')return false;
	}
	return true;
}
int  bin_to_dec(char str[])
{
	if (is_bin_number(str))
	{
		int* Buffer = new int[strlen(str)]{};
		for (int i = 0; str[i]; i++)
		{
			Buffer[i] = power(2, strlen(str) - i - 1) * ((int)str[i] - '0');
			//cout << Buffer[i] << "\t"; 
		}
		//cout << endl; 
		int result_bin_to_dec = 0;
		for (int i = 0; str[i]; i++)
		{
			result_bin_to_dec += Buffer[i];
		}
		return result_bin_to_dec;
		delete[]Buffer;
	}
	else return false;
}
bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] == 48 || 
			str[i] == 49 || 
			str[i] == 50 || 
			str[i] == 51 || 
			str[i] == 52 || 
			str[i] == 53 || 
			str[i] == 54 || 
			str[i] == 55 || 
			str[i] == 56 || 
			str[i] == 57 || 
			str[i] == 'A' || 
			str[i] == 'B' || 
			str[i] == 'C' || 
			str[i] == 'D' || 
			str[i] == 'E' || 
			str[i] == 'F' ||
			str[i] == 'a' || 
			str[i] == 'b' || 
			str[i] == 'c' || 
			str[i] == 'd' || 
			str[i] == 'e' || 
			str[i] == 'f'
			)continue;
		else return false;
	}
	return true;
}
int hex_to_dec(char str[])
{
	if (is_hex_number)
	{
		int size = strlen(str);
		//cout << size << endl;
		char buf[256] = {};
		strcpy(buf, str);//copy to str buf
		//cout << buf << endl;
		lower_case(buf);//to lower case
		//cout << buf << endl;
		int* Buffer = new int[size] {};
		int result_hex_to_dec = 0;
		for (int i = 0; buf[i]; i++)//Num to the Buffer
		{
			if (buf[i] == 97)Buffer[i] = 10;
			else if (buf[i] == 98)Buffer[i] = 11;
			else if (buf[i] == 99)Buffer[i] = 12;
			else if (buf[i] == 100)Buffer[i] = 13;
			else if (buf[i] == 101)Buffer[i] = 14;
			else if (buf[i] == 102)Buffer[i] = 15;
			else Buffer[i] = buf[i] - '0';//change ASCII to num
		}
		for (int i = 0; i < size; i++)
		{
			Buffer[i] *= power(16, size - i - 1);//умножаем рязряды числа на 16 в степ от 0 с конца числа
		}
		for (int i = 0; i < size; i++)//суммируем в результат
		{
			result_hex_to_dec += Buffer[i];
		}
		return result_hex_to_dec;
		delete[]Buffer;
	}
	else return false;
	/*cout << result_hex_to_dec << endl;
	for (int i = 0; i<size; i++)
	{
		cout << Buffer[i] << "\t";
	}*/
}