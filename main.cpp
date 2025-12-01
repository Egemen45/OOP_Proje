


#include "C:\Users\egeme\source\repos\main\include\ShoppingCart.h"
#include <chrono>
#include <thread>


#define GREEN "\033[32m"

using namespace std;

void startInterface() {

    string tabela = R"(
       ___   ___  ____     ____   ___   ___  _  __ ____  _____  ___   ____  ____ 
      / _ \ / _ \|  _ \   | __ ) / _ \ / _ \| |/ // ___||_   _|/ _ \ |  _ \| ===|
     | (_) | (_) | |_) |  |  _ \| (_) | (_) | ' / \___ \  | | | (_) || |_) |  __|
      \___/ \___/|  __/   |____/ \___/ \___/|_|\_\|____/  |_|  \___/ |_| \_\ |___|
                 |_|                                                              
    )";

    cout <<GREEN<<tabela << endl;

    string tanitim = "OOP BOOKSTORE UYGULAMASINA HOSGELDINIZ!!";


    for (int i = 0; i < tanitim.length(); i++)
    {
        cout << tanitim[i];
        this_thread::sleep_for(chrono::milliseconds(75));

    }
    cout << "\n";



}

void customerMenu() {

    int option;
    string customerMenu = R"(
        ============================================
                 C U S T O M E R   M E N U            
        ============================================
        [1] Add a new customer                              
        [2] Show the customers                    
        [3] Back
        ============================================
        Select an option >> )";
    cout << customerMenu << endl;
    cin >> option;
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
void ItemsMenu() {

    int option;
    string ItemsMenu = R"(
        ============================================
                    I T E M S   M E N U            
        ============================================
        [1] Add a new customer                              
        [2] Show the customers                    
        [3] Back
        ============================================
        Select an option >> )";
    cout << customerMenu << endl;
    cin >> option;
    //yapimda


}
void ShoppingCartMenu() {


    int option;
    string ShoppingCartMenu = R"(
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
    cout << ShoppingCartMenu << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        break;

    default:
        break;
    }

}















void mainMenu() {

    int option;
    string main_menu = R"(
        ============================================
                    M A I N    M E N U            
        ============================================
        [1] Customer                              
        [2] Items                                 
        [3] Shopping Cart
        [4] Quit Application
        ============================================
        Select an option >> )";
    cout << main_menu << endl;
    cin >> option;

    switch (option)
    {
    case 1 : 
        customerMenu();
        break;
    case 2 :
        ItemsMenu();
        break;
    case 3 :
        ShoppingCartMenu();
        break;

    case 4 :
        cout << "Quitting..." << endl;
        break;

    default:
        cout << "Irrelevant action please try again" << endl;
        mainMenu();
        break;
    }
}


int main()
{
    startInterface();
    mainMenu();



}

