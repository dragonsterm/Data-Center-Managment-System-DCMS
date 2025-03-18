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

    void SetId(int IdBaru) { id = IdBaru; }
    void SetNamaServer(const std::string& nama) { NamaServer = nama; }
    void SetIp(const std::string& ip) { Ip = ip; }
    void SetCpuUsage(double cpu) { CpuUsage = cpu; }
    void SetRamUsage(double ram) { RamUsage = ram; }
    void SetStatus(bool stats) { status = stats; }
};
