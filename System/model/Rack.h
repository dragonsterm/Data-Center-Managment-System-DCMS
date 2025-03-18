#pragma once
#include "Server.h"

struct Rack
{
    Server** server;
    int TotalServer;

    Rack();
    ~Rack();

    void Init(int nomServer);

    void TambahServer(int posisi, Server* ServerBaru);

    Server* PanggilServer(int posisi);
};
