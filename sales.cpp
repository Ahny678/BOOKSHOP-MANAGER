#include "sales.h"
#include <iostream>
#include "main.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <string>

using namespace std; 

void sales::add(sql::Connection* con) {
	cout << "Enter member id: "; 
	cin >> member_id;
	cout << "Enterr book id: ";
	cin >> book_id;
	cout << "Enter quantity: ";
	cin >> qty;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT price FROM books WHERE id = ?");

	pstmt->setInt(1, book_id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	if (!res->next()) {
		cout << "Invalid book id. Try again!" << endl; 
		return;
	}

	 price = res->getInt(1); //get the first (and only) column in the result set 
	amount = price * qty;
	delete pstmt;
	delete res; 

	pstmt = con->prepareStatement("INSERT INTO sales (member_id, book_id, qty, amount, date_s) VALUES (?, ?, ?, ?, CURDATE())");

	pstmt->setInt(1, member_id);
	pstmt->setInt(2, book_id);
	pstmt->setInt(3, qty);
	pstmt->setInt(4, amount);
	
	res = pstmt->executeQuery();
	delete pstmt;
	delete res;
	cout << "sales added successfully!" << endl; 

};
void sales::find_total_sales(sql::Connection* con) {
	//total sales for the year 

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT SUM(amount) AS total_amount FROM sales WHERE YEAR(date_s) = YEAR(CURDATE()) ");

	sql::ResultSet* res;
	res = pstmt->executeQuery();

	if (res->next())
	{
		total_sales = res->getInt("total_amount");
		cout << "Tatal yearly sales: " << total_sales << endl;

	}
	else {
		cout << "no yearly sales" << endl;
	}
};
	