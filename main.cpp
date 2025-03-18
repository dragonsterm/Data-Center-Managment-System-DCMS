#include <iostream>
#include <limits>
#include "views/menu.h"


int main() {
    MenuManager menuManager;

    menuManager.tambahMenuItem(0, "Manajemen Server Center", "");
    menuManager.tambahMenuItem(0, "Utility", "");
    menuManager.tambahMenuItem(0, "Laporan", "");
    menuManager.tambahMenuItem(0, "Pengaturan System", "");

    bool run = true;

    while (run)
    {
        menuManager.displayMenu(menuManager.getMenuSekarang());
        int pilihan = menuManager.getPilihanMenu();

        switch (pilihan)
        {
            case 1:
                std::cout << "Manajemen Server Center" << std::endl;
                break;
            case 2:
                std::cout << "Utility" << std::endl;
                break;
            case 3:
                std::cout << "Laporan" << std::endl;
                break;
            case 4:
                std::cout << "Pengaturan System" << std::endl;
                break;
            case 9:
                std::cout << "Keluar dari aplikasi" << std::endl;
                run = false;
                break;
            default:
                std::cout << "Pilihan tidak valid\n\n";
                std::cout << "Press Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
        }
    }
    return 0;
}
