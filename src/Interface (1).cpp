//HAVA IŞIKLI
//07.12.2025
//YARARLANILAN KAYNAK:
//https://www.geeksforgeeks.org/cpp/exception-handling-c/

#include <iostream>
#include <exception>
#include "Book.h"

using namespace std;

// satir ayirici,her test sonunda uzun uzun yazmamiza gerek yok
void line() {
    cout << "-------------------------------------------" << endl;
}
/*------------------------------------
--------BOOK TEST FONKSİYONU----------
-------------------------------------*/
// Basarili / Basarisiz yazdiran yardimci fonksiyon
void printResult(bool success) {
    if (success)
        cout << "SONUC: BASARILI" << endl;
    else
        cout << "SONUC: BASARISIZ" << endl;
}

void test_book(){
    cout << ">> BOOK SINIFI TESTLERI <<" << endl;
    line();

    // TEST 1: Gecerli kitap olusturma
    {
        cout << "[TEST 1] Gecerli kitap olusturma..." << endl;
        bool success = true;

        try {
            Book b1(1, "OOP Dersleri", 79.90, "Buse", "KodYayin", 320);
            b1.printProperties();
        }
        // e yakalanan hatanın nesnesi,icinde hata mesaji var
        //hatayı yakalayıp mesaji gonderiyoruz
        catch (const exception& e) {
            cout << "Beklenmeyen hata: " << e.what() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 2: Constructor - bos yazar adi (hata beklenir)
    {
        cout << "[TEST 2] Constructor bos author (hata bekleniyor)..." << endl;
        bool success = false; // hata gelirse basarili olacak

//hata durumunda program durmasini onlemek icin try-catch kullaniriz.
//try durumundaki hatayı throw ile firlatiriz,catch bu hatayi yakalar
        try {
            Book b2(2, "Kitap", 45.0, "", "Yayinci", 150);
            cout << "Hata: Exception bekleniyordu fakat firlatilmadi!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata geldi: " << e.what() << endl;
            success = true;
        }

        printResult(success);
        line();
    }

    // TEST 3: Constructor - page = 0 (hata beklenir)
    {
        cout << "[TEST 3] Constructor page=0 (hata bekleniyor)..." << endl;
        bool success = false;

     //PAGE =0 DURUMUNDA HATA BEKLİYORUZ
        try {
            Book b3(3, "Kitap2", 55.5, "Yazar", "Yayinci", 0);
            cout << "Hata: Exception beklendi fakat firlatilmadi!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata geldi: " << e.what() << endl;
            success = true;
        }

        printResult(success);
        line();
    }

    // TEST 4: setAuthor bos string
    {
        cout << "[TEST 4] setAuthor bos (hata bekleniyor)..." << endl;
        bool success = false;

        try {
            Book b4(4, "Kitap3", 30.0, "Yazar", "Yayinci", 100);

            //author null ayarlandı hata bekliyoruz
            b4.setAuthor("");
            cout << "Hata: Exception bekleniyordu fakat firlatilmadi!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata geldi: " << e.what() << endl;
            success = true;
        }

        printResult(success);
        line();
    }

    // TEST 5: setPublisher bos string
    {
        cout << "[TEST 5] setPublisher bos (hata bekleniyor)..." << endl;
        bool success = false;

        try {
            Book b5(5, "Kitap4", 20.0, "Yazar", "Yayinci", 80);

            //publisher null ayarlandı hata bekliyoruz
            b5.setPublisher("");
            cout << "Hata: Exception bekleniyordu fakat firlatilmadi!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata geldi: " << e.what() << endl;
            success = true;
        }

        printResult(success);
        line();
    }

    // TEST 6: setPage negatif deger
    {
        cout << "[TEST 6] setPage negatif (hata bekleniyor)..." << endl;
        bool success = false;

        try {
            Book b6(6, "Kitap5", 99.9, "Yazar", "Yayinci", 200);

            //page negatif deger durumunda hata bekliyoruz
            b6.setPage(-10);
            cout << "Hata: Exception bekleniyordu fakat firlatilmadi!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata geldi: " << e.what() <<"\n"<< endl;
            success = true;
        }

        printResult(success);
        line();
    }

    // TEST 7: Gecerli set islemleri
    {
        cout << "[TEST 7] Gecerli set islemleri..." << endl;
        bool success = true;

        try {
            Book b7(7, "Eski Kitap", 12.34, "Eski Yazar", "Eski Yayinci", 50);

            // Onceki hali
            b7.printProperties();

            //set fonklarimiz dogru calisiyor mu testi
            // Guncelle
            b7.setAuthor("Yeni Yazar");
            b7.setPublisher("Yeni Yayinci");
            b7.setPage(123);

            // Sonrasi
            b7.printProperties();
        }
        catch (const exception& e) {
            cout << "Beklenmeyen hata: " << e.what() <<"\n"<< endl;
            success = false;
        }
        cout<<endl;
        printResult(success);
        line();
    }

    cout << "Tum testler tamamlandi." << endl;
}
/*-----------------------------------------------
-------------BOOK TEST FONKSİYON SUNU------------
------------------------------------------------*/
int main() {

     test_book();

    return 0;
}
