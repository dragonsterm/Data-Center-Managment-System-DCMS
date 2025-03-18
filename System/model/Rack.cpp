#include "Rack.h"
#include <cstdlib>

Rack::Rack()
{

    server = nullptr;
    TotalServer = 0;
}

Rack::~Rack()
{
    if (server) {
        for (int i = 0; i < TotalServer; i++)
        {
            delete server[i];
        }
    }
}

void Rack::Init(int nomServer)
{
    TotalServer = nomServer;
    server = new Server*[TotalServer];

    for (int i = 0; i < TotalServer; i++)
    {
        server[i] = new Server();
    }
}

void Rack::TambahServer(int posisi, Server* ServerBaru)
{
    if (posisi >= 0 && posisi < TotalServer)
    {
        if (server[posisi])
        {
            delete server[posisi];
        }
        server[posisi] = ServerBaru;
    }
}

Server* Rack::PanggilServer(int posisi)
{
    if (posisi >= 0 && posisi < TotalServer)
    {
        return server[posisi];
    }
    return nullptr;
}