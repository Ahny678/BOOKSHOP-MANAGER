#pragma once
#ifndef PURCHASES_H
#define PURCHASES
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>

using namespace std;

class purchase {
public:
	int ord_id; //primary key
	int book_id; //foreign key ref books
	int sup_id; //foreign key ref suppliers
	int qty;
	string dt_ordered;
	int eta;
	char received; //defalt is false
	int inv; 

	//functions
	void new_order(sql::Connection* con);
	void mark_received(sql::Connection* con);
	void mark_cancelled(sql::Connection* con);
	void view(sql::Connection* con);
	


};
#endif // !PURCHASES_H

