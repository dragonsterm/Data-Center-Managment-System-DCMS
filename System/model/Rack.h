#pragma once
#include "Server.h"

struct Rack
{
    Server** server;
    int serverHitung;

    Rack();
    ~Rack();

    void Init(int nomServer);
};
