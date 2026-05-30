#include "Database.h"

#include <iostream>

Database::Database(const std::string& dbName)
{
    sqlite3_open(dbName.c_str(), &db);
}

Database::~Database()
{
    close();
}

bool Database::connect()
{
    return db != nullptr;
}

void Database::createTable()
{
    const char* sql =
        "CREATE TABLE IF NOT EXISTS mazes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "data TEXT);";

    char* error = nullptr;

    sqlite3_exec(db, sql, nullptr, nullptr, &error);
}

void Database::saveMaze(
    const std::string& mazeName,
    const std::string& mazeData)
{
    std::string sql =
        "INSERT INTO mazes(name,data) VALUES('"
        + mazeName +
        "','" +
        mazeData +
        "');";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

void Database::loadMazes()
{
    std::cout << "\nMaze loading feature ready.\n";
}

void Database::close()
{
    if (db)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}