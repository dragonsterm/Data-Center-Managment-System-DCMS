#pragma once
#include <string>

struct NetworkDevice
{
    int Id;
    std::string Type;
    std::string Ip;
    NetworkDevice* networkdevice;

    NetworkDevice();
    void connect(NetworkDevice* device);
};
