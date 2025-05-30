#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

// Struct ServerUnit
enum ServerStatus
{
    Offline,
    Online,
    Maintanance,
    UnKnown
};
enum ServerType
{
    Web,
    Database,
    Application,
    File,
    UnCategorized
};

struct ServerUnit
{
    string id;               // ID server
    ServerType type;         // Tipe server (Web, Database, Application, File)
    ServerStatus status;     // Status server
    float utilization;       // utilisasi server (0-100%)
    double stroageCapacity;  // Kapasitas penyimpanan server (dalam GB)
    double availableStorage; // Penyimpanan yang tersedia (dalam GB)

    // Informasi Spesifikasi Server
    string model;
    int cpuCores;
    int ram; // RAM dalam GB
    string ipAddress;

    // Constructor untuk nilai default
    ServerUnit(string id = "", ServerType type = UnCategorized, ServerStatus status = Offline) : 
        id(id),
        type(type),
        status(status),
        utilization(0.0),
        stroageCapacity(100.0),
        availableStorage(100.0),
        model("Generic Server Device"),
        cpuCores(4),
        ram(16),
        ipAddress("1.0.0.1") {}
};

// Struct ServerRack
struct ServerRack
{
    string id;
    string location;
    int maxCapacity;
    ServerUnit servers[5]; // Maksimal 5 server per rack
    int serverCount;
    int operationalStatus;

    // Constructor untuk nilai default
    ServerRack() : 
        id(""),
        location(""),
        maxCapacity(5),
        serverCount(0),
        operationalStatus(true) {}
};

// Struct DataCenter
struct DataCenter
{
    static const int Row = 8;
    static const int Colum = 8; // row dan colum untuk visualisasi server rack

    ServerRack rack[Row][Colum];
    string name;
    string location;

    // Constructor untuk nilai default
    DataCenter() : 
        name("Default Data Center"),
        location("Unrecognized Location")
    {
        for (int r = 0; r < Row; r++)
        {
            for (int c = 0; c < Colum; c++)
            {
                rack[r][c].id = "R" + to_string(r + 1) + "-C" + to_string(c + 1);
                rack[r][c].location = "Zone " + to_string((r / 2) + 1);
            }
        }
    }
};

// Global data center
DataCenter dataCenter;

// deklarasi function
// void initializeDataCenter();
bool addServer(ServerRack &rack, const ServerUnit &server);
bool removeServer(ServerRack &rack, int index);
void startMenu();
void saveDataToFile(string fileName = "");
void loadDataFromFile(string fileName = "");
void createNewDataCenter();
void createDataFile(string fileName);
void createSampleDataFile(string fileName);
void mainMenu();
void processChoice(int choice);
string getCurrentDateTime();
void displayDataCenterMap();
void displayRackView();
void displayServerDetails(ServerRack &rack);
void manageServers();
void displaySimpleDataCenterMap();
void addNewServer();
void removeExistingServer();
void updateServerStatus();
void updateServerUtilization();
bool validateServerPlacement(int row, int colum);
void displayServerInputForm(ServerUnit& server);
void searchAndFilter();
void sortData();
void generateReports();
void backupAndRestore();
void optimizeRackLayout();

// main
int main()
{
    startMenu();
    // initializeDataCenter();
    mainMenu();
    return 0;
}


// function untuk inisialisasi Data Center sudah tidak dipakai tapi di simpan sementara
/* void initializeDataCenter()
{
    // Membuat 10 unique server dengan ID unik
    ServerUnit server1("WEB-001", Web, Online);
    ServerUnit server2("DB-001", Database, Online);
    ServerUnit server3("APP-001", Application, Online);
    ServerUnit server4("FILE-001", File, Online);
    ServerUnit server5("WEB-002", Web, Online);
    ServerUnit server6("DB-002", Database, Online);
    ServerUnit server7("WEB-003", Web, Online);

    const bool walkwayChecker[DataCenter::Row][DataCenter::Colum] = {
        {false, false, true, false, false, true, false, false}, // Row 0
        {false, false, true, false, false, true, false, false}, // Row 1
        {true,  true,  true, true,  true,  true, true,  true},       // Row 2 (walkway row)
        {false, false, true, false, false, true, false, false}, // Row 3
        {false, false, true, false, false, true, false, false}, // Row 4
        {true,  true,  true, true,  true,  true, true,  true},       // Row 5 (walkway row)
        {false, false, true, false, false, true, false, false}, // Row 6
        {false, false, true, false, false, true, false, false}  // Row 7
    };

    // 2 Server di Rack 1,1 (koordinat 0,0)
    addServer(dataCenter.rack[0][0], server1);
    addServer(dataCenter.rack[0][0], server2);

    // 1 Server di Rack 2,1 (koordinat 1,0)
    addServer(dataCenter.rack[1][0], server3);

    // 1 Server di Rack 2,3 (koordinat 1,3)
    addServer(dataCenter.rack[1][3], server4);

    // 1 Server di Rack 4,4 (koordinat 3,3)
    addServer(dataCenter.rack[3][3], server5);

    // 1 Server di Rack 7,1 (koordinat 6,0)
    addServer(dataCenter.rack[6][0], server6);

    // 1 Server di Rack 7,4 (koordinat 6,3)
    addServer(dataCenter.rack[6][3], server7);

    // Static data custom server tidak pakai default constructor bisa add lagi
    ServerUnit customServer1;
    customServer1.id = "WEB-004";
    customServer1.type = Web;  
    customServer1.status = Online;
    customServer1.utilization = 75.5;
    customServer1.stroageCapacity = 2000.0;
    customServer1.availableStorage = 1000.0;
    customServer1.model = "Skibidi T01LET";
    customServer1.cpuCores = 24;
    customServer1.ram = 128;
    customServer1.ipAddress = "192.168.1.100";

    addServer(dataCenter.rack[0][3], customServer1); // {1,4} (koordinat 0,3)
} */

bool addServer(ServerRack& rack, const ServerUnit& server)
{
    if (rack.serverCount < 5)
    {
        rack.servers[rack.serverCount] = server; // Menambahkan server ke dalam array
        rack.serverCount++;
        return true;
    }
    return false; // rack penuh
}

bool removeServer(ServerRack& rack, int index)
{
    if (index >= 0 && index < rack.serverCount)
    {
        for (int i = index; i < rack.serverCount - 1; i++)
        {
            rack.servers[i] = rack.servers[i + 1];
        }
        rack.serverCount--;
        return true;
    }
    return false;
}

// fungsi mendapatkan waktu saat ini lewat lokal
string getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    char temp[80];
    strftime(temp, 80, "%d/%m/%Y %H:%M:%S", localTime);
    return string(temp);
}

// function start menu
void startMenu()
{
    int choice;
    bool validChoice = false;
    while(!validChoice)
    {
        system("cls");
        cout << "===== DATA CENTER MANAGEMENT SYSTEM =====" << endl;
        cout << "===== DCMS V 0.5 (Unreleased) #2025 =====" << endl;
        cout << "[Current Date & Time: " << getCurrentDateTime() << "]" << endl << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "|             START MENU                |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "|  1. Load Data dari File Existing      |" << endl;
        cout << "|  2. Buat Data Center Baru             |" << endl;
        cout << "+---------------------------------------+" << endl;
        
        cout << "\nPilih opsi [1-2]: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInput tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            {
                string fileName;
                cout << "Masukkan nama file (tipe file .txt): ";
                cin.ignore();
                getline(cin, fileName);
                ifstream checkFile(fileName);
                if (checkFile.good())
                {
                    checkFile.close();
                    loadDataFromFile(fileName);
                    cout << "\nData berhasil dimuat dari file: " << fileName << endl;
                    cout << "\n\nTekan Enter untuk melanjutkan ke menu utama...";
                    cin.get();
                    validChoice = true;
                } else
                {
                    cout << "\nFile tidak ditemukan atau tidak valid. Silakan coba lagi." << endl;
                    cout << "\nTekan Enter untuk mencoba lagi...";
                    cin.ignore();
                }
            }
            break;
        case 2:
            createNewDataCenter();
            validChoice = true;
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
// function untuk pembuatan data center baru
void createNewDataCenter()
{
    int choice;
    bool validChoice = false;

    while (!validChoice)
    {
        system("cls");
        cout << "=== Buat Data Center Baru ===" << endl;
        cout << "1. Gunakan Pengaturan Default (sample data)" << endl;
        cout << "2. Input Manual (Zero Data)" << endl;
        cout << "Pilih opsi [1-2]: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInput tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            {
                dataCenter.name = "Default Data Center";
                dataCenter.location = "Unrecognized Location";

                for (int r = 0; r < DataCenter::Row; r++)
                {
                    for (int c = 0; c < DataCenter::Colum; c++)
                    {
                        dataCenter.rack[r][c].id = "R" + to_string(r + 1) + "-C" + to_string(c + 1);
                        dataCenter.rack[r][c].location = "Zone " + to_string((r / 2) + 1);
                        dataCenter.rack[r][c].serverCount = 0; 
                    }
                }
                createSampleDataFile("DataCenterData.txt");
                cout << "\nData Center default berhasil dibuat dengan sample data!" << endl;
                cout << "File tersimpan sebagai: DataCenterData.txt" << endl;
                validChoice = true;
            }
            break;
        case 2:
            {
                string fileName;
                string dcName;
                string dcLocation;

                cin.ignore();
                cout << "Masukkan nama file (hanya nama tanpa .txt): ";
                getline(cin, fileName);
                fileName += ".txt";
                cout << "Masukkan nama Data Center: ";
                getline(cin, dcName);
                cout << "Masukkan lokasi Data Center: ";
                getline(cin, dcLocation);

                dataCenter.name = dcName;
                dataCenter.location = dcLocation;
                for (int r = 0; r < DataCenter::Row; r++) {
                    for (int c = 0; c < DataCenter::Colum; c++) {
                        dataCenter.rack[r][c].id = "R" + to_string(r + 1) + "-C" + to_string(c + 1);
                        dataCenter.rack[r][c].location = "Zone " + to_string((r / 2) + 1);
                        dataCenter.rack[r][c].serverCount = 0;
                    }
                }
                createDataFile(fileName);
                cout << "\n\nData Center baru berhasil dibuat!" << endl;
                cout << "File tersimpan sebagai: " << fileName << endl;
                validChoice = true;
            }
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            cout << "\nTekan Enter untuk melanjutkan..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }
    cout << "\nTekan Enter untuk melanjutkan ke menu utama...";
    cin.ignore();
    cin.get();
}
// fucntion membuat data 
void createDataFile(string fileName)
{
    ofstream file (fileName);
    if (file.is_open())
    {
        file << "DATA_CENTER_INFO" << endl;
        file << dataCenter.name << endl;
        file << dataCenter.location << endl;
        file << "END_DATA_CENTER_INFO" << endl;
        file << "RACK_DATA" << endl;
        for (int r = 0; r < DataCenter::Row; r++) 
        {
            for (int c = 0; c < DataCenter::Colum; c++) 
            {
                file << "RACK " << r << " " << c << endl;
                file << dataCenter.rack[r][c].id << endl;
                file << dataCenter.rack[r][c].location << endl;
                file << dataCenter.rack[r][c].maxCapacity << endl;
                file << dataCenter.rack[r][c].operationalStatus << endl;
                file << "0" << endl;
                file << "END_RACK" << endl;
            }
        }
        file << "END_RACK_DATA" << endl;
        
        file.close();
    } else 
    {
        cout << "\nError: Tidak dapat membuat file " << endl;
    }
}

// function memebuat sample data
void createSampleDataFile(string fileName)
{
     // Membuat 10 unique server dengan ID unik
    ServerUnit server1("WEB-001", Web, Online);
    ServerUnit server2("DB-001", Database, Online);
    ServerUnit server3("APP-001", Application, Online);
    ServerUnit server4("FILE-001", File, Online);
    ServerUnit server5("WEB-002", Web, Online);
    ServerUnit server6("DB-002", Database, Online);
    ServerUnit server7("WEB-003", Web, Online);

    /* const bool walkwayChecker[DataCenter::Row][DataCenter::Colum] = {
        {false, false, true, false, false, true, false, false}, // Row 0
        {false, false, true, false, false, true, false, false}, // Row 1
        {true,  true,  true, true,  true,  true, true,  true},       // Row 2 (walkway row)
        {false, false, true, false, false, true, false, false}, // Row 3
        {false, false, true, false, false, true, false, false}, // Row 4
        {true,  true,  true, true,  true,  true, true,  true},       // Row 5 (walkway row)
        {false, false, true, false, false, true, false, false}, // Row 6
        {false, false, true, false, false, true, false, false}  // Row 7
    }; */ // Hanya buat visualisasi

    // 2 Server di Rack 1,1 (koordinat 0,0)
    addServer(dataCenter.rack[0][0], server1);
    addServer(dataCenter.rack[0][0], server2);

    // 1 Server di Rack 2,1 (koordinat 1,0)
    addServer(dataCenter.rack[1][0], server3);

    // 1 Server di Rack 2,3 (koordinat 1,3)
    addServer(dataCenter.rack[1][3], server4);

    // 1 Server di Rack 4,4 (koordinat 3,3)
    addServer(dataCenter.rack[3][3], server5);

    // 1 Server di Rack 7,1 (koordinat 6,0)
    addServer(dataCenter.rack[6][0], server6);

    // 1 Server di Rack 7,4 (koordinat 6,3)
    addServer(dataCenter.rack[6][3], server7);

    // Static data custom server tidak pakai default constructor bisa add lagi
    ServerUnit customServer1;
    customServer1.id = "WEB-004";
    customServer1.type = Web;  
    customServer1.status = Online;
    customServer1.utilization = 75.5;
    customServer1.stroageCapacity = 2000.0;
    customServer1.availableStorage = 1000.0;
    customServer1.model = "Skibidi T01LET";
    customServer1.cpuCores = 24;
    customServer1.ram = 128;
    customServer1.ipAddress = "192.168.1.100";

    addServer(dataCenter.rack[0][3], customServer1); // {1,4} (koordinat 0,3)
    saveDataToFile(fileName);
}

// fucntion save file
void saveDataToFile(string fileName)
{
    ofstream file(fileName);
    if (file.is_open()) 
    {
        // menulis info data center
        file << "DATA_CENTER_INFO" << endl;
        file << dataCenter.name << endl;
        file << dataCenter.location << endl;
        file << "END_DATA_CENTER_INFO" << endl;

        // menulis rack dan server data
        file << "RACK_DATA" << endl;
        for (int r = 0; r < DataCenter::Row; r++) 
        {
            for (int c = 0; c < DataCenter::Colum; c++) 
            {
                file << "RACK " << r << " " << c << endl;
                file << dataCenter.rack[r][c].id << endl;
                file << dataCenter.rack[r][c].location << endl;
                file << dataCenter.rack[r][c].maxCapacity << endl;
                file << dataCenter.rack[r][c].operationalStatus << endl;
                file << dataCenter.rack[r][c].serverCount << endl;
                
                // menulis data server untuk rack
                for (int s = 0; s < dataCenter.rack[r][c].serverCount; s++) 
                {
                    ServerUnit& server = dataCenter.rack[r][c].servers[s];
                    file << "SERVER" << endl;
                    file << server.id << endl;
                    file << (int)server.type << endl;
                    file << (int)server.status << endl;
                    file << server.utilization << endl;
                    file << server.stroageCapacity << endl;
                    file << server.availableStorage << endl;
                    file << server.model << endl;
                    file << server.cpuCores << endl;
                    file << server.ram << endl;
                    file << server.ipAddress << endl;
                    file << "END_SERVER" << endl;
                }
                file << "END_RACK" << endl;
            }
        }
        file << "END_RACK_DATA" << endl;
        
        file.close();
        cout << "Data berhasil disimpan ke file: " << fileName << endl;
    } else 
    {
        cout << "Error: Tidak dapat membuka file untuk penyimpanan" << endl;
    }
}
void loadDataFromFile(string fileName)
{
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;

        // mambaca info data center
        while (getline(file, line))
        {
            if (line == "DATA_CENTER_INFO")
            {
                getline(file, dataCenter.name);
                getline(file, dataCenter.location);
                getline(file, line);
                break;
            }
        }

        // membaca data untuk Rack
        while (getline(file, line))
        {
            if (line == "RACK_DATA")
            {
                while (getline(file, line))
                {
                    if (line == "END_RACK_DATA") break;
                    if (line.substr(0, 4) == "RACK")
                    {
                        int r;
                        int c;
                        sscanf(line.c_str(), "RACK %d %d", &r, &c);
                        getline(file,dataCenter.rack[r][c].id);
                        getline(file, dataCenter.rack[r][c].location);

                        string temp;
                        getline(file, temp);
                        dataCenter.rack[r][c].maxCapacity = stoi(temp);
                        getline(file, temp);
                        dataCenter.rack[r][c].operationalStatus = stoi(temp);
                        getline(file, temp);
                        int serverCount = stoi(temp);
                        dataCenter.rack[r][c].serverCount = serverCount;

                        // Membaca server untuk Rack
                        for (int s = 0; s < serverCount; s++) 
                        {
                            getline(file, line); // SERVER
                            if (line == "SERVER") {
                                ServerUnit& server = dataCenter.rack[r][c].servers[s];
                                
                                getline(file, server.id);
                                
                                getline(file, temp);
                                server.type = (ServerType)stoi(temp);
                                
                                getline(file, temp);
                                server.status = (ServerStatus)stoi(temp);
                                
                                getline(file, temp);
                                server.utilization = stof(temp);
                                
                                getline(file, temp);
                                server.stroageCapacity = stod(temp);
                                
                                getline(file, temp);
                                server.availableStorage = stod(temp);
                                
                                getline(file, server.model);
                                
                                getline(file, temp);
                                server.cpuCores = stoi(temp);
                                
                                getline(file, temp);
                                server.ram = stoi(temp);
                                
                                getline(file, server.ipAddress);
                                
                                getline(file, line);
                            }
                        }
                        getline(file, line);
                    }
                }
                break;
            }
        }
        file.close();
    } else
    {
        cout << "Error: Tidak dapat membuka file: " << fileName << endl;
    }
}
// function main menu
void mainMenu()
{
    int choice;
    bool exit = false;

    do
    {
        system("cls");
        // Diplay Header
        cout << "===== DATA CENTER MANAGEMENT SYSTEM =====" << endl;
        cout << "===== DCMS V 0.5 (Unreleased) #2025 =====" << endl;
        cout << "[Current Date & Time: " << getCurrentDateTime() << "]" << endl
             << endl;

        // Dispay Menu opsi
        cout << "+---------------------------------------+" << endl;
        cout << "|          MENU UTAMA                   |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "|  1. Visualisasi Data Center           |" << endl;
        cout << "|  2. Manajemen Server                  |" << endl;
        cout << "|  3. Pencarian & Filter                |" << endl;
        cout << "|  4. Pengurutan Data                   |" << endl;
        cout << "|  5. Laporan & Statistik               |" << endl;
        cout << "|  6. Save, Backup & Restore Data       |" << endl;
        cout << "|  7. Optimasi Penataan Rak             |" << endl;
        cout << "|  8. Keluar                            |" << endl;
        cout << "+---------------------------------------+\n\n"
             << endl;

        // Perhitungan System Status
        int activeServer = 0;
        double totalStorage = 0.0;
        string countServerId[1000];
        int countServerIdSize = 0;

        for (int r = 0; r < DataCenter::Row; r++)
        {
            for (int c = 0; c < DataCenter::Colum; c++)
            {
                for (int s = 0; s < dataCenter.rack[r][c].serverCount; s++)
                {
                    ServerUnit &server = dataCenter.rack[r][c].servers[s];
                    if (server.status == Online)
                    {
                        // checker untuk memastikan server tidak terhitung lebih dari sekali
                        bool countCheck = false;
                        for (int i = 0; i < countServerIdSize; i++)
                        {
                            if (countServerId[i] == server.id)
                            {
                                countCheck = true;
                                break;
                            }
                        }
                        if (!countCheck)
                        {
                            activeServer++;
                            totalStorage += server.availableStorage;
                            countServerId[countServerIdSize++] = server.id;
                            countServerIdSize++;
                        }
                    }
                }
            }
        }

        // Dispay System Status
        cout << "System Status: \n";
        cout << "- Servers Aktif: " << activeServer << "\n";
        cout << "- Storage Tersedia: " << totalStorage << "GB \n\n";

        // User input
        cout << "Pilih menu [1-8]: ";
        cin >> choice;

        // Validasi Input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }

        if (choice == 8)
        {
            exit = true;
            cout << "Terima kasih telah menggunakan Data Center Management System." << endl;
        }
        else
        {
            processChoice(choice);
        }
    } while (!exit);
}

// funciton untuk memproses pilihan menu
void processChoice(int choice)
{
    switch (choice)
    {
    case 1:
        displayDataCenterMap();
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
void displayDataCenterMap()
{
    int choice;
    bool exit = false;

    do
    {
        system("cls");
        cout << "\n=== Visualisasi Data Center ===" << endl;
        cout << "Nama Data Center: [" << dataCenter.name << "]" << endl;
        cout << "Lokasi: [" << dataCenter.location << "]" << endl;

        // Colum Header
        cout << "{0} ";
        for (int c = 0; c < DataCenter::Colum; c++)
        {
            if (c == 2 || c == 5)
            {
                cout << "{W}";
            }
            else
            {
                cout << "{" << c + 1 << "}";
            }
        }
        cout << endl;
        // Data Center Layout
        for (int r = 0; r < DataCenter::Row; r++)
        {
            // Walkway Row
            if (r == 2 || r == 5)
            {
                cout << "{W}" << endl;
                continue;
            }

            // Print nomer Row
            cout << "{" << r + 1 << "} ";

            // Server Rack di dalam setiap Row
            for (int c = 0; c < DataCenter::Colum; c++)
            {
                // Walkway space
                if (c == 2 || c == 5)
                {
                    cout << "   ";
                    continue;
                }

                int serverCount = dataCenter.rack[r][c].serverCount; // Mendapatakan jumlah server di dalam rack

                // Display Rack kosong
                if (serverCount > 0)
                {
                    cout << "[" << serverCount << "]";
                }
                else
                {
                    cout << "[ ]";
                }
            }
            cout << endl;
        }
        // menghitung toal rack dan server
        int totalRackServers = 0;
        int totalServers = 0;
        for (int r = 0; r < DataCenter::Row; r++)
        {
            for (int c = 0; c < DataCenter::Colum; c++)
            {
                int count = dataCenter.rack[r][c].serverCount;
                if (count > 0)
                {
                    totalRackServers++;
                    totalServers += count;
                }
            }
        }
        cout << "\nTotal:\n";
        cout << "- " << totalServers << " server dalam " << totalRackServers << " rack\n";

        // Deskripsi
        cout << "\nKeterangan:\n";
        cout << "[n] = Server Count\n";
        cout << "[ ] = Empty Rack\n";
        cout << "{W} = Walkway/Koridor\n";

        cout << "\n=== Sub Menu Visualisasi ===" << endl;
        cout << "1. Tampilan Server Rack\n";
        cout << "2. Return to Main Menu\n";
        cout << "Pilih menu [1-2]: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            displayRackView();
            break;
        case 2:
            exit = true;
            break;
        default:
            cout << "Pilihan tidak valid. Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            break;
        }
    } while (!exit);
}

void displayRackView()
{
    int row, column;
    bool ValidCoords = false;
    while (!ValidCoords) {
    system("cls");
    cout << "\n===== Tampilan Server Rack =====" << endl;
    cout << "\nReferensi Peta Data Center:" << endl;
    cout << "{0} ";
    for (int c = 0; c < DataCenter::Colum; c++)
    {
        if (c == 2 || c == 5)
        {
            cout << "{W}";
        }
        else
        {
            cout << "{" << c + 1 << "}";
        }
    }
    cout << endl;
    for (int r = 0; r < DataCenter::Row; r++)
    {
        if (r == 2 || r == 5)
        {
            cout << "{W}" << endl;
            continue;
        }
        cout << "{" << r + 1 << "} ";
        for (int c = 0; c < DataCenter::Colum; c++)
        {
            if (c == 2 || c == 5)
            {
                cout << "   ";
                continue;
            }
            int serverCount = dataCenter.rack[r][c].serverCount;
            if (serverCount > 0)
            {
                cout << "[" << serverCount << "]";
            }
            else
            {
                cout << "[ ]";
            }
        }
        cout << endl;
    }
    cout << "\n------------------------------------------\n";
    cout << "\n=== Tampilan Server Rack ===" << endl;
    cout << "Masukkan koordinat Rack (Baris,Kolom):\n";
    cout << "[1-" << DataCenter::Row << "]: ";
    cin >> row;
    cout << "[1-" << DataCenter::Colum << "]: ";
    cin >> column;

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid. Tekan Enter untuk mencoba lagi...";
        cin.get();
        continue;
    }
    row--;
    column--; // agar sesuai dengan index array

    // Validasi koorinat
    if (row < 0 || row >= DataCenter::Row || column < 0 || column >= DataCenter::Colum)
    {
        cout << "Koordinat tidak valid. Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
    }
    // Validasi walkway
    if (row == 2 || row == 5 || column == 2 || column == 5)
    {
        cout << "Koordinat tidak valid. Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
    }
    ValidCoords = true; 
    }

    bool exit = false;

    while (!exit) {
    // Ambil informasi rack
    ServerRack &rack = dataCenter.rack[row][column];
    string rackId = rack.id;
    string locataion = rack.location;
    int serverCount = rack.serverCount;

    system("cls");
    cout << "\n===== Detail Rack Server =====" << endl;
    cout << "ID Rack: " << rackId << endl;
    cout << "Lokasi: " << locataion << endl;
    cout << "Kapasitas: " << rack.maxCapacity << " Server" << endl;
    cout << "Status Operasional: " << (rack.operationalStatus ? "Aktif" : "Tidak Aktif") << endl;

    if (serverCount > 0)
    {
        cout << "\n===== Daftar Server dalam Rack =====" << endl;
        cout << "+-------+------------+--------------+-----------+---------------+----------------+" << endl;
        cout << "| No.   | Server ID  | Tipe         | Status    | Utilisasi (%) | Storage (GB)   |" << endl;
        cout << "+-------+------------+--------------+-----------+---------------+----------------+" << endl;

        for (int i = 0; i < serverCount; i++) 
        {
            ServerUnit& server = rack.servers[i];

            //konversi enum ke string
            string typeString;
            switch (server.type)
            {
            case Web:
                typeString = "Web";
                break;
            case Database:
                typeString = "Database";
                break;
            case Application:
                typeString = "Application";
                break;
            case File:
                typeString = "File";
                break;    
            default:
                typeString = "UnCategorized";
                break;
            }

            string statusString;
            switch (server.status)
            {
            case Online:
                statusString = "Online";
                break;
            case Offline:
                statusString = "Offline";
                break;
            case Maintanance:
                statusString = "Maintenance";
                break;
            default:
                statusString = "Unknown";
                break;    
            }

            // Display server details dalam tabel
            string storageInfo = to_string(int(server.availableStorage)) + "/" + to_string(int(server.stroageCapacity));
             cout << "| " << setw(5) << left << i+1 << " | "
                 << setw(10) << left << server.id << " | "
                 << setw(12) << left << typeString << " | "
                 << setw(9) << left << statusString << " | "
                 << setw(13) << left << server.utilization << " | "
                 << setw(14) << left << storageInfo << " |" << endl;
        }
        cout << "+-------+------------+--------------+-----------+---------------+----------------+\n";
        cout << "\n\n=== Sub Menu Detail Rack===\n";
        cout << "1. Detail Server\n";
        cout << "2. Kembali\n";
        cout << "Pilih menu [1-2]: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            displayServerDetails(rack);
            continue;
        }
        else 
        {
            exit = true;
        }
    } else 
    {
        exit = true;
        cout << "Tidak ada server dalam rack ini." << endl;
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
    }
}
}

void displayServerDetails(ServerRack& rack)
{
    int serverIndex;
    system("cls");
    cout << "\n===== Detail Server =====" << endl;
    cout << "\nServer dalam Rack " << rack.id << ":" << endl;
    cout << "+-------+------------+" << endl;
    cout << "| No.   | Server ID  |" << endl;
    cout << "+-------+------------+" << endl;

    for (int i = 0; i < rack.serverCount; i++)
    {
        cout << "| " << setw(5) << left << i + 1 << " | "
             << setw(10) << left << rack.servers[i].id << " |" << endl;
    }
    cout << "+-------+------------+" << endl;
    
    cout << "Masukkan nomor server [1-" << rack.serverCount << "]: ";
    cin >> serverIndex;

    // Validasi input
    if (cin.fail() || serverIndex < 1 || serverIndex > rack.serverCount)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid. Tekan Enter untuk kembali...";
        cin.get();
        return;
    }

    serverIndex--; // untuk menyesuaikan dengan index array
    ServerUnit& server = rack.servers[serverIndex]; // ambil server berdasarkan index

    //konversi enum ke string
    string typeString;
    switch (server.type)
    {
        case Web:
        typeString = "Web";
        break;
        case Database:
        typeString = "Database";
        break;
        case Application:
        typeString = "Application";
        break;
        case File:
        typeString = "File";
        break;    
        default:
        typeString = "UnCategorized";
        break;
    }
    string statusString;
    switch (server.status)
    {
        case Online:
        statusString = "Online";
        break;
        case Offline:
        statusString = "Offline";
        break;
        case Maintanance:
        statusString = "Maintenance";
        break;
        default:
        statusString = "Unknown";
        break;    
    }
    system("cls");
    cout << "\n===== Detail Server =====" << endl;
    cout << "Dalam Rack: " << rack.id << " (Server " << serverIndex + 1 << " dari " << rack.serverCount << ")" << endl;
    cout << "\n=== Informasi Umum ===" << endl;
    cout << "| ID Server              : " << server.id << endl;
    cout << "| Model                  : " << server.model << endl;
    cout << "| Tipe                   : " << typeString << endl;
    cout << "| Status                 : " << statusString << endl;
    cout << "| IP Address             : " << server.ipAddress << endl;
    cout << "---spesifikasi Server---" << endl;
    cout << "| CPU Cores              : " << server.cpuCores << endl;
    cout << "| RAM                    : " << server.ram << " GB" << endl;
    cout << "| Kapasitas Penyimpanan  : " << server.stroageCapacity << " GB" << endl;
    cout << "| Penyimpanan Tersedia   : " << server.availableStorage << " GB" << endl;
    cout << "| Utilisasi              : " << server.utilization << " %" << endl;

    cout << "\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

// Fungsi manage Server ***WIP***
void manageServers()
{
    int choice;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\n===== Manajemen Server =====" << endl;
        cout << "1. Tambah Server Baru" << endl;
        cout << "2. Hapus Server" << endl;
        cout << "3. Update Status Server" << endl;
        cout << "4. Update Utilisasi Server" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "Pilih opsi [1-5]: ";
        cin >> choice;
        cin.get();
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
            continue;
        }
        switch(choice)
        {
            case 1:
                addNewServer();
                break;
            case 2:
                removeExistingServer();
                break;
            case 3:
                updateServerStatus();
                break;
            case 4:
                updateServerUtilization();
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "Pilihan tidak valid. Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                break;
        }
    }while(!exit);
}
void displaySimpleDataCenterMap()
{
    cout << "\nReferensi Peta Data Center:" << endl;
    cout << "{0} ";
    for (int c = 0; c < DataCenter::Colum; c++)
    {
        if (c == 2 || c == 5)
        {
            cout << "{W}";
        }
        else
        {
            cout << "{" << c + 1 << "}";
        }
    }
    cout << endl;
    
    for (int r = 0; r < DataCenter::Row; r++)
    {
        if (r == 2 || r == 5)
        {
            cout << "{W}" << endl;
            continue;
        }
        cout << "{" << r + 1 << "} ";
        for (int c = 0; c < DataCenter::Colum; c++)
        {
            if (c == 2 || c == 5)
            {
                cout << "   ";
                continue;
            }
            int serverCount = dataCenter.rack[r][c].serverCount;
            if (serverCount > 0)
            {
                cout << "[" << serverCount << "]";
            }
            else
            {
                cout << "[ ]";
            }
        }
        cout << endl;
    }
    cout << "\nKeterangan:" << endl;
    cout << "[ ] = kosong\n";
    cout << "{W} = walkway\n\n";
}
void addNewServer()
{
    system("cls");
    cout << "\n===== Tambah Server Baru =====" << endl;
    displaySimpleDataCenterMap();

    int row;
    int colum;
    bool validLocation = false;
    while (!validLocation)
    {
        cout << "\nMasukkan lokasi untuk server baru:" << endl;
        cout << "Baris [1-" << DataCenter::Row << "]: ";
        cin >> row;
        cout << "Kolom [1-" << DataCenter::Colum << "]: ";
        cin >> colum;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInput tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        row--;
        colum--; // konversi agar sesuai array
        if (!validateServerPlacement(row, colum))
        {
            if (row == 2 || row == 5 || colum == 2 || colum == 5)
            {
                cout << "Error: Lokasi tersebut adalah walkway!" << endl;
            }
            else if (dataCenter.rack[row][colum].serverCount >= dataCenter.rack[row][colum].maxCapacity)
            {
                cout << "Error: Rack sudah penuh! (Kapasitas: " << dataCenter.rack[row][colum].maxCapacity << ")" << endl;
            }
            else
            {
                cout << "Error: Koordinat tidak valid!" << endl;
            }
            cout << "\n\nTekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        validLocation = true;
    }
    ServerUnit newServer;
    displayServerInputForm(newServer);
    if (addServer(dataCenter.rack[row][colum], newServer))
    {
        system("cls");
        cout << "\n===== Tambah Server Baru =====" << endl;
        cout << "============================" << endl;
        cout << "| Server berhasil ditambahkan ke Rack " << dataCenter.rack[row][colum].id << endl;
        cout << "| Server ID: " << newServer.id << endl;
        cout << "| Baris: " << (row + 1) << endl;
        cout << "| Kolom: " << (colum + 1) << endl;
        cout << "============================" << endl;
    }
    cout << "\n\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
    return;
}
void removeExistingServer()
{
    char confirm;
    system("cls");
    cout << "\n===== Hapus Server =====" << endl;
    displaySimpleDataCenterMap();
    int row;
    int colum;
    bool validlocation = false;
    while (!validlocation)
    {
        cout << "\nMasukkan lokasi rack yang berisi server:" << endl;
        cout << "Baris [1-" << DataCenter::Row << "]: ";
        cin >> row;
        cout << "Kolom [1-" << DataCenter::Colum << "]: ";
        cin >> colum;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        row--;
        colum--;
        if (row < 0 || row >= DataCenter::Row || colum < 0 || colum >= DataCenter::Colum)
        {
            cout << "Error: Koordinat tidak valid!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (row == 2 || row == 5 || colum == 2 || colum == 5)
        {
            cout << "Error: Lokasi tersebut adalah walkway!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (dataCenter.rack[row][colum].serverCount == 0)
        {
            cout << "Error: Tidak ada server dalam rack ini!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        validlocation = true;
    }
    ServerRack& rack = dataCenter.rack[row][colum];
    system("cls");
    cout << "\n===== Hapus Server =====" << endl;
    cout << "Server dalam Rack " << rack.id << ":" << endl;
    cout << "+-------+------------+--------------+" << endl;
    cout << "| No.   | Server ID  | Status       |" << endl;
    cout << "+-------+------------+--------------+" << endl;
    for (int i = 0; i < rack.serverCount; i++)
    {
        string statusString;
        switch (rack.servers[i].status)
        {
            case Online:
                statusString = "Online";
                break;
            case Offline:
                statusString = "Offline";
                break;
            case Maintanance:
                statusString = "Maintenance";
                break;
            default:
                statusString = "Unknown";
                break;
        }
        cout << "| " << setw(5) << left << i + 1 << " | "
             << setw(10) << left << rack.servers[i].id << " | "
             << setw(12) << left << statusString << " |" << endl;
    }
    cout << "+-------+------------+--------------+" << endl;
    int serverIndex;
    cout << "\nMasukkan nomor server [1-" << rack.serverCount << "]: ";
    cin >> serverIndex;
    if (cin.fail() || serverIndex < 1 || serverIndex > rack.serverCount)
    {
        cout << "Nomor server tidak valid!" << endl;
        cout << "Tekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }
    serverIndex--; //konversi ke array (ya begitu lah :( )
    string serverIdToDelete = rack.servers[serverIndex].id;
    system("cls");
    cout << "\n===== Hapus Server =====" << endl;
    cout << "Apakah Anda yakin ingin menghapus server '" << serverIdToDelete << "'? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
    {
        if (removeServer(rack, serverIndex))
        {
            cout << "\nServer '" << serverIdToDelete << "' berhasil dihapus" << endl;
        } else
        {
            cout << "\nGagal menghapus server!" << endl;
        }
    } else
    {
        cout << "\nPenghapusan dibatalkan." << endl;
    }
    cout << "Tekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}
void updateServerStatus()
{
    int newStatus;
    system("cls");
    cout << "\n===== Update Status Server =====" << endl;
    displaySimpleDataCenterMap();
    int row;
    int colum;
    bool validlocation = false;
    while (!validlocation)
    {
        cout << "\nMasukkan lokasi rack yang berisi server:" << endl;
        cout << "Baris [1-" << DataCenter::Row << "]: ";
        cin >> row;
        cout << "Kolom [1-" << DataCenter::Colum << "]: ";
        cin >> colum;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        row--;
        colum--;
        if (row < 0 || row >= DataCenter::Row || colum < 0 || colum >= DataCenter::Colum)
        {
            cout << "Error: Koordinat tidak valid!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (row == 2 || row == 5 || colum == 2 || colum == 5)
        {
            cout << "Error: Lokasi tersebut adalah walkway!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (dataCenter.rack[row][colum].serverCount == 0)
        {
            cout << "Error: Tidak ada server dalam rack ini!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        validlocation = true;
    }
    ServerRack& rack = dataCenter.rack[row][colum];
    system("cls");
    cout << "\n===== Update Status Server =====" << endl;
    cout << "Server dalam Rack " << rack.id << ":" << endl;
    cout << "+-------+------------+--------------+" << endl;
    cout << "| No.   | Server ID  | Status       |" << endl;
    cout << "+-------+------------+--------------+" << endl;
    for (int i = 0; i < rack.serverCount; i++)
    {
        string statusString;
        switch (rack.servers[i].status)
        {
            case Online:
                statusString = "Online";
                break;
            case Offline:
                statusString = "Offline";
                break;
            case Maintanance:
                statusString = "Maintenance";
                break;
            default:
                statusString = "Unknown";
                break;
        }
        cout << "| " << setw(5) << left << i + 1 << " | "
             << setw(10) << left << rack.servers[i].id << " | "
             << setw(12) << left << statusString << " |" << endl;
    }
    cout << "+-------+------------+--------------+" << endl;
    int serverIndex;
    cout << "Masukkan nomor server [1-" << rack.serverCount << "]: "; // ADD THIS LINE
    cin >> serverIndex;
    if (cin.fail() || serverIndex < 1 || serverIndex > rack.serverCount)
    {
        cout << "Nomor server tidak valid!" << endl;
        cout << "Tekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }
    serverIndex--;
    ServerUnit& server = rack.servers[serverIndex];
    system("cls");
    cout << "\n===== Update Status Server =====" << endl;
    cout << "| Server yang dipilih: " << server.id << endl;
    cout << "| Status saat ini: ";
    switch (server.status)
    {
        case Online: 
            cout << "Online"; 
            break;
        case Offline: 
            cout << "Offline"; 
            break;
        case Maintanance: 
            cout << "Maintenance"; 
            break;
        default: 
            cout << "Unknown"; 
            break;
    }
    cout << endl;
    cout << "============================" << endl;
    cout << "| Pilih status baru:" << endl;
    cout << "| 1. Offline" << endl;
    cout << "| 2. Online" << endl;
    cout << "| 3. Maintenance" << endl;
    cout << "Pilih [1-3]: ";
    cin >> newStatus;
    system("cls");
    cout << "\n===== Update Status Server =====" << endl;
    switch(newStatus)
    {
        case 1:
            server.status = Offline;
            cout << "\nStatus server berhasil diubah ke Offline!" << endl;
            break;
        case 2:
            server.status = Online;
            cout << "\nStatus server berhasil diubah ke Online!" << endl;
            break;
        case 3:
            server.status = Maintanance;
            cout << "\nStatus server berhasil diubah ke Maintenance!" << endl;
            break;
        default:
            cout << "\nStatus tidak valid!" << endl;
            break;
    }
    cout << "Tekan Enter untuk kembali....";
    cin.ignore();
    cin.get();
}
void updateServerUtilization()
{
    system("cls");
    cout << "\n===== Update Utilisasi Server =====" << endl;
    displaySimpleDataCenterMap();
    int row;
    int colum;
    bool validlocation = false;
    while (!validlocation)
    {
        cout << "\nMasukkan lokasi rack yang berisi server:" << endl;
        cout << "Baris [1-" << DataCenter::Row << "]: ";
        cin >> row;
        cout << "Kolom [1-" << DataCenter::Colum << "]: ";
        cin >> colum;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        row--;
        colum--;
        if (row < 0 || row >= DataCenter::Row || colum < 0 || colum >= DataCenter::Colum)
        {
            cout << "Error: Koordinat tidak valid!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (row == 2 || row == 5 || colum == 2 || colum == 5)
        {
            cout << "Error: Lokasi tersebut adalah walkway!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (dataCenter.rack[row][colum].serverCount == 0)
        {
            cout << "Error: Tidak ada server dalam rack ini!" << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore();
            cin.get();
            continue;
        }
        validlocation = true;
    }
    ServerRack& rack = dataCenter.rack[row][colum];
    system("cls");
    cout << "\n===== Update Utilisasi Server =====" << endl;
    cout << "Server dalam Rack " << rack.id << ":" << endl;
    cout << "+-------+------------+--------------+" << endl;
    cout << "| No.   | Server ID  | Status       |" << endl;
    cout << "+-------+------------+--------------+" << endl;
    for (int i = 0; i < rack.serverCount; i++)
    {
        string statusString;
        switch (rack.servers[i].status)
        {
            case Online:
                statusString = "Online";
                break;
            case Offline:
                statusString = "Offline";
                break;
            case Maintanance:
                statusString = "Maintenance";
                break;
            default:
                statusString = "Unknown";
                break;
        }
        cout << "| " << setw(5) << left << i + 1 << " | "
             << setw(10) << left << rack.servers[i].id << " | "
             << setw(12) << left << statusString << " |" << endl;
    }
    cout << "+-------+------------+--------------+" << endl;
    int serverIndex;
    cout << "Masukkan nomor server [1-" << rack.serverCount << "]: "; // ADD THIS LINE
    cin >> serverIndex;
    if (cin.fail() || serverIndex < 1 || serverIndex > rack.serverCount)
    {
        cout << "Nomor server tidak valid!" << endl;
        cout << "Tekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }
    serverIndex--;
    ServerUnit& server = rack.servers[serverIndex];
    system("cls");
    cout << "\n===== Update Utilisasi Server =====" << endl;
    cout << "| Server yang dipilih: " << server.id << endl;
    cout << "| Utilisasi saat ini: " << server.utilization << "%" << endl;
    float newUtilization;
     cout << "| Masukkan utilisasi baru (0-100%): ";
    cin >> newUtilization;
    cout << "============================" << endl;
    if (newUtilization < 0 || newUtilization > 100)
    {
        cout << "Error: Utilisasi harus antara 0-100%!" << endl;
    }
    else
    {
        server.utilization = newUtilization;
        cout << "\nUtilisasi server berhasil diubah ke " << newUtilization << "%!" << endl;
    }
    cout << "Tekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}
bool validateServerPlacement(int row, int colum)
{
    if (row < 0 || row >= DataCenter::Row || colum < 0 || colum >= DataCenter::Colum)
    {
        return false;
    }

    // Check walkway
    if (row == 2 || row == 5 || colum == 2 || colum == 5)
    {
        return false;
    }
    if (dataCenter.rack[row][colum].serverCount >= dataCenter.rack[row][colum].maxCapacity)
    {
        return false;
    }
    return true;
}
void displayServerInputForm(ServerUnit& server)
{
    int typeChoice;
    int statusChoice;
    system("cls");
    cout << "\n===== Tambah Server Baru =====" << endl;
    cout << "| Masukkan ID Server: ";
    cin.ignore();
    getline(cin, server.id);
    system("cls");
    cout << "\n===== Tambah Server Baru =====" << endl;
    cout << "| Pilih Tipe Server:" << endl;
    cout << "| 1. Web Server" << endl;
    cout << "| 2. Database Server" << endl;
    cout << "| 3. Application Server" << endl;
    cout << "| 4. File Server" << endl;
    cout << "Pilih [1-4]: ";
    cin >> typeChoice;
    switch (typeChoice)
    {
    case 1:
        server.type = Web;
        break;
    case 2:
        server.type = Database;
        break;
    case 3:
        server.type = Application;
        break;
    case 4:
        server.type = File;
        break;
    default:
        server.type = UnCategorized;
        break;
    }
    system("cls");
    cout << "\n===== Tambah Server Baru =====" << endl;
    cout << "| Pilih Status Server:" << endl;
    cout << "| 1. Offline" << endl;
    cout << "| 2. Online" << endl;
    cout << "| 3. Maintenance" << endl;
    cout << "Pilih [1-3]: ";
    cin >> statusChoice;
    switch (statusChoice)
    {
    case 1:
        server.status = Offline;
        break;
    case 2:
        server.status = Online;
        break;
    case 3:
        server.status = Maintanance;
        break;
    default:
        server.status = UnKnown;
        break;
    }
    system("cls");
    cout << "\n===== Tambah Server Baru =====" << endl;
    cout << "| Masukkan Utilisasi (0-100%): ";
    cin >> server.utilization;
    cout << "| Masukkan Kapasitas Storage (GB): ";
    cin >> server.stroageCapacity;
    cout << "| Masukkan Available Storage (GB): ";
    cin >> server.availableStorage;
    cout << "| Masukkan Model Server: ";
    cin.ignore();
    getline(cin, server.model);
    cout << "| Masukkan Jumlah CPU Cores: ";
    cin >> server.cpuCores;
    cout << "| Masukkan RAM (GB): ";
    cin >> server.ram;
    cout << "| Masukkan IP Address: ";
    cin.ignore();
    getline(cin, server.ipAddress);
}

// Fungsi Search dan Filter ***PlaceHolder WIP***
void searchAndFilter()
{
    cout << "\n=== Pencarian & Filter ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Sort Data ***PlaceHolder WIP***
void sortData()
{
    cout << "\n=== Pengurutan Data ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Generate Reports ***PlaceHolder WIP***
void generateReports()
{
    cout << "\n=== Laporan & Statistik ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi Backup & Restore ***PlaceHolder WIP***
void backupAndRestore()
{
    int choice;
    bool exit = false;
    do 
    {
        system("cls");
        cout << "\n===== Backup & Restore Data =====" << endl;
        cout << "1. Save Data ke File (Replace Current)" << endl;
        cout << "2. Backup Data ke File (Create Copy)" << endl;
        cout << "3. Restore Data dari File" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Pilih opsi [1-4]: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        
        switch (choice) {
        case 1:
        {
            system("cls");
            cout << "\n===== Save Data ke File =====" << endl;
            string fileName;
            cout << "Masukkan nama file untuk disimpan (dengan .txt): ";
            cin.ignore();
            getline(cin, fileName);
            ifstream checkFile(fileName);
                if (checkFile.good()) 
                {
                    checkFile.close();
                    char confirm;
                    cout << "\nFile '" << fileName << "' sudah ada." << endl;
                    cout << "Apakah Anda yakin ingin menimpa file tersebut? (y/n): ";
                    cin >> confirm;
                    
                    if (confirm == 'y' || confirm == 'Y') 
                    {
                        saveDataToFile(fileName);
                        cout << "\nFile berhasil ditimpa!" << endl;
                    } else 
                    {
                        cout << "\nPenyimpanan dibatalkan." << endl;
                    }
                } else 
                {
                    saveDataToFile(fileName);
                }
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
        }
        break;
        case 2:
            {
                system("cls");
                cout << "\n===== Backup Data ke File =====" << endl;
                string fileName;
                cout << "Masukkan nama file backup (tanpa .txt): ";
                cin.ignore();
                getline(cin, fileName);
                fileName += "_backup.txt";
                saveDataToFile(fileName);
                cout << "Tekan Enter untuk melanjutkan...";
                cin.get();
            }
            break;
        case 3:
            {
                system("cls");
                cout << "\n===== Restore Data ke File =====" << endl;
                string fileName;
                cout << "Masukkan nama file untuk restore (dengan .txt): ";
                cin.ignore();
                getline(cin, fileName);
                
                ifstream checkFile(fileName);
                if (checkFile.good()) {
                    checkFile.close();
                    loadDataFromFile(fileName);
                    cout << "Data berhasil di-restore dari file: " << fileName << endl;
                } else {
                    cout << "File tidak ditemukan: " << fileName << endl;
                }
                cout << "Tekan Enter untuk melanjutkan...";
                cin.get();
            }
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "Pilihan tidak valid. Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            break;
        }
    } while (!exit);
}

// Fungsi Optimize Rack Layout ***PlaceHolder WIP***
void optimizeRackLayout()
{
    cout << "\n=== Optimasi Penataan Rak ===" << endl;
    cout << "Fitur ini belum diimplementasikan." << endl;
    cout << "\nTekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}
