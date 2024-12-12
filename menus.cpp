#include "menus.h"
#include "main.h"
#include "books.h"
#include "purchases.h"
#include "suppliers.h"
#include "employee.h"
#include "members.h"
#include "sales.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <conio.h>
using namespace std; 

void main_menu() {
    int option;
  
        cout << "BOOKSHOP MANAGEMENT SYSTEM" << endl;
        cout << "1, BOOKS" << endl;
        cout << "2, SUPPLIERS" << endl;
        cout << "3, PURCHASES" << endl;
        cout << "4, EMPLOYEES" << endl;
        cout << "5, MEMEBERS" << endl;
        cout << "6, SALES" << endl;
        cout << "7, EXIT" << endl;

        cin >> option;
        switch (option) {
        case 1:
            system("cls");
            book_menu();
            _getch();
            break;

        case 2:
            system("cls");
            sup_menu();
            _getch();
            break;

        case 3:
            system("cls");
            pur_menu();
            _getch();
            break;

        case 4:
            system("cls");
            emp_menu();
            _getch();
            break;

        case 5:
            system("cls");
            mem_menu();
            _getch();
            break;

        case 6:
            system("cls");
            sal_menu();
            _getch();
            break;

        case 7:
            exit(1);

        default:
            system("cls");
            cout << "invalid input" << endl;
            _getch();
            break;
        }
        return;
  
};
void book_menu() {
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        //THE SWITCH CASES
        int option;
        do {
            
            books b;
            cout << "BOOKS MENU7" << endl;
            cout << "1, ADD" << endl;
            cout << "2, UPDATE PRICE" << endl;
            cout << "3, SEARCH" << endl;
            cout << "4, UPDATE STATUS" << endl;
            cout << "5, DISPLAY ALL" << endl;
            cout << "6, RETURN TO MAIN MENU" << endl;
            cout << "7, Clear Screen()" << endl;

            cin >> option;
            switch (option) {
            case 1:
                b.add(con);
                break;

            case 2:
                b.update_price(con);
                break;

            case 3:
                b.search(con);
                break;

            case 4:
                b.update(con);
                break;

            case 5:
                b.display(con);
                break;

            case 6:
                return;
               

            case 7:
                system("cls"); 
                break;
            };
        } while (option != 0); 
       
        
        delete con;
    }

    catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }

};

void pur_menu() {
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        //THE SWITCH CASES
        int option;
        do {

           purchase p;
            cout << "PURCHASES MENU" << endl;
            cout << "1, NEW ORDER" << endl;
            cout << "2, VIEW ALL" << endl;
            cout << "3, CANCEL ORDER" << endl;
            cout << "4, RECEIVED ORDER" << endl;
            cout << "5, RETURN TO MAIN MENU" << endl;
            cout << "6, Clear Screen()" << endl;

            cin >> option;
            switch (option) {
            case 1:
                p.new_order(con);
                break;

            case 2:
                p.view(con);
                break;

            case 3:
                p.mark_cancelled(con); 
                break;

            case 4:
                p.mark_received(con);
                break;

            case 5:
                return;

            case 6:
                system("cls");
                break;
            default:
                cout << "invalid number" << endl;
            };
        } while (option != 0);


        delete con;
    }

    catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }

};

void sup_menu() {
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        //THE SWITCH CASES
        int option;
        do {

            suppliers s; 
            cout << "SUPPLIERS MENU" << endl;
            cout << "1, ADD" << endl;
            cout << "2, REMOVE" << endl;
            cout << "3, SEARCH" << endl;
            cout << "4, RETURN TO MAIN MENU" << endl;
            
            cin >> option;
            switch (option) {
            case 1:
                s.add_sup(con);
                break;

            case 2:
                s.remove_sup(con);
                break;

            case 3:
                s.search_id(con);
                break;

            case 4:
                return;
            default:
                cout << "wrong input" << endl;
                break; 

            };

        } while (option != 0);


        delete con;
    }

    catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }

};

void emp_menu() {
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        //THE SWITCH CASES
        int option;
        do {
            employee e;
            cout << "EMPLOYEE MENU" << endl;
            cout << "1, ADD EMPLOYEE" << endl;
            cout << "2, SEARCH EMPLOYEE" << endl;
            cout << "3, ASSIGN MANAGER" << endl;
            cout << "4, VIEW ALL" << endl;
            cout << "5, UPDATE SALARY" << endl;
            cout << "6, RETURN TO MAIN MENU" << endl;

            cin >> option;
            switch (option) {
            case 1:
                e.add_emp(con);
                break;

            case 2:
                e.search_emp(con);
                break;

            case 3:
                e.assign_mgr_state(con);
                break;

            case 4:
                e.display(con); 
                break;

            case 5:
                e.update_sal(con);
                break; 
            default:
                cout << "wrong input" << endl;
                break;

            };

        } while (option != 0);


        delete con;
    }

    catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }

};

void mem_menu() {
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        //THE SWITCH CASES
        int option;
        do {
            members m; 
            cout << "MEMBERS MENU" << endl;
            cout << "1, NEW MEMBER" << endl;
            cout << "2, SEARCH MEMBER" << endl;
            cout << "3, REFRESH" << endl;
            cout << "4, RETURN TO MAIN MENU" << endl;

            cin >> option;
            switch (option) {
            case 1:
                m.add_mem(con); 
                break;

            case 2:
                m.search_mem(con); 
                break;

            case 3:
                m.refresh(con);
                break;

            case 4:
                return; 

     
            default:
                cout << "wrong input" << endl;
                break;

            };

        } while (option != 0);


        delete con;
    }

    catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }


};



void sal_menu() {
    try {
        sql::Connection* con = createConnection();
        //CODE AND FUNCTION CALLS
        //THE SWITCH CASES
        int option;
        do {
            sales s;
            cout << "SALES MENU" << endl;
            cout << "1, ADD SALES" << endl;
            cout << "2, TOTAL SALES" << endl;
            cout << "3, RETURN TO MAIN MENU" << endl;

            cin >> option;
            switch (option) {
            case 1:
                s.add(con);
                break;

            case 2:
                s.find_total_sales(con);
                break;


            case 3:
                return;


            default:
                cout << "wrong input" << endl;
                break;

            };

        } while (option != 0);


        delete con;
    }

    catch (sql::SQLException& e) {

        std::cerr << "SQL Error: " << e.what() << std::endl;

    }


};

