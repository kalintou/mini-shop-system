#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <math.h>
#include "sellers.h"
#include "data.h"
#include "users.h"

using namespace std;

string create_good_id();
string new_time3();
void add_new_good(Good* newGood);
void MyStrCpy(char t[], const char s[]);
bool str_match(const int length, const char x[], const char y[]);
string find_str_seller_price_front(const char keyword[]);
string find_str_seller_price_end(const char keyword[]);
string find_str_seller_info_front(const char keyword[]);
string find_str_seller_info_end(const char keyword[]);
string double_to_string(string x);
bool match_checker(int x_length, int y_length, const char x[], const char y[]);
string find_str_good(const char keyword[]);

void Sellers::seller_menu()
{
	cout << "======================================================================================================================" << endl;
	cout << "1. Selling  2. Checking my Goods  3. Change Info of Goods 4.off-shelves Goods 5. Checking Orders  6. Back to User Mode" << endl;
	cout << "======================================================================================================================" << endl;
	cout << endl;
	cout << endl;
}
void Sellers::selling(User* somebody)
{
	char y_n;
	char g_name[21];
	cout << "Commodity Name: ";
	cin >> g_name;
	double g_price;
	cout << "Price: ";
	cin >> g_price;
	int g_num;
	cout << "Number of Goods: ";
	cin >> g_num;
	char g_info[201];
	cout << "Info: ";
	cin >> g_info;
	cout << endl;
	cout << "Plz confirm the Info!" << endl;
	cout << "************************************" << endl;
	cout << "Name: " << g_name << endl;
	cout << "Price: " << g_price << endl;
	cout << "Number: " << g_num << endl;
	cout << "Info: " << g_info << endl;
	cout << "************************************" << endl;
	do
	{
		cout << "Is this OK? (y/n): ";
		cin >> y_n;
	} while (!cin.fail() && y_n != 'y' && y_n != 'n');
	if (y_n == 'y') {
		cout << "Done" << endl;
		Good* newGood = new Good;
		newGood->g_state = 1;
		MyStrCpy(newGood->g_id, (char*)create_good_id().data());
		MyStrCpy(newGood->g_name, g_name);
		newGood->g_price = g_price;
		newGood->g_num = g_num;
		MyStrCpy(newGood->g_info, g_info);
		MyStrCpy(newGood->g_time, (char*)new_time3().data());
		MyStrCpy(newGood->seller_id, somebody->u_id);
		add_new_good(newGood);
	}
	else if (y_n == 'n')
	{
		cout << "Action Cancelled..." << endl;
	}
}
void Sellers::seller_check_goods(User* somebody) {

	fstream selling_check_file;
	selling_check_file.open("commodity.txt", ios::in);
	bool no_good_flag = false;

	//
	if (selling_check_file.is_open())
	{
		string line;
		while (getline(selling_check_file, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (str_match(strlen(somebody->u_id), somebody->u_id, (char*)words[5].data()))
			{
				no_good_flag = true;
			}
		}
		selling_check_file.close();
	}

	if (no_good_flag == false)
	{
		cout << "There is no Good!!!" << endl;
	}
	else
	{
		cout << "******************************************************************************************************" << endl;
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
				if (str_match(strlen(somebody->u_id), somebody->u_id, (char*)words[5].data()))
				{
					cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
				}
			}
			myFile.close();
		}
		cout << "******************************************************************************************************" << endl;
	}
}
void Sellers::seller_check_orders(User* somebody) {
	fstream selling_order_file;
	selling_order_file.open("order.txt", ios::in);
	bool no_good_flag = false;

	//
	if (selling_order_file.is_open())
	{
		string line;
		while (getline(selling_order_file, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (str_match(strlen(somebody->u_id), somebody->u_id, (char*)words[5].data()))
			{
				no_good_flag = true;
			}
		}
		selling_order_file.close();
	}

	if (no_good_flag == false)
	{
		cout << "There is no Good!!!" << endl;
	}
	else
	{
		cout << "*************************************************************************************" << endl;
		fstream myFile;
		myFile.open("order.txt", ios::in);
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
				if (str_match(strlen(somebody->u_id), somebody->u_id, (char*)words[5].data()))
				{
					cout << left << setw(11) << words[0] << left << setw(15) << words[1] << left << setw(13) << words[2] << left << setw(10) << words[3] << left << setw(13) << words[4] << left << setw(13) << words[5] << left << setw(9) << words[6] << endl;
				}
			}
			myFile.close();
		}
		cout << "*************************************************************************************" << endl;

	}
}
void Sellers::good_off_shelves(User* somebody)
{
	char type;
	char keyword[20];
	char off_shelves[20] = "offShelves";
	cout << "ID of Target: ";
	cin >> keyword;

	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		cout << "***************************************************************************************************" << endl;
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
				cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
			}
		}
		cout << "***************************************************************************************************" << endl;
		cout << "Do you really wanna off-shelves this?" << endl;
		do
		{
			cout << "(y/n): ";
			cin >> type;
		} while (!cin.fail() && type != 'y' && type != 'n');
		if (type == 'y') {
			cout << "Done" << endl;

			fstream replace_file;
			replace_file.open("commodity.txt", ios::in);

			if (replace_file.is_open()) {
				string replace = find_str_good(keyword) + "," + "onSale";
				string replace_with = find_str_good(keyword) + "," + "offShelves";
				string line;
				vector<string> lines;

				while (getline(replace_file, line))
				{
					string::size_type pos = 0;

					while ((pos = line.find(replace, pos)) != string::npos)
					{
						line.replace(pos, line.size(), replace_with);
						pos += replace_with.size();
					}

					lines.push_back(line);
				}
				replace_file.close();

				replace_file.open("commodity.txt", ios::out | ios::trunc);

				for (const auto& i : lines)
				{
					replace_file << i << endl;
				}
				replace_file.close();
			}
		}
		else if (type == 'n')
		{
			cout << "Action Cancelled..." << endl;
		}
	}
	myFile.close();
}
void Sellers::modify_good(User* somebody) {
	char opt1;
	char opt2;
	char g_id[7];
	char g_name[21];
	double g_price_old;
	double g_price_new;
	int g_num;
	char g_info_old[201];
	char g_info_new[201];
	char g_time[11];
	char seller_id[7] = { "U" };
	cout << "ID of Target: ";
	cin >> g_id;
	cout << "Choose your request ";
	do
	{
		cout << "(1. Change price  2. Modify info): ";
		cin >> opt1;
	} while (!cin.fail() && opt1 != '1' && opt1 != '2');

	if (opt1 == '1')
	{
		cout << "Input the new price: ";
		cin >> g_price_new;
		cout << "Plz confirm the new Price below is correct." << endl;
		fstream myFile;
		myFile.open("commodity.txt", ios::in);
		if (myFile.is_open())
		{
			cout << "******************************************" << endl;
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
				if (str_match(strlen(g_id), g_id, (char*)words[0].data()))
				{
					g_price_old = stoi(words[2]);
					cout << "ID: " << g_id << endl;
					cout << "Name: " << words[1] << endl;
					cout << "Price: " << double_to_string(to_string(g_price_new)) << endl;
					cout << "Info: " << words[4] << endl;
					break;
				}
			}
			cout << "******************************************" << endl;
			cout << "Do you really wanna off-shelves this?" << endl;
			do
			{
				cout << "(y/n): ";
				cin >> opt2;
			} while (!cin.fail() && opt2 != 'y' && opt2 != 'n');
			if (opt2 == 'y') {
				cout << "Done" << endl;

				fstream replace_file;
				replace_file.open("commodity.txt", ios::in);



				if (replace_file.is_open()) {
					string replace = find_str_seller_price_front(g_id) + "," + double_to_string(to_string(g_price_old)) + "," + find_str_seller_price_end(g_id);
					string replace_with = find_str_seller_price_front(g_id) + "," + double_to_string(to_string(g_price_new)) + "," + find_str_seller_price_end(g_id);
					string line;
					vector<string> lines;

					while (getline(replace_file, line))
					{
						string::size_type pos = 0;

						while ((pos = line.find(replace, pos)) != string::npos)
						{
							line.replace(pos, line.size(), replace_with);
							pos += replace_with.size();
						}

						lines.push_back(line);
					}
					replace_file.close();

					replace_file.open("commodity.txt", ios::out | ios::trunc);

					for (const auto& i : lines)
					{
						replace_file << i << endl;
					}
				}
			}
			else if (opt2 == 'n')
			{
				cout << "Action Cancelled..." << endl;
			}
		}
		myFile.close();
	}
	else if (opt1 == '2')
	{
		cout << "Input new info: ";
		cin >> g_info_new;
		cout << "Plz confirm the new Info below is correct." << endl;
		fstream myFile;
		myFile.open("commodity.txt", ios::in);
		if (myFile.is_open())
		{
			cout << "******************************************" << endl;
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
				if (str_match(strlen(g_id), g_id, (char*)words[0].data()))
				{
					MyStrCpy(g_info_old, (char*)words[4].data());
					cout << "ID: " << g_id << endl;
					cout << "Name: " << words[1] << endl;
					cout << "Price: " << words[2] << endl;
					cout << "Info: " << g_info_new << endl;
					break;
				}
			}
			cout << "******************************************" << endl;
			cout << "Do you really wanna off-shelves this?" << endl;
			do
			{
				cout << "(y/n): ";
				cin >> opt2;
			} while (!cin.fail() && opt2 != 'y' && opt2 != 'n');
			if (opt2 == 'y') {
				cout << "������Done������" << endl;

				fstream replace_file;
				replace_file.open("commodity.txt", ios::in);



				if (replace_file.is_open()) {
					string replace = find_str_seller_info_front(g_id) + "," + g_info_old + "," + find_str_seller_info_end(g_id);
					string replace_with = find_str_seller_info_front(g_id) + "," + g_info_new + "," + find_str_seller_info_end(g_id);
					string line;
					vector<string> lines;

					while (getline(replace_file, line))
					{
						string::size_type pos = 0;

						while ((pos = line.find(replace, pos)) != string::npos)
						{
							line.replace(pos, line.size(), replace_with);
							pos += replace_with.size();
						}

						lines.push_back(line);
					}
					replace_file.close();

					replace_file.open("commodity.txt", ios::out | ios::trunc);

					for (const auto& i : lines)
					{
						replace_file << i << endl;
					}
				}
			}
			else if (opt2 == 'n')
			{
				cout << "Action Cancelled..." << endl;
			}
		}
		myFile.close();
	}
}