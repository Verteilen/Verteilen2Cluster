#pragma once
#include <memory>

#include <data/job.h>

namespace vertelien2 {
    struct Database;

    struct Database_Job {
        Database_Job();
        Database_Job(std::weak_ptr<Database> data);
        ~Database_Job();

        bool Add(Job& job);
        bool Update(Job& job);
        bool Remove(Job& job);
        bool Remove(char uuid[36]);

    private:
        std::weak_ptr<Database> db;
    };
}
