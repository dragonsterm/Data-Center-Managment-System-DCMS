#pragma once
#include "Server.h"
#include "Rack.h"
#include "NetworkDevice.h"
#include "StorageDevice.h"
#include <vector>

struct DataCenter
{
    Rack** rack;
    int TotalRack;
    std::vector<NetworkDevice*> networkdevice;
    std::vector<StorageDevice*> storagedevice;

    DataCenter();
    ~DataCenter();

    void Init(int nomRack);

    void TambahRack(int posisi, Rack* RackBaru);

    Rack* PanggilRack(int posisi) const;
    
    void TambahNetworkDevice(NetworkDevice* device);

    void TambahStorageDevice(StorageDevice* device);
};
