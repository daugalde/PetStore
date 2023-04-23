#pragma once
#include <iostream>
#include <string>
#include "FileLoader.h"
#include "Client.h"
#include "Store.h"
#include "List.h"
using namespace std;

class AppManager {

private:
	Store store;
	List* processedClients;

public:  // Constructors

	AppManager() {
		processedClients = new List();
	}

	Store getStore() {
		return store;
	}

	void setStore(Store store) {
		this->store = store;
	}

	void setProcessedClients(List* list) {
		this->processedClients = list;
	}

	List* getProcessedClients() {
		return processedClients;
	}

	void InitStoreLoad();

	void DataManager();

	void ExecuteCommandByType(int type);

	void InsertCountry();

	void InsertCity();

	void InsertClient();

	void InsertPet();

	void InsertAppointment();

	void InsertTreatment();

	void InsertMedication();

	void SearchCountry();

	void SearchCity();
	
	void SearchClient();

	void SearchPet();

	void SearchAppointment();

	void SearchTreatment();

	void SearchMedication();

	void UpdateCountry();

	void UpdateCity();

	void UpdateClient();

	void UpdatePet();

	void UpdateAppointment();

	void UpdateTreatment();

	void UpdateMedication();

	Client* GetValidRegisteredClient(string clientId);

	void QueueClient(Client* c);

	void BillClient();

	void CheckIfShelfShouldBeLoaded();

	void CheckIfInvetoryShouldBeLoaded();

	void ShowReports();

	friend class List;
};
