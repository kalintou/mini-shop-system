class Administrator
{
public:
	bool boss_login(const char name[], const char pass[]);
	void boss_menu();
	void boss_search();
	void good_off_shelves();
	void user_ban();
	void all_users();
	void all_goods();
	void all_orders();
	Administrator();
private:
	char boss_name[11];
	char boss_pass[21];
};
