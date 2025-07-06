#pragma once
#include <sqlite3.h>

#include "Job.h"

namespace vertelien2 {
    struct Database {
        friend Database_Job;
        Database_Job job;

        Database(const char* _filename = "database.db");
        ~Database();

        void TableCheck();
        bool isVaild();
        const char* ErrorMessage();
    private:
        char* filename;
        sqlite3 *db{};
        bool vaild;
        std::shared_ptr<Database> self;

        bool ProjectTable();
        bool TaskTable();
        bool JobTable();

        static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    };
}
