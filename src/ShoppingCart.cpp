#include "../include/ShoppingCart.h"
#include "../include/Interface.h"


//EGEMEN ÖZER
//1.12.2025



ShoppingCart::ShoppingCart() : isBonusUsed(false) , paymentMethod(nullptr) {}; //isBonusUsed baslangýcta false olarak ayarlandi
ShoppingCart::~ShoppingCart() {
	for (auto item : productsToPurchase) {
		delete item;
	}
	productsToPurchase.clear();

};


Customer * ShoppingCart::getCustomer() { // customer nesnesini dondurur
	return customer;
}

Payment* ShoppingCart::getPaymentMethod() { //paymentMethodu dondurur
	return paymentMethod;
}


void ShoppingCart::setPaymentMethod(Payment* paymentMethod) {  //payment method shoppingcart nesnesine atandi

	this->paymentMethod = paymentMethod;


}
void ShoppingCart::setCustomer(Customer* customer) { //customeri nesnede bulunan customer degiskenine atadik

	this->customer = customer;


}
void ShoppingCart::setBonusUsed() { //bonus kullanilacaksa isBonusUsed true olur
	if (customer == nullptr) {

		std::cout << "User informations couldn't taken please login..." << std::endl;
	}
	isBonusUsed = true;


}

void ShoppingCart::addProduct(ProductToPurchase*productToPurchase){ //urun ekleme kismi

	for (int i = 0; i < productsToPurchase.size(); i++) //eklenecek olan urunun sepette olup olmadigina bakiyoruz
	{
		if (productsToPurchase[i]->getProduct()->getID() == productToPurchase->getProduct()->getID()) { //eger eklenecek olan urun zaten sepette varsa miktarini artiriyoruz
			productsToPurchase[i]->setQuantity(productsToPurchase[i]->getQuantity() + productToPurchase->getQuantity());
			return;
		}

	}
	//eklenecek olan urun sepette yoksa sepete direkt ekliyoruz
	productsToPurchase.push_back(productToPurchase); 
	
}

void ShoppingCart::removeProduct(ProductToPurchase* productToPurchase) { //alisveris sepetinden alinacak urunu kaldirmak istiyoruz
	int size = productsToPurchase.size(); // alisveris sepetimizin boyutuna bakiyoruz
	bool removed = true; //urunun kaldirildigini mi yoksa sayisinin mi azaldigini gosterecek bool
	if (size == 0) { // eger sepetimiz bossa return
		std::cout << "        Shopping cart is already empty" << std::endl;
		return;
	}
	else {

		std::vector<ProductToPurchase*> temp; // cikarmak istediklerimizden kalanlari bu vectore atacagiz

		for (int i = 0; i < size; i++)
		{
			if (productsToPurchase[i]->getProduct()->getID() == productToPurchase->getProduct()->getID()) {
				//ID'ler her urun icin benzersizdir urunleri dogrudan karsilastirmadan Id uzerinden karsilastirma yapabiliriz


				//sepetimizden kac tane urun cikarmak istiyorsak sepette bulunandan o kadar cikartiriz 
				// sepette 5 tane varsa ve 3 tane cikartmak istiyorsak geriye sepette 2 tane kalir 
				productsToPurchase[i]->setQuantity(productsToPurchase[i]->getQuantity() - productToPurchase->getQuantity());

				//urun sayisi 0 ve altindaysa urun sepette kalmamistir degilse urunden belirli bir miktar cikarilmis ve kalmistir
				if (productsToPurchase[i]->getQuantity() > 0) {
					temp.push_back(productsToPurchase[i]);
					removed = false; //urunun sayisi degismis kaldirilmamis


				}

			}
			else {
				//cikarilmasi istenen urun degilse tempe eklenir
				temp.push_back(productsToPurchase[i]); 
			}

		}
		if (size == temp.size()&& removed) { // eger boyutlari birbirine esitse demek ki urun sepette yoktu


			std::cout << "        Product couldn't find..." << std::endl;

		}
		else {
			productsToPurchase = temp; // degilse yeni sepetimiz temp olur 
		}
	}



	


}

void ShoppingCart::printProducts() {

	std::cout << "        ********* Inside of the cart *********\n" << std::endl;
	if (productsToPurchase.empty()) {
		std::cout << "        Nothings to see here lets buy something!!\n" << std::endl;
	}

	for (int i = 0; i < productsToPurchase.size(); i++) //alisveris sepetimizin icini gosterir 
	{
		std::cout<<"        " << i + 1 << ". Product" << endl;
		productsToPurchase[i]->getProduct()->printProperties(); 
		std::cout<<"        Quantity of the products : " << productsToPurchase[i]->getQuantity() << std::endl;
		std::cout << "============================================" << std::endl;
		//Alinacak urun uzerinden cagirdigimiz fonksiyonla urunun ozelliklerini yazdiran fonksiyonu cagirdik 
		//her bir urunun ozelliklerini goruruz

	}

}

void ShoppingCart::placeOrder() {//toplam alisveris tutarinin hesaplandigi odeme metodu ve bonus kullaniminin da dahil oldugu kodun neredeyse en onemli kismi

	//adres bilgileri alinamazsa odeme gerceklesemez
	if (customer->getAddress() == "") {
		cout << "        Please define your address..." << endl;
	}
	if (paymentMethod == nullptr) { //odeme methodu dogrulanamazsa odeme gerceklesemez

		cout << "        Please add perform method..." << endl;
		return;

	}
	if (customer == nullptr) { //musteri bulunamazsa odeme gerceklesemez

		cout << "        Customer information couldn't find please login..." << endl;
		return;

	}
	cout << "        Odeme gerceklestiriliyor..." << endl; //odeme gerceklesiyor
	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //daha gercekci olsun diye 

	double total_price=0.0;
	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		total_price += (productsToPurchase[i]->getProduct()->getPrice()) * productsToPurchase[i]->getQuantity();
		//her bir urunun fiyatini alinan kac tane alindiysa carpip toplam fiyata ekliyoruz

	}
	
	double original_price = total_price;

	
	if (original_price == 0.0) { //eger hicbir urun alinmamissa placeorder gerceklesmez
		cout << "        Your cart is empty please add something..." << endl;
		return;
	}
	
	

	if (isBonusUsed) { // bonus kullanildiysa toplam fiyattan cikartilir 

		total_price -= customer->getBonus();
		customer->useBonus(); //musteri bonusunu kullanir

		customer->setBonus(original_price/100); 
		//yeni bonus orijinal fiyat uzerinden tekrar belirlenip kullaniciya ekleniyor


	}
	else {

		customer->addBonus(original_price / 100); 


	}

	paymentMethod->setAmount(total_price); //odeme yontemine ekleniyor
	paymentMethod->performPayment(); //odeme gerceklesiyor

	customer->sendBill();

	isBonusUsed = false; //bonus kullanim durumu varsayilan olarak tekrar false alindi


}
void ShoppingCart::cancelOrder() {
	if (customer == nullptr) {
		std::cout << "        Customer information couldn't taken please login..." << std::endl;
		return;
	}
	if (productsToPurchase.empty()) { //sepet bossa siparisi iptal etmeye gerek yok
		std::cout << "        Your card is already empty" << std::endl;
	}

	isBonusUsed = false;  //bonus varsayilan olarak false kalir
	productsToPurchase.clear(); //alisveris sepeti bosaltilir
	paymentMethod = nullptr;//odeme yontemi silinir
	std::cout << "        Your order has been cancelled" << std::endl;
}

void ShoppingCart::showInvoice() { //showInvoceda bir öncelik var
	if (customer == nullptr) { //musteri bilgileri alinamazsa return
		std::cout << "        Customer information couldn't taken please login..." << std::endl;
		return;
	}
	std::cout << "        *********** OOP Market Invoice ***********" << std::endl;

	customer->printProperties(); //Invoice ust kisimda musteri bilgileri
	std::cout<<std::endl;

	std::cout<<"        Product Info"<<std::endl; //sepette bulunan her bir urunun bilgileri 


	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		productsToPurchase[i]->getProduct()->printProperties();
		std::cout << "        Quantity of product : " << productsToPurchase[i]->getQuantity() << std::endl;
		std::cout<<"\n";


	}
	std::cout << "        +" << std::endl;
	std::cout << "        ----------------------" << std::endl;
	std::cout << "        Total : " << paymentMethod->getAmount()<< std::endl;
	productsToPurchase.clear(); //sepetteki urunler bosaltiliyor

}



