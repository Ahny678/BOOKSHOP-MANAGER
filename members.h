#pragma once
#ifndef MEMBERS_H
#define MEMBERS_H
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>
using namespace std; 

class members {
public:
	int mem_id;
	string name; 
	string address;
	string city;
	string state;
	int phn;
	string beg_date;
	string end_date; 
	string valid;

	void add_mem(sql::Connection* con);
	void refresh(sql::Connection* con);
	void search_mem(sql::Connection* con);

};
#endif // !MEMEERS_H

