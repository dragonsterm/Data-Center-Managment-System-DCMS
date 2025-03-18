#include "menu.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <ctime>

MenuManager::MenuManager() : MenuSekarang(0) 
{
    tambahMenu("MENU UTAMA");
}

MenuManager::~MenuManager() 
{
    menus.clear();
}

void MenuManager::tambahMenu(const std::string& title) 
{
    Menu menubaru;
    menubaru.title = title;
    menus.push_back(menubaru);
}

void MenuManager::tambahMenuItem(int menuindex, const std::string& nama, const std::string& deskripsi) 
{
    if (menuindex >= 0 && menuindex < static_cast<int>(menus.size())) 
    {
        MenuItem item;
        item.id = menus[menuindex].items.size() + 1;
        item.nama = nama;
        item.deskripsi = deskripsi;
        menus[menuindex].items.push_back(item);
    }
}

void MenuManager::displayHeader() 
{
    std::cout << "===== DATA CENTER MANAGEMENT SYSTEM =====" << std::endl;
    
    time_t now = time(0);
    tm* localTime = localtime(&now);
    
    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y %H:%M", localTime);
    
    std::cout << "[Current Date & Time: " << buffer << "]" << std::endl;
    std::cout << std::endl;
}

void MenuManager::displayFooter() 
{
    std::cout << "\nStatus Sistem:" << std::endl;
    std::cout << "- Servers Aktif: WIP" << std::endl;
    std::cout << "- Storage Tersedia: WIP" << std::endl;
    std::cout << "- Status Jaringan: WIP" << std::endl;
}

void MenuManager::displayMenu(int menuindex)
{
    if (menuindex >= 0 && menuindex < static_cast<int>(menus.size())) 
    {
        system("cls");
        displayHeader();
        
        // Menu box width - adjust this if needed
        const int boxWidth = 39; 
        const std::string horizontalLine = "+-------------------------------------+";
        
        std::cout << horizontalLine << std::endl;
        
        std::string titleLine = "|          " + menus[menuindex].title;
        int titlePadding = boxWidth - titleLine.length() - 1;
        titleLine += std::string(titlePadding, ' ') + "|";
        std::cout << titleLine << std::endl;
        std::cout << "|-------------------------------------|" << std::endl;
        for (const auto& item : menus[menuindex].items) 
        {
            // Format: |  1. Item Name                      |
            std::string itemText = "  " + std::to_string(item.id) + ". " + item.nama;
            std::string menuLine = "|" + itemText;
            int itemPadding = boxWidth - menuLine.length() - 1;
            menuLine += std::string(itemPadding, ' ') + "|";
            std::cout << menuLine << std::endl;
        }
        std::string exitLine = "|  9. Keluar";
        int exitPadding = boxWidth - exitLine.length() - 1;
        exitLine += std::string(exitPadding, ' ') + "|";
        std::cout << exitLine << std::endl;
        
        std::cout << horizontalLine << std::endl;
        
        displayFooter();
    }
}

int MenuManager::getMenuSekarang() const 
{
    return MenuSekarang;
}

void MenuManager::setMenuSekarang(int menuindex) 
{
    if (menuindex >= 0 && menuindex < static_cast<int>(menus.size())) 
    {
        MenuSekarang = menuindex;
    }
}

int MenuManager::getPilihanMenu() 
{
    int pilihan;
    std::cout << "\nPilih menu [1-" << menus[MenuSekarang].items.size() << " atau 9]: ";
    while (!(std::cin >> pilihan))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input. Harap input angka: ";
    }
    return pilihan;
}