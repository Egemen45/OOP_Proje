//HAVA IŞIKLI
//07.12.2025 book-customer
//10.12.2025 check
//YARARLANILAN KAYNAKLAR:
//https://www.geeksforgeeks.org/cpp/exception-handling-c/
//https://medium.com/@eren.dev/projelerde-test-s%C3%BCreci-a8340750ca44
//https://app.hackviser.com/academy/trainings/network-fundamentals

#include <iostream>
#include <exception>
#include "Book.h"
#include "Customer.h"
#include "Check.h"
#include "CreditCard.h"
#include "Magazine.h"
#include "MusicCD.h"
#include "Payment.h"
#include "Product.h"

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

/*-----------------------------------------------
-----------CUSTOMER TEST FONKSIYONU--------------
-------------------------------------------------*/
void test_customer() {
    cout << "\n\n>> CUSTOMER SINIFI TESTLERI <<" << endl;
    line();

    // TEST 1: Varsayilan constructor degerleri
    {
        cout << "[TEST 1] Varsayilan constructor degerleri..." << endl;
        //baslangic success true cunku sartlar saglanmazsa false dondurup basarisiz yazdiririm
        bool success = true;

        Customer c;
        // Beklenen: id = 0, name = "", email = "", bonus = 0
        //Degerler bu sekilde degilse success false olacak ve basarisiz yazisini gorucez
        if (c.getCustomerID() != 0) success = false;
        if (!c.getName().empty()) success = false;
        if (!c.getEmail().empty()) success = false;
        if (c.getBonus() != 0.0) success = false;

        cout<<endl;
        printResult(success);
        line();
    }

    // TEST 2: Parametreli constructor ve checkAccount
    {
        cout << "[TEST 2] Parametreli constructor ve checkAccount..." << endl;
        bool success = true;

        Customer c(12345, "HAVA", "H_user", "sifre1905");
        if (c.getCustomerID() != 12345) success = false;
        if (c.getName() != "HAVA") success = false;

        // checkAccount dogru sifre ile true donmeli
        if (!c.checkAccount("H_user", "sifre1905")) success = false;

        // yanlis sifre ile false
        if (c.checkAccount("H_user", "hatali")) success = false;

        cout<<endl;
        printResult(success);
        line();
    }

    // TEST 3: setCustomerID negatif deger girilirse degismez
    {
        cout << "[TEST 3] setCustomerID negatif deger kontrolu..." << endl;
        bool success = true;

        Customer c;
        c.setCustomerID(50);
        c.setCustomerID(-10); // negatif verilince atanmamali, id = 50 kalmali
        if (c.getCustomerID() != 50) {
            cout << "ID negatif degere degisti: " << c.getCustomerID() << endl;
            success = false;
        }

        cout<<endl;
        printResult(success);
        line();
    }

    // TEST 4: setName icinde hatali karakter kontrolu (rakam/ozel karakter)
    {
        cout << "[TEST 4] setName hatali karakter kontrolu..." << endl;
        bool success = true;

        Customer c;
        c.setName("Mehmet"); // gecerli atansin
        c.setName("Mehmet123"); // hatali, atama yapilmamali
        if (c.getName() != "Mehmet") {
            cout << "Isim hatali karakter ile degistirildi: " << c.getName() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 5: setAddress bos olamaz
    {
        cout << "[TEST 5] setAddress bos olma kontrolu..." << endl;
        bool success = true;

        Customer c;
        c.setAddress("Ankara Mah. 12"); // gecerli
        c.setAddress(""); // bos verilince atama yapilmasin (adres gecerli kalmali)
        if (c.getAddress() != "Ankara Mah. 12") {
            cout << "Adres bos girince degisti: " << c.getAddress() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 6: setPhone sadece rakam kontrolu
    {
        cout << "[TEST 6] setPhone rakam kontrolu..." << endl;
        bool success = true;

        Customer c;
        c.setPhone("05551234567"); // gecerli
        if (c.getPhone() != "05551234567") {
            cout << "Gecerli telefon atanamadi: " << c.getPhone() << endl;
            success = false;
        }

        // simdi hatali tel girisi
        c.setPhone("05A5123B"); // hatali, atama olmamali
        if (c.getPhone() != "05551234567") {
            cout << "Hatali telefon girisi ile degisti: " << c.getPhone() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 7: setEmail '@' ve '.' icerme kontrolu
    {
        cout << "[TEST 7] setEmail format kontrolleri..." << endl;
        bool success = true;

        Customer c;
        c.setEmail("havaexample.com"); // @ yok -> atanmamali
        if (!c.getEmail().empty()) {
            cout << "Hatali email (no @) atandi: " << c.getEmail() << endl;
            success = false;
        }

        c.setEmail("hava@main"); // '.' yok -> atanmamali
        if (!c.getEmail().empty()) {
            cout << "Hatali email (no .) atandi: " << c.getEmail() << endl;
            success = false;
        }

        c.setEmail("hava@main.com"); // gecerli -> atansin
        if (c.getEmail() != "hava@main.com") {
            cout << "Gecerli email atanmadi: " << c.getEmail() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 8: setBonus negatif kontrolu ve setBonus pozitif
    {
        cout << "[TEST 8] setBonus negatif kontrolu ve pozitif atama..." << endl;
        bool success = true;

        Customer c;
        c.setBonus(50.0);
        if (c.getBonus() != 50.0) {
            cout << "Bonus pozitif atama basarisiz: " << c.getBonus() << endl;
            success = false;
        }

        c.setBonus(-20.0); // negatif verilince degismemeli
        if (c.getBonus() != 50.0) {
            cout << "Negatif bonus atamasi yapildi: " << c.getBonus() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 9: addBonus fonksiyonu ile bakiye artisi
    {
        cout << "[TEST 9] addBonus ile bakiye artisi..." << endl;
        bool success = true;

        Customer c;
        c.setBonus(10.0);
        c.addBonus(5.0); // beklenen: bonus 15.0
        //double türü bilgisayarda tam saklanmaz bu yuzden yakasik karsilastirma yaptik
        //iki sayi arasindaki fark 10^-9 dan buyuk ise aynı sayı degil deriz
        if (abs(c.getBonus() - 15.0) > 1e-9) {
            cout << "addBonus beklenen sonucu vermedi. bonus = " << c.getBonus() << endl;
            success = false;
        }

        // negatif addBonus beklenen: degismez
        c.addBonus(-3.0);
        if (abs(c.getBonus() - 15.0) > 1e-9) {
            cout << "Negatif addBonus ile degisti: " << c.getBonus() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

   // TEST 10: useBonus — Tum bonusu tek seferde sifirlama testi
{
    cout << "[TEST 10] useBonus fonksiyonu ..." << endl;
    bool success = true;

    Customer c;
    c.setBonus(80.0); // başlangıç bonusu

    //  Bonus varken useBonus() çağrısı
    c.useBonus();

    // Beklenen: bonus sifirlanmali
    if (abs(c.getBonus() - 0.0) > 1e-9) {
        cout << "HATA: useBonus sonrasi bonus sifirlanmadi. Bonus = "
             << c.getBonus() << endl;
        success = false;
    }

    //  Bonus 0 iken tekrar çağrılırsa değişmemeli
    c.useBonus(); // bu sadece uyarı verecek, bonus 0 kalmalı

    if (abs(c.getBonus() - 0.0) > 1e-9) {
        cout << "HATA: Bonus 0 iken useBonus bonusu degistirdi!" << endl;
        success = false;
    }
    cout<<endl;
    printResult(success);
    line();
}


    // TEST 11: sendBill ciktilari (email yokken ve varken)
    {
        cout << "[TEST 11] sendBill email yokken ve varken..." << endl;
        bool success = true;

        Customer c;
        c.setName("uzay");

        // email bos ise sendBill uyarisi
        c.sendBill(); // beklenen: "Email bilgisi bulunamadi ,fatura gonderilemedi!!!"

        // simdi email setleyip tekrar
        c.setEmail("uzay@example.com");
        c.sendBill(); // beklenen: fatura gonderildi

        // Burada yalnizca programin cagrilmasi basarili kabul ediliyor.
        cout<<endl;
        printResult(success);
        line();
    }
    // TEST 12: printProperties fonksiyonunun cikti testi
    {
        cout << "[TEST 12] printProperties cikti testi..." << endl;
        bool success = true;

        Customer c;
        c.setCustomerID(999);
        c.setName("Hava");
        c.setAddress("Es Street 1");
        c.setPhone("05550000000");
        c.setEmail("hava@main.com");
        c.setUsername("ooop");
        c.setBonus(77.77);

        if(success){
        c.printProperties();
        }
        cout<<endl;
        printResult(success);
        line();
    }

    cout << "Tum testler tamamlandi.\n\n" << endl;
}
/*--------------------------------------------------
------------CUSTOMER TEST FONKSIYONU SONU-----------
---------------------------------------------------*/

/*-------------------------------------------------------
-----------------CHECK CLASS KONTROLU--------------------
---------------------------------------------------------*/

void test_check() {
    cout << "\n\n\n\n>> CHECK SINIFI TESTLERI <<" << endl;
    line();

    // TEST 1: Gecerli constructor
    {
        cout << "[TEST 1] Gecerli constructor..." << endl;
        bool success = true;

        Check c1("Ahmet Yilmaz", "1234");
        if (c1.getName() != "Ahmet Yilmaz") success = false;
        if (c1.getBankID() != "1234") success = false;

        printResult(success);
        line();
    }

    // TEST 2: Constructor - bos name (default 'Unknown' beklenir)
    {
        cout << "[TEST 2] Constructor bos name (Unknown atanacak)..." << endl;
        bool success = true;

        Check c2("", "5678");
        if (c2.getName() != "Unknown") {
            cout << "Beklenen 'Unknown' atanmadi: " << c2.getName() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 3: Constructor - bos bankID (default '0000' beklenir)
    {
        cout << "[TEST 3] Constructor bos bankID (0000 atanacak)..." << endl;
        bool success = true;

        Check c3("Ayse", "");
        if (c3.getBankID() != "0000") {
            cout << "Beklenen '0000' atanmadi: " << c3.getBankID() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 4: setName bos olunca degismemeli
    {
        cout << "[TEST 4] setName bos (degismemeli)..." << endl;
        bool success = true;

        Check c4("Mehmet", "9999");
        c4.setName(""); // hata verip degistirmemeli
        if (c4.getName() != "Mehmet") {
            cout << "Isim bos verilince degisti: " << c4.getName() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 5: setBankID bos olunca degismemeli
    {
        cout << "[TEST 5] setBankID bos (degismemeli)..." << endl;
        bool success = true;

        Check c5("Leyla", "1111");
        c5.setBankID(""); // hata verip degistirmemeli
        if (c5.getBankID() != "1111") {
            cout << "BankID bos verilince degisti: " << c5.getBankID() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 6: setBankID gecerli degisiklik
    {
        cout << "[TEST 6] setBankID gecerli degisiklik..." << endl;
        bool success = true;

        Check c6("Kemal", "2222");
        c6.setBankID("3333");
        if (c6.getBankID() != "3333") {
            cout << "BankID guncellenemedi: " << c6.getBankID() << endl;
            success = false;
        }

        printResult(success);
        line();
    }
}
/*------------------------------------------------------------
--------------------CHECK TEST SONU---------------------------
--------------------------------------------------------------*/

/*------------------------------------------------------------
-------------------CREDIT CARD TESTLERİ-----------------------
--------------------------------------------------------------*/
void test_creditcard() {
    cout << "\n\n>> CREDIT CARD SINIFI TESTLERI <<" << endl;
    line();

    // TEST 1: Geçerli constructor + getters
    {
        cout << "[TEST 1] Gecerli constructor ve getter'lar..." << endl;
        bool success = true;

        CreditCard c1(12345678, "VISA", "12/25");
        if (c1.getNumber() != 12345678) success = false;
        if (c1.getType() != "VISA") success = false;
        if (c1.getExpDate() != "12/25") success = false;

        cout<<"\n\n";
        printResult(success);
        line();
    }

    // TEST 2: setNumber negatif giris reddedilmeli (deger ayni kalmali)
    {
        cout << "[TEST 2] setNumber negatif giris reddedilmeli..." << endl;
        bool success = true;

        CreditCard c2(9999, "MASTERCARD", "01/24");
        c2.setNumber(-50); // negatif, reddedilmeli
        if (c2.getNumber() != 9999) {
            cout << "Negatif sayi atamasi yapildi: " << c2.getNumber() << endl;
            success = false;
        }

        // geçerli pozitif atama
        c2.setNumber(5555);
        if (c2.getNumber() != 5555) {
            cout << "Gecerli sayi atamasi basarisiz: " << c2.getNumber() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 3: setType bos giris reddedilmeli (eski deger korunmali)
    {
        cout << "[TEST 3] setType bos giris reddedilmeli..." << endl;
        bool success = true;

        CreditCard c3(1111, "AMEX", "03/23");
        c3.setType(""); // reddedilmeli
        if (c3.getType() != "AMEX") {
            cout << "Bos type atamasi yapildi: " << c3.getType() << endl;
            success = false;
        }

        // gecerli degisiklik
        c3.setType("VISA");
        if (c3.getType() != "VISA") {
            cout << "Type guncelleme basarisiz: " << c3.getType() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 4: setExpDate bos giris reddedilmeli (eski deger korunmali)
    {
        cout << "[TEST 4] setExpDate bos giris reddedilmeli..." << endl;
        bool success = true;

        CreditCard c4(2222, "VISA", "05/26");
        c4.setExpDate(""); // reddedilmeli
        if (c4.getExpDate() != "05/26") {
            cout << "Bos expDate atamasi yapildi: " << c4.getExpDate() << endl;
            success = false;
        }

        // gecerli degisiklik
        c4.setExpDate("08/28");
        if (c4.getExpDate() != "08/28") {
            cout << "ExpDate guncelleme basarisiz: " << c4.getExpDate() << endl;
            success = false;
        }

        printResult(success);
        line();
    }
    cout << "CreditCard testleri tamamlandi.\n\n" << endl;
}
/*-----------------------------------------------------------------------
-------------------------CREDIT CARD TEST SONU---------------------------
-------------------------------------------------------------------------*/




/*------------------------------------
--------CASH TEST FONKSİYONU----------
-------------------------------------*/

void test_cash() {

    cout << ">> CASH SINIFI TESTLERI <<" << endl;
    line();

    // TEST 1: Gecerli Cash nesnesi olusturma
    {
        cout << "[TEST 1] Gecerli Cash olusturma..." << endl;
        bool success = true;

        try {
            Cash c1(150.0);
            c1.performPayment();
        }
        catch (const exception& e) {
            cout << "Beklenmeyen hata: " << e.what() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 2: Negatif amount ile constructor (hata vercek)
    {
        cout << "[TEST 2] Negatif amount ile constructor (hata bekleniyor)..." << endl;
        bool success = false;

        try {
            Cash c2(-50);  // hata vermeli
            cout << "HATA: Exception bekleniyordu fakat firlatilmadi!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata geldi: " << e.what() << endl;
            success = true;
        }

        printResult(success);
        line();
    }

    // TEST 3: performPayment genel testi
    {
        cout << "[TEST 3] performPayment fonksiyon testi..." << endl;
        bool success = true;

        try {
            Cash c3(300);
            c3.performPayment(); // sadece çıktı verir
        }
        catch (const exception& e) {
            cout << "Beklenmeyen hata: " << e.what() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 4: Sıfır amount ile Cash oluşturma (geçerli olmali)
    {
        cout << "[TEST 4] Amount = 0 olusturma testi..." << endl;
        bool success = true;

        try {
            Cash c4(0);
            c4.performPayment();
        }
        catch (const exception& e) {
            cout << "Beklenmeyen hata: " << e.what() << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    cout << "Tum Cash testleri tamamlandi" << endl;
}

/*-----------------------------------------------
-------------CASH TEST FONKSİYONU SONU-----------
------------------------------------------------*/



/*------------------------------------
--------MAGAZINE TEST FONKSİYONU------
-------------------------------------*/

void test_magazine() {

    cout << ">> MAGAZINE SINIFI TESTLERI <<" << endl;
    line();

    // TEST 1: Gecerli Magazine olusturma testi
    {
        cout << "[TEST 1] Gecerli Magazine olusturma..." << endl;
        bool success = true;

        try {
            Magazine m1(10, " kizilelma", 55.5, 120, "Bilim");
            m1.printProperties();
        }
        catch (...) {
            cout << "Beklenmeyen hata" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 2: Issue negatif verilirse hata mesaji vermeli
    {
        cout << "[TEST 2] setIssue negatif (hata bekleniyor)..." << endl;
        bool success = true;

        Magazine m2(20, "zaman", 30.0, 15, "kultur");
        m2.setIssue(-5);         //  sadece cerr'e yazar, değer değişmez

        if (m2.getIssue() != 15) {
            cout << "Issue negatif verilince degismemesi gerekirken degisti!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 3: setIssue = 0 (hata bekleniyor, degismemeli)
    {
        cout << "[TEST 3] setIssue = 0 (hata bekleniyor)..." << endl;
        bool success = true;

        Magazine m3(21, "Spor", 40.0, 50, "Spor");
        m3.setIssue(0);  // HATA: cerr uyarısı, değişmemeli

        if (m3.getIssue() != 50) {
            cout << "Issue 0 verilince degismemesi gerekirken degisti!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 4: setType bos verilirse hata mesaji beklenir (degismemeli)
    {
        cout << "[TEST 4] setType bos (hata bekleniyor)..." << endl;
        bool success = true;

        Magazine m4(30, "Ekonomi", 25.0, 12, "Ekonomi");
        m4.setType("");           // HATA:sadece cerr, değişmemeli

        if (m4.getType() != "Ekonomi") {
            cout << "Type bos verilince degismemesi gerekirken degisti!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 5: Gecerli set islemleri testi
    {
        cout << "[TEST 5] Gecerli set islemleri" << endl;
        bool success = true;

        Magazine m5(40, "Moda", 60.0, 7, "Lifestyle");

        try {
            m5.printProperties();

            m5.setIssue(99);
            m5.setType("Trend");

            cout << "\n** Guncellenmis Hali **" << endl;
            m5.printProperties();
        }
        catch (...) {
            cout << "Beklenmeyen hata!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    cout << "Tum Magazine testleri tamamlandi\n" << endl;
}

//----------------------------------------------------------
//MUSIC CD TESTLERI------------------------------------------
//------------------------------------------------------------
void test_musicCD() {

    cout << ">> MUSIC CD SINIFI TESTLERI <<" << endl;
    line();

    /*
        MusicCD sınıfında THROW kullanılmıyor.
        Hatalar sadece cerr'e yazdırılıyor.
        Bu yüzden testlerde value değişip değişmediğini kontrol ediyoruz.
    */

    // TEST 1: Gecerli MusicCD olusturma testi
    {
        cout << "[TEST 1] Gecerli MusicCD olusturma..." << endl;
        bool success = true;

        try {
            MusicCD cd1(1, "Best Hits", 49.90, "can bonomo", "Pop");
            cd1.printProperties();
        }
        catch (...) {
            cout << "Beklenmeyen hata olustu!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 2: setSinger bos verilirse hata mesaji vermeli (degismemeli)
    {
        cout << "[TEST 2] setSinger bos (hata bekleniyor)..." << endl;
        bool success = true;

        MusicCD cd2(2, "Album", 30.0, "Tarkan", "Pop");
        cd2.setSinger("");  // cerr yazacak ama değer değişmemeli

        if (cd2.getSinger() != "Tarkan") {
            cout << "Singer bos verilince degismemesi gerekirken degisti!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 3: setType bos verilirse hata mesaji vermeli (degismemeli)
    {
        cout << "[TEST 3] setType bos (hata bekleniyor)..." << endl;
        bool success = true;

        MusicCD cd3(3, "Rock Album", 40.0, "manga", "Rock");
        cd3.setType("");   // cerr uyarısı, değişmemeli

        if (cd3.getType() != "Rock") {
            cout << "Type bos verilince degismemesi gerekirken degisti!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 4: printProperties testi
    {
        cout << "[TEST 4] printProperties testi..." << endl;
        bool success = true;

        try {
            MusicCD cd4(4, "Jazz Essentials", 35.0, "Louis Armstrong", "Jazz");
            cd4.printProperties();
        }
        catch (...) {
            cout << "Beklenmeyen hata!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 5: Gecerli set islemleri testi
    {
        cout << "[TEST 5] Gecerli set islemleri testi..." << endl;
        bool success = true;

        MusicCD cd5(5, "Pop Remix", 55.0, "semicenk", "Pop");

        try {
            cd5.printProperties();

            cd5.setSinger("Beyonce");
            cd5.setType("R&B");

            cout << "\n** Guncellenmis Hali **" << endl;
            cd5.printProperties();
        }
        catch (...) {
            cout << "Beklenmeyen hata olustu!" << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    cout << "Tum MusicCD testleri tamamlandi\n" << endl;
}

//----------------------------------------------------------
// PAYMENT SINIFI TESTLERİ (AMOUNT KONTROLLERİ) --------------
//------------------------------------------------------------

//payment soyut sinif olduğu için direkt bir nesnesi olsuturup test yapılamaz
//cash.cpp de amount için testler zaten yapılmısrır negatif pozitif kontrolleri yapılmıstır
//sadece setAmount() fonksşiyonu için test yazıldı

void test_payment() {


    cout << ">> PAYMENT SINIFI TEMEL KONTROLLERİ (Cash Uzerinden) <<" << endl;
    line();



    // TEST 1: Gecerli Tutarla setAmount() Testi
    {
        cout << "[TEST 1] Gecerli tutarla setAmount() (50.0) testi..." << endl;
        bool success = true;
        Cash c3(10.0);          // Başlangıçta geçerli nesne

        try {
            c3.setAmount(50.0);   //set fonksiyonu testi

            if (c3.getAmount() != 50.0) {
                cerr << "HATA: setAmount() degeri dogru degildir" << endl;
                success = false;
            }
        }
        catch (...) {
            cerr << "Beklenmeyen hata " << endl;
            success = false;
        }

        printResult(success);
        line();
    }

    // TEST 2: Negatif Tutarla setAmount() Testi (Payment::setAmount'daki HATA KONTROLÜ)
    {
        cout << "[TEST 1] Negatif tutarla setAmount() (-5.0) hata vermeli" << endl;
        bool success = false;       // Başlangıçta false, istisna yakalanırsa true olur.
        Cash c4(20.0);
        double initial_amount = c4.getAmount();

        try {
            c4.setAmount(-5.0);
            cerr << "HATA: setAmount() negatif tutar icin istisna firlatmadi." << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Beklenen hata firlatildi: " << e.what() << endl;

            // İstisna fırlatıldıktan sonra tutarın değişmediğini kontrol ediyoruz
            if (c4.getAmount() == initial_amount) {
                success = true;
            } else {
                 cerr << "HATA: setAmount() basarisiz olmasina ragmen tutar degisti" << endl;
            }
        }
        catch (...) {
            cerr << "HATA: std::invalid_argument disinda beklenmeyen bir istisna oldu" << endl;
        }

        printResult(success);
        line();
    }

    cout << "Tum Payment testleri tamamlandi\n" << endl;
}



int main() {
    
    test_book();
    test_customer();
    test_check();
    test_cash();
    test_magazine();
    test_musicCD();
    test_payment();
    
    return 0;
}

