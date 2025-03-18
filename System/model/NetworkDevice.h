#pragma once
#include <string>

struct NetworkDevice
{
    int Id;
    std::string Type;
    std::string Ip;
    int ConnectedDevice;

    NetworkDevice();
    void SetId(int id) { Id = id; }
    void SetType(const std::string& type) { Type = type; }
    void SetIp(const std::string& ip) { Ip = ip; }
    void SetConnectedDevice(int id) { ConnectedDevice = id; }

    void connect(NetworkDevice* device);
};
