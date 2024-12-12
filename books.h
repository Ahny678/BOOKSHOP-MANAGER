#pragma once
#ifndef BOOKS_H
#define BOOKS_H

#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>

using namespace std; 

class books {
public:
	int id; //primary key
	string name; 
	string auth;
	int price; 
	int qty;


	void add(sql::Connection* con);
	void update_price(sql::Connection* con);
	void search(sql::Connection* con);
	void update(sql::Connection* con);
	void display(sql::Connection* con);
	
	

};


#endif // !BOOKS_H
