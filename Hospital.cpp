#include "Hospital.h"
#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

Hospital::Hospital(const std::string& id, const std::string& name, 
                  const std::string& type, const std::string& city, 
                  const std::string& district, const std::string& address,
                  const std::string& phone_number, int capacity)
    : hospital_id(id), hospital_name(name), hospital_type(type),
      city(city), district(district), address(address),
      phone_number(phone_number), patient_capacity(capacity), db(nullptr)
{
    rc = sqlite3_open("hospital.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        db = nullptr;
        throw std::runtime_error("Can't open database");
    }
    createTable(); // Tabloyu otomatik oluştur
}

Hospital::~Hospital() {
    if (db) {
        sqlite3_close(db);
    }
}

void Hospital::createTable() {
    const char* createQuery = 
        "CREATE TABLE IF NOT EXISTS Hospital("
        "hospital_id TEXT PRIMARY KEY, "
        "name VARCHAR(100) NOT NULL, "
        "type VARCHAR(50), "  // Private, Public or University
        "city VARCHAR(50) NOT NULL, "
        "district VARCHAR(50) NOT NULL, "
        "address TEXT, "
        "phone_number VARCHAR(15), "
        "patient_capacity INTEGER);";  // Eksik virgüller ve noktalı virgül eklendi

    char* errorMessage = nullptr;
    rc = sqlite3_exec(db, createQuery, nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
}

void Hospital::insertItem() {
    sqlite3_stmt* stmt = nullptr;
    const char* insertSQL =
        "INSERT INTO Hospital (hospital_id, name, type, city, district, address, phone_number, patient_capacity) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?);";  // Sütun ismi düzeltildi ve parametre sayısı eşitlendi

    rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL prepare error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Parametreleri bağla (1'den başlayarak)
    sqlite3_bind_text(stmt, 1, hospital_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hospital_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, hospital_type.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, city.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, district.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, address.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 8, patient_capacity);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "SQL execution error: " << sqlite3_errmsg(db) << std::endl;
    }
    
    sqlite3_finalize(stmt);
}