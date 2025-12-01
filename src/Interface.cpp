#include "../include/Interface.h"

Interface::Interface() {};
Interface::~Interface() {};

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
        login();
        break;

    case 2:
        addProduct();
        break;

    case 3:
        removeProduct();
        break;

    case 4:
        allProducts();
        break;

    case 5:
        shoppingCart.printProducts();
        break;

    case 6:
    {
        Customer* tmp = shoppingCart.getCustomer();
        if (tmp == nullptr) {
            std::cout << "Kullanıcı yok!!" << endl;
            break;
        }
        std::cout << "Bonus: " << tmp->getBonus() << endl;
        break;
    }

    case 7:
        shoppingCart.setBonusUsed();
        break;

    case 8:
        shoppingCart.placeOrder();
        break;

    case 9:
        shoppingCart.cancelOrder();
        break;

    case 10:
        shoppingCart.showInvoice();
        break;

    case 11:
        return;
    default:
        cout << "Gecersiz secenek!!!" << endl;
    
    }
    ShoppingCartMenu();
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




//Yardımcı fonksiyonların yazılması emin degilim:(
void Interface::addProduct() {
//doldurulcak

}
void Interface::removeProduct() {

//doldurulcak

}
void Interface::allProducts() {
    if (products.size() != 0) {
        cout << "********** PRODUCT LIST **********" << endl;

        for (int j = 0; j < products.size(); j++)
        {
           
            cout << j+1<<".Product: "<<endl;
            products[j]->printProperties();
            cout << endl;
            cout << endl;
            
        }


    }
    else {
        cout << "urun bulunamadi!!!" << endl;
        return;
    }


}
void Interface::login() {

    string name, password;

    cout << "Enter the username: ";  //isim alinir
    cin >> name;

    cout << "Enter the password: ";  //sifre alinir
    cin >> password;

    for (int i = 0; i < customer.size(); i++) { //tum musteri listesini dolasiyoruz

        Customer* tmp = customers[i];

        if (tmp->checkAccount(name, password)) {//Customer sınıfının fonksiyonu ile kontrol saglandi

            shoppingCart.setCustomer(tmp); //musteri  atanir

            return;

        }

      
    }

    cout << "Invalid username or password,be careful!!!"<<endl;

}

