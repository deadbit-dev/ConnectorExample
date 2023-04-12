#include "DB.h"

DB::DB(const char* host, const char* user, const char* password, const char* database) {
    driver = get_driver_instance();
    connection = driver->connect(host, user, password);
    connection->setSchema(database);
}

DB::~DB() {
    delete connection;
}

sql::PreparedStatement* DB::prepare(const char* sql) {
    return connection->prepareStatement(sql);
}