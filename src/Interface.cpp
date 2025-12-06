#include "../include/Interface.h"
#define GREEN "\033[32m"



Interface::Interface() {};
Interface::~Interface() {
    for (int i = 0; i < customers.size(); i++) {
        delete customers[i];
    }
    customers.clear();


}

void Interface::startInterface() {

    std::string tabela = R"(
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
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
    std::cout << "\n";



}

long Interface::setIdFunc() {
    static long val = 1000;

    return ++val;

}

void Interface::addCustomerSystemMenu() {
    long id = setIdFunc();
    std::string name, username, email, password, address, phone;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "Enter the customer name >> " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter the username >> " << std::endl;
    std::getline(std::cin, username);

    std::cout << "Enter the password >> " << std::endl;
    std::getline(std::cin, password);

    std::cout << "Please enter your address >> " << std::endl;
    std::getline(std::cin, address);

    std::cout << "Please enter your phone number to contact like this(05xxxxxxxxx)>> " << std::endl;
    while (true) {
        std::getline(std::cin, phone);
        if (isValidPhone(phone)) break;
        std::cout << "Invalid phone number! Must contain only digits and be at least 10 characters." << std::endl
            << "Try again: ";
    }

    std::cout << "Please enter your email >> " << std::endl;
    while (true) {
        std::getline(std::cin, email);
        if (isValidEmail(email)) break;
        std::cout << "Invalid email! Example: name@example.com\nTry again >> ";
    }

    Customer* newCustomer = new Customer(id, name, username, password);
    newCustomer->setAddress(address);
    newCustomer->setPhone(phone);
    newCustomer->setEmail(email);

    customers.push_back(newCustomer);

    customerMenu();

};

void Interface::showCustomersMenu() {

    std::string showcustomersmenu = R"(
        ============================================
               C U S T O M E R S    D A T A                
        ============================================
    )";

    std::cout << showcustomersmenu << std::endl;

    for (int i = 0; i < customers.size(); i++)
    {
        customers[i]->printProperties();

        std::cout << "==========================================" << std::endl;

    }

    std::string x;
    std::cout << "Please enter to back" << std::endl;
    std::cin >> x;

    customerMenu();



}

void Interface::customerMenu() {

    int option;
    std::string customermenu = R"(
        ============================================
                 C U S T O M E R   M E N U            
        ============================================
        [1] Add a new customer to the system                            
        [2] Show the customers from the sytstem                   
        [3] Back
        ============================================
        )";
    std::cout << customermenu << std::endl;
    std::cout << "Select an option >> ";

    std::cin >> option;
    if (std::cin.fail()) {
        std::cout << "Invalid argument please try again..." << std::endl;

        std::cin.clear();
        std::string trash;
        std::cin >> trash;
        customerMenu();
        return;
    }
    switch (option)
    {
    case 1:
        addCustomerSystemMenu();
        break;
    case 2:
        showCustomersMenu();
        break;
    case 3:
        mainMenu();
        break;

    default:
        std::cout << "Invalid option!" << std::endl;
        customerMenu();
        break;
    }



}

void Interface::addProductMenu() {
    int option;
    std::string addpromenu = R"(
        ============================================
                   A D D  P R O D U C T S           
        ============================================
        [1] Add Book                             
        [2] Add Magazine                     
        [3] Add Music CD
        [4] Back
        ============================================
        )";
    std::cout << addpromenu << std::endl;
    std::cout << "Select an option >> ";
    std::cin >> option;
    if (std::cin.fail()) {
        std::cout << "Invalid argument please try again..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        addProductMenu();
        return;
    }
    switch (option) {
    case 1:
    case 2:
    case 3:
        addProductToSystem(option);
        break;
    case 4:
        ItemsMenu();
        break;
    default:
        std::cout << "Invalid option" << std::endl;
        ItemsMenu();
        break;
    }
}

void Interface::addProductToSystem(int option) {
    std::string name;
    double price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (1) {
        std::cout << "Enter product name: " << std::endl;
        std::getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Product name cannot be empty. Please try again..." << std::endl;
            continue;
        }
        std::cout << "Enter product price: " << std::endl;
        std::cin >> price;
        if (std::cin.fail() || price < 0) {
            std::cout << "Invalid argument please try again..." << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        break;
    }
    Product* p = nullptr;
    switch (option) {
    case 1:
        p = new Book(productsInSystem.size() + 1, name, price);
        break;
    case 2:
        p = new Magazine(productsInSystem.size() + 1, name, price);
        break;
    case 3:
        p = new MusicCD(productsInSystem.size() + 1, name, price);
        break;
    case 4:
        ItemsMenu();
        return;
    default:
        std::cout << "Invalid selection" << std::endl;
        addProductMenu();
        return;
    }
    productsInSystem.push_back(p);
    std::cout << "Product added successfully" << std::endl;
    ItemsMenu();
    return;
}

void Interface::allProductsInSystem() {
    if (productsInSystem.empty()) {
        std::cout << "No products in the system." << std::endl; // listelenecek urun yoksa itemsmenuye geri doner
        ItemsMenu();
        return;
    }
    std::cout << "========== PRODUCTS IN SYSTEM ==========" << std::endl;
    for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) {
        Product* product = *it;
        product->printProperties();
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
    }
    ItemsMenu(); //listeleyip menuye geri dondu
}

void Interface::removeProductFromSystem() {
    if (productsInSystem.empty()) {
        std::cout << "No products available to remove." << std::endl;
        ItemsMenu();
        return;
    }
    allProductsInSystem();
    int id;
    bool removed = false;
    while (!removed) {
        std::cout << "Enter the ID of the product to remove: " << std::endl;
        std::cin >> id;
        if (std::cin.fail()) {
            std::cout << "Invalid argument please try again..." << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        bool found = false;
        for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) {
            if ((*it)->getID() == id) {
                delete* it;
                productsInSystem.erase(it);
                std::cout << "Product removed successfully" << std::endl;
                removed = true;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Product with ID " << id << " not found. Please try again." << std::endl;
        }
    }
    ItemsMenu();
    return;
}

void Interface::searchProductMenu() {
    int option;
    std::string searchpromenu = R"(
        ============================================
                    S E A R C H   M E N U            
        ============================================
        [1] Search by Name                             
        [2] Search by Price Range 
        [3] Search by ID                   
        [4] Back                            
        ============================================
        )";
    std::cout << searchpromenu << std::endl;
    std::cout << "Select an option >> ";
    std::cin >> option;
    if (std::cin.fail()) {
        std::cout << "Invalid argument please try again..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        searchProductMenu();
        return;
    }
    switch (option) {
    case 1:
    case 2:
    case 3:
        searchProducts(option);
        break;
    case 4:
        ItemsMenu();
        break;
    default:
        std::cout << "Invalid option" << std::endl;
        searchProductMenu();
        break;
    }
}

void Interface::ItemsMenu() {
    int opt;
    std::string itemsmenu = R"(
        ============================================
                    I T E M S   M E N U            
        ============================================
        [1] Add products                             
        [2] Remove products                    
        [3] Update products
        [4] List All Products
        [5] Search Products
        [6] Back
        ============================================
        )";
    std::cout << itemsmenu << std::endl;
    std::cout << "Select an option >> ";
    std::cin >> opt;
    if (std::cin.fail()) {
        std::cout << "Invalid argument please try again..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        ItemsMenu();
        return;
    }
    switch (opt) {
    case 1:
        addProductMenu();
        break;
    case 2:
        removeProductFromSystem();
        break;
    case 3:
        updateProducts();
        break;
    case 4:
        allProductsInSystem();
        break;
    case 5:
        searchProductMenu();
        break;
    case 6:
        mainMenu();
        break;
    default:
        std::cout << "Invalid option!" << std::endl;
        ItemsMenu();
        break;
    }

}

void Interface::updateProducts() {
    if (productsInSystem.empty()) {
        std::cout << "No products available to update." << std::endl;
        ItemsMenu();
        return;
    }
    allProductsInSystem();
    Product* p = nullptr;
    int id;
    while (p == nullptr) {
        std::cout << "Enter the ID of the product to update: " << std::endl;
        std::cin >> id;
        if (std::cin.fail()) {
            std::cout << "Invalid argument please try again..." << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) {
            if ((*it)->getID() == id) {
                p = *it;
                break;
            }
        }
        if (p == nullptr) {
            std::cout << "Product with ID " << id << " not found." << std::endl;
        }
    }
    std::cin.ignore();
    std::string newName;
    while (1) {
        std::cout << "Enter new name for the product " << std::endl;
        std::getline(std::cin, newName);
        if (!newName.empty()) break;
        std::cout << "Product name cannot be empty. Please try again..." << std::endl;
    }
    double newPrice;
    while (1) {
        std::cout << "Enter new price for the product " << std::endl;
        std::cin >> newPrice;
        if (!std::cin.fail() && newPrice >= 0) break;
        std::cout << "Invalid price please try again..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
    p->setName(newName);
    p->setPrice(newPrice);
    std::cout << "Product updated successfully" << std::endl;
    ItemsMenu();
    return;
}

void Interface::searchProducts(int option) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (option) {
    case 1: {
        std::string keyword;
        while (true) {
            std::cout << "Enter the product name to search: " << std::endl;
            std::getline(std::cin, keyword);
            if (!keyword.empty()) break;
            std::cout << "Product name cannot be empty. Please try again..." << std::endl;
        }
        vector<Product*> found;
        for (Product* p : productsInSystem) {
            if (p->getName().find(keyword) != string::npos) {
                found.push_back(p);
            }
        }
        if (found.empty()) {
            std::cout << "No products found with the name: " << keyword << std::endl;
        }
        else {
            std::cout << "Products found with the name: " << keyword << std::endl;
            for (Product* p : found) {
                p->printProperties();
                std::cout << "----------------------------------------" << std::endl;
            }
        }
        break;
    }
    case 2: {
        double minPrice, maxPrice;
        while (true) {
            std::cout << "Enter minimum price: " << std::endl;
            if (std::cin >> minPrice) break;
            std::cout << "Invalid number. Try again. " << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        while (true) {
            std::cout << "Enter maximum price: " << std::endl;
            if (std::cin >> maxPrice) break;
            std::cout << "Invalid number. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        if (maxPrice < minPrice) {
            std::swap(minPrice, maxPrice);
        }
        std::vector<Product*>found;
        for (Product* p : productsInSystem) {
            if (p->getPrice() >= minPrice && p->getPrice() <= maxPrice) {
                found.push_back(p);
            }
        }
        if (found.empty()) {
            std::cout << "No products found in the price range: " << minPrice << " - " << maxPrice << std::endl;
        }
        else {
            std::cout << "Products found in the price range: " << minPrice << " - " << maxPrice << std::endl;
            for (Product* p : found) {
                p->printProperties();
                std::cout << "----------------------------------------" << std::endl;
            }
        }
        std::cin.ignore();
        break;
    }
    case 3: {
        int id;
        while (true) {
            std::cout << "Enter the product ID to search: " << std::endl;
            if (std::cin >> id) break;
            std::cout << "Invalid number. Try again: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        Product* founda = nullptr;
        for (Product* p : productsInSystem) {
            if (p->getID() == id) {
                founda = p;
                break;
            }
        }
        if (founda) {
            founda->printProperties();
        }
        else {
            std::cout << "No products found with the ID: " << id << std::endl;
        }
        std::cin.ignore();
        break;
    }
    case 4:
        ItemsMenu();
        return;
    default:
        cout << "Invalid option!" << endl;
        searchProductMenu();
        return;
    }
    ItemsMenu();
    return;
}

void Interface::ShoppingCartMenu() {


    int option;
    std::string shoppingcartmenu = R"(
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
        [11] Back
        ============================================
        )";
    std::cout << shoppingcartmenu << std::endl;
    std::cout << "Select an option >> ";

    std::cin >> option;
    if (cin.fail()) {
        cout << "Invalid argument please try again..." << endl;

        cin.clear();
        string trash;
        cin >> trash;
        ShoppingCartMenu();
        return;
    }
    switch (option)
    {
    case 1:
        login();    //kullanıcı ekleyen yardımcı fonksiyon
        break;

    case 2:
    {
        addProduct();
    }
    break;

    case 3:
    {
        removeProduct();
        break;
    }



    case 4:
        allProducts();  //Urunleri listeleyen fonksiyon

        break;

    case 5:
        shoppingCart.printProducts();  //
        break;

    case 6:
    {
        Customer* tmp = shoppingCart.getCustomer();   //istenilen kullanıcının bonusunu bildiriyoruz
        if (tmp == nullptr) {
            std::cout << "User couldn't find please login!!" << std::endl;

            break;
        }
        std::cout << "Bonus: " << tmp->getBonus() << std::endl;//bonus bilgisi

        break;
    }

    case 7:
        shoppingCart.setBonusUsed();//bonus kullanmak icin fonksiyonu cagırıyoruz
        break;

    case 8:
        shoppingCart.placeOrder();

        break;

    case 9:
        shoppingCart.cancelOrder();//siparis iptal eden fonksiyon

        break;

    case 10:
        shoppingCart.showInvoice();

        break;

    case 11:
        mainMenu();
        return;
    default:
        std::cout << "Gecersiz secenek!!!" << std::endl;

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
        )";

    std::cout << main_menu << std::endl;
    std::cout << "Select an option >> ";
    std::cin >> option;
    if (cin.fail()) {
        cout << "Invalid argument please try again..." << endl;

        cin.clear();
        string trash;
        cin >> trash;
        mainMenu();
        return;
    }

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


    allProducts();
    if (productsInSystem.size() != 0) {
        int num;
        std::cout << "Hangi urunu eklemek istiyorsunuz: " << std::endl;   //kullanıcı ile etkileşim sağlanarak sepete ekleme islemi gerceklestirilir
        std::cin >> num;

        if (num > productsInSystem.size() || num < 1) //gecerli sayı girilip girilmedigi kontrol edilir
        {
            cerr << "gecersiz urun !!!" << std::endl;
            return;
        }

        Product* q = productsInSystem[num - 1];

        ProductToPurchase* p = new  ProductToPurchase();
        p->setProduct(q);

        int adet;                                          //kac adet eklenecegi bilgisini tutar
        std::cout << "Kac adet eklensin: " << std::endl;
        cin >> adet;
        p->setQuantity(adet);                               //adet bilgisi aktarılır


        shoppingCart.addProduct(p);                         //urun eklenir
        std::cout << "Urun artık sepetinizde" << std::endl;
    }
    else {
        std::cout << "Urun yok!!!Ekleme yapılamaz." << std::endl; //urun yok ise hata mesajı kullanıcıya verilir
        return;
    }


}
void Interface::removeProduct() {
    shoppingCart.printProducts();



    int num;
    std::cout << "Cikarmak istediginiz urun kodu: ";
    std::cin >> num;

    if (num < 1) {
        std::cout << "Geçersiz ürün numarası!" << std::endl;
        return;
    }

    std::cout << "Urun sepetten cikarildi" << std::endl;

    return;
}



void Interface::allProducts() {
    if (productsInSystem.size() != 0) {
        cout << "********** PRODUCT LIST **********" << endl;

        for (int j = 0; j < productsInSystem.size(); j++)  //vector icinde geziniyoruz
        {

            cout << j + 1 << ".Product: " << endl;
            productsInSystem[j]->printProperties(); //urun bilgisini yazdırıyoruz
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

    std::cout << "Enter the username: ";  //isim alinir
    std::cin >> name;

    std::cout << "Enter the password: ";  //sifre alinir
    std::cin >> password;

    for (int i = 0; i < customers.size(); i++) { //tum musteri listesini dolasiyoruz

        Customer* tmp = customers[i];

        if (tmp->checkAccount(name, password)) {//Customer sınıfının fonksiyonu ile kontrol saglandi

            shoppingCart.setCustomer(tmp); //musteri  atanir
            std::cout << "Welcome " << std::endl;
            std::cout << "============================================<<" << std::endl;
            std::cout << "Giris durumu : Basarili!" << std::endl;
            std::cout << "Kullanici adi" << name << std::endl;

            ShoppingCartMenu();
            return;

        }


    }

    std::cout << "        Invalid username or password,be careful!!!" << std::endl;
    std::cout << "        ============================================<<" << std::endl;
    std::cout << "        Giris durumu : Oturum acilmadi!" << std::endl;
    ShoppingCartMenu();


}
/*void Interface::login() {

    string name, password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {


        cout << "Enter the username: ";  //isim alinir
        getline(cin, name);

        cout << "Enter the password: ";  //sifre alinir
        getline(cin, password);

        for (int i = 0; i < customers.size(); i++) { //tum musteri listesini dolasiyoruz

            Customer* tmp = customers[i];

            if (tmp->checkAccount(name, password)) {//Customer sınıfının fonksiyonu ile kontrol saglandi

                shoppingCart.setCustomer(tmp); //musteri  atanir
                std::cout << "Welcome " << std::endl;
                std::cout << "============================================<<" << std::endl;
                std::cout << "Giris durumu : Basarili!" << std::endl;
                std::cout << "Kullanici adi" << name << std::endl;



                return;

            }


        }

        cout << "Invalid username or password,be careful!!!" << endl;
        std::cout << "        ============================================<<" << std::endl;
        std::cout << "        Giris durumu : Oturum acilmadi!" << std::endl;



       // cin ile aldıgımız icin hata veriyo
       cout << "Try again?  Enter \"y\" to tes or enter \"n\"to no:  ";
        string c;
        getline(cin, c);

        if (c == 'n' || c == 'N') {
            return; // menüye dönüs yapar
        }


    }
}

*/


//Customer Menu yardımci fonksiyonlari

bool  Interface::isValidPhone(const std::string& phone)
{
    if (phone.length() != 11) {
        return false;
    }
    for (int i = 0; i < phone.length(); i++) {
        if (!isdigit(phone[i])) return false;
    }

    if (phone[0] != '0' || phone[1] != '5') {
        return false;
    }
    return true;

}



bool Interface::isValidEmail(const std::string& email) //girilen e mailin kontrolu gerceklestirildi
{
    bool At = false;
    bool Dot = false;

    int atPos = -1;
    int dotPos = -1;


    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {                          //verilen karakterlerin pozisyonlari bulunur
            At = true;
            atPos = i;
        }
        if (email[i] == '.') {
            Dot = true;
            dotPos = i;
        }
    }

    //@ ve . icermezse email degildir
    if (!(At && Dot))
        return false;

    // @ ilk karakter olursa email gecerli degildir
    if (atPos == 0)
        return false;
    //noktadan once @ kullanilmis olmali
    if (dotPos < atPos)
        return false;

    return true;
}
