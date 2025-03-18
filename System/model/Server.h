#pragma once
#include <string>

struct Server
{
    int id;
    std::string NamaServer;
    std::string Ip;
    double CpuUsage;
    double RamUsage;
    bool status;

    Server();
    double HitungPenggunaan() const;
    bool CekStatus() const;
};
