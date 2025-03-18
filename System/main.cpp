#include <iostream>
#include <controllers/DataCenterController.h>
#include <views/MenuView.h>

int main () {
    std::cout << "======================================\n";
    std::cout << "  Selamat Datang di Data Center App   \n";
    std::cout << "======================================\n\n";

    DataCenterController dataCenterController;

    bool Run= true;
    while (Run) {

        MenuView::showMainMenu();

        int pilihan;
        std::cout << "Pilih menu >> ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "fitur 1.\n";
                break;
            case 2:
                std::cout << "fitur 2.\n";
                break;
            case 3:
                std::cout << "Keluar dari program.\n";
                system("pause");
                Run = false;
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    }
}