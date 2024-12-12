#include "books.h"
#include <iostream>
#include "main.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <vector>
using namespace std; 

void books::add(sql::Connection* con) {
	cout << "Enter book name: ";
	cin.ignore();
	getline(cin, name); 
	cout << "Enter author name: ";
	cin.ignore();
	getline(cin, auth);
	cout << "Enter the price: ";
	cin >> price; 
	cout << "Enter quantity received: "; 
	cin >> qty;
	cout << "Enter id: ";
	cin >> id;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO db1test.books (id, name, author, price, quantity) VALUES (?, ?, ?, ?, ?)");
	pstmt->setInt(1, books::id);
	pstmt->setString(2,books::name);
	pstmt->setString(3, books::auth);
	pstmt->setInt(4, books::price);
	pstmt->setInt(5, books::qty);
	

	pstmt->executeUpdate();
	cout << "Book added succesfully!" << endl; 
	delete pstmt;

};

void books::update_price(sql::Connection* con) {
	cout << "Enter the id of the book to update in price: ";
	char choice;
	cin >> id;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM books WHERE id = ?");
	pstmt->setInt(1, id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	if (res->next()) {
		cout << "Book name: " << res->getString("name") << endl;
		cout << "Book price: " << res->getInt("price") << endl;
	}

	else {
		cout << "id does not exist" << endl;
		return;
	}
	delete res;
	delete pstmt;
	cout << "Are you sure you want to update the current price? Input Y/O" << endl; 
	cin >> choice;
	if (choice == 121 || choice == 89) { //121 is owercase y and 89 is uppercase y
		cout << "Enter new price: ";
		cin >> price;
		pstmt = con->prepareStatement("UPDATE books SET price = ? WHERE id = ?");
		pstmt->setInt(1, price);
		pstmt->setInt(2, id);

		pstmt->executeUpdate();
		cout << "Price successfully updated!" << endl;
		delete pstmt;
	}

	else
		cout << "Invalid input" << endl; 
};

void books::search(sql::Connection* con) {
	cout << "Enter book id for details" << endl;
	cin >> id;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM books WHERE id = ?");
	pstmt->setInt(1, id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	if (res->next()) {
		cout << "Book id: " << res->getInt("id") << endl;
		cout << "Book name: " << res->getString("name") << endl;
		cout << "Book auhtor: " << res->getString("author") << endl;
		cout << "Book price: " << res->getInt("price") << endl;
		cout << "Book quantity: " << res->getInt("quantity") << endl;
	}

	else{
		cout << "id does not exist" << endl;
		return;
}
	delete res;
	delete pstmt;


};

void books::update(sql::Connection* con) {
	//select books id& quanity when received is t AND INV IS null
	
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT book_id, quantity FROM purchases WHERE received = 'T' AND inv IS NULL");
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	//create storage containers: vectors
	vector<int> bookIds;
	vector<int> quantities; 

	//store the results in the vectors
	while (res->next())
	{
		bookIds.push_back(res->getInt("book_id"));
		quantities.push_back(res->getInt("quantity"));
	}
	delete pstmt;
	
	//update purchases
	pstmt = con->prepareStatement("UPDATE purchases SET inv = 1 WHERE received = 'T' AND inv IS NULL");
	pstmt->executeUpdate();
	delete pstmt;

	//update the quantity left in the books table
	for (size_t i = 0;  i < bookIds.size();  ++i)
	{
		pstmt = con->prepareStatement("UPDATE books SET quantity = quantity - ? WHERE id = ?");
		pstmt->setInt(1, quantities[i]);
		pstmt->setInt(2, bookIds[i]);
		pstmt->executeUpdate();
		
	}
	cout << "Orders received have been updated" << endl; 
	delete pstmt;
	delete res; 

};
void books::display(sql::Connection* con) {
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM books");
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	while (res->next()) {
		cout << "Book id: " << res->getInt("id") << endl;
		cout << "Book name: " << res->getString("name") << endl;
		cout << "Book auhtor: " << res->getString("author") << endl;
		cout << "Book price: " << res->getInt("price") << endl;
		cout << "Book quantity: " << res->getInt("quantity") << endl;
		cout <<"--------------------------------------------------"<<endl;
		cout << endl; 
	}

	delete pstmt;
	delete res;
};