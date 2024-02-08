#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "users.h"

using namespace std;

void MyStrCpy(char t[], const char s[]);
bool active_checker(const int length, const char x[]);

bool Users::user_login(User* somebody)
{
	char u_name[21];
	char u_pass[21];
	cout << "Username: ";
	cin >> u_name;
	cout << "Password: ";
	cin >> u_pass;

	fstream user_file;
	user_file.open("user.txt", ios::in);
	if (user_file.is_open())
	{
		string line;
		while (getline(user_file, line))
		{
			char delimiter = ',';
			vector<string> words{};
			stringstream sstream(line);
			string word;
			while (getline(sstream, word, delimiter)) {
				words.push_back(word);
			}
			if (((string)u_name == words[1].data()) && ((string)u_pass == words[2].data()) && (active_checker(words[6].length(), (char*)words[6].data())))
			{
				somebody->u_state = 1;
				MyStrCpy(somebody->u_id, (char*)words[0].data());
				MyStrCpy(somebody->u_name, (char*)words[1].data());
				MyStrCpy(somebody->u_pass, (char*)words[2].data());
				MyStrCpy(somebody->u_phone, (char*)words[3].data());
				MyStrCpy(somebody->u_address, (char*)words[4].data());
				somebody->u_money = stod(words[5].data());
				user_file.close();
				return true;
			}
		}
	}
	user_file.close();
	return false;
}
bool Users::user_register(User* somebody)
{
	char u_name[21];
	char u_pass[21];
	cout << "Username: ";
	cin >> u_name;
	cout << "Password: ";
	cin >> u_pass;

	string last_user_id;
	string new_user_id;
	string supporter;

	fstream register_file;
	register_file.open("user.txt", ios::in);
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
			last_user_id = words[0];
			if (words[1].data() == (string)u_name)
			{
				return false;
			}
		}
		register_file.close();
	}
	int id_int = stoi(last_user_id.substr(1));
	if (id_int < 10)
	{
		new_user_id = "U00" + to_string(id_int + 1) + "\0";
	}
	else if (id_int < 100)
	{
		new_user_id = "U0" + to_string(id_int + 1) + "\0";
	}
	else
	{
		new_user_id = "U" + to_string(id_int + 1) + "\0";
	}

	MyStrCpy(somebody->u_id, (char*)new_user_id.data());
	MyStrCpy(somebody->u_name, u_name);
	MyStrCpy(somebody->u_pass, u_pass);
	MyStrCpy(somebody->u_phone, "12345678");
	MyStrCpy(somebody->u_address, "Default");
	somebody->u_money = 0;

	fstream create_user_file;
	create_user_file.open("user.txt", ios::app);
	if (create_user_file.is_open())
	{
		create_user_file << endl;
		create_user_file << (string)somebody->u_id + "," + (string)somebody->u_name + "," + (string)somebody->u_pass + "," + (string)somebody->u_phone + "," + (string)somebody->u_address + ",";
		create_user_file << fixed << setprecision(1) << somebody->u_money << ",";
		create_user_file << "active";
		create_user_file.close();
	}

	return true;
}
void Users::self_menu()
{
	cout << "===================================================" << endl;
	cout << "1. Buyer Mode  2. Seller Mode  3. Info  4. Sign Out" << endl;
	cout << "===================================================" << endl;
	cout << endl;
	cout << endl;
}



















//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <vector>
////#include "sellers.h"
////#include "users.h"
////#include "data.h"
//
//using namespace std;
//
////functions statement
//void MyStrCpy(char t[], const char s[]);
//bool active_checker(const int length, const char x[]);
//
//struct User
//{
//	bool u_state = 0;
//	char u_id[7];
//	char u_name[21];
//	char u_pass[21];
//	char u_phone[21];
//	char u_address[41];
//	double u_money = 0;
//};
//
//class Users
//{
//public:
//	bool user_login(User* somebody);
//	bool user_register(User* somebody);
//	void self_menu();
//	void searching_good();
//	void check_info();
//	void modify_info();
//	void modify_name();
//	void modify_phone();
//	void modify_address();
//};
//
//bool Users::user_login(User* somebody)
//{
//	char u_name[21];
//	char u_pass[21];
//	cout << "Username: ";
//	cin >> u_name;
//	cout << "Password: ";
//	cin >> u_pass;
//
//	fstream user_file;
//	user_file.open("user.txt", ios::in);
//	if (user_file.is_open())
//	{
//		string line;
//		while (getline(user_file, line))
//		{
//			char delimiter = ',';
//			vector<string> words{};
//			stringstream sstream(line);
//			string word;
//			while (getline(sstream, word, delimiter)) {
//				words.push_back(word);
//			}
//			if (((string)u_name == words[1].data()) && ((string)u_pass == words[2].data()) && (active_checker(words[6].length(), (char*)words[6].data())))
//			{
//				somebody->u_state = 1;
//				MyStrCpy(somebody->u_id, (char*)words[0].data());
//				MyStrCpy(somebody->u_name, (char*)words[1].data());
//				MyStrCpy(somebody->u_pass, (char*)words[2].data());
//				MyStrCpy(somebody->u_phone, (char*)words[3].data());
//				MyStrCpy(somebody->u_address, (char*)words[4].data());
//				somebody->u_money = stod(words[5].data());
//				user_file.close();
//				return true;
//			}
//		}
//	}
//	user_file.close();
//	return false;
//}
//bool Users::user_register(User* somebody)
//{
//	char u_name[21];
//	char u_pass[21];
//	cout << "Username: ";
//	cin >> u_name;
//	cout << "Password: ";
//	cin >> u_pass;
//
//	string last_user_id;
//	string new_user_id;
//	string supporter;
//
//	fstream register_file;
//	register_file.open("user.txt", ios::in);
//	if (register_file.is_open())
//	{
//		string line;
//		while (getline(register_file, line))
//		{
//			char delimiter = ',';
//			vector<string> words{};
//			stringstream sstream(line);
//			string word;
//			while (getline(sstream, word, delimiter)) {
//				words.push_back(word);
//			}
//			last_user_id = words[0];
//			if (words[1].data() == (string)u_name)
//			{
//				return false;
//			}
//		}
//		register_file.close();
//	}
//	int id_int = stoi(last_user_id.substr(1));
//	if (id_int < 10)
//	{
//		new_user_id = "U00" + to_string(id_int + 1) + "\0";
//	}
//	else if (id_int < 100)
//	{
//		new_user_id = "U0" + to_string(id_int + 1) + "\0";
//	}
//	else
//	{
//		new_user_id = "U" + to_string(id_int + 1) + "\0";
//	}
//
//	MyStrCpy(somebody->u_id, (char*)new_user_id.data());
//	MyStrCpy(somebody->u_name, u_name);
//	MyStrCpy(somebody->u_pass, u_pass);
//	MyStrCpy(somebody->u_phone, "12345678");
//	MyStrCpy(somebody->u_address, "Default");
//	somebody->u_money = 0;
//
//	fstream create_user_file;
//	create_user_file.open("user.txt", ios::app);
//	if (create_user_file.is_open())
//	{
//		create_user_file << endl;
//		create_user_file << (string)somebody->u_id + "," + (string)somebody->u_name + "," + (string)somebody->u_pass + "," + (string)somebody->u_phone + "," + (string)somebody->u_address + ",";
//		create_user_file << fixed << setprecision(1) << somebody->u_money << ",";
//		create_user_file << "active";
//		create_user_file.close();
//	}
//
//	return true;
//}
//void Users::self_menu()
//{
//	cout << "===================================================" << endl;
//	cout << "1. Buyer Mode  2. Seller Mode  3. Info  4. Sign Out" << endl;
//	cout << "===================================================" << endl;
//	cout << endl;
//	cout << endl;
//}
//void MyStrCpy(char t[], const char s[])
//{
//
//	int i = 0;
//	while (s[i] != '\0')
//	{
//		t[i] = s[i];
//
//		++i;
//
//	}
//	t[i] = s[i];
//
//}
//bool active_checker(const int length, const char x[])
//{
//	char y[7] = { "active" };
//	for (int i = 0; i < length; i++)
//	{
//		if (x[i] != y[i])
//			return false;
//	}
//	return true;
//}