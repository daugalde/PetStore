#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Medication : public Object {

private:
	
	int petId;
	int quantity;
	int treatmentId;
	float unitPrice;
	int lastVisitDay;
	int lastVisitMonth;
	int lastVisitYear;
	float totalPrice;

public:

	Medication() {
		this->petId = 0;
		this->lastVisitDay = 0;
		this->lastVisitMonth = 0;
		this->lastVisitYear = 0;
		this->treatmentId = 0;
		this->unitPrice = 0.00;
		this->quantity = 0;
		this->totalPrice = 0.00;
	}

	Medication(int id, string name, int petId, int lastVisitDay, int lastVisitMonth, int lastVisitYear, int treatmentId, float unitPrice, int quantity, float totalPrice) : Object(id, name) {
		this->petId = petId;
		this->lastVisitDay = lastVisitDay;
		this->lastVisitMonth = lastVisitMonth;
		this->lastVisitYear = lastVisitYear;
		this->treatmentId = treatmentId;
		this->unitPrice = unitPrice;
		this->quantity = quantity;
		this->totalPrice = totalPrice;
	}

	int getPetId() {
		return this->petId;
	};

	void setPetId(int petId) {
		this->petId = petId;
	};

	int getLastVisitDay() {
		return this->lastVisitDay;
	};

	void setLastVisitDay(int lastVisitDay) {
		this->lastVisitDay = lastVisitDay;
	};
	int getLastVisitMonth() {
		return this->lastVisitMonth;
	};

	void setLastVisitMonth(int lastVisitMonth) {
		this->lastVisitMonth = lastVisitMonth;
	};

	int getLastVisitYear() {
		return this->lastVisitYear;
	};

	void setLastVisitYear(int lastVisitYear) {
		this->lastVisitYear = lastVisitYear;
	};

	int getTreatmentId() {
		return this->lastVisitYear;
	};

	void setTreatmentId(int treatmentId) {
		this->treatmentId = treatmentId;
	};

	int getQuantity() {
		return this->quantity;
	};

	void setQuantity(int quantity) {
		this->quantity = quantity;
	};

	float getUnitPrice() {
		return this->unitPrice;
	};

	void setUnitPrice(float unitPrice) {
		this->unitPrice = unitPrice;
	};

	float getTotalPrice() {
		return this->totalPrice;
	};

	void setTotalPrice(float totalPrice) {
		this->totalPrice = totalPrice;
	};

	friend class List;
};
