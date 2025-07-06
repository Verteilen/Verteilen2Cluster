#include "Database.h"

#include <cstdio>
#include <functional>

namespace vertelien2 {
    Database::Database(const char* _filename) {
        filename = (char*)_filename;
        vaild = sqlite3_open(filename, &db) == SQLITE_OK;
        self = std::make_shared<Database>(*this);
        job = Database_Job(self);
    }

    Database::~Database() {
        sqlite3_close(db);
    }

    void Database::TableCheck() {
        ProjectTable();
        TaskTable();
        JobTable();
    }

    bool Database::isVaild() {
        return vaild;
    }

    const char* Database::ErrorMessage() {
        return sqlite3_errmsg(db);
    }

    bool Database::ProjectTable() {
        char* msg{};
        bool r = true;
        if (r) {
            fprintf(stdout, "Project table created successfully\n");
        }else {
            fprintf(stdout, "Project table created failed %s\n", msg);
        }
        return r;
    }

    bool Database::TaskTable() {
        char* msg{};
        bool r = true;
        if (r) {
            fprintf(stdout, "Task table created successfully\n");
        }else {
            fprintf(stdout, "Task table created failed %s\n", msg);
        }
        return r;
    }

    bool Database::JobTable() {
        const char* sql = "CREATE TABLE JOB(" \
        "UUID CHAR(36) PRIMARY KEY NOT NULL,"\
        "CATEGORY INTEGER NOT NULL,"\
        "SUBCATEGORY INTEGER NOT NULL,"\
        "SCRIPT TEXT,"\
        "ARGUMENT BLOB"\
        ");";
        char* msg{};
        bool r = sqlite3_exec(db, sql, &Database::callback, NULL, &msg) == SQLITE_OK;
        if (r){
            fprintf(stdout, "Job table created successfully\n");
            sqlite3_free(msg);
        }else {
            fprintf(stdout, "Job table created failed %s\n", msg);
        }
        return r;
    }

    int Database::callback(void *NotUsed, int argc, char **argv, char **azColName) {
        int i;
        for(i = 0; i<argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }
}
