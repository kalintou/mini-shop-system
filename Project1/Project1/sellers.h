struct User;
class Users;

class Sellers
{
public:
	void seller_menu();
	void selling(User* somebody);
	void good_off_shelves(User* somebody);
	void modify_good(User* somebody);
	void seller_check_goods(User* somebody);
	void seller_check_orders(User* somebody);
};
