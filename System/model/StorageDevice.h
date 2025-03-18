#pragma once
#include <string>

struct StorageDevice 
{
    int id;
    std::string NamaStorage;
    double Penyimpanan; 

    StorageDevice();

    void SetId (int idBaru) { id = idBaru; }
    void SetNamaStorage(const std::string& nama) { NamaStorage = nama; }
    void SetPenyimpanan(double kapasitas) { Penyimpanan = kapasitas; }
};