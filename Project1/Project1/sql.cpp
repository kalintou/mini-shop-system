#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <time.h>
#include <string>
#include "sql.h"

using namespace std;

string new_time3_detail();
void create_command(int opt1, int set, int where, int contains, const char table[], const char column[], const char value[]);

SQL::SQL()
{
	//option = 0;
}

SQL::SQL(int opt)
{
	//option = opt;
}

