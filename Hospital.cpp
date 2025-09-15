//
// Created by berke on 9/15/2025.
//
#include "Hospital.h"

Hospital::Hospital() {
    std::string sqlQuery = "CREATE TABLE IF NOT EXISTS Hospitals("
                           "hospital_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                           "name VARCHAR(100) NOT NULL,"
                           "type VARCHAR(50)" // Private, Public or University
                           "city VARCHAR(50) NOT NULL,"
    "district VARCHAR(50) NOT NULL,"
    "address TEXT,"
    "phone_number VARCHAR(15)"
    "patient_capacity INTEGER";
}
