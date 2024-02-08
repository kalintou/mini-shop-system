struct User
{
	bool u_state = 0;
	char u_id[7];
	char u_name[21];
	char u_pass[21];
	char u_phone[21];
	char u_address[41];
	double u_money = 0;
};

class Users
{
public:
	bool user_login(User* somebody);
	bool user_register(User* somebody);
	void self_menu();
	void searching_good();
	void check_info();
	void modify_info();
	void modify_name();
	void modify_phone();
	void modify_address();
};

//cout << "======================================================================================================================" << endl;
//cout << "1. Selling  2. Checking my Goods  3. Change Info of Goods 4.off-shelves Goods 5. Checking Orders  6. Back to User Mode" << endl;
//cout << "======================================================================================================================" << endl;
//cout << endl;
//cout << endl;