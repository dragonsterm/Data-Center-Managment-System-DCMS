# Struktur Data Center Management System

## File Struktur

```
DataCenterManagementSystem.cpp
```

## Komponen Utama

### Struktur Data (Struct)

#### 1. ServerUnit
- Merepresentasikan satu unit server dalam rak
- Menyimpan informasi:
  - Jenis/tipe server
  - Status operasional (online, offline, maintenance)
  - Persentase utilisasi
  - Kapasitas penyimpanan total
  - Penyimpanan tersedia
  - Informasi spesifikasi teknis

#### 2. ServerRack
- Merepresentasikan rak server
- Menyimpan informasi:
  - Lokasi rak (ruangan, zona)
  - Kapasitas maksimum server
  - Array server yang terpasang
  - Status keseluruhan rak

#### 3. DataCenter
- Struktur utama yang merepresentasikan keseluruhan data center
- Berisi array multi-dimensi dari ServerRack
- Informasi tentang layout data center

### Fungsi-Fungsi

#### Fungsi Inisialisasi & Dasar
- **initializeDataCenter()** - Inisialisasi struktur data center dengan default values
- **mainMenu()** - Menampilkan menu utama program
- **processChoice()** - Memproses pilihan menu user

#### Fungsi Manajemen Server
- **addServer()** - Menambah server baru ke rak tertentu
- **removeServer()** - Menghapus server dari rak
- **updateServerStatus()** - Mengubah status server
- **updateServerUtilization()** - Memperbarui metrik utilisasi

#### Fungsi Visualisasi
- **displayDataCenterMap()** - Menampilkan peta data center secara keseluruhan
- **displayRackView()** - Menampilkan visualisasi rak dengan server-servernya
- **displayServerDetails()** - Menampilkan detail lengkap server tertentu

#### Fungsi Pencarian (Searching)
- **findServerByType()** - Mencari server berdasarkan jenisnya (sentinel)
- **findAvailableStorage()** - Mencari server dengan storage tersedia (Binary Search)
- **findServersByStatus()** - Mencari server berdasarkan status bin (Non-Sentinel)
- **findServerById()** - Mencari Server bedasarkan ID (Binary Search)

#### Fungsi Pengurutan (Sorting)
- **insertionSortServersAscending()** - Mengurutkan naik dengan insertion sort
- **quickSortServersDescending()** - Mengurutkan turun dengan quick sort
- **partitionForQuickSort()** - Fungsi pendukung untuk algoritma quick sort

#### Fungsi Rekursif
- **calculateTotalStorageRecursive()** - Menghitung total penyimpanan secara rekursif
- **traverseDataCenterRecursive()** - Melakukan traversal struktur data center

#### Fungsi Pointer
- **swapServers()** - Menukar posisi dua server menggunakan pointer
- **optimizeRackSpace()** - Optimasi penempatan server menggunakan pointer

#### Operasi File
- **saveDataToFile()** - Menyimpan seluruh data ke file lokal
- **loadDataFromFile()** - Membaca data dari file yang tersimpan

#### Fungsi Utilitas & Pembantu
- **generateReports()** - Menghasilkan laporan statistik data center
- **validateServerPlacement()** - Validasi lokasi penempatan server
- **calculateUtilizationMetrics()** - Menghitung metrik utilisasi

## Diagram Relasi

+-------------------+     contains     +-------------------+     contains     +-------------------+
|                   |----------------->|                   |----------------->|                   |
|    DataCenter     |     1:many       |    ServerRack     |     1:many       |    ServerUnit     |
|                   |<-----------------|                   |<-----------------|                   |
+-------------------+                  +-------------------+                  +-------------------+


## Alur Program

1. Program dimulai dengan inisialisasi data center
2. Menampilkan menu utama
3. User memilih opsi (manajemen server, visualisasi, pencarian, dll)
4. Program memproses pilihan user
5. Program menyimpan data secara otomatis setelah modifikasi
6. Repeat dari langkah 2 sampai user memilih untuk keluar
