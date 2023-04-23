#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class SoldItem : public Object {

private:

	int makeId;
	int count;

public:

	SoldItem() {
		makeId = 0;
		count = 0;
	}

	SoldItem(int id, string name, int makeId, int count) : Object(id, name) {
		this->makeId = makeId;
		this->count = count;
	}

	int getMakeId() {
		return this->makeId;
	};

	void setMakeId(int make) {
		this->makeId = make;
	};

	int getCount() {
		return this->count;
	};

	void setCount(int count) {
		this->count = count;
	};

	friend class List;
};
