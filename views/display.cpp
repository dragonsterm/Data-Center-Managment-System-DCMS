#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "display.h"

// Data masih Static atau data yang di set display.cpp masih WIP.
// Akan dirubah untuk Versi Berikut
// Mungkin Format Tabel bisa lebih bagus dalam implementasi coding nya agar lebih fleksibel

Display::Display() {
    // Konstruktor
}

Display::~Display() {
    // Destruktor
}

void Display::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Display::displayHeader(const std::string& title) {
    drawHorizontalLine(tableWidth);
    centerText(title, tableWidth);
    drawHorizontalLine(tableWidth);
}

void Display::displayFooter(const std::string& message) {
    drawHorizontalLine(tableWidth);
    if (!message.empty()) {
        std::cout << message << std::endl;
    }
    std::cout << std::endl;
}

void Display::drawHorizontalLine(int width) {
    std::cout << cornerChar;
    for (int i = 0; i < width - 2; i++) {
        std::cout << horizontalLine;
    }
    std::cout << cornerChar << std::endl;
}

void Display::centerText(const std::string& text, int width) {
    int padding = (width - text.length()) / 2;
    std::cout << verticalLine << std::string(padding - 1, ' ') << text;
    int remaining = width - text.length() - padding - 1;
    std::cout << std::string(remaining, ' ') << verticalLine << std::endl;
}

void Display::displayServerTable() {
    tableWidth = 83;
    
    displayHeader("DAFTAR SERVER");
    
    // Header
    std::cout << verticalLine << " ID   " 
              << verticalLine << " Nama Server      " 
              << verticalLine << " IP Address     " 
              << verticalLine << " CPU Usage  "
              << verticalLine << " RAM Usage   "
              << verticalLine << " Status    "
              << verticalLine << std::endl;
              
    drawHorizontalLine(tableWidth);

    struct StaticServerInfo {
        int id;
        std::string name;
        std::string ip;
        int cpuUsage;
        int ramGB;
        bool online;
    };
    
    StaticServerInfo servers[] = {
        {1, "Web Server", "192.168.74.102", 75, 8, true},
        {2, "Database Server", "192.168.64.1", 10, 4, false}
    };
    
    for (const auto& server : servers) {
        std::cout << verticalLine << " " << std::left << std::setw(4) << server.id << " "
                  << verticalLine << " " << std::left << std::setw(16) << server.name << " "
                  << verticalLine << " " << std::left << std::setw(14) << server.ip << " "
                  << verticalLine << " " << std::left << std::setw(9) << (std::to_string(server.cpuUsage) + " %") << " "
                  << verticalLine << " " << std::left << std::setw(12) << (std::to_string(server.ramGB) + " GB") << " "
                  << verticalLine << " " << std::left << std::setw(7) << (server.online ? "Online" : "Offline") << "   "
                  << verticalLine << std::endl;
    }
    
    displayFooter("Total Servers: 2");
    
    tableWidth = 80;
}

void Display::displayNetworkTable() {
    tableWidth = 78;
    
    displayHeader("PERANGKAT JARINGAN");
    
    // Header
    std::cout << verticalLine << " ID   " 
              << verticalLine << " Nama Perangkat    " 
              << verticalLine << " IP Address     " 
              << verticalLine << " Tipe           "
              << verticalLine << " Status        "
              << verticalLine << std::endl;
              
    drawHorizontalLine(tableWidth);
    
    struct StaticNetworkInfo {
        int id;
        std::string name;
        std::string ip;
        std::string type;
        bool online;
    };
    
    StaticNetworkInfo devices[] = {
        {1, "Router 1", "192.168.74.1  ", "Router", true},
        {2, "Switch 1", "192.168.64.222", "Switch", false}
    };

    for (const auto& device : devices) {
        std::cout << verticalLine << " " << std::left << std::setw(4) << device.id << " "
                  << verticalLine << " " << std::left << std::setw(17) << device.name << " "
                  << verticalLine << " " << std::left << std::setw(13) << device.ip << " "
                  << verticalLine << " " << std::left << std::setw(13) << device.type << "  "
                  << verticalLine << " " << std::left << std::setw(13) << (device.online ? "Online" : "Offline") << " "
                  << verticalLine << std::endl;
    }
    
    displayFooter("Total Perangkat Jaringan: 2");
    
    tableWidth = 80;
}
void Display::displayStorageTable() {
    tableWidth = 82;
    
    displayHeader("PERANGKAT PENYIMPANAN");
    
    // Header
    std::cout << verticalLine << " ID   " 
              << verticalLine << " Nama Perangkat    " 
              << verticalLine << " Tipe       " 
              << verticalLine << " Kapasitas    "
              << verticalLine << " Terpakai   "
              << verticalLine << " Status     "
              << verticalLine << std::endl;
              
    drawHorizontalLine(tableWidth);
    
    struct StaticStorageInfo {
        int id;
        std::string name;
        std::string type;
        int capacityGB;
        int usedGB;
        bool online;
    };
    
    StaticStorageInfo devices[] = {
        {1, "Storage 1", "HDD", 1000, 500, true},
        {2, "Storage 2", "SSD", 500, 200, false}
    };
    
    for (const auto& device : devices) {
        int usedPercent = static_cast<int>((static_cast<double>(device.usedGB) / device.capacityGB) * 100); // Menghitung persentase storage yang terpakai dari GB ke Persen
        std::cout << verticalLine << " " << std::left << std::setw(4) << device.id << " "
                  << verticalLine << " " << std::left << std::setw(17) << device.name << " "
                  << verticalLine << " " << std::left << std::setw(10) << device.type << " "
                  << verticalLine << " " << std::left << std::setw(12) << (std::to_string(device.capacityGB) + " GB") << " "
                  << verticalLine << " " << std::left << std::setw(9) << (std::to_string(usedPercent) + "%")  << "  "
                  << verticalLine << " " << std::left << std::setw(9) << (device.online ? "Online" : "Offline") << "  "
                  << verticalLine << std::endl;
    }
    
    displayFooter("Total Perangkat Penyimpanan: 2");
    

    tableWidth = 80;
}

void Display::displayDataCenterLayout() {
    tableWidth = 80;
    
    displayHeader("LAYOUT DATA CENTER");
    
    // layout dari data center untuk visualisasi posisi masing2 device/server
    char layout[5][5] = {
        {'S', 'N', 'D', '-', '-'},
        {'-', 'S', 'N', 'D', '-'},
        {'D', '-', 'S', 'N', 'D'},
        {'-', 'D', '-', 'S', 'N'},
        {'-', '-', 'D', 'N', 'S'}
    };

    int rows = 5;
    int cols = 5;

    // Menampilkan grid layout data center
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Contoh visualisasi menggunakan ASCII
            // 'S' untuk server, 'N' untuk network, 'D' untuk storage, '-' untuk kosong
            char cellContent = layout[i][j];
            
            if (cellContent == 'S') {
                std::cout << "[S]"; // Server
            } else if (cellContent == 'N') {
                std::cout << "[N]"; // Network
            } else if (cellContent == 'D') {
                std::cout << "[D]"; // Storage
            } else {
                std::cout << "[ ]"; // Empty
            }
        }
        std::cout << std::endl;
    }
    
    // Keterangan
    std::cout << "\nKeterangan:" << std::endl;
    std::cout << "[S] = Server" << std::endl;
    std::cout << "[N] = Perangkat Jaringan" << std::endl;
    std::cout << "[D] = Perangkat Penyimpanan" << std::endl;
    std::cout << "[ ] = Kosong" << std::endl;
    
    displayFooter();
}

void Display::displaySystemStatus() {
    std::cout << "\nStatus Sistem:" << std::endl;
    int activeServers = 1; // masih data statis di update ke depan akan diimplementasikan membaca data dari file yang ada di data
    int totalServers = 2;  // sama seperti diatas
    int TotalStorage = 1500; // Dalam GB kecuali jika diatas 1000 maka di convert ke TB
    int RemainingStorage = 800; // GB nanti akan di update ke depan akan menghitung sisa storage yang ada
    bool networkStatus = true;

    std::cout << "- Servers Aktif: " << activeServers << "/" << totalServers << std::endl;
    
    // Mengconvert GB ke TB jika storage lebih dari 1000 GB
    if (TotalStorage >= 1000) {
        double storageInTB = TotalStorage / 1000.0;
        std::cout << "- Storage Tersedia: " << storageInTB << " TB" << std::endl;
    } else {
        std::cout << "- Storage Tersedia: " << TotalStorage << " GB" << std::endl;
    }

    std::cout << "- Storage Tersisa: " << RemainingStorage << " GB" << std::endl;
    std::cout << "- Status Jaringan: " << (networkStatus ? "Online" : "Offline") << std::endl;
}

void Display::displayConfirmation(const std::string& message) {
    std::cout << "\n[KONFIRMASI] " << message << " (Y/N): ";
}

void Display::displayError(const std::string& message) {
    std::cout << "\n[ERROR] " << message << std::endl;
    std::cout << "Tekan Enter untuk melanjutkan...";
    std::cin.ignore();
    std::cin.get();
}

void Display::displaySuccess(const std::string& message) {
    std::cout << "\n[SUKSES] " << message << std::endl;
    std::cout << "Tekan Enter untuk melanjutkan...";
    std::cin.ignore();
    std::cin.get();
}

// Animasi loading dengan slowtype
void Display::displayLoading(const std::string& message) {
    std::cout << message;
    for (int i = 0; i < 3; i++) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << std::endl;
}