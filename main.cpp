


#include "C:\Users\egeme\source\repos\main\include\ShoppingCart.h"
#include <chrono>
#include <thread>


#define GREEN "\033[32m"

using namespace std;

void printInterface() {

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


}




int main()
{
    printInterface();



}

