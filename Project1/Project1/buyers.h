struct User;
class Users;

class Buyers
{
public:
	void buyer_menu();
	void buyer_searching_good();
	void buying(User* somebody);
	void check_one(User* somebody);
	void buyer_check_goods(User* somebody);
	void buyer_check_orders(User* somebody);
};