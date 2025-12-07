#include "../include/Interface.h"
#define CYAN    "\033[36m"


Interface::Interface()  {};
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

    std::cout << CYAN << tabela << std::endl;

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

    if (customers.empty()) {

        std::cout << "        No customer data please add a new customer..." << std::endl;
    }



    std::string showcustomersmenu = R"(
        ============================================
               C U S T O M E R S    D A T A                
        ============================================
    )";

    std::cout << showcustomersmenu << std::endl;

    for (int i = 0; i < customers.size(); i++)
    {
        customers[i]->printProperties();

        std::cout << "        ==========================================" << std::endl;

    }


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
        std::cout << "        Invalid argument please try again..." << std::endl;

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
        std::cout << "        Invalid option!" << std::endl;
        customerMenu();
        break;
    }



}
int Interface::nextid() { //when a new product added, we need to assign a unique ID
    //in order to update or remove *that product* only
    return globalid++;
}

void Interface::addProductMenu() { //to add products to the system, user must decide what to add
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
    if (std::cin.fail()) { //invalid input entered
        std::cout << "        Invalid input, please try again." << std::endl;
        std::cin.clear(); //clear the fail state
        std::cin.ignore(); //discard invalid input
        addProductMenu(); //recall the menu
        return;
    }
    switch (option) {
    case 1: //book
    case 2: //magazine
    case 3: //music cd, all three of them need to call the same function
        //with different parameter
        addProductToSystem(option);
        break;
    case 4: //back to items menu
        ItemsMenu();
        break;
    default: //invalid option detected, recall the menu
        std::cout << "        Invalid option, please try again." << std::endl;
        addProductMenu();
        break;
    }
}

void Interface::addProductToSystem(int option) { //after user decides what to add, we need to get the appropiate properties
    //of that product
    std::string name; //common property
    double price; //common property
    std::string author; //book
    std::string publisher; //book
    int page; //book
    std::string singer; //music cd
    std::string type; //magazine and music cd (type/genre)
    int issue; //magazine
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear the input buffer
    //getting common properties
    while (1) { //infinite loop until valid name entered
        std::cout << "Enter product name: " << std::endl;
        std::getline(std::cin, name);
        if (!name.empty()) break; //condition to exit the loop, non-empty name
        std::cout << "Product name cannot be empty, please try again." << std::endl;

    }
    while (1) { //infinite loop until valid price entered
        std::cout << "Enter product price: " << std::endl;
        if (std::cin >> price && price >= 0.0) { //valid price entered, exit the loop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cout << "Invalid price, please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (option) {
    case 1: //book, getting book specific properties
        while (true) { //infinite loop until valid author entered
            std::cout << "Enter author: " << std::endl;
            std::getline(std::cin, author);
            if (!author.empty()) break;
            std::cout << "Author cannot be empty, please try again." << std::endl;
        }
        while (true) { //infinite loop until valid publisher entered
            std::cout << "Enter publisher: " << std::endl;
            std::getline(std::cin, publisher);
            if (!publisher.empty()) break;
            std::cout << "Publisher cannot be empty, please try again." << std::endl;
        }
        while (true) { //infinite loop until valid page count entered
            std::cout << "Enter page count: " << std::endl;
            if (std::cin >> page && page > 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "Invalid page count, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        { //create the book object and add it to the system
            Product* p = new Book(nextid(), name, price, author, publisher, page);
            productsInSystem.push_back(p);
        }
        break;
    case 2: //magazine, getting magazine specific properties
        while (true) { //infinite loop until valid issue number entered
            std::cout << "Enter issue number: " << std::endl;
            if (std::cin >> issue && issue >= 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "Invalid issue number, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        while (true) { //infinite loop until valid type entered
            std::cout << "Enter magazine type: " << std::endl;
            std::getline(std::cin, type);
            if (!type.empty()) break;
            std::cout << "Type cannot be empty, please try again." << std::endl;
        }
        { //create the magazine object and add it to the system
            Product* p = new Magazine(nextid(), name, price, issue, type);
            productsInSystem.push_back(p);
        }
        break;
    case 3: //music cd, getting music cd specific properties
        while (true) { //infinite loop until valid singer entered
            std::cout << "Enter singer: " << std::endl;
            std::getline(std::cin, singer);
            if (!singer.empty()) break;
            std::cout << "Singer cannot be empty, please try again." << std::endl;
        }
        while (true) { //infinite loop until valid type/genre entered,
            //since user cannot choose both magazine and music cd
            //type variable is used for both of them
            std::cout << "Enter music type/genre: " << std::endl;
            std::getline(std::cin, type);
            if (!type.empty()) break;
            std::cout << "Type cannot be empty, please try again." << std::endl;
        }
        { //create the music cd object and add it to the system
            Product* p = new MusicCD(nextid(), name, price, singer, type);
            productsInSystem.push_back(p);
        }
        break;
    case 4: //back
        ItemsMenu();
        return;
    default: //invalid option, recall add product menu
        std::cout << "Invalid selection" << std::endl;
        addProductMenu();
        return;
    }
    std::cout << "Product added successfully" << std::endl;
    ItemsMenu(); //after adding product, return to items menu
}

void Interface::allProductsInSystem() { //list all products in the system
    if (productsInSystem.empty()) {
        std::cout << "No products in the system." << std::endl; // listelenecek urun yoksa itemsmenuye geri doner
        ItemsMenu();
        return;
    }
    std::cout << "        ========== PRODUCTS IN SYSTEM ==========" << std::endl;
    for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) { //using iterators to go through the vector
        Product* product = *it;
        product->printProperties(); //and print each product's properties
        std::cout << std::endl;
        std::cout << "        ============================================" << std::endl;
    } //did not recalled for removing or updating products, it returns straight to itemsmenu
    ItemsMenu(); //listeleyip menuye geri dondu
}

void Interface::removeProductFromSystem() { //removing a product from the system
    if (productsInSystem.empty()) { //if there is no product to remove, return to itemsmenu
        std::cout << "No products available to remove." << std::endl;
        ItemsMenu();
        return;
    } //list all products in the system without recalling allproductsinsystem function
    std::cout << "========== PRODUCTS IN SYSTEM ==========" << std::endl;
    for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) {
        Product* product = *it;
        product->printProperties();
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
    }
    int id; //getting the id of the product, since each product has a unique id
    while (true) { //infinite loop until valid id entered
        std::cout << "Enter the ID of the product to remove: " << std::endl;
        if (!(std::cin >> id)) {
            std::cout << "Invalid ID, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (id == 0) { //since id's start from 1, 0 is invalid
            std::cout << "Product ID cannot be zero, please try again." << std::endl;
            ItemsMenu();
            return;
        }
        bool found = false; //flag to check if product with given id exists
        for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) { //iterating through the vector
            if ((*it)->getID() == id) { //if product with given id found
                delete* it; //free the memory
                productsInSystem.erase(it); //remove the product from system
                std::cout << "Product removed successfully" << std::endl;
                found = true;
                break;
            }
        }
        if (found) break; //exit the loop if product removed successfully
        std::cout << "Product with ID " << id << " not found, please try again." << std::endl;
    }
    ItemsMenu(); //after removing product, return to items menu
    return;
}

void Interface::searchProductMenu() { //to search products in the system, user must decide how to search
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
    if (!(std::cin >> option)) { //invalid input entered
        std::cout << "Invalid input, please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        searchProductMenu(); //recall the menu
        return;
    }
    switch (option) {
    case 1: //search by name
    case 2: //search by price range
    case 3: //search by id, all three of them need to call the same function
        //with different parameter
        searchProducts(option);
        break;
    case 4: //back
        ItemsMenu();
        break;
    default: //invalid option detected, recall the menu
        std::cout << "Invalid option" << std::endl;
        searchProductMenu();
        break;
    }
}

void Interface::ItemsMenu() { //main menu for products
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
    if (std::cin.fail()) { //invalid input entered
        std::cout << "        Invalid input, please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ItemsMenu(); //recall the menu
        return;
    }
    switch (opt) {
    case 1: //add products, call the add product menu
        addProductMenu();
        break;
    case 2: //remove products
        removeProductFromSystem();
        break;
    case 3: //update products
        updateProducts();
        break;
    case 4: //list all products
        allProductsInSystem();
        break;
    case 5: //search products, call the search product menu
        searchProductMenu();
        break;
    case 6: //back
        mainMenu();
        break;
    default: //invalid option, recall the items menu
        std::cout << "Invalid option" << std::endl;
        ItemsMenu();
        break;
    }
}

void Interface::updateProducts() { //updating a product in the system
    if (productsInSystem.empty()) {
        std::cout << "        No products available to update." << std::endl; //if there is no product, return to itemsmenu
        ItemsMenu();
        return;
    } //list all products in the system without recalling allproductsinsystem function
    std::cout << "        ========== PRODUCTS IN SYSTEM ==========" << std::endl;
    for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) {
        Product* product = *it;
        product->printProperties();
        std::cout << std::endl;
        std::cout << "        ============================================" << std::endl;
    }
    Product* p = nullptr;
    int id;
    while (true) { //infinite loop until valid ID entered
        std::cout << "Enter the ID of the product to update: " << std::endl;
        if (!(std::cin >> id)) {
            std::cout << "Invalid ID, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (id <= 0) { //id cannot be negative or zero
            std::cout << "Product ID must be positive, please try again." << std::endl;
            continue;
        }
        for (auto it = productsInSystem.begin(); it != productsInSystem.end(); ++it) { //traverse through the system to search for that product
            if ((*it)->getID() == id) { //if product with given id found
                p = *it; //store the product, since id's are unique there will be only one product with that id.
                break;
            }
        }
        if (p == nullptr) { //if the pointer after the search is still null,
            //there isnt a product with that id
            std::cout << "Product with ID " << id << " not found." << std::endl;
            continue;
        }
        break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string newName; //common property
    //setting common properties
    while (1) { //infinite loop until valid name entered
        std::cout << "Enter new name for the product: " << std::endl;
        std::getline(std::cin, newName);
        if (!newName.empty()) break;
        std::cout << "Product name cannot be empty, please try again." << std::endl;
    }
    double newPrice; //common property
    while (1) { //infinite loop until valid price entered
        std::cout << "Enter new price for the product: " << std::endl;
        if (std::cin >> newPrice && newPrice >= 0.0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cout << "Invalid price, please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    p->setName(newName); //set the new name and new price for that product
    p->setPrice(newPrice);
    //stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
    if (Book* b = dynamic_cast<Book*>(p)) { //if the product is a book, update book properties (author, publisher, page)
        std::string newAuthor;
        while (true) { //infinite loop until valid author entered
            std::cout << "Enter new author: " << std::endl;
            std::getline(std::cin, newAuthor);
            if (!newAuthor.empty()) break;
            std::cout << "Author cannot be empty, please try again." << std::endl;
        }
        std::string newPublisher;
        while (true) { //infinite loop until valid publisher entered
            std::cout << "Enter new publisher: " << std::endl;
            std::getline(std::cin, newPublisher);
            if (!newPublisher.empty()) break;
            std::cout << "Publisher cannot be empty, please try again." << std::endl;
        }
        int newPage;
        while (true) { //infinite loop until valid page number entered
            std::cout << "Enter new page number: " << std::endl;
            if (std::cin >> newPage && newPage > 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "Invalid page number, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        b->setAuthor(newAuthor); //using Book class' set functions to set new author, publisher and page number
        b->setPublisher(newPublisher);
        b->setPage(newPage);
    }
    else if (Magazine* m = dynamic_cast<Magazine*>(p)) { //if the product is a magazine, update magazine properties (issue number and type)
        int newIssue;
        while (true) { //infinite loop until valid issue number entered
            std::cout << "Enter new issue number: " << std::endl;
            if (std::cin >> newIssue && newIssue >= 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "Invalid issue number, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::string newType;
        while (true) { //infinite loop until valid type entered
            std::cout << "Enter new magazine type: " << std::endl;
            std::getline(std::cin, newType);
            if (!newType.empty()) break;
            std::cout << "Type cannot be empty, please try again." << std::endl;
        }
        m->setIssue(newIssue); //using Maganize class' set functions to set new issue number and type
        m->setType(newType);
    }
    else if (MusicCD* mc = dynamic_cast<MusicCD*>(p)) { //if the product is a music cd, update music cd properties type/genre and singer
        std::string newSinger;
        while (true) { //infinite loop until valid singer entered
            std::cout << "Enter new singer: " << std::endl;
            std::getline(std::cin, newSinger);
            if (!newSinger.empty()) break;
            std::cout << "Singer cannot be empty, please try again." << std::endl;
        }
        std::string newType;
        while (true) { //infinite loop until valid type entered
            std::cout << "Enter new music type/genre: " << std::endl;
            std::getline(std::cin, newType);
            if (!newType.empty()) break;
            std::cout << "Type cannot be empty, please try again." << std::endl;
        }
        mc->setSinger(newSinger); //using Music CD class' set functions to set new type and singer
        mc->setType(newType);
    }
    std::cout << "Product updated successfully" << std::endl;
    ItemsMenu(); //return back to items menu
    return;
}
void Interface::searchProducts(int option) { //after user decided which method to search through the system
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (option) {
    case 1: { //by name
        std::string keyword;
        while (true) { //infinite loop until valid name entered
            std::cout << "Enter the product name to search: " << std::endl;
            std::getline(std::cin, keyword);
            if (!keyword.empty()) break;
            std::cout << "Product name cannot be empty, please try again." << std::endl;
        }
        std::string lowerKeyword = keyword; //stackoverflow.com/questions/3152241/case-insensitive-stdstring-find
        std::transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower); //change every character in the name to lower case letters,
        //so that if there is a misspelling of capital letter, search still can be completed
        vector<Product*> found; //there could be more than one product with the same name
        for (Product* p : productsInSystem) { //traverse through the products to get their name,
            std::string lowerName = p->getName();
            std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower); //then change every character in the name to lower case letter
            if (lowerName.find(lowerKeyword) != string::npos) { //if name that is being search has found in the system, then store them
                found.push_back(p);
            }
        }
        if (found.empty()) { //if the vector is empty, there isnt a product with that name
            std::cout << "No products found with the name: " << keyword << std::endl;
        }
        else { //list all the products with the same name with their properties
            std::cout << "Products found with the name: " << keyword << std::endl;
            for (Product* p : found) {
                p->printProperties();
                std::cout << "----------------------------------------" << std::endl;
            }
        }
        break;
    }
    case 2: { //by price range
        double minPrice, maxPrice;
        while (true) { //infinite loop until valid price (min) entered
            std::cout << "Enter minimum price: " << std::endl;
            if (std::cin >> minPrice) break;
            std::cout << "Invalid price number, please try again. " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        while (true) { //infinite loop until valid price (max) entered
            std::cout << "Enter maximum price: " << std::endl;
            if (std::cin >> maxPrice) break;
            std::cout << "Invalid price number, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (maxPrice < minPrice) { //if user accidentally enteres min for max max for min, swap the values
            std::swap(minPrice, maxPrice);
        }
        std::vector<Product*>found; //there could be more than one product within the same prince range
        for (Product* p : productsInSystem) { //traverse through all the products and get their price,
            if (p->getPrice() >= minPrice && p->getPrice() <= maxPrice) { //then check if they are in the price range
                found.push_back(p);
            }
        }
        if (found.empty()) { //if the vector is empty there isnt a product with that range
            std::cout << "No products found in the price range: " << minPrice << " - " << maxPrice << std::endl;
        }
        else { //list all the products within the same price range with their properties
            std::cout << "Products found in the price range: " << minPrice << " - " << maxPrice << std::endl;
            for (Product* p : found) {
                p->printProperties();
                std::cout << "----------------------------------------" << std::endl;
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
    case 3: { //by id
        int id;
        while (true) { //infinite loop until valid ID entered
            std::cout << "Enter the product ID to search: " << std::endl;
            if (std::cin >> id) break;
            std::cout << "Invalid ID, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        Product* founda = nullptr;
        for (Product* p : productsInSystem) { //traverse through all the products and get their ID,
            if (p->getID() == id) { //then check if there is a product with that ID, since ids are
                //unique there will be only one product with that id.
                founda = p;
                break;
            }
        }
        if (founda) { //print properties of the product with that ID number
            founda->printProperties();
        }
        else {
            std::cout << "No products found with the ID: " << id << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
    case 4: //back
        ItemsMenu();
        return;
    default: //invalid option, recall the menu
        cout << "Invalid option." << endl;
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
        [2] Add Product to cart                  
        [3] Remove Products from the cart
        [4] List All Products
        [5] List Shopping Cart
        [6] Show Bonus
        [7] Use Bonus
        [8] Place Order
        [9] Cancel Order
        [10] Show Invoice
        [11] Add payment method
        [12] Back
        ============================================
        )";
    std::cout << shoppingcartmenu << std::endl;
    std::cout << "Select an option >> ";

    std::cin >> option;
    if (cin.fail()) {
        cout << "        Invalid argument please try again..." << endl;

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
        paymentMethodMenu();


    case 12:
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
        cout << "        Invalid argument please try again..." << endl;

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
        std::cout << "        Irrelevant action please try again" << std::endl;
        mainMenu();
        break;
    }
}

void Interface::paymentMethodMenu() {
    //customer var mi yok mu eklenecek

    std::string itemsmenu = R"(
        ============================================
                   P A Y M E N T   M E N U            
        ============================================
        [1] Cash                             
        [2] CreditCard                
        [3] Check
        [4] Back
        ============================================
        )";
    int option;
    cout << itemsmenu << endl;
    std::cout << "Select an option >> ";
    std::cin >> option;
    if (cin.fail()) {
        cout << "        Invalid argument please try again..." << endl;

        cin.clear();
        string trash;
        cin >> trash;
        ShoppingCartMenu();
        return;
    }
    std::string name, bankId;
    Payment* payment = nullptr;
    switch (option)
    {
    case 1:
        payment = new Cash();
        cout << "        Payment method set succesfully cash" << endl;
        break;
    case 2:
       {

        long long number;
        std::cout << "        Enter Credit Card Number: ";
        std::cin >> number;

        string type;
        cout << "        Enter Card Type (Visa/Mastercard/etc): ";
        cin >> type;

        string exp;
        cout << "        Enter Expiration Date (MM/YY): ";
        cin >> exp;


        payment = new CreditCard(number, type, exp);
        cout << "        Payment method set successfully credit card" << endl;

        break;
        }
    case 3:
        cout << "Name: ";
        std::cin >> name;
        std::cout << "Bank ID: ";
        std::cin >> bankId;
        payment = new Check(name, bankId);
        cout << "        Payment method set succesfully check" << endl;

        break;

    default:
        std::cout << "        Irrelevant action please try again..." << std::endl;
        paymentMethodMenu();
        break;
    }


    shoppingCart.setPaymentMethod(payment);




}


//Yardımcı fonksiyonların yazılması emin degilim:(
void Interface::addProduct() {


    allProducts();
    if (productsInSystem.size() != 0) {
        int num;
        std::cout << "        Which product would you like to add : " << std::endl;   //kullanıcı ile etkileşim sağlanarak sepete ekleme islemi gerceklestirilir
        std::cin >> num;

        if (num > productsInSystem.size() || num < 1) //gecerli sayı girilip girilmedigi kontrol edilir
        {
            cerr << "        Invalid product !!!" << std::endl;
            return;
        }

        Product* q = productsInSystem[num - 1];

        ProductToPurchase* p = new  ProductToPurchase();
        p->setProduct(q);

        int adet;                                          //kac adet eklenecegi bilgisini tutar
        std::cout << "        How many products should be added :  " << std::endl;
        cin >> adet;
        p->setQuantity(adet);                               //adet bilgisi aktarılır


        shoppingCart.addProduct(p);                         //urun eklenir
        std::cout << "        Product is in your cart!" << std::endl;
    }
    else {
        std::cout << "        Product couldn't find it can't be added." << std::endl; //urun yok ise hata mesajı kullanıcıya verilir
        return;
    }


}
void Interface::removeProduct() {
    Product* item = nullptr;
    int option,quantity,ID;
    std::string removeproductmenu = R"(
        ============================================
                    R E M O V E    M E N U            
        ============================================
        [1] Remove book                              
        [2] Remove magazin                        
        [3] Remove MusicCd
        [4] Back
        ============================================
        )";

    std::cout << removeproductmenu << std::endl;
    std::cout << "Select an option >> ";
    std::cin >> option;
    if (cin.fail()) {
        cout << "        Invalid argument please try again..." << endl;

        cin.clear();
        string trash;
        cin >> trash;
        removeProduct();
        return;
    }

    std::cout << "Enter the ID >> ";
    std::cin >> ID;
    if (cin.fail()) {
        cout << "        Invalid argument please try again..." << endl;

        cin.clear();
        string trash;
        cin >> trash;
        removeProduct();
        return;
    }

    std::cout << "        Enter the quantity >> ";
    std::cin >> quantity;
    if (cin.fail()) {
        cout << "        Invalid argument please try again..." << endl;

        cin.clear();
        string trash;
        cin >> trash;
        removeProduct();
        return;
    }
    switch (option)
    {
    case 1:
        item = new Book();

        break;
    case 2:
        item = new Magazine();
 

        break;
    case 3:
        item = new MusicCD();
        break;

    case 4:
        ShoppingCartMenu();
        break;

    default:
        std::cout << "        Irrelevant action please try again" << std::endl;
        removeProduct();
        break;
    }

    item->setID(ID);
    ProductToPurchase* n = new ProductToPurchase();
    n->setQuantity(quantity);
    n->setProduct(item);

    shoppingCart.removeProduct(n);
        


    cout << "        Product has been removed" << endl;
    delete n;
    delete item;
    ShoppingCartMenu();
}



void Interface::allProducts() {
    if (productsInSystem.size() != 0) {
        cout << "        ********** PRODUCT LIST **********" << endl;

        for (int j = 0; j < productsInSystem.size(); j++)  //vector icinde geziniyoruz
        {

            cout<<"        " << j + 1 << ".Product: " << endl;
            productsInSystem[j]->printProperties(); //urun bilgisini yazdırıyoruz
            cout << endl;
            cout << endl;

        }


    }
    else {
        cout << "        urun bulunamadi!!!" << endl;
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
            std::cout << "Kullanici adi: " << name << std::endl;

            ShoppingCartMenu();
            return;

        }


    }

    std::cout << "        Invalid username or password,be careful!!!" << std::endl;
    std::cout << "        ============================================<<" << std::endl;
    std::cout << "        Giris durumu : Oturum acilmadi!" << std::endl;

    shoppingCart.cancelOrder();
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

