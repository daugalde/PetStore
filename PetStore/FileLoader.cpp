#include <fstream>
#include <iostream>
#include <string>
#include "FileLoader.h"
#include "Store.h"
#include "Client.h"
#include "Pet.h"
#include "Appointment.h"
#include "Treatment.h"
#include "Medication.h"

using namespace std;

FileLoader::~FileLoader()
{
	
}

Store FileLoader::LoadFiles() {

	Store store;

	store.SetCountries(ReadCountriesFile());

	store.SetCities(ReadCitiesFile(store.GetCountries()));

	store.SetClients(ReadAndLoadClientFile());

	store.SetPets(ReadPetsFile(store.GetClients()));

	store.SetAppointments(ReadAppointmentsFile(store.GetPets()));

	store.SetTreatments(ReadAndLoadTreatmentsFile());

	store.SetMedications(ReadAndLoadMedicationsFile(store.GetTreatments()));

	return store;
}

BinaryTree* FileLoader::ReadCountriesFile() {
	string str;

	ifstream file("Paises.txt");

	BinaryTree* bst = new BinaryTree();

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {
			Object* country = new Object();

			string delim = ";";

			size_t pos = 0;

			string token;

			while ((pos = str.find(delim)) != string::npos)
			{
				token = str.substr(0, pos);

				country->setId(stoi(token));

				str.erase(0, pos + delim.length());

			}

			country->setName(str);

			bst->Insert(country);
		}
	}

	//bst->InOrder(bst->GetRoot());
	return bst;
}

BinaryTree* FileLoader::ReadCitiesFile(BinaryTree* countries) {
	string str;

	ifstream file("Ciudades.txt");

	BinaryTree* bst = new BinaryTree();

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {
			Object* city = new Object();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			int countryId = -1;

			while (((pos = str.find(delim)) != string::npos) || count <= 2)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					countryId = stoi(token);
				}
				else if (count == 1 && countryId != -1 )
				{
					city->setId(stoi(token));
				}
				else if (count == 2 && countryId != -1)
				{
					city->setName(token);
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			Object* country = countries->SearchById(countryId, countries->GetRoot());
			if (countryId != -1 && country != NULL)
			{
				bst->Insert(city);
			}
		}
	}

	//bst->InOrder(bst->GetRoot());
	return bst;
}

BinaryTree* FileLoader::ReadPetsFile(BinaryTree* clients) {
	string str;

	ifstream file("Mascotas.txt");

	BinaryTree* bst = new BinaryTree();

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {
			Pet* pet = new Pet();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			int clientId = -1;

			while (((pos = str.find(delim)) != string::npos) || count <= 13)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					pet->setClientId(stoi(token));
				}
				else if (count == 1 )
				{
					pet->setId(stoi(token));
				}
				else if (count == 2 )
				{
					pet->setName(token);
				}
				else if (count == 3)
				{
					pet->setType(token);
				}
				else if (count == 4)
				{
					pet->setBreed(token);
				}
				else if (count == 5)
				{
					pet->setBirthDate(token);
					pet->setBirthDay(token);
				}
				else if (count == 6)
				{
					pet->setBirthDate(pet->getBirthDate() + " " + token);
					pet->setBirthMonth(token);
				}
				else if (count == 7)
				{
					pet->setBirthDate(pet->getBirthDate() + " " + token);
					pet->setBirthYear(token);
				}
				else if (count == 8)
				{
					pet->setSex(token);
				}
				else if (count == 9)
				{
					pet->setColor(token);
				}
				else if (count == 10)
				{
					pet->setCastrated(token);
				}
				else if (count == 11)
				{
					pet->setLastVisitDate(token);
					pet->setLastVisitDay(token);
				}
				else if (count == 12)
				{
					pet->setLastVisitDate(pet->getLastVisitDate() + " " + token);
					pet->setLastVisitMonth(token);
				}
				else if (count == 13)
				{
					pet->setLastVisitDate(pet->getLastVisitDate() + " " + token);
					pet->setLastVisitYear(token);
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			if (clients->SearchById(pet->getClientId(),clients->GetRoot()))
			{
				bst->InsertBalanced(pet);
			}
		}
	}

	//bst->InOrder(bst->GetRoot());
	return bst;
}

BinaryTree* FileLoader::ReadAppointmentsFile(BinaryTree* pets) {
	string str;

	ifstream file("Visitas.txt");

	BinaryTree* bst = new BinaryTree();

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {
			Appointment* appointment = new Appointment();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;


			while (((pos = str.find(delim)) != string::npos) || count <= 6)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					appointment->setId(stoi(token));
				}
				else if (count == 1 )
				{
					appointment->setPetId(stoi(token));
				}
				else if (count == 2)
				{
					appointment->setDay(token);
				}
				else if (count == 3)
				{
					appointment->setMonth(token);
				}
				else if (count == 4)
				{
					appointment->setYear(token);
				}
				else if (count == 5)
				{
					appointment->setTotalInvoiced(stof(token));
				}
				else if (count == 6)
				{
					appointment->setPaymentType(stoi(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			Object* pet = pets->SearchById(appointment->getPetId(), pets->GetRoot());
			if (pet != NULL)
			{
				bst->Insert(appointment);
			}
		}
	}

	//bst->InOrder(bst->GetRoot());
	return bst;
}

RBTree* FileLoader::ReadAndLoadTreatmentsFile() {

	string str;

	ifstream file("Tratamiento.txt");

	RBTree* rbTree = new RBTree();

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			Treatment* treatment = new Treatment();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 2 )
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					treatment->setId(stoi(token));
				}
				else if (count == 1)
				{
					treatment->setName(token);
				}
				else if (count == 2)
				{
					treatment->setPrice(stof(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}
			rbTree->RBInsert(treatment);
		}
	}
	return rbTree;
}

BinaryTree* FileLoader::ReadAndLoadMedicationsFile(RBTree* treatments) {

	string str;

	ifstream file("Medicacion.txt");

	BinaryTree* bst = new BinaryTree();

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {

			Medication* medication = new Medication();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 8)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					medication->setPetId(stoi(token));
				}
				else if (count == 1)
				{
					medication->setId(stoi(token));
				}
				else if (count == 2)
				{
					medication->setLastVisitDay(stoi(token));
				}
				else if (count == 3)
				{
					medication->setLastVisitMonth(stoi(token));
				}
				else if (count == 4)
				{
					medication->setLastVisitYear(stoi(token));
				}
				else if (count == 5)
				{
					medication->setTreatmentId(stoi(str));
				}
				else if (count == 6)
				{
					medication->setUnitPrice(stof(str));
				}
				else if (count == 7)
				{
					medication->setQuantity(stoi(str));
				}
				else if (count == 8)
				{
					medication->setTotalPrice(stof(str));
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			bst->Insert(medication);
		}
		
	}
	return bst;
}

BinaryTree* FileLoader::ReadAndLoadClientFile(){
	string str;

	ifstream file("Clientes.txt");

	BinaryTree* bst = new BinaryTree ();

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			Client* client = new Client();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 10)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					client->setId(stoi(token));
				}
				else if (count == 1)
				{
					client->setName(token);
				}
				else if (count == 2)
				{
					client->setAddress(token);
				}
				else if (count == 3)
				{
					client->setCountryId(stoi(token));
				}
				else if (count == 4)
				{
					client->setCityId(stoi(token));
				}
				else if (count == 5)
				{
					client->setPhone(token);
				}
				else if (count == 6)
				{
					client->setDay(token);
				}
				else if (count == 7)
				{
					client->setMonth(token);
				}
				else if (count == 8)
				{
					client->setYear(token);
				}
				else if (count == 9)
				{
					client->setDiscount(stoi(token));
				}
				else if (count == 10)
				{
					client->setBalance(stoi(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}

			bst->Insert(client);
		}
	}
	return bst;
}