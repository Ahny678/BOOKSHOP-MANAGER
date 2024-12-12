#include "suppliers.h"
#include <iostream>
#include "main.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
using namespace std; 

void suppliers::add_sup(sql::Connection* con) {
	cout << "Enter supplier name: ";
	cin.ignore();
	getline(cin>>ws, name); 
	cout << "Enter phone no.: ";
	cin >> phn;
	cout << "Enter address: ";
	cin.ignore();
	getline(cin>>ws, address);
	cout << "Enter city:";
	cin.ignore();
	getline(cin>>ws, city);
	cout << "Enterr state: ";
	cin.ignore();
	getline(cin, state);
	
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO db1test.suppliers ( name, phonenumber, address, city, state) VALUES (?, ?, ?, ?, ?)");
	pstmt->setString(1, name);
	pstmt->setInt(2, phn);
	pstmt->setString(3, address);
	pstmt->setString(4, city);
	pstmt->setString(5, state);



	pstmt->executeUpdate();
	cout << "Supplier added succesfully!" << endl;
	delete pstmt;
};

void suppliers::remove_sup(sql::Connection* con) {
	cout << "Enter the id of the supplier to be removed: ";
	cin >> id; 

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("DELETE FROM db1test.suppliers WHERE sup_id = ? ");
	pstmt->setInt(1, id);



	pstmt->executeUpdate();
	cout << "Supplier deleted succesfully!" << endl;
	delete pstmt;

};
void suppliers::search_id(sql::Connection* con) {
	cout << "Input id for supplier details: ";
	cin >> id; 

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM suppliers WHERE sup_id = ?");
	pstmt->setInt(1, id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	if (res->next()) {
		cout << "Suppliers id: " << res->getInt("sup_id") << endl;
		cout << "Suppliers name: " << res->getString("name") << endl;
		cout << "Suppliers phone numberr: " << res->getInt("phonenumber") << endl;
		cout << "Suppliers adress: " << res->getString("address") << endl;
		cout << "Suppliers city: " << res->getString("city") << endl;
		cout << "Suppliers stat: " << res->getString("state") << endl;
	}

	else {
		cout << "id does not exist" << endl;
		return;
	}
	delete res;
	delete pstmt;
};