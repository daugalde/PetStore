#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Pet : public Object {
private:
	int clientId;
	string type;
	string breed;
	string birthDay;
	string birthMonth;
	string birthYear;
	string birthDate;
	string sex;
	string color;
	string castrated;
	string lastVisitDay;
	string lastVisitMonth;
	string lastVisitYear;
	string lastVisitDate;

public:

	Pet() {

	}

	Pet(int id, string name, int clientid, string castrated) : Object(id, name) {
		this->clientId = clientid;
		this->castrated = castrated;
	}

	Pet(int id, string name, int clientId,string type, string breed, string day, string month, string year, string birthDate, string sex, string color, string castrated, string lastVisitDay, string lastVisitMonth, string lastVisitYear,string lastVisitDate) : Object(id, name) {
		this->clientId = clientId;
		this->type = type;
		this->breed = breed;
		this->birthDay = day,
		this->birthMonth = month;
		this->birthYear = year;
		this->birthDate = birthDate;
		this->sex = sex;
		this->color = color;
		this->castrated = castrated;
		this->lastVisitDate = lastVisitDate;
		this->lastVisitDay = lastVisitDay;
		this->lastVisitMonth = lastVisitMonth;
		this->lastVisitYear = lastVisitYear;
	}

	int getClientId() {
		return clientId;
	};

	void setClientId(int clientId) {
		this->clientId = clientId;
	};

	string getType() {
		return type;
	};

	void setType(string type) {
		this->type = type;
	};

	void setBreed(string breed) {
		this->breed = breed;
	};

	string getBreed() {
		return breed;
	};

	void setBirthDate(string birthDate) {
		this->birthDate = birthDate;
	};

	string getBirthDate() {
		return this->birthDate;
	};

	void setBirthDay(string birthDay) {
		this->birthDay = birthDay;
	};

	string getBirthDay() {
		return this->birthDay;
	};

	void setBirthMonth(string birthMonth) {
		this->birthMonth = birthMonth;
	};

	string getBirthMonth() {
		return this->birthMonth;
	};

	void setBirthYear(string birthYear) {
		this->birthYear = birthYear;
	};

	string getBirthYear() {
		return this->birthYear;
	};

	void setLastVisitDay(string lastVisitDay) {
		this->lastVisitDay = lastVisitDay;
	};

	string getLastVisitDay() {
		return this->lastVisitDay;
	};

	void setLastVisitMonth(string lastVisitMonth) {
		this->lastVisitMonth = lastVisitMonth;
	};

	string getLastVisitMonth() {
		return this->lastVisitMonth;
	};

	void setLastVisitYear(string lastVisitYear) {
		this->lastVisitYear = lastVisitYear;
	};

	string getLastVisitYear() {
		return this->lastVisitYear;
	};

	string getSex() {
		return sex;
	};

	void setSex(string sex) {
		this->sex = sex;
	};

	string getColor() {
		return color;
	};

	void setColor(string color) {
		this->color = color;
	};

	string getCastrated() {
		return castrated;
	};

	void setCastrated(string castrated) {
		this->castrated = castrated;
	};

	string getLastVisitDate() {
		return lastVisitDate;
	};

	void setLastVisitDate(string lastVisitDate) {
		this->lastVisitDate = lastVisitDate;
	};

	friend class List;
};
