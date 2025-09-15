#include <iostream>
#include <sqlite3.h>

#include "Hospital.h"

int main()
{
    Hospital* hospital = new Hospital("HOSP001", "Istanbul Cam ve Sakura", "Devlet", "Istanbul", "Basaksehir", "Merkez Efendi Mahallesi",
        "0238112829", 500);
    hospital->createTable();
    hospital->insertItem();
    return 0;
}
