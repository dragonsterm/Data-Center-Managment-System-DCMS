#include <iostream>
#include <limits>
#include "views/menu.h"
#include "views/display.h"

int main()
{
    MenuManager menuManager;
    Display display;

    menuManager.tambahMenuItem(0, "Manajemen Data Center", "");
    menuManager.tambahMenuItem(0, "Manajemen Server", "");
    menuManager.tambahMenuItem(0, "Manajemen Jaringan", "");
    menuManager.tambahMenuItem(0, "Manajemen Penyimpanan", "");
    menuManager.tambahMenuItem(0, "Laporan & Analisis", "");
    menuManager.tambahMenuItem(0, "Pengaturan Sistem", "");
    menuManager.tambahMenuItem(0, "Bantuan & Dokumentasi", "");

    bool run = true;

    while (run)
    {
        menuManager.displayMenu(menuManager.getMenuSekarang());
        int pilihan = menuManager.getPilihanMenu();

        switch (pilihan)
        {
        case 1:
        {
            display.displayLoading("Loading"); // Nanti akan di add kesemua case
            display.clearScreen();
            display.displayDataCenterLayout();
            system("pause");
            break;
        }
        case 2:
        {
            display.clearScreen();
            display.displayServerTable();
            system("pause");
            break;
        }
        case 3:
        {
            display.clearScreen();
            display.displayNetworkTable();
            system("pause");
            break;
        }
        case 4:
        {
            display.clearScreen();
            display.displayStorageTable();
            system("pause");
            break;
        }
        case 5:
        {
            display.clearScreen();
            display.displayHeader("LAPORAN & ANALISIS");
            display.displaySystemStatus();
            system("pause");
            ;
            break;
        }
        case 6:
        {
            display.clearScreen();
            display.displayHeader("PENGATURAN SISTEM");
            std::cout << "\nPengaturan Sistem (Fitur belum diimplementasikan)\n"
                      << std::endl;
            system("pause");
            break;
        }
        case 7:
        {
            display.clearScreen();
            display.displayHeader("BANTUAN & DOKUMENTASI");
            std::cout << "\nBantuan & Dokumentasi (Fitur belum diimplementasikan)\n"
                      << std::endl;
            system("pause");
            break;
        }
        case 0:
            display.displayLoading("Menutup aplikasi");
            system("pause");
            run = false;
            break;
        default:
            display.displayError("Pilihan tidak valid");
            break;
        }
    }
    return 0;
}
