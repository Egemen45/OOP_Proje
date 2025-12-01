#include "../include/Interface.h"



void Interface::startInterface() {

    string tabela = R"(
       ___   ___  ____     ____   ___   ___  _  __ ____  _____  ___   ____  ____ 
      / _ \ / _ \|  _ \   | __ ) / _ \ / _ \| |/ // ___||_   _|/ _ \ |  _ \| ===|
     | (_) | (_) | |_) |  |  _ \| (_) | (_) | ' / \___ \  | | | (_) || |_) |  __|
      \___/ \___/|  __/   |____/ \___/ \___/|_|\_\|____/  |_|  \___/ |_| \_\ |___|
                 |_|                                                              
    )";

    std::cout << GREEN << tabela << std::endl;

    std::string tanitim = "OOP BOOKSTORE UYGULAMASINA HOSGELDINIZ!!";


    for (int i = 0; i < tanitim.length(); i++)
    {
        std::cout << tanitim[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(75));

    }
    std::cout << "\n";



}


void Interface::customerMenu() {

    int option;
    std::string customerMenu = R"(
        ============================================
                 C U S T O M E R   M E N U            
        ============================================
        [1] Add a new customer                              
        [2] Show the customers                    
        [3] Back
        ============================================
        Select an option >> )";
    std::cout << customerMenu << std::endl;
    std::cin >> option;
    switch (option)
    {
    case 1:
        //beklemede
        break;
    case 2:
        //beklemede
        break;
    case 3:
        mainMenu();
        break;

    default:
        break;
    }



}

void Interface::ItemsMenu() {

    int option;
    std::string ItemsMenu = R"(
        ============================================
                    I T E M S   M E N U            
        ============================================
        [1] Add a new customer                              
        [2] Show the customers                    
        [3] Back
        ============================================
        Select an option >> )";
    std::cout << customerMenu << std::endl;
    std::cin >> option;
    //yapimda


}

void Interface::ShoppingCartMenu() {


    int option;
    std::string ShoppingCartMenu = R"(
        ============================================
                 S H O P P I N G   M E N U            
        ============================================
        [1] Login                             
        [2] Add Product                    
        [3] Remove Product
        [4] List All Products
        [5] List Shopping Cart
        [6] Show Bonus
        [7] Use Bonus
        [8] Place Order
        [9] Cancel Order
        [10] Show Invoice
        [11] Quit
        ============================================
        Select an option >> )";
    std::cout << ShoppingCartMenu << std::endl;
    std::cin >> option;
    switch (option)
    //buradan devam
    {
    case 1:
        break;

    default:
        break;
    }

}

void Interface::mainMenu() {

    int option;
    std::string main_menu = R"(
        ============================================
                    M A I N    M E N U            
        ============================================
        [1] Customer                              
        [2] Items                                 
        [3] Shopping Cart
        [4] Quit Application
        ============================================
        Select an option >> )";
    std::cout << main_menu << std::endl;
    std::cin >> option;

    switch (option)
    {
    case 1:
        customerMenu();
        break;
    case 2:
        ItemsMenu();
        break;
    case 3:
        ShoppingCartMenu();
        break;

    case 4:
        std::cout << "Quitting..." << std::endl;
        break;

    default:
        std::cout << "Irrelevant action please try again" << std::endl;
        mainMenu();
        break;
    }
}