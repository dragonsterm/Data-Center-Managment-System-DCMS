# Struktur Data Center Management System

## File Struktur

```
DataCenterManagementSystem.cpp
```

## Komponen Utama

### Enumerasi (Enum)

#### 1. ServerType
- Web: Server untuk aplikasi web
- Database: Server basis data
- Application: Server aplikasi
- File: Server file
- UnCategorized: Kategori tidak terdefinisi

#### 2. ServerStatus
- Online: Server aktif dan beroperasi
- Offline: Server mati/tidak aktif
- Maintanance: Server dalam pemeliharaan
- UnKnown: Status tidak diketahui

### Struktur Data (Struct)

#### 1. ServerUnit
- **id**: ID unik server (string)
- **type**: Jenis server (enum ServerType)
- **status**: Status operasional (enum ServerStatus)
- **utilization**: Persentase utilisasi CPU (float)
- **stroageCapacity**: Kapasitas penyimpanan total (double)
- **availableStorage**: Penyimpanan tersedia (double)
- **model**: Model server (string, default "Unspecified Model")
- **cpuCores**: Jumlah core CPU (int, default 4)
- **ram**: Kapasitas RAM dalam GB (int, default 8)
- **ipAddress**: Alamat IP server (string, default "0.0.0.0")

#### 2. ServerRack
- **id**: ID rak server (string)
- **location**: Lokasi rak dalam data center (string)
- **maxCapacity**: Kapasitas maksimum server (int, default 5)
- **operationalStatus**: Status operasional rak (bool, default true)
- **serverCount**: Jumlah server saat ini dalam rak (int, default 0)
- **servers**: Array server yang terpasang (ServerUnit[5])

#### 3. DataCenter
- **name**: Nama data center (string)
- **location**: Lokasi data center (string)
- **Row**: Konstanta jumlah baris (8)
- **Colum**: Konstanta jumlah kolom (8)
- **rack**: Array multi-dimensi rak server (ServerRack[8][8])

### Fungsi-Fungsi

#### Fungsi Inisialisasi & Menu
- **main()** - Fungsi utama program yang memanggil startMenu() dan mainMenu()
- **startMenu()** - Menu awal untuk load data atau buat data center baru
- **createNewDataCenter()** - Membuat data center baru (default atau manual)
- **createDataFile()** - Membuat file data kosong baru
- **createSampleDataFile()** - Membuat file data dengan sample data
- **mainMenu()** - Menampilkan menu utama program dengan 7 opsi
- **processChoice()** - Memproses pilihan menu user
- **getCurrentDateTime()** - Mendapatkan waktu dan tanggal saat ini

#### Fungsi Manajemen Server
- **addServer()** - Menambah server baru ke rak tertentu (return bool)
- **removeServer()** - Menghapus server dari rak berdasarkan index (return bool)
- **manageServers()** - Menu manajemen server utama
- **addNewServer()** - Interface untuk menambah server baru (dengan rekursi)
- **removeExistingServer()** - Interface untuk menghapus server
- **updateServerStatus()** - Mengubah status server (Online/Offline/Maintenance)
- **updateServerUtilization()** - Memperbarui persentase utilisasi server
- **validateServerPlacement()** - Validasi penempatan server (return bool)
- **displayServerInputForm()** - Form input data server baru

#### Fungsi Visualisasi
- **displayDataCenterMap()** - Menampilkan peta data center dengan sub-menu
- **displaySimpleDataCenterMap()** - Menampilkan peta sederhana data center
- **displayRackView()** - Menampilkan detail rak dengan input koordinat
- **displayServerDetails()** - Menampilkan detail lengkap server tertentu

#### Fungsi Pencarian (Searching)
- **search()** - Menu pencarian utama dengan 4 opsi
- **findServerByType()** - Mencari server berdasarkan tipe (Sequential Search) - Placeholder
- **findAvailableStorage()** - Mencari server berdasarkan storage tersedia (Binary Search)
- **findServersByStatus()** - Mencari server berdasarkan status (Sequential Search) - Placeholder
- **findServerById()** - Mencari server berdasarkan ID (Binary Search)

#### Fungsi Pengurutan (Sorting)
- **sortData()** - Menu pengurutan utama dengan kriteria berbeda
- **quickSortServersDescending()** - Quick sort descending berdasarkan kriteria
- **partitionForQuickSort()** - Fungsi partisi untuk quick sort
- **insertionSortServersAscending()** - Insertion sort ascending - Placeholder
- **collectAllServersWithRackInfo()** - Mengumpulkan semua server dari seluruh rak

#### Fungsi Pointer
- **swapServers()** - Menukar posisi dua server menggunakan pointer

#### Operasi File
- **saveDataToFile()** - Menyimpan seluruh data ke file dengan format terstruktur
- **loadDataFromFile()** - Membaca dan memuat data dari file

#### Fungsi Laporan & Backup
- **generateReports()** - Menghasilkan laporan lengkap data center ke file
- **backupAndRestore()** - Menu backup dan restore dengan 3 opsi


### Layout Data Center

```
Data center memiliki layout 8x8 dengan walkway (koridor):
- Baris 3 dan 6 adalah walkway horizontal
- Kolom 3 dan 6 adalah walkway vertikal  
- Total: 48 rak server yang dapat digunakan
- Setiap rak dapat menampung maksimal 5 server
```

## Diagram Relasi

```
+-------------------+     contains     +-------------------+     contains     +-------------------+
|                   |----------------->|                   |----------------->|                   |
|    DataCenter     |     1:many       |    ServerRack     |     1:many       |    ServerUnit     |
|    (8x8 matrix)   |<-----------------|    (max 5 units)  |<-----------------|   (individual)    |
+-------------------+                  +-------------------+                  +-------------------+
```

## Fitur yang Diimplementasikan

### 1. Array Multi-dimensi
- DataCenter menggunakan array 2D untuk menyimpan ServerRack[8][8]
- Setiap ServerRack memiliki array ServerUnit[5]

### 2. Struct Lengkap
- Tiga struct utama dengan konstruktor dan data member lengkap
- Enum untuk type dan status server

### 3. Fungsi Rekursif
- addNewServer() memiliki pilihan rekursif untuk menambah server ke rak lain

### 4. Searching
- Binary Search untuk pencarian berdasarkan ID dan Available Storage
- Sequential Search untuk pencarian berdasarkan type dan status (placeholder)

### 5. Sorting
- Quick Sort descending dengan multiple criteria (utilization, storage, CPU, RAM)
- Insertion Sort ascending (placeholder)

### 6. Pointer
- swapServers() menggunakan pointer untuk efisiensi pertukaran data

### 7. Operasi File
- Format file terstruktur untuk save/load data
- Backup dan restore functionality
- Report generation ke file

## Alur Program

1. **Start Menu**: Program dimulai dengan pilihan load data existing atau buat baru
2. **Data Center Setup**: 
   - Load dari file existing, atau
   - Buat baru dengan sample data atau kosong
3. **Main Menu**: 7 opsi utama dengan status system real-time
4. **Operasi**: User dapat melakukan berbagai operasi manajemen
5. **Manual Save**: User harus manual save melalui menu "Save, Backup & Restore" (opsi 6)
6. **Loop**: Kembali ke main menu hingga user memilih keluar

## Status Implementasi

- ✅ **Lengkap**: Struktur data, file operations, visualisasi, sorting, pointer
- ✅ **Sebagian**: Searching (2 dari 4 fungsi aktif)  
- ❌ **Placeholder**: Beberapa fungsi pencarian dan insertion sort
