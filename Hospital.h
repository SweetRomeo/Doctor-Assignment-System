//
// Created by berke on 9/15/2025.
//

#ifndef DATABASEAPP_HOSPITALCHOICE_H
#define DATABASEAPP_HOSPITALCHOICE_H
#include "sqlite3.h"
#include <string>

class Hospital {
    public:
    Hospital();
    ~Hospital();
private:
    sqlite3 *db;
};
#endif //DATABASEAPP_HOSPITALCHOICE_H