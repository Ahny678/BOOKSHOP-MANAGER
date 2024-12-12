#include "employee.h"
#include <iostream>
#include "main.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <string>

using namespace std;


void employee::add_emp(sql::Connection* con) {
	cout << "Ener your ID for verification: ";
	cin >> emp_id; 

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT mgr_status FROM employees WHERE emp_id = ?");
	pstmt->setInt(1, emp_id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

		delete pstmt; 

	if (!res->next() ) {
		cout << "Id does not exists!" << endl; 
	}

	else {		
			mgr_status = res->getString("mgr_status");
			delete res;
		

			if (mgr_status[0] == 'F') { //the only way to comapre a string with a chacter
				cout << "You do not have manager rights!!!" << endl;
				return; 
			}

			else {
				int year, month, day; 
				cout << "Enter the details of new employee" << endl; 
				cout << "Employee name: ";
				cin.ignore();
				getline(cin>>ws, name);
				cout << "Employee address: ";
				cin.ignore();
				getline(cin>>ws, address);
				cout << "Enter city: ";
				getline(cin>>ws, city);
				cout << "Employee phone numebr: ";
				cin >> phn;
				cout << "Date of joining. Enter the year: ";
				cin >> year;
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter day: ";
				cin >> day;
				cout << "Employee salary: ";
				cin >> salary;
				date_of_joining = formatDate(year, month, day); 
				
				pstmt = con->prepareStatement("INSERT INTO employees (name, address, city, phone_number, date_of_joining, salary) VALUES (?, ?, ?, ?, ?, ?)");
				pstmt->setString(1, name);
				pstmt->setString(2, address);
				pstmt->setString(3, city);
				pstmt->setInt(4, phn);
				pstmt->setString(5, date_of_joining);
				pstmt->setInt(6, salary);
				
				res = pstmt->executeQuery();
				cout << "Employee addded successfully!" << endl; 
				delete pstmt;
				delete res; 

		}
		
	}

};

void employee::assign_mgr_state(sql::Connection* con) {
	cout << "Ener your ID for verification: ";
	cin >> emp_id;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT mgr_status FROM employees WHERE emp_id = ?");
	pstmt->setInt(1, emp_id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();

	delete pstmt;

	if (!res->next()) {
		cout << "Id does not exists!" << endl;
	}

	else {
		mgr_status = res->getString("mgr_status");
		delete res;


		if (mgr_status[0] == 'F') {
			cout << "You do not have manager rights!!!" << endl;
			return;
		}

		else {
			cout << "Enter employee id to grant manager status" << endl;
			cin >> emp_id;

			pstmt = con->prepareStatement("UPDATE employees SET mgr_status = 'T' WHERE emp_id = ?");
			pstmt->setInt(1, emp_id);
			res = pstmt->executeQuery();
			delete pstmt;
			delete res;

			cout << "Employee's manager status updated!" << endl;

		}
	}
};


void employee::search_emp(sql::Connection* con) {
	cout << "Enter employee id" << endl;
	cin >> emp_id;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM employees WHERE emp_id = ?");

	pstmt->setInt(1, emp_id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();


	if (!res->next()) {
		cout << "No such id exists" << endl; 
		return;
	}
	else {
			cout << "Nmme " << res->getString("name") << endl;
			cout << "Address:: " << res->getString("address") << endl;
			cout << "City:: " << res->getInt("city") << endl;
			cout << "Phone Number: " << res->getInt("phone_number") << endl;
			cout << "date of joining: " << res->getString("date_of_joining") << endl;
			cout << "salary: " << res->getInt("salary") << endl;
			cout << "manager status: " << res->getInt("mgr_status") << endl;
	}
	delete res;
	delete pstmt;

};


void employee::display(sql::Connection* con) {
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM employees");
	sql::ResultSet* res;
	res = pstmt->executeQuery();


	 while(res->next()){
		 cout << "Id: " << res->getInt("emp_id") << endl; 
		 cout << "Nmme " << res->getString("name") << endl;
		 cout << "Address:: " << res->getString("address") << endl;
		 cout << "City:: " << res->getString("city") << endl;
		 cout << "Phone Number: " << res->getInt("phone_number") << endl;
		 cout << "date of joining: " << res->getString("date_of_joining") << endl;
		 cout << "salary: " << res->getInt("salary") << endl;
		 cout << "manager status: " << res->getString("mgr_status") << endl;
		 cout << "-------------------------------------------" << endl;
		 cout << endl; 
	}
	
	delete res;
	delete pstmt;
};

void employee::update_sal(sql::Connection* con) {
	cout << "Enter the employee id to update salary" << endl; 
	cin >> emp_id; 
	cout << "Enter the updated salary " << endl;
	cin >> salary; 

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT emp_id FROM employees WHERE emp_id = ?");
	pstmt->setInt(1, emp_id);
	sql::ResultSet* res;
	res = pstmt->executeQuery();
	delete pstmt; 
	if (!res->next()) {
		cout << "No such id exists" << endl; 
		return; 
	}
	else {
		pstmt = con->prepareStatement("UPDATE employees SET salary = ? WHERE emp_id = ?");
		pstmt->setInt(1, salary);
		pstmt->setInt(2, emp_id);
		delete res;
		res = pstmt->executeQuery();
		cout << "Salary updated successfully!" << endl;
	}
	delete res;
	delete pstmt; 
	
	
	
	
};
