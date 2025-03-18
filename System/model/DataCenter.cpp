#include "DataCenter.h"
#include <cstdlib>

DataCenter::DataCenter()
{
    rack = nullptr;
    TotalRack = 0;
}

DataCenter::~DataCenter()
{
    if(rack)
    {
        for (int i = 0; i < TotalRack; i++)
        {
            delete rack[i];
        }
        delete[] rack;
    }

    for (auto& device : networkdevice)
    {
        delete device;
    }

    for (auto& device : storagedevice)
    {
        delete device;
    }
}

void DataCenter::Init(int nomRack)
{
    TotalRack = nomRack;
    rack = new Rack*[TotalRack];
    for (int i = 0; i < TotalRack; i++)
    {
        rack[i] = new Rack();
    }
}

void DataCenter::TambahRack(int posisi, Rack* RackBaru)
{
    if (posisi >= 0 && posisi < TotalRack)
    {
        if (rack[posisi])
        {
            delete rack[posisi];
        }
        rack[posisi] = RackBaru;
    }
}

Rack* DataCenter::PanggilRack(int posisi) const
{
    if (posisi >= 0 && posisi < TotalRack)
    {
        return rack[posisi];
    }
    return nullptr;
}

void DataCenter::TambahNetworkDevice(NetworkDevice* device)
{
    networkdevice.push_back(device);
}

void DataCenter::TambahStorageDevice(StorageDevice* device)
{
    storagedevice.push_back(device);
}