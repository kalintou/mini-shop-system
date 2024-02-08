#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <math.h>
#include "Buyers.h"
#include "data.h"
#include "users.h"

using namespace std;

void MyStrCpy(char t[], const char s[]);
bool str_match(const int length, const char x[], const char y[]);
bool match_checker(int x_length, int y_length, const char x[], const char y[]);
string double_to_string(string x);
string new_time3();
string find_str_price_front(const char keyword[]);
string find_str_price_end(const char keyword[]);
string find_str_balance_front(const char keyword[]);
string find_str_balance_end(const char keyword[]);

void Buyers::buyer_menu()
{
	cout << "=======================================================================================================================" << endl;
	cout << "1. Listing all Goods  2. Buying  3. Searching one  4. Checking Orders  5. Checking Goods detail  6. Return to User Mode" << endl;
	cout << "=======================================================================================================================" << endl;
	cout << endl;
	cout << endl;
}
void Buyers::buyer_check_goods(User* somebody) {

	fstream buying_check_file;
	buying_check_file.open("commodity.txt", ios::in);
	bool no_good_flag = false;

	//
	if (buying_check_file.is_open())
	{
		string line;
		while (getline(buying_check_file, line))
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
		buying_check_file.close();
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
				if (words[7] == "onSale")
				{
					cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
				}
			}
			myFile.close();
		}
		cout << "******************************************************************************************************" << endl;
	}
}
void Buyers::buyer_searching_good()
{
	int no_good_checker = 0;
	char keyword[20];
	cout << "Keyword of your Good: ";
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
			if ((match_checker(words[1].length(), strlen(keyword), (char*)words[1].data(), keyword)) && (words[7] == "onSale"))
			{
				cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
				no_good_checker++;
			}
		}
		if (no_good_checker == 0)
		{
			cout << "Sry.. No matched good." << endl;
		}
		cout << "***************************************************************************************************" << endl;
		myFile.close();
	}
};
void Buyers::buyer_check_orders(User* somebody) {
	fstream buyer_order_file;
	buyer_order_file.open("order.txt", ios::in);
	bool no_good_flag = false;

	//
	if (buyer_order_file.is_open())
	{
		string line;
		while (getline(buyer_order_file, line))
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
		buyer_order_file.close();
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
void Buyers::check_one(User* somebody)
{
	int no_good_checker = 0;
	char g_id[20];
	cout << "id of your Good: ";
	cin >> g_id;
	fstream myFile;
	myFile.open("commodity.txt", ios::in);
	if (myFile.is_open())
	{
		cout << "**********************" << endl;

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
			if (match_checker(words[0].length(), strlen(g_id), (char*)words[1].data(), g_id))
			{
				cout << "ID: " << words[0] << endl;
				cout << "Name: " << words[1] << endl;
				cout << "Price: " << words[2] << endl;
				cout << "Time: " << words[6] << endl;
				cout << "Info: " << words[4] << endl;
				cout << "Seller ID: " << words[5] << endl;


				no_good_checker++;
			}
		}
		if (no_good_checker == 0)
		{
			cout << "Sry.. No matched good." << endl;
		}
		cout << "**********************" << endl;
		myFile.close();
	}
};
void Buyers::buying(User* somebody)
{
	char g_id[7];
	char u_id[7];
	char seller_id[7];
	string time;
	double good_price;
	double balance;
	int request_num;
	int good_num;
	string off_shelves = "offShelves";
	cout << "Commpdity ID: ";
	cin >> g_id;
	cout << "How many do you wanna buy? ";
	cin >> request_num;
	int something_or_not = 0;
	int off_shelves_or_not = 0;

	fstream search_good;
	search_good.open("commodity.txt", ios::in);
	if (search_good.is_open())
	{
		string line;
		while (getline(search_good, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (words[7] == off_shelves)
			{
				off_shelves_or_not++;
				break;
			}
			if (match_checker(words[0].length(), strlen(g_id), (char*)words[0].data(), g_id))
			{
				something_or_not++;
				good_price = stod(words[2]);
				good_num = stoi(words[3]);
				MyStrCpy(seller_id, (char*)words[5].data());
				break;
			}
		}
		if (something_or_not == 0)
		{
			cout << "Wrong ID or No such thing..Try again." << endl;
			return;
		}
		if (off_shelves_or_not != 0)
		{
			cout << "You cannot buy Goods of offShelves" << endl;
			return;
		}
	}
	search_good.close();

	if (good_num < request_num || good_num <= 0)
	{
		cout << "Your request exceed the number of good stocked. Try again." << endl;
		return;
	}

	fstream search_user;
	search_user.open("user.txt", ios::in);
	if (search_user.is_open())
	{
		string line;
		while (getline(search_user, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(somebody->u_id), (char*)words[0].data(), somebody->u_id))
			{
				MyStrCpy(u_id, somebody->u_id);
				balance = somebody->u_money;
			}
		}
	}
	search_user.close();

	if (good_price * good_num > balance)
	{
		cout << "Insufficient Balance! Do not steal chicken!" << endl;
		return;
	}

	time = new_time3();
	cout << "********************************" << endl;
	cout << "Order Reminder!" << endl;
	cout << "Commodity Price: " << good_price << endl;
	cout << "Number of Commodity: " << good_num - request_num << endl;
	cout << "Order status: Successed" << endl;
	cout << "Your Balance: " << double_to_string(to_string(balance - good_price * request_num)) << endl;
	cout << "********************************" << endl;

	fstream change_num;
	change_num.open("commodity.txt", ios::in);
	if (change_num.is_open())
	{
		string line;
		while (getline(change_num, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (std::getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (match_checker(words[0].length(), strlen(g_id), (char*)words[0].data(), g_id))
			{
				
				fstream replace_file;
				replace_file.open("commodity.txt", ios::in);

				if (replace_file.is_open()) {
					string replace = find_str_price_front(g_id) + "," + to_string(good_num) + "," + find_str_price_end(g_id);
					string replace_with = find_str_price_front(g_id) + "," + to_string(good_num - request_num) + "," + find_str_price_end(g_id);
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

				fstream replace_file2;
				replace_file2.open("user.txt", ios::in);

				if (replace_file2.is_open()) {
					string replace = find_str_balance_front(u_id) + "," + double_to_string(to_string(balance)) + "," + find_str_balance_end(u_id);
					string replace_with = find_str_balance_front(u_id) + "," + double_to_string(to_string(balance - good_price * request_num)) + "," + find_str_balance_end(u_id);
					string line;
					vector<string> lines;

					while (getline(replace_file2, line))
					{
						string::size_type pos = 0;

						while ((pos = line.find(replace, pos)) != string::npos)
						{
							line.replace(pos, line.size(), replace_with);
							pos += replace_with.size();
						}

						lines.push_back(line);
					}
					replace_file2.close();

					replace_file2.open("user.txt", ios::out | ios::trunc);

					for (const auto& i : lines)
					{
						replace_file2 << i << endl;
					}
					replace_file2.close();
				}

			}
		}
	}
	change_num.close();

	Order* order = new Order;

	string last_order_id;
	string new_order_id;

	fstream register_file;
	register_file.open("order.txt", ios::in);
	if (register_file.is_open())
	{
		string line;
		while (getline(register_file, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			last_order_id = words[0];
		}
		register_file.close();
	}
	int id_int = stoi(last_order_id.substr(1));
	if (id_int < 10)
	{
		new_order_id = "U00" + to_string(id_int + 1) + "\0";
	}
	else if (id_int < 100)
	{
		new_order_id = "U0" + to_string(id_int + 1) + "\0";
	}
	else
	{
		new_order_id = "U" + to_string(id_int + 1) + "\0";
	}

	MyStrCpy(order->o_id, (char*)new_order_id.data());
	MyStrCpy(order->good_id, g_id);
	order->good_price = good_price;
	order->good_num = good_num - request_num;
	MyStrCpy(order->o_time, (char*)time.data());
	MyStrCpy(order->seller_id, seller_id);
	MyStrCpy(order->buyer_id, u_id);

	//create order

}