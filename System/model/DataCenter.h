#pragma once
#include "Server.h"
#include "Rack.h"
#include "NetworkDevice.h"
#include "StorageDevice.h"

struct DataCenter
{
    Rack** rack;
    int rackHitung;

    DataCenter();
    ~DataCenter();

    void Init(int nomRack);
};
