#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Treatment : public Object {

private:

	float price;

public:

	Treatment() {
		price = 0.0;
	}

	Treatment(int id, string name, float price) : Object(id, name) {
		this->price = price;
	}

	float getPrice() {
		return this->price;
	};

	void setPrice(float price) {
		this->price = price;
	};

	friend class List;
};
