#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Item.h"
#include "List.h"
using namespace std;

class Client : public Object {

private:
	int countryId = 0;
	int cityId = 0;
	string phone = "";
	string address = "";
	string day = "";
	string month = "";
	string year = "";
	List* groceryItems;
	int invoices = 0;
	float totalInvoiced = 0.0;
	int discount = 0;
	float balance = 0.0;

public:  // Constructors

	Client() {}

	Client(int id, string name, string address, int countryId, int cityId ,string clientPhone , string day, string month, string year, int discount, float balance): Object(id, name)
	{
		this->address = address;
		this->phone = clientPhone;
		this->countryId = countryId;
		this->cityId = cityId;
		this->day = day;
		this->month = month;
		this->year = year;
		this->discount = discount;
		this->balance = balance;
	}

	string getPhone() {
		return this->phone;
	};

	void setPhone(string phone) {
		this->phone = phone;
	};

	string getAddress() {
		return this->address;
	};

	void setAddress(string address) {
		this->address = address;
	};

	int getCountryId() {
		return this->countryId;
	};

	void setCountryId(int countryId) {
		this->countryId = countryId;
	};

	int getCityId() {
		return this->cityId;
	};

	void setCityId(int cityId) {
		this->cityId = cityId;
	};

	string getDay() {
		return this->day;
	};

	void setDay(string day) {
		this->day = day;
	};

	string getMonth() {
		return this->month;
	};

	void setMonth(string month){
		this->month = month;
	};

	string getYear() {
		return this->year;
	};

	void setYear(string year) {
		this->year = year;
	};

	int getDiscount() {
		return this->discount;
	};

	void setDiscount(int discount) {
		this->discount = discount;
	};

	float getBalance() {
		return this->balance;
	};

	void setBalance(float balance) {
		this->balance = balance;
	};

	List* getGroceryItems() {
		return this->groceryItems;
	}

	void setGroceryItems(List* groceryItems) {
		this->groceryItems = groceryItems;
	}

	int getInvoices() {
		return this->invoices;
	}

	void setInvoices(int invoices) {
		this->invoices = invoices;
	}

	int getTotalInvoiced() {
		return this->totalInvoiced;
	}

	void setTotalInvoiced(float totalInvoiced) {
		this->totalInvoiced = totalInvoiced;
	}

	void BuyProducts(List* groceryItems) {

		string selectedAsileId;

		string selectedProductId;

		string selectedProductMakeId;

		string selectedProductQuantity;

		do
		{
			getline(cin, selectedAsileId);

			if (selectedAsileId == "")
			{
				selectedAsileId = " ";
			}

			if (Menu::Is_number(selectedAsileId) && groceryItems->HasAisleId(stoi(selectedAsileId)))
			{
				cout << flush;

				system("CLS");

				//Aisle* aisle = static_cast<Aisle*>(groceryItems->GetObjectById(stoi(selectedAsileId)));

				//aisle->setVisits(aisle->getVisits() + 1);

				do {
					if (NULL != NULL)
					{
						cout << flush;

						system("CLS");

						cout << "\nPor favor seleccione el Tipo de producto a comprar\n";

						//aisle->getProductAisles()->Display("productAisle");

						getline(cin, selectedProductId);

						if (Menu::Is_number(selectedProductId))
						{
							//ProductAisle* productsAisle = static_cast<ProductAisle*>(aisle->getProductAisles()->GetObjectByProductId(stoi(selectedProductId)));

							//productsAisle->setVisits(productsAisle->getVisits() + 1);

							do {
								if (NULL != NULL)
								{
									cout << flush;

									system("CLS");

									cout << "\nPor favor seleccione el producto a comprar\n";

									//productsAisle->getProducts()->Display("product");

									getline(cin, selectedProductMakeId);

									if (Menu::Is_number(selectedProductMakeId))
									{
										//Product* product = static_cast<Product*>(productsAisle->getProducts()->GetObjectByMakeProductId(stoi(selectedProductMakeId)));

										if (NULL != NULL)
										{
											//product->setVisits(product->getVisits() + 1);

											cout << "\nPor favor seleccione la Cantidad existe " << "TODO" << " unidades\n";

											getline(cin, selectedProductQuantity);

											if (Menu::Is_number(selectedProductQuantity) && stoi(selectedProductQuantity) <= 1 /*product->getShelfQuantity()*/)
											{
												//Item* item = (new Item(/*product->getId()*/0, product->getName(), product->getMakeId(), product->getPrice(), stoi(selectedProductQuantity)));

												List* list = new List();

												//list->Push(item);

												setGroceryItems(list);
												this->setVisits(this->getVisits() + 1);
												//product->setShelfQuantity(product->getShelfQuantity() - stoi(selectedProductQuantity));
												selectedAsileId = "";
												selectedProductId = "";
											}
											else {
												cout << "\nCantidad invalida" << endl;
											}
										}

									}
									else {
										cout << "\nProducto invalido" << endl;
									}
								}
								else {
									cout << "\nTipo de Producto No encontrado";
									selectedProductId = " ";
								}
							} while (selectedProductId.length() != 0);
						}
						else {
							cout << "\nProducto No encontrado";
						}
					}
					else {
						cout << "\nPasillo No encontrado";
					}
				} while (selectedAsileId.length() != 0);
			}
			else {

				cout << flush;

				system("CLS");

				cout << "\nPor Favor Seleccionar un Pasillo o cualquier tecla para volver al menu anterior " << endl;

				groceryItems->Display("aisle");
			}

			if (selectedAsileId == "")
			{
				cout << "\nLos productos Fueron Agregados a su Canasta." << endl;
				cout << "\nPresione una tecla para continuar." << endl;
			}
		} while (selectedAsileId.length() != 0);

	}

	friend class List;
	//friend class FileLoader;
};