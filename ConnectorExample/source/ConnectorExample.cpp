#include <iostream>
#include "DB.h"

int main()
{
    try
    {
        DB db("localhost", "root", "password", "database");

        sql::PreparedStatement* preparedStatement = db.prepare("SELECT * FROM users WHERE name = ?");
        preparedStatement->setString(1, "John");
        sql::ResultSet* result = preparedStatement->executeQuery();

        while (result->next()) {
            cout << result->getString(1) << ", " << result->getString(2) << endl;
        }

        delete result;
        delete preparedStatement;
    }
    catch (...) 
    {
        cout << "[ERROR] Catch some exception before close programm!";
    }
}