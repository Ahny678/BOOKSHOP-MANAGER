#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include<string>
using namespace std; 

sql::Connection* createConnection();
string formatDate(int year, int month, int day);
#endif // !MAIN_H
