#pragma once
#ifndef SUPPLIERS_H
#define SUPPLIERS
#include <string>
#include <mysql_connection.h> 
#include <mysql_driver.h> 
using namespace std;

class suppliers {
public:
	int id; //primary key
	string name; 
	int phn;
	string address;
	string city;
	string state;

	//functions
	void add_sup(sql::Connection* con);
	void remove_sup(sql::Connection* con);
	void search_id(sql::Connection* con);

};
#endif // !SUPPLIERS_H
