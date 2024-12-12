#pragma once
#ifndef SALES_H
#define SALES_H
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>
using namespace std;

class sales {
public:
	int invoice_id;
	int member_id;
	int book_id;
	int qty;
	int amount;
	string date_s;
	int price;
	int total_sales;

	void add(sql::Connection* con);
	void find_total_sales(sql::Connection* con);

};


#endif // !SALES_H

