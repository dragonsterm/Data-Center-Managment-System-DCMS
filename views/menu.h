#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

struct MenuItem {
    int id;
    std::string nama;
    std::string deskripsi;
};

struct Menu {
    std::string title;
    std::vector<MenuItem> items;
};

class MenuManager
{
private:
    std::vector<Menu> menus;
    int MenuSekarang;
public:
    MenuManager();
    ~MenuManager();

    void tambahMenu(const std::string& title);
    void tambahMenuItem(int menuindex, const std::string& nama, const std::string& deskripsi);
    void displayMenu(int menuindex);
    int getMenuSekarang() const;
    void setMenuSekarang(int menuindex);
    int getPilihanMenu();
    void displayHeader();
    void displayFooter();
};

#endif 