#include "model/Database.h"

int main(){
    vertelien2::Database db;
    db.TableCheck();
    vertelien2::Job job = vertelien2::Job();
    db.job.Add(job);
    return 0;
}
