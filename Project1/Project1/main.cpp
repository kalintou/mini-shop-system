#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <math.h>
//#include <stdio.h>
#include "sellers.h"
#include "data.h"
#include "users.h"
#include "administrator.h"
#include "buyers.h"
#include "calculator.cpp"
//#include "sql.h"

using namespace std;

//functions statements
void main_menu();
void administrator_module();
void user_module(int user_opt);
void buyer_module(User* somebody);
void seller_module(User* somebody);
//void self_manage(Users user, User* somebody);

//main function
int main() {

	cout << "calculator test" << endl;
	string test;
	getline(cin, test);

	cout << calculator(get_rid_of_space(test));





	int main_opt = 0;
	while (true)
	{
		main_menu();
		cin >> main_opt;
		switch (main_opt)
		{
		case 1: administrator_module(); break;
		case 2: user_module(1); break;
		case 3: user_module(2); break;
		case 4: break;
		case 5: exit(-1); break;
		default:
			cout << "Not a valid number!" << endl; break;
		}
	}
	return 0;
}

void main_menu()
{
	cout << "========================================================================================" << endl;
	cout << "1. Login with Admin  2. Login with User  3. Sign up  4. Forget password  5. Exit program" << endl;
	cout << "========================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << "Input your request: ";
}
void administrator_module()
{
	Administrator Admin;
	char aln[11], alp[21];
	cout << "Adminname: ";
	cin >> aln;
	cout << "Password: ";
	cin >> alp;
	cout << endl;
	cout << endl;
	if (Admin.boss_login(aln, alp))
	{
		cout << "********************************" << endl;
		cout << "******** Login success! ********" << endl;
		cout << "********************************" << endl;
		cout << endl;
		cout << endl;
		while (true)
		{
			Admin.boss_menu();
			cout << endl;
			cout << endl;
			int admin_opt = 0;
			cout << "Input ur request: ";
			cin >> admin_opt;

			switch (admin_opt)
			{
			case 1: Admin.all_goods(); break;
			case 2: Admin.boss_search(); break;
			case 3: Admin.good_off_shelves(); break;
			case 4: Admin.all_orders(); break;
			case 5: Admin.all_users(); break;
			case 6: Admin.user_ban(); break;
			case 7: return;
			default:
				cout << "Not a valid number!" << endl; break;
			}
			cout << endl;
			cout << endl;
		}

	}
	else
	{
		cout << "++++++++ Login unsuccess T T ! Return to main menu soon... ++++++++" << endl;
		return;
	}
};
void user_module(int user_opt)
{
	Users user;
	User* somebody = new User;
	if (user_opt == 1)
	{
		if (user.user_login(somebody))
		{
			cout << "*************************************" << endl;
			cout << "******** Login Successfully! ********" << endl;
			cout << "*************************************" << endl;
		}
		else
		{
			cout << "++++++++ Name or PWD is wrong. Try again... ++++++++" << endl;
			return;
		}
	}
	else
	{
		if (user.user_register(somebody))
		{
			cout << "***************************************" << endl;
			cout << "******** Successfully Created! ********" << endl;
			cout << "***************************************" << endl;

		}
		else
		{
			cout << "++++++++ Name already existed. Try again... ++++++++" << endl;
			return;
		}
	}
	while (true) {
		int user_opt = 0;
		user.self_menu();
		cout << "Input your request: ";
		cin >> user_opt;

		switch (user_opt)
		{
		case 1: buyer_module(somebody); break;
		case 2: seller_module(somebody); break;
		case 3: //self_manage(user, somebody); break;
		case 4: return;
		default:
			cout << "Not a valid number!" << endl; break;
		}
	}
};
void buyer_module(User* somebody)
{
	int buyer_opt;
	Buyers buyer;
	Good* something = new Good;
	while (true)
	{
		buyer.buyer_menu();
		cout << "Input your request: ";
		cin >> buyer_opt;

		switch (buyer_opt)
		{
		case 1: buyer.buyer_check_goods(somebody); break;
		case 2: buyer.buying(somebody); break;
		case 3: buyer.buyer_searching_good(); break;
		case 4: buyer.buyer_check_orders(somebody); break;
		case 5: buyer.check_one(somebody); break;
		case 6: return;
		default:
			cout << "Not a valid number!" << endl; break;
		}
	}
}
void seller_module(User* somebody)
{
	int seller_opt;
	Sellers seller;
	while (true)
	{
		seller.seller_menu();
		cout << "Input your request: ";
		cin >> seller_opt;

		switch (seller_opt)
		{
		case 1: seller.selling(somebody); break;
		case 2: seller.seller_check_goods(somebody); break;
		case 3: seller.modify_good(somebody); break;
		case 4: seller.good_off_shelves(somebody); break;
		case 5: seller.seller_check_orders(somebody); break;
		case 6: return;
		default:
			cout << "Not a valid number!" << endl; break;
		}
	}
}
//void self_manage(Users user, User* somebody)
//{
//
//}


//admin functions
bool str_match(const int length, const char x[], const char y[])
{
	for (int i = 0; i < length; i++)
	{
		if (x[i] != y[i])
			return false;
	}
	return true;
}
bool match_checker(int x_length, int y_length, const char x[], const char y[])
{
	for (int i = 0; i < x_length; i++)
	{
		if (x[i] == y[0])
		{
			return str_match(y_length, y, x);
		}
	}
	return false;
}
string find_str_good(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[0] + "," + words[1] + "," + words[2] + "," + words[3] + "," + words[4] + "," + words[5] + "," + words[6];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};

//user functions
void MyStrCpy(char t[], const char s[])
{

	int i = 0;
	while (s[i] != '\0')
	{
		t[i] = s[i];

		++i;

	}
	t[i] = s[i];

}
bool active_checker(const int length, const char x[])
{
	char y[7] = { "active" };
	for (int i = 0; i < length; i++)
	{
		if (x[i] != y[i])
			return false;
	}
	return true;
}

//seller functions
string create_good_id()
{
	string last_good_id;
	string new_good_id;

	fstream create_good_file;
	create_good_file.open("commodity.txt", ios::in);
	if (create_good_file.is_open())
	{
		string line;
		while (getline(create_good_file, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			last_good_id = words[0];

		}
		create_good_file.close();
	}
	int id_int = stoi(last_good_id.substr(1));
	if (id_int < 10)
	{
		new_good_id = "M00" + to_string(id_int + 1) + "\0";
	}
	else if (id_int < 100)
	{
		new_good_id = "M0" + to_string(id_int + 1) + "\0";
	}
	else
	{
		new_good_id = "M" + to_string(id_int + 1) + "\0";
	}
	return new_good_id;
}
string new_time3()
{
	struct tm newtime;
	time_t timer = time(NULL);
	errno_t error;
	string time;
	string month;
	error = localtime_s(&newtime, &timer);
	if (newtime.tm_mon + 1 < 10)
	{
		month = "0" + to_string(newtime.tm_mon + 1);
	}
	if (error != 0)
	{
		time = "1999-01-01";
	}
	else
	{
		time = to_string(newtime.tm_year + 1900) + "-" + month + "-" + to_string(newtime.tm_mday);
	}
	return time;
}
void add_new_good(Good* newGood)
{
	string double_killer;

	for (int i = 0; i < to_string(newGood->g_price).length(); ++i)
	{
		double_killer += to_string(newGood->g_price)[i];
		if (to_string(newGood->g_price)[i] == '.')
		{
			double_killer += to_string(newGood->g_price)[i + 1];
			break;
		}
	}


	fstream add_new_file;
	add_new_file.open("commodity.txt", ios::app);
	if (add_new_file.is_open())
	{
		add_new_file << endl;
		add_new_file << (string)newGood->g_id + "," + (string)newGood->g_name + "," + double_killer + "," + to_string(newGood->g_num) + "," + (string)newGood->g_info + "," + (string)newGood->seller_id + "," + (string)newGood->g_time + "," + "onSale";
		add_new_file.close();
	}
}
string find_str_seller_price_front(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[0] + "," + words[1];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_seller_price_end(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[3] + "," + words[4] + "," + words[5] + "," + words[6] + "," + words[7];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_seller_info_front(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[0] + "," + words[1] + "," + words[2] + "," + words[3];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_seller_info_end(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[5] + "," + words[6] + "," + words[7];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string double_to_string(string x)
{
	string newStr;

	for (int i = 0; i < (x).length(); ++i)
	{
		newStr += x[i];
		if (x[i] == '.')
		{
			newStr += x[i + 1];
			break;
		}
	}

	return newStr;
}

//buyer functions
string find_str_user(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("user.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[0] + "," + words[1] + "," + words[2] + "," + words[3] + "," + words[4] + "," + words[5];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_price_front(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[0] + "," + words[1] + "," + words[2];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_price_end(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[4] + "," + words[5] + "," + words[6] + "," + words[7];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_balance_front(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("user.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[0] + "," + words[1] + "," + words[2] + "," + words[3] + "," + words[4];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};
string find_str_balance_end(const char keyword[])
{
	string replace;
	fstream myFile;
	myFile.open("user.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
			{
				string replace = words[6];
				myFile.close();
				return replace;
			}

		}
		myFile.close();
	}
	return replace;
};

//sql functions
void create_command(int opt1, int set, int where, int contains, int user, int good, const char table[], const char column[], const char name[], const char value[]) {
	string command;
	if (opt1 == 1)
	{
		command += "INSERT INTO ";
	}
	else if (opt1 == 2)
	{
		command += "UPDATE " + (string)table;
		if (set == 1)
		{
			if (user == 1)
			{

			}
			else if (good == 1)
			{
				command += " SET state = offShelves ";
			}
		}
	}
	else if (opt1 == 3)
	{
		command += "SELECT " + (string)table;
		if (where == 1)
			command += " WHERE " + (string)name;
		if (contains == 1)
			command += " CONTAINS " + (string)value;
	}
}
