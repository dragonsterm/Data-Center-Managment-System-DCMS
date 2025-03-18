#include "Server.h"

Server::Server()
{
    id = 0;
    NamaServer = "";
    Ip = "";
    CpuUsage = 0.0;
    RamUsage = 0.0;
    status = true;
}

double Server::HitungPenggunaan() const
{
    return CpuUsage + RamUsage;
}

bool Server::CekStatus() const
{
    return status;
}