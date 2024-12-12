#ifndef EMPLOYEE_H
#define EMPLOYEE
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>
using namespace std;

class employee {
public:
	int emp_id; //primary key
	string name;
	string address; 
	string city;
	string state;
	int phn; 
	string date_of_joining; 
	int salary;
	string mgr_status; // def f. check T or F

	//functios;
	void add_emp(sql::Connection* con);
	void assign_mgr_state(sql::Connection* con);
	void search_emp(sql::Connection* con);
	void display(sql::Connection* con);
	void update_sal(sql::Connection* con);
	

};
#endif // !EMPLOYEE_H 
