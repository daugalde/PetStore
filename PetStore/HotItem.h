#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class HotItem : public Object {

private:

	int makeId;

public:

	HotItem() {
		makeId = 0;
	}

	HotItem(int id, string name, int makeId) : Object(id, name) {
		this->makeId = makeId;
	}

	int getMakeId() {
		return this->makeId;
	};

	void setMakeId(int make) {
		this->makeId = make;
	};

	friend class List;
};
