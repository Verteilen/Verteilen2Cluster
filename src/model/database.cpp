#include "database.h"

namespace vertelien2 {
    database::database() {
        vaild = sqlite3_open("database.db", &db) == 0;
    }

    database::~database() {
        sqlite3_close(db);
    }

    void database::TableCheck() {
        ProjectTable();
        TaskTable();
        JobTable();
    }

    bool database::isVaild() {
        return vaild;
    }

    const char* database::ErrorMessage() {
        return sqlite3_errmsg(db);
    }

    void database::ProjectTable() {
    }

    void database::TaskTable() {
    }

    void database::JobTable() {
        const char* sql = "CREATE TABLE JOB(" \
        "UUID CHAR(36) PRIMARY KEY NOT NULL ASC,"\
        ""\
        ");";
    }
}
