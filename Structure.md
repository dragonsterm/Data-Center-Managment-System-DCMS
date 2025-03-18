DataCenterManagement/
│
├── main.cpp                  # "Mainboard" utama, program entry point
│
├── models/                   # Folder untuk semua struktur data/model
│   ├── datacenter.h          # Struktur utama data center
│   ├── datacenter.cpp        # Implementasi struktur data center
│   ├── server.h              # Struktur data untuk server
│   ├── server.cpp            # Implementasi server
│   ├── network.h             # Struktur data untuk perangkat jaringan
│   ├── network.cpp           # Implementasi perangkat jaringan
│   └── storage.h             # Struktur data untuk perangkat penyimpanan
│   └── storage.cpp           # Implementasi perangkat penyimpanan
│
├── views/                    # Folder untuk tampilan dan interaksi user
│   ├── menu.h                # Header untuk sistem menu
│   ├── menu.cpp              # Implementasi menu aplikasi
│   ├── display.h             # Header untuk fungsi tampilan
│   ├── display.cpp           # Implementasi tampilan data center
│   ├── input.h               # Header untuk fungsi input
│   └── input.cpp             # Implementasi validasi dan pengambilan input
│
├── controllers/              # Folder untuk logic pengontrol
│   ├── datacenter_ctrl.h     # Kontroler untuk data center
│   ├── datacenter_ctrl.cpp   # Implementasi kontroler data center
│   ├── server_ctrl.h         # Kontroler untuk server
│   ├── server_ctrl.cpp       # Implementasi kontroler server
│   ├── network_ctrl.h        # Kontroler untuk jaringan
│   └── network_ctrl.cpp      # Implementasi kontroler jaringan
│
├── utils/                    # Folder untuk fungsi utilitas
│   ├── fileio.h              # Header untuk operasi file
│   ├── fileio.cpp            # Implementasi operasi file
│   ├── search.h              # Header untuk algoritma pencarian
│   ├── search.cpp            # Implementasi algoritma pencarian
│   ├── sort.h                # Header untuk algoritma pengurutan
│   ├── sort.cpp              # Implementasi algoritma pengurutan
│   ├── report.h              # Header untuk pembuatan laporan
│   └── report.cpp            # Implementasi pembuatan laporan
│
├── data/                     # Folder untuk file data
│   ├── servers.dat           # Data server
│   ├── network.dat           # Data jaringan
│   ├── storage.dat           # Data penyimpanan
│   └── logs.txt              # File log aktivitas
│
├── config/                   # Folder untuk konfigurasi
│   └── settings.txt          # File konfigurasi aplikasi
│
└── Makefile                  # File untuk kompilasi
