#include <cstdio>
#include <sqlite3.h>

int main(){
    sqlite3 *db;
    const int rc = sqlite3_open("database.db", &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
    return 0;
}