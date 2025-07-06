#include "Job.h"

#include "Database.h"

namespace vertelien2 {
    Database_Job::Database_Job() {
    }

    Database_Job::Database_Job(std::weak_ptr<Database> data) {
        db = data;
    }

    Database_Job::~Database_Job() {
    }

    bool Database_Job::Add(Job& job) {
        const char* sql = "INSERT INTO JOB (UUID,CATEGORY,SUBCATEGORY) "  \
         "VALUES ('TEST', 1, 1); ";
        char* msg{};
        bool r = sqlite3_exec(db.lock().get()->db, sql, Database::callback, NULL, &msg) == SQLITE_OK;
        if (r){
            fprintf(stdout, "Job data created successfully\n");
            sqlite3_free(msg);
        }else {
            fprintf(stdout, "Job data created failed %s\n", msg);
        }
        return true;
    }

    bool Database_Job::Update(Job& job) {
        return true;
    }

    bool Database_Job::Remove(Job& job) {
        return true;
    }

    bool Database_Job::Remove(char uuid[36]) {
        return true;
    }
}
