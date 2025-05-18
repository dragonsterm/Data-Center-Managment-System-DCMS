#include <iostream>
#include <iomanip>
#include <string>
#include <Ctime>
#include <cstdlib>
using namespace std;

void mainMenu();
void processChoice(int choice);
string getCurrentDateTime();
void visualizeDataCenter();
void manageServers();
void searchAndFilter();
void sortData();
void generateReports();
void backupAndRestore();
void optimizeRackLayout();




int main() {
    mainMenu();
    return 0;
}

string getCurrentDateTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    char temp[80];
    strftime(temp, 80, "%d/%m/%Y %H:%M:%S", localTime);
    return string(temp);
}

void mainMenu() {
    int choice;
    bool exit = false;

    do {
        // system("cls"); // Clear the console (Windows) ***Disabled sementara selama pengembangan*** 

        // Diplay Header
        cout << "===== DATA CENTER MANAGEMENT SYSTEM =====" << endl;
        cout << "===== DCMS V 0.4 (Unreleased) #2025 =====" << endl;
        cout << "[Current Date & Time: " << getCurrentDateTime() << "]" << endl << endl;

        // Dispay Menu opsi
        cout << "+---------------------------------------+" << endl;
        cout << "|          MENU UTAMA                   |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "|  1. Visualisasi Data Center           |" << endl;
        cout << "|  2. Manajemen Server                  |" << endl;
        cout << "|  3. Pencarian & Filter                |" << endl;
        cout << "|  4. Pengurutan Data                   |" << endl;
        cout << "|  5. Laporan & Statistik               |" << endl;
        cout << "|  6. Backup & Restore Data             |" << endl;
        cout << "|  7. Optimasi Penataan Rak             |" << endl;
        cout << "|  8. Keluar                            |" << endl;
        cout << "+---------------------------------------+\n\n" << endl;
        
        // Dispay System Status ****Work in Progress****
        cout << "System Status: \n";
        cout << "- Servers Aktif: TBA\n";
        cout << "- Storage Tersedia: TBA\n\n";

        // User input
        cout << "Pilih menu [1-8]: ";
        cin >> choice;

        // Validasi Input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }

        if (choice == 8) {
            exit = true;
            cout << "Terima kasih telah menggunakan Data Center Management System." << endl;
        } else {
            processChoice(choice);
        }       
    } while (!exit);
}

void processChoice(int choice) {
    switch (choice) {
        case 1:
            visualizeDataCenter();
            break;
        case 2:
            manageServers();
            break;
        case 3:
            searchAndFilter();
            break;
        case 4:
            sortData();
            break;
        case 5:
            generateReports();
            break;
        case 6:
            backupAndRestore();
            break;
        case 7:
            optimizeRackLayout();
            break;
        default:
            cout << "Pilihan tidak valid. Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            break;
    }
}

// Fungsi Visualisasi Data Center ***PlaceHolder WIP***
void visualizeDataCenter() {
    cout << "\n=== Visualisasi Data Center ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi manage Server ***PlaceHolder WIP***
void manageServers() {
    cout << "\n=== Manajemen Server ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Search dan Filter ***PlaceHolder WIP***
void searchAndFilter() {
    cout << "\n=== Pencarian & Filter ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Sort Data ***PlaceHolder WIP***
void sortData() {
    cout << "\n=== Pengurutan Data ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Generate Reports ***PlaceHolder WIP***
void generateReports() {
    cout << "\n=== Laporan & Statistik ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Backup & Restore ***PlaceHolder WIP***
void backupAndRestore() {
    cout << "\n=== Backup & Restore Data ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Optimize Rack Layout ***PlaceHolder WIP***
void optimizeRackLayout() {
    cout << "\n=== Optimasi Penataan Rak ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

