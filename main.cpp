


#include "C:\Users\egeme\source\repos\main\include\ShoppingCart.h"
#include "Windows.h"
using namespace std;

void printInterface() {

    string tabela = R"(
    ----------------------------------------------------------------
    |  OOO   OOO   PPPP     M   M   AAA   RRRR   K  K  EEEEE  TTTTT |
    | O   O O   O  P   P    MM MM  A   A  R   R  K K   E        T   |
    | O   O O   O  PPPP     M M M  AAAAA  RRRR   KK    EEE      T   |
    | O   O O   O  P        M   M  A   A  R R    K K   E        T   |
    |  OOO   OOO   P        M   M  A   A  R  RR  K  K  EEEEE    T   |
    ----------------------------------------------------------------
    )";

    cout << tabela << endl;

    string tanitim = "OOP MARKET ALISVERISE HOSGELDINIZ!!";


    for (int i = 0; i < tanitim.length(); i++)
    {
        cout << tanitim[i];
        Sleep(100);

    }


}




int main()
{
    printInterface();



}

