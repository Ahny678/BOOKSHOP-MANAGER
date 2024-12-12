#include "purchases.h"
#include <iostream>
#include "main.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <string>

using namespace std;



void purchase::new_order(sql::Connection* con) {
	int year, month, day;
	cout << "Enter the book id: "; 
	cin >> book_id;
	cout << "Enter supplier id: ";
	cin >> sup_id;
	cout << "Enter the quantity: ";
	cin >> qty;
	cout << "Date ordered. Enter the year: ";
	cin >> year;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter day: ";
	cin >> day; 
	cout << "Estimated time of delivery(in days): ";
	cin >> eta;

	dt_ordered = formatDate(year, month, day);

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO db1test.purchases (book_id, sup_id, eta, quantity, date_ordered) VALUES (?, ?, ?, ?, ?)");
	pstmt->setInt(1, book_id);
	pstmt->setInt(2, sup_id);
	pstmt->setInt(3, eta);
	pstmt->setInt(4, qty);
	pstmt->setString(5, dt_ordered);
	


	pstmt->executeUpdate();
	cout << "New Order Added!" << endl;
	delete pstmt;
};

void purchase::mark_received(sql::Connection* con) {
	cout << "Enter the order id fro the order received: ";
	cin >> ord_id;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE purchases SET received = 'T' WHERE ord_id = ? ");
	pstmt->setInt(1, ord_id);


	pstmt->executeUpdate();
	cout << "Received MadE successfully!!" << endl;
	delete pstmt;

};

void purchase::mark_cancelled(sql::Connection* con) {
	cout << "Enter the order id fro the order cancelled: ";
	cin >> ord_id;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE purchases SET received = 'C' WHERE ord_id = ? ");
	pstmt->setInt(1, ord_id);


	pstmt->executeUpdate();
	cout << "Cancel Marked successfully!!" << endl;
	delete pstmt;
};

void checkView(sql::Connection* con, char x) {
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM purchases WHERE received = ?");
	//convert char to string
	string stringX(1, x);

	pstmt->setString(1, stringX);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	while (res->next()) {
		cout << "Order Id:: " << res->getInt("ord_id") << endl;
		cout << "Book Id:: " << res->getInt("book_id") << endl;
		cout << "Supplier Id:: " << res->getInt("sup_id") << endl;
		cout << "Quantity: " << res->getInt("quantity") << endl;
		cout << "date ordered: " << res->getString("date_ordered") << endl;
		cout << "estimated delivery days: " << res->getInt("eta") << endl;
	}
	cout << endl; 

	delete res;
	delete pstmt;

}
void purchase::view(sql::Connection* con) {

	int option;
	do {
		cout << "ORDERS STATUS MENU" << endl;
		cout << "1, Orders not received" << endl;
		cout << "2, Orders cancelled" << endl;
		cout << "3, Orders recieved" << endl;
		cout << "4, RETURN TO PURCHASES MENU" << endl;

		cin >> option;
		switch (option) {
			char mark; 
		case 1:
			mark = 'F';
			cout << "Orders not received are: " << endl;
			 checkView (con, mark);
			break;

		case 2:
			mark = 'C';
			cout << "Orders cancelled are: " << endl;
			checkView(con, mark);
			break;

		case 3:
			mark = 'T';
			cout << "Orders  received are: " << endl;
			checkView(con, mark);
			break;

		case 4:
			return;
		default:
			cout << "wrong input" << endl;
			break;

		};

	} while (option != 0);
};