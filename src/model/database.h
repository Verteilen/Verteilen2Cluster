#pragma once
#include <sqlite3.h>

namespace vertelien2 {
    struct database {
        database();
        ~database();

        void TableCheck();
        bool isVaild();
        const char* ErrorMessage();
    private:
        sqlite3 *db;
        bool vaild;

        void ProjectTable();
        void TaskTable();
        void JobTable();
    };
}