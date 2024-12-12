#include "members.h"
#include <iostream>
#include "main.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <string>
#include <memory>

using namespace std;

void members::add_mem(sql::Connection* con) {

	cout << "Enter details of the new members: "<<endl;
	cout << "Member name: ";
	cin.ignore();
	getline(cin >> ws, name);
	cout << "Member address: ";
	cin.ignore();
	getline(cin >> ws, address);
	cout << "Employee phone numebr: ";
	cin >> phn;
	cout << "Enter city: ";
	cin.ignore();
	getline(cin >> ws, city);
	cout << "Enter state: ";
	cin.ignore();
	getline(cin >> ws, state);
	cout << "Enter how many years member will be with us: ";
	int interval;
	cin >> interval; 
	
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO db1test.members (name, address, city, state, phone_number, beg_date, end_date) VALUES (?, ?, ?, ?, ?, CURDATE(), DATE_ADD(CURDATE(), INTERVAL ? YEAR))");
	pstmt->setString(1, name);
	pstmt->setString(2, address);
	pstmt->setString(3, city);
	pstmt->setString(4, state);
	pstmt->setInt(5, phn);
	pstmt->setInt(6, interval);



	pstmt->executeUpdate();
	cout << "New Memebr added!" << endl;
	delete pstmt;
	

	
	


};

void members::refresh(sql::Connection* con) {
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE db1test.members SET status ='invalid' WHERE CURDATE()>= end_date");
	pstmt->executeUpdate();
	cout << "All Member Status Refreshed!!" << endl;
	delete pstmt;
};

void members::search_mem(sql::Connection* con) {
	cout << "Enter member id: "; 
	cin >> mem_id; 

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM members WHERE id = ?");

	pstmt->setInt(1, mem_id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	if (!res->next()) {
		cout << "no such member exists in records" << endl; 
		return; 
	}
	else{
		cout << "Nmme " << res->getString("name") << endl;
		cout << "Address:: " << res->getString("address") << endl;
		cout << "City:: " << res->getString("city") << endl;
		cout << "Phone Number: " << res->getInt("phone_number") << endl;
		cout << "date of start: " << res->getString("beg_date") << endl;
		cout << "end date: " << res->getString("end_date") << endl;
		cout << " status: " << res->getString("status") << endl;
	}
	cout << endl;

	delete res;
	delete pstmt;

};
