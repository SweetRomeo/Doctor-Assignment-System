//
// Created by berke on 9/15/2025.
//

#ifndef DATABASEAPP_HOSPITALCHOICE_H
#define DATABASEAPP_HOSPITALCHOICE_H
#include "sqlite3.h"
#include <string>

class Hospital {
public:
    Hospital() = default;

    Hospital(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
             const std::string &, const std::string &, int);
    ~Hospital();

    void createTable();

    void insertItem();

private:
    sqlite3 *db;
    int rc;
    std::string hospital_id;
    std::string hospital_name;
    std::string hospital_phone_number;
    std::string hospital_type;
    std::string city;
    std::string district;
    std::string address;
    std::string phone_number;
    int patient_capacity;
};
#endif //DATABASEAPP_HOSPITALCHOICE_H
