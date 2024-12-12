
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>

#include "menus.h"
#include "books.h"
using namespace std;

//CONNECTION FUNCTION

sql::Connection* createConnection() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://localhost:3306",
        "root", "MYSQLROOTPASS");  //TO CONNECT TO DATABASE

    con->setSchema("db1test"); // your database name 
    return con; 

}

//function to format date
string formatDate(int year, int month, int day) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return string(buffer);
}

//TEMPLATE FOR A QUERY FUNCTION
void funcName(sql::Connection* con, const int id, const string name) {
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("INSERT INTO db1test.employees (id, name) VALUES (?, ?)");
    pstmt->setInt(1, id);
    pstmt->setString(2, name);

    pstmt->executeUpdate();
    delete pstmt;
}

//TEMPLATE FOR FETCHING
void funcName2(sql::Connection* con) {
    sql::Statement* stmt;
    sql::ResultSet* res; 

    stmt = con->createStatement();
    string selectDataSQL = " "; //The select query
    res = stmt->executeQuery(selectDataSQL); 
    // Loop through the result set and display data 

    while (res->next()) {
        cout << " Course " <<  ": " <<res->getInt ("id")
            << res->getString("courses") << endl;
    }
    delete res;  delete stmt;  

}

//PASSWORD FUNCTION
void pass() {

};


int main(){
   
    main_menu();

    /*
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        
        delete con;  
    }

   catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }

    */
    


    return 0;
}
