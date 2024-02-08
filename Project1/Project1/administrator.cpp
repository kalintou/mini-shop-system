#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "administrator.h"

using namespace std;

bool str_match(const int length, const char x[], const char y[]);
bool match_checker(int x_length, int y_length, const char x[], const char y[]);
string find_str_good(const char keyword[]);
string find_str_user(const char keyword[]);

Administrator::Administrator() {
	char tmp_name[] = "admin";
	char tmp_pass[] = "123456";
	strcpy_s(boss_name, tmp_name);
	strcpy_s(boss_pass, tmp_pass);
}
void Administrator::boss_menu()
{
	cout << "=================================================================================================================================================" << endl;
	cout << "1. Search for ALL goods  2. Search for ONE  3. off-shelves Goods  4. Checking All of Orders  5. Checking All of Users  6. Ban Users  7. Sign Out" << endl;
	cout << "=================================================================================================================================================" << endl;
};
bool Administrator::boss_login(const char name[], const char pass[])
{
	if (str_match(6, boss_name, name) && str_match(6, boss_pass, pass))
	{
		return true;
	}
	else {
		return false;
	}
}
void Administrator::all_goods()
{

	fstream fileChecker;
	fileChecker.open("commodity.txt", ios::in);
	int no_good_flag = 0;

	//
	if (fileChecker.is_open())
	{
		string check;
		while (getline(fileChecker, check))
		{
			no_good_flag++;
		}
		fileChecker.close();
	}

	if (no_good_flag <= 1)
	{
		cout << "There is no Good!!!" << endl;
	}
	else
	{
		cout << "**************************************************************************************" << endl;
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
				cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
			}
			myFile.close();
		}
		cout << "**************************************************************************************" << endl;
	}

};
void Administrator::boss_search()
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
			if (match_checker(words[1].length(), strlen(keyword), (char*)words[1].data(), keyword))
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
void Administrator::good_off_shelves()
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
			cout << "šššDoneššš" << endl;

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
			}
		}
		else if (type == 'n')
		{
			cout << "Action Cancelled..." << endl;
		}
	}
	myFile.close();

};
void Administrator::all_orders()
{
	fstream fileChecker;
	fileChecker.open("order.txt", ios::in);
	int no_order_flag = 0;

	//
	if (fileChecker.is_open())
	{
		string check;
		while (getline(fileChecker, check))
		{
			no_order_flag++;
		}
		fileChecker.close();
	}

	if (no_order_flag <= 1)
	{
		cout << "There is no Order!!!" << endl;
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
				cout << left << setw(11) << words[0] << left << setw(15) << words[1] << left << setw(13) << words[2] << left << setw(10) << words[3] << left << setw(13) << words[4] << left << setw(13) << words[5] << left << setw(9) << words[6] << endl;
			}
			myFile.close();
		}
		cout << "*************************************************************************************" << endl;

	}
};
void Administrator::all_users()
{
	fstream fileChecker;
	fileChecker.open("user.txt", ios::in);
	int no_user_flag = 0;

	//
	if (fileChecker.is_open())
	{
		string check;
		while (getline(fileChecker, check))
		{
			no_user_flag++;
		}
		fileChecker.close();
	}

	if (no_user_flag <= 1)
	{
		cout << "There is no User!!!" << endl;
	}
	else
	{
		cout << "***********************************************************************************" << endl;
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
				while (getline(sstream, word, delimiter)) {
					words.push_back(word);
				}
				cout << left << setw(10) << words[0] << left << setw(12) << words[1] << left << setw(12) << words[2] << left << setw(15) << words[3] << left << setw(11) << words[4] << left << setw(11) << words[5] << left << setw(13) << words[6] << endl;
			}
			myFile.close();
		}
		cout << "***********************************************************************************" << endl;
	}
};
void Administrator::user_ban()
{
	char type;
	char keyword[20];
	char off_shelves[20] = "inactive";
	cout << "ID of User: ";
	cin >> keyword;

	fstream myFile;
	myFile.open("user.txt", ios::in);
	if (myFile.is_open())
	{
		cout << "***********************************************************************************" << endl;

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
				cout << left << setw(10) << words[0] << left << setw(12) << words[1] << left << setw(12) << words[2] << left << setw(15) << words[3] << left << setw(11) << words[4] << left << setw(11) << words[5] << left << setw(13) << words[6] << endl;
			}
		}
		cout << "***********************************************************************************" << endl;
		cout << "Do you really wanna BAN this user?" << endl;
		do
		{
			cout << "(y/n): ";
			cin >> type;
		} while (!cin.fail() && type != 'y' && type != 'n');
		if (type == 'y') {
			cout << "šššDoneššš" << endl;

			fstream replace_file;
			replace_file.open("user.txt", ios::in);

			if (replace_file.is_open()) {
				string replace = find_str_user(keyword) + "," + "active";
				string replace_with = find_str_user(keyword) + "," + "inactive";
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

				replace_file.open("user.txt", ios::out | ios::trunc);

				for (const auto& i : lines)
				{
					replace_file << i << endl;
				}
			}
		}
		else if (type == 'n')
		{
			cout << "Action Cancelled..." << endl;
		}
	}
	myFile.close();
};

//functions statement
//bool str_match(const int length, const char x[], const char y[]);
//bool match_checker(int x_length, int y_length, const char x[], const char y[]);
//string find_str(const char target[]);

//Administrator::Administrator() {
//	char tmp_name[] = "admin";
//	char tmp_pass[] = "123456";
//	strcpy_s(boss_name, tmp_name);
//	strcpy_s(boss_pass, tmp_pass);
//}
//bool Administrator::boss_login(const char name[], const char pass[])
//{
//	if (str_match(6, boss_name, name) && str_match(6, boss_pass, pass))
//	{
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void Administrator::boss_menu()
//{
//	cout << "=================================================================================================================================================" << endl;
//	cout << "1. Search for ALL goods  2. Search for ONE  3. off-shelves Goods  4. Checking All of Orders  5. Checking All of Users  6. Ban Users  7. Sign Out" << endl;
//	cout << "=================================================================================================================================================" << endl;
//};
//void Administrator::boss_search()
//{
//	int no_good_checker = 0;
//	char keyword[20];
//	cout << "Keyword of your Good: ";
//	cin >> keyword;
//	fstream myFile;
//	myFile.open("commodity.txt", ios::in);
//	if (myFile.is_open())
//	{
//		cout << "***************************************************************************************************" << endl;
//
//		string line;
//		while (getline(myFile, line))
//		{
//			char delimiter = ',';
//			vector<string> words{};
//			stringstream sstream(line);
//			string word;
//			while (std::getline(sstream, word, delimiter)) {
//				words.push_back(word);
//			}
//			if (match_checker(words[1].length(), strlen(keyword), (char*)words[1].data(), keyword))
//			{
//				cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
//				no_good_checker++;
//			}
//		}
//		if (no_good_checker == 0)
//		{
//			cout << "Sry.. No matched good." << endl;
//		}
//		cout << "***************************************************************************************************" << endl;
//		myFile.close();
//	}
//};
//void Administrator::good_off_shelves()
//{
//	char type;
//	char keyword[20];
//	char off_shelves[20] = "offShelves";
//	cout << "ID of Target: ";
//	cin >> keyword;
//
//	fstream myFile;
//	myFile.open("commodity.txt", ios::in);
//	if (myFile.is_open())
//	{
//		cout << "***************************************************************************************************" << endl;
//		string line;
//		while (getline(myFile, line))
//		{
//			char delimiter = ',';
//			vector<string> words{};
//			stringstream sstream(line);
//			string word;
//			while (std::getline(sstream, word, delimiter)) {
//				words.push_back(word);
//			}
//			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
//			{
//				cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
//			}
//		}
//		cout << "***************************************************************************************************" << endl;
//		cout << "Do you really wanna off-shelves this?" << endl;
//		do
//		{
//			cout << "(y/n): ";
//			cin >> type;
//		} while (!cin.fail() && type != 'y' && type != 'n');
//		if (type == 'y') {
//			cout << "šššDoneššš" << endl;
//
//			fstream replace_file;
//			replace_file.open("commodity.txt", ios::in);
//
//			if (replace_file.is_open()) {
//				string replace = find_str(keyword) + "," + "onSale";
//				string replace_with = find_str(keyword) + "," + "offShelves";
//				string line;
//				vector<string> lines;
//
//				while (getline(replace_file, line))
//				{
//					string::size_type pos = 0;
//
//					while ((pos = line.find(replace, pos)) != string::npos)
//					{
//						line.replace(pos, line.size(), replace_with);
//						pos += replace_with.size();
//					}
//
//					lines.push_back(line);
//				}
//				replace_file.close();
//
//				replace_file.open("commodity.txt", ios::out | ios::trunc);
//
//				for (const auto& i : lines)
//				{
//					replace_file << i << endl;
//				}
//			}
//		}
//		else if (type == 'n')
//		{
//			cout << "Action Cancelled..." << endl;
//		}
//	}
//	myFile.close();
//
//};
//void Administrator::user_ban()
//{
//	char type;
//	char keyword[20];
//	char off_shelves[20] = "inactive";
//	cout << "ID of User: ";
//	cin >> keyword;
//
//	fstream myFile;
//	myFile.open("user.txt", ios::in);
//	if (myFile.is_open())
//	{
//		cout << "***********************************************************************************" << endl;
//
//		string line;
//		while (getline(myFile, line))
//		{
//			char delimiter = ',';
//			vector<string> words{};
//			stringstream sstream(line);
//			string word;
//			while (std::getline(sstream, word, delimiter)) {
//				words.push_back(word);
//			}
//			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
//			{
//				cout << left << setw(10) << words[0] << left << setw(12) << words[1] << left << setw(12) << words[2] << left << setw(15) << words[3] << left << setw(11) << words[4] << left << setw(11) << words[5] << left << setw(13) << words[6] << endl;
//			}
//		}
//		cout << "***********************************************************************************" << endl;
//		cout << "Do you really wanna BAN this user?" << endl;
//		do
//		{
//			cout << "(y/n): ";
//			cin >> type;
//		} while (!cin.fail() && type != 'y' && type != 'n');
//		if (type == 'y') {
//			cout << "šššDoneššš" << endl;
//
//			fstream replace_file;
//			replace_file.open("user.txt", ios::in);
//
//			if (replace_file.is_open()) {
//				string replace = find_str(keyword) + "," + "active";
//				string replace_with = find_str(keyword) + "," + "inactive";
//				string line;
//				vector<string> lines;
//
//				while (getline(replace_file, line))
//				{
//					string::size_type pos = 0;
//
//					while ((pos = line.find(replace, pos)) != string::npos)
//					{
//						line.replace(pos, line.size(), replace_with);
//						pos += replace_with.size();
//					}
//
//					lines.push_back(line);
//				}
//				replace_file.close();
//
//				replace_file.open("user.txt", ios::out | ios::trunc);
//
//				for (const auto& i : lines)
//				{
//					replace_file << i << endl;
//				}
//			}
//		}
//		else if (type == 'n')
//		{
//			cout << "Action Cancelled..." << endl;
//		}
//	}
//	myFile.close();
//};
//void Administrator::all_users()
//{
//	fstream fileChecker;
//	fileChecker.open("user.txt", ios::in);
//	int no_user_flag = 0;
//
//	//
//	if (fileChecker.is_open())
//	{
//		string check;
//		while (getline(fileChecker, check))
//		{
//			no_user_flag++;
//		}
//		fileChecker.close();
//	}
//
//	if (no_user_flag <= 1)
//	{
//		cout << "There is no User!!!" << endl;
//	}
//	else
//	{
//		cout << "***********************************************************************************" << endl;
//		fstream myFile;
//		myFile.open("user.txt", ios::in);
//		if (myFile.is_open())
//		{
//			string line;
//			while (getline(myFile, line))
//			{
//				char delimiter = ',';
//				vector<string> words{};
//				stringstream sstream(line);
//				string word;
//				while (getline(sstream, word, delimiter)) {
//					words.push_back(word);
//				}
//				cout << left << setw(10) << words[0] << left << setw(12) << words[1] << left << setw(12) << words[2] << left << setw(15) << words[3] << left << setw(11) << words[4] << left << setw(11) << words[5] << left << setw(13) << words[6] << endl;
//			}
//			myFile.close();
//		}
//		cout << "***********************************************************************************" << endl;
//	}
//};
//void Administrator::all_goods()
//{
//
//	fstream fileChecker;
//	fileChecker.open("commodity.txt", ios::in);
//	int no_good_flag = 0;
//
//	//
//	if (fileChecker.is_open())
//	{
//		string check;
//		while (getline(fileChecker, check))
//		{
//			no_good_flag++;
//		}
//		fileChecker.close();
//	}
//
//	if (no_good_flag <= 1)
//	{
//		cout << "There is no Good!!!" << endl;
//	}
//	else
//	{
//		cout << "**************************************************************************************" << endl;
//		fstream myFile;
//		myFile.open("commodity.txt", ios::in);
//		if (myFile.is_open())
//		{
//			string line;
//			while (getline(myFile, line))
//			{
//				char delimiter = ',';
//				vector<string> words{};
//				stringstream sstream(line);
//				string word;
//				while (std::getline(sstream, word, delimiter)) {
//					words.push_back(word);
//				}
//				cout << left << setw(15) << words[0] << left << setw(17) << words[1] << left << setw(9) << words[2] << left << setw(10) << words[3] << left << setw(15) << words[4] << left << setw(12) << words[5] << left << setw(13) << words[6] << left << setw(14) << words[7] << endl;
//			}
//			myFile.close();
//		}
//		cout << "**************************************************************************************" << endl;
//	}
//
//};
//void Administrator::all_orders()
//{
//	fstream fileChecker;
//	fileChecker.open("order.txt", ios::in);
//	int no_order_flag = 0;
//
//	//
//	if (fileChecker.is_open())
//	{
//		string check;
//		while (getline(fileChecker, check))
//		{
//			no_order_flag++;
//		}
//		fileChecker.close();
//	}
//
//	if (no_order_flag <= 1)
//	{
//		cout << "There is no Order!!!" << endl;
//	}
//	else
//	{
//		cout << "*************************************************************************************" << endl;
//		fstream myFile;
//		myFile.open("order.txt", ios::in);
//		if (myFile.is_open())
//		{
//			string line;
//			while (getline(myFile, line))
//			{
//				char delimiter = ',';
//				vector<string> words{};
//				stringstream sstream(line);
//				string word;
//				while (std::getline(sstream, word, delimiter)) {
//					words.push_back(word);
//				}
//				cout << left << setw(11) << words[0] << left << setw(15) << words[1] << left << setw(13) << words[2] << left << setw(10) << words[3] << left << setw(13) << words[4] << left << setw(13) << words[5] << left << setw(9) << words[6] << endl;
//			}
//			myFile.close();
//		}
//		cout << "*************************************************************************************" << endl;
//
//	}
//};
//
////functions
//bool str_match(const int length, const char x[], const char y[])
//{
//	for (int i = 0; i < length; i++)
//	{
//		if (x[i] != y[i])
//			return false;
//	}
//	return true;
//}
//bool match_checker(int x_length, int y_length, const char x[], const char y[])
//{
//	for (int i = 0; i < x_length; i++)
//	{
//		if (x[i] == y[0])
//		{
//			return str_match(y_length, y, x);
//		}
//	}
//	return false;
//}
//string find_str(const char keyword[])
//{
//	string replace;
//	fstream myFile;
//	myFile.open("commodity.txt", ios::in);
//	if (myFile.is_open())
//	{
//		string line;
//		while (getline(myFile, line))
//		{
//			char delimiter = ',';
//			vector<string> words{};
//			stringstream sstream(line);
//			string word;
//			while (std::getline(sstream, word, delimiter)) {
//				words.push_back(word);
//			}
//			if (match_checker(words[0].length(), strlen(keyword), (char*)words[0].data(), keyword))
//			{
//				string replace = words[0] + "," + words[1] + "," + words[2] + "," + words[3] + "," + words[4] + "," + words[5] + "," + words[6];
//				myFile.close();
//				return replace;
//			}
//
//		}
//		myFile.close();
//	}
//	return replace;
//};