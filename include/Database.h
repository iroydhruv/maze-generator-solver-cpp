#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database
{
private:
    sqlite3* db;

public:
    Database(const std::string& dbName);
    ~Database();

    bool connect();
    void createTable();

    void saveMaze(
        const std::string& mazeName,
        const std::string& mazeData
    );

    void loadMazes();

    void close();
};

#endif