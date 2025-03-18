#include <NetworkDevice.h>

NetworkDevice::NetworkDevice()
{
    Id = 0;
    Type = "";
    Ip = "";
    ConnectedDevice = -1;
}

void NetworkDevice::connect(NetworkDevice* device)
{
    if (device)
    {
        ConnectedDevice = device->Id;
    }   
}