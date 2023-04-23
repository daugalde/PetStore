#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Item : public Object {

private:

	int aisleId;
	int makeId;
	float price;
	int quantity;

public:

	Item() {
		aisleId = 0;
		makeId = 0;
		price = 0.0;
	}

	Item(int aisleId, string name, int makeId, float price, int quantity) : Object(aisleId, name) {
		this->makeId = makeId;
		this->price = price;
		this->quantity = quantity;
	}

	int getMakeId() {
		return this->makeId;
	};

	void setMakeId(int make) {
		this->makeId = make;
	};

	int getAisleId() {
		return this->aisleId;
	};

	void setAisleId(int aisleId) {
		this->aisleId = aisleId;
	};

	float getPrice() {
		return this->price;
	};

	void setPrice(float price) {
		this->price = price;
	};

	void setQuantity(int quantity) {
		this->quantity = quantity;
	};

	int getQuantity() {
		return this->quantity;
	};

	friend class List;
};
