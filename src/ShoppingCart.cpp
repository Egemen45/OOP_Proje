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

void ShoppingCart::addProduct(ProductToPurchase*productToPurchase){ 
	productsToPurchase.push_back(productToPurchase); //alinacak urunu alisveris sepetimize atiyoruz

}

void ShoppingCart::removeProduct(ProductToPurchase* productToPurchase) { //alisveris sepetinden alinacak urunu kaldirmak istiyoruz
	int size = productsToPurchase.size(); // alisveris sepetimizin boyutuna bakiyoruz

	if (size == 0) { // eger sepetimiz bossa return
		std::cout << "Shopping cart is already empty" << std::endl;
		return;
	}
	else {

		std::vector<ProductToPurchase*> temp; // cikarmak istediklerimizden kalanlari bu vectore atacagiz

		for (int i = 0; i < size; i++)
		{
			if (productsToPurchase[i]->getProduct()->getID() == productToPurchase->getProduct()->getID()) { // eger cikarmak istedigimiz degilse temp'e ekleriz
				productsToPurchase[i]->setQuantity(productsToPurchase[i]->getQuantity() - productToPurchase->getQuantity());
				if (productsToPurchase[i]->getQuantity() > 0) {
					temp.push_back(productsToPurchase[i]);

				}
			}
			else {

				temp.push_back(productsToPurchase[i]);

			}

		}
		if (size == temp.size()) { // eger boyutlari birbirine esitse demek ki urun sepette yoktu


			std::cout << "Product couldn't find" << std::endl;

		}
		else {
			productsToPurchase = temp; // degilse yeni sepetimiz temp olur 
		}
	}



	


}

void ShoppingCart::printProducts() {

	std::cout << "***** Inside of the cart *****\n" << std::endl;
	if (productsToPurchase.empty()) {
		std::cout << "Nothings to see here lets buy something!!\n" << std::endl;
	}

	for (int i = 0; i < productsToPurchase.size(); i++) //alisveris sepetimizin icini gosterir 
	{
		std::cout << i + 1 << ". Product" << endl; 
		productsToPurchase[i]->getProduct()->printProperties(); 
		//Alinacak urun uzerinden cagirdigimiz fonksiyonla urunun ozelliklerini yazdiran fonksiyonu cagirdik 
		//her bir urunun ozelliklerini goruruz

	}

}

void ShoppingCart::placeOrder() { 
	//toplam alisveris tutarinin hesaplandigi odeme metodu ve bonus kullaniminin da dahil oldugu kodun neredeyse en onemli kismi
	cout << "Odeme gerceklestiriliyor..." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	double total_price=0.0;
	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		total_price += (productsToPurchase[i]->getProduct()->getPrice()) * productsToPurchase[i]->getQuantity();
		//her bir urunun fiyatini alinan kac tane alindiysa carpip toplam fiyata ekliyoruz



	}
	
	double original_price = total_price;

	if (customer == nullptr) {

		cout << "Customer information couldn't find please login..." << endl;
		return;

	}
	if (original_price == 0.0) { //eger hicbir urun alinmamissa placeorder gerceklesmez
		cout << "Your cart is empty please add something..." << endl;
		return;
	}
	if (customer->getAddress() == "") {
		cout << "Please define your address..." << endl;
	}
	if (paymentMethod == nullptr) {

		cout << "Please add perform method..." << endl;
		return;

	}
	

	if (isBonusUsed) {

		total_price -= customer->getBonus();
		customer->useBonus();

		customer->setBonus(original_price/100);


	}
	else {

		customer->addBonus(original_price / 100);


	}

	paymentMethod->setAmount(total_price);
	paymentMethod->performPayment();

	customer->sendBill();

	isBonusUsed = false;
	productsToPurchase.clear();


}
void ShoppingCart::cancelOrder() {
	if (customer == nullptr) {
		std::cout << "Customer information couldn't taken please login..." << std::endl;
		return;
	}
	if (productsToPurchase.empty()) {
		std::cout << "Your card is already empty" << std::endl;
	}

	isBonusUsed = false;
	productsToPurchase.clear();
	paymentMethod = nullptr;
	std::cout << "Your order has been cancelled" << std::endl;
}

void ShoppingCart::showInvoice() { //showInvoceda bir öncelik var
	if (customer == nullptr) {
		std::cout << "Customer information couldn't taken please login..." << std::endl;
		return;
	}
	std::cout << "*********** Dumenden market fatura bilgileri ***********" << std::endl;

	customer->printProperties();
	std::cout<<std::endl;

	std::cout<<"Urun bilgileri"<<std::endl;


	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		productsToPurchase[i]->getProduct()->printProperties();


	}
	std::cout << "+" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "Total : " << paymentMethod->getAmount()<< std::endl;

}



