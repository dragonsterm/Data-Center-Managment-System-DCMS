#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>

// WIP - Work in Proggres

class Display {
private:
    // Konstanta untuk format tampilan
    int tableWidth = 80;
    const char horizontalLine = '-';
    const char verticalLine = '|';
    const char cornerChar = '+';

public:
    Display();
    ~Display();

    // Fungsi untuk menampilkan header
    void displayHeader(const std::string& title);
    
    // Fungsi untuk menampilkan footer
    void displayFooter(const std::string& message = "");
    
    // Fungsi untuk menampilkan tabel data server
    void displayServerTable();
    
    // Fungsi untuk menampilkan tabel data jaringan
    void displayNetworkTable();
    
    // Fungsi untuk menampilkan tabel data storage
    void displayStorageTable();
    
    // Fungsi untuk visualisasi data center dengan ASCII art
    void displayDataCenterLayout();
    
    // Fungsi untuk menampilkan status sistem secara ringkas
    void displaySystemStatus();
    
    // Fungsi untuk menampilkan pesan konfirmasi
    void displayConfirmation(const std::string& message);
    
    // Fungsi untuk menampilkan pesan error
    void displayError(const std::string& message);
    
    // Fungsi untuk menampilkan pesan sukses
    void displaySuccess(const std::string& message);
    
    // Fungsi untuk menampilkan loading dengan animasi loading menggunakan slowtype pada ... dan delete text
    void displayLoading(const std::string& message);
    
    // Fungsi utilitas untuk format tabel
    void drawHorizontalLine(int width);
    void centerText(const std::string& text, int width);
    
    // Fungsi untuk membersihkan layar
    void clearScreen();
};

#endif