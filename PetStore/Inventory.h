#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Inventory : public Object {

private:

	int productId;
	int makeId;
	int stockQuantity;
	int isBasicBasket;

public:

	Inventory() {
		productId = 0;
		makeId = 0;
		stockQuantity = 0;
		isBasicBasket = 0;
	}

	Inventory(int id, string name, int make, int stockQuantity, int isBasicBasket) : Object(id, name) {
		this->makeId = make;
		this->stockQuantity = stockQuantity;
		this->isBasicBasket = isBasicBasket;
	}

	int getMakeId() {
		return this->makeId;
	};

	void setMakeId(int make) {
		this->makeId = make;
	};

	int getProductId() {
		return this->productId;
	};

	void setProductId(int productId) {
		this->productId = productId;
	};

	int getStockQuantity() {
		return this->stockQuantity;
	};

	void setStockQuantity(int stockQuantity) {
		this->stockQuantity = stockQuantity;
	};

	int getIsBasicBasket() {
		return this->isBasicBasket;
	};

	void setIsBasicBasket(int isBasicBasket) {
		this->isBasicBasket = isBasicBasket;
	};

	friend class List;
};
