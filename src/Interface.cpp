#include "../include/Interface.h"
#define GREEN "\033[32m"





Interface::Interface() {};
Interface::~Interface() {};

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
    static long val= 57439057097543095;

    return ++val;

}


 void Interface::addCustomerSystemMenu() {
    long id = setIdFunc();
    std::string name,username,password,address,phone;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "Enter the customer name >> " << std::endl;
    std::getline(cin, name);

    std::cout << "Enter the username >> " << std::endl;
    std::getline(cin, username);

    std::cout << "Enter the password >> " << std::endl;
    std::getline(cin, password);

    std::cout << "Please enter your address >> " << std::endl;
    std::getline(cin, address);

    std::cout << "Please enter your phone number to contact >> " << std::endl;
    std::getline(cin, phone);

    Customer*newCustomer =  new Customer(id, name, username, password);
    newCustomer->setAddress(address);
    newCustomer->setPhone(phone);

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
        Select an option >> )";
    std::cout << customermenu << std::endl;
    std::cin >> option;
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
        break;
    }



}
 
 void Interface::ItemsMenu() {

    int option;
    std::string itemsmenu = R"(
        ============================================
                    I T E M S   M E N U            
        ============================================
        [1] Add a new customer                              
        [2] Show the customers                    
        [3] Back
        ============================================
        Select an option >> )";
    std::cout << itemsmenu << std::endl;
    std::cin >> option;
    //yapimda

    mainMenu();
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
        Select an option >> )";
    std::cout << shoppingcartmenu << std::endl;
    std::cin >> option;
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


     allProducts();  
     if (products.size() != 0) {
         int num;
         std::cout << "Hangi urunu eklemek istiyorsunuz: " << std::endl;   //kullanıcı ile etkileşim sağlanarak sepete ekleme islemi gerceklestirilir
         std::cin >> num;

         if (num > products.size() || num < 1) //gecerli sayı girilip girilmedigi kontrol edilir
         {
             cerr << "gecersiz urun !!!" << std::endl;
             return;
         }

         Product* q = products[num - 1];

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

     std::cout << "Urun sepetten cikaildi" << std::endl;

     return;
 }



void Interface::allProducts() {
    if (products.size() != 0) {
        cout << "********** PRODUCT LIST **********" << endl;   

        for (int j = 0; j < products.size(); j++)  //vector icinde geziniyoruz
        {
           
            cout << j+1<<".Product: "<<endl;  
            products[j]->printProperties(); //urun bilgisini yazdırıyoruz
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
            std::cout << "============================================<<"<<std::endl;
            std::cout << "Giris durumu : Basarili!" << std::endl;
            std::cout << "Kullanici adi" <<name<<std::endl;

            ShoppingCartMenu();
            return;

        }

      
    }

    std::cout << "        Invalid username or password,be careful!!!"<<std::endl;
    std::cout << "        ============================================<<" << std::endl;
    std::cout << "        Giris durumu : Oturum acilmadi!" << std::endl;
    ShoppingCartMenu();


}


