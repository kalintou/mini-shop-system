struct Good
{
	int g_state = 0;
	char g_id[7] = { "M" };
	char g_name[21];
	double g_price;
	int g_num;
	char g_info[201];
	char g_time[11];
	char seller_id[7] = { "U" };
};

struct Order
{
	char o_id[7] = { "T" };
	char good_id[7];
	double good_price = 0;
	int good_num;
	char o_time[11];
	char seller_id[7];
	char buyer_id[7];
};