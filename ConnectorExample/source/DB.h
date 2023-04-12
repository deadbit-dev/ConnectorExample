#pragma once

#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>

using namespace std;

class DB {
    sql::Driver* driver;
    sql::Connection* connection;

public:
    DB(const char* host, const char* user, const char* password, const char* database);
    ~DB();

    sql::PreparedStatement* prepare(const char* sql);
};