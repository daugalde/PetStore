#include <iostream>
#include <iomanip>
#include "AppManager.h"
#include "Client.h"
#include "Pet.h"
#include "Appointment.h"
#include "Treatment.h"
#include "Medication.h"

using namespace std;

void AppManager::InitStoreLoad()
{
	FileLoader loader;

	this->setStore(loader.LoadFiles());
}

void AppManager::DataManager() {
	Menu::ClearMenu();

	Menu::DisplayDataMaintenanceMenu();

	string confirmData = "";

	do {
		getline(cin, confirmData);

		switch (confirmData[0])
		{
		case '1':
			//Insert
			ExecuteCommandByType(1);
			break;
		case '2':
			//Search
			ExecuteCommandByType(2);
			break;
		case '3':
			//Update
			ExecuteCommandByType(3);
			break;
		default:
			confirmData = "";
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::Displaymenu();
}

void AppManager::ExecuteCommandByType(int type) {
	Menu::ClearMenu();

	Menu::DisplayDataTypeMenu();

	string confirmData = "";

	do {
		getline(cin, confirmData);

		switch (confirmData[0])
		{
		case '1':
			if (type == 1)
			{
				InsertCountry();
			}
			else if (type == 2) {
				SearchCountry();
			}
			else if (type == 3) {
				UpdateCountry();
			}
			break;
		case '2':
			if (type == 1)
			{
				InsertCity();
			}
			else if (type == 2) {
				SearchCity();
			}
			else if (type == 3) {
				UpdateCity();
			}
			break;
		case '3':
			if (type == 1)
			{
				InsertClient();
			}
			else if (type == 2) {
				SearchClient();
			}
			else if (type == 3) {
				UpdateClient();
			}
			break;
		case '4':
			if (type == 1)
			{
				InsertPet();
			}
			else if (type == 2) {
				SearchPet();
			}
			else if (type == 3) {
				UpdatePet();
			}
			break;
		case '5':
			if (type == 1)
			{
				InsertAppointment();
			}
			else if (type == 2) {
				SearchAppointment();
			}
			else if (type == 3) {
				UpdateAppointment();
			}
			break;
		case '6':
			if (type == 1)
			{
				InsertTreatment();
			}
			else if (type == 2) {
				SearchTreatment();
			}
			else if (type == 3) {
				UpdateTreatment();
			}
			break;
		case '7':
			if (type == 1)
			{
				InsertMedication();
			}
			else if (type == 2) {
				SearchMedication();
			}
			else if (type == 3) {
				UpdateMedication();
			}
			break;
		default:
			confirmData = "";
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::DisplayDataMaintenanceMenu();
}

/// <summary>
/// Inserts
/// </summary>

void AppManager::InsertCountry() {

	string id = "";

	string name = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Pais \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre de Pais\n";
	getline(cin, name);
	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) 
		)
	{
		if (this->getStore().GetCountries()->Insert(new Object (stoi(id), name)))
		{
			this->getStore().GetCountries()->InOrder(this->getStore().GetCountries()->GetRoot(), "");
			cout << "\n \nPais Insertado Correctamente\n \n";
		}
		else {
			cout << "Pais Con el Id proveido YA Existe\n \n";
		}
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertCity() {

	string countryId = "";

	Menu::ClearMenu();
	cout << "Insertar Nueva Ciudad \nDigite Primero un Id de un Pais Valido \n";
	getline(cin, countryId);

	if (
		Menu::Is_number(countryId)
		&& this->getStore().GetCountries()->SearchById(stoi(countryId), this->getStore().GetCountries()->GetRoot()) != NULL
		)
	{
		cout << "Digite Segundo un Id de una Ciudad Valido \n";
		string cityId = "";
		getline(cin, cityId);

		string name = "";
		cout << "Digite un Nombre de Ciudad\n";
		getline(cin, name);

		if (Menu::Is_number(cityId) &&
			Menu::Is_NOT_EmptyOrWhiteSpace(name)
		   )
		{
			if (this->getStore().GetCities()->Insert(new Object(stoi(cityId), name)))
			{
				this->getStore().GetCities()->InOrder(this->getStore().GetCities()->GetRoot(), "");
				cout << "Ciudad Insertada Correctamente\n \n";
			}
			else {
				cout << "La Ciudad con el Id proveido YA Existe\n \n";
			}
		}
		else {
			cout << "El nombre esta vacio o no es valido o el Id no es valido\n";
		}
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertClient() {
	string clientId = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Cliente \nDigite Primero un cliente Id \n";
	getline(cin, clientId);

	if (Menu::Is_number(clientId))
	{
		Client* client = static_cast<Client*>(this->getStore().GetClients()->SearchById(stoi(clientId), this->getStore().GetClients()->GetRoot()));
		if (client == NULL)
		{
			string clientName = "";

			cout << "Digite Nombre de Nuevo Cliente\n";
			getline(cin, clientName);

			if (Menu::Is_NOT_EmptyOrWhiteSpace(clientName))
			{
					cout << "Digite Direccion Nuevo Cliente\n";
					string address = "";
					getline(cin, address);

					cout << "Digite Codigo Pais Nuevo Cliente\n";
					string countryId = "";
					getline(cin, countryId);

					string cityId = "";
					cout << "Digite el Codigo de Ciudad Nuevo Cliente\n";
					getline(cin, cityId);

					if (Menu::Is_number(countryId)
						&& this->getStore().GetCountries()->SearchById(stoi(countryId), this->getStore().GetCountries()->GetRoot()) != NULL
						)
					{
						if (Menu::Is_number(cityId)
							&& this->getStore().GetCities()->SearchById(stoi(cityId), this->getStore().GetCities()->GetRoot()) != NULL)
						{
							string phoneNumber = "";
							cout << "Digite el Telefono del Nuevo Cliente \n";
							getline(cin, phoneNumber);

							if (Menu::Is_number(phoneNumber))
							{
								string yearVisit = "";
								cout << "Digite un Anio de Ultima visita, Debe Ser de 4 digitos Nuevo Cliente\n";
								getline(cin, yearVisit);

								string monthVisit = "";
								cout << "Digite un mes de Ultima visita Nuevo Cliente\n";
								getline(cin, monthVisit);

								string dayVisit = "";
								cout << "Digite un dia de Ultima visita Nuevo Cliente\n";
								getline(cin, dayVisit);

								if (Menu::Is_number(yearVisit) && yearVisit.length() == 4 &&
									Menu::Is_number(monthVisit) && stoi(monthVisit) < 13 &&
									Menu::Is_number(dayVisit) && stoi(dayVisit) < 32)
								{
									string discount = "";
									cout << "Digite el Descuento del Nuevo Cliente\n";
									getline(cin, discount);
									if (Menu::Is_number(discount))
									{
										string totalDue = "";
										cout << "Digite el Saldo del Nuevo Cliente\n";
										getline(cin, totalDue);

										if (Menu::Is_number(totalDue))
										{
											Client* client = new Client(stoi(clientId), clientName, address, stoi(countryId), stoi(cityId), phoneNumber, dayVisit, monthVisit, yearVisit, stoi(discount), stof(totalDue));
											this->getStore().GetClients()->Insert(client);
											cout << "El Cliente ha sido Ingresado Correctamente\n \n";
										}
										else {
											cout << "El Saldo NO es valido\n \n";
										}
									}
									else {
										cout << "El Descuento NO es valido\n \n";
									}
								}
								else {
									cout << "La Fecha NO es valida\n \n";
								}
							}
							else {
								cout << "El Telefono NO es valido\n \n";
							}
						}
						else {
							cout << "El Codigo de ciudad NO existe\n \n";
						}
					}
					else {
						cout << "El Codigo de pais NO existe\n \n";
					}
			}
			else {
				cout << "El Id proveido NO es valido\n \n";
			}
		}
		else {
			cout << "El Client Id proveido NO es valido o YA existe \n \n";
		}
	}
	else {
		cout << "El Id proveido NO es valido o no Existe\n \n";
	}
	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertPet() {
	string clientId = "";

	Menu::ClearMenu();
	cout << "Insertar Nueva Mascota \nDigite Primero un cliente Id \n";
	getline(cin, clientId);

	if (Menu::Is_number(clientId))
	{
		Client* client = static_cast<Client*>(this->getStore().GetClients()->SearchById(stoi(clientId), this->getStore().GetClients()->GetRoot()));
		if (client != NULL)
		{
			string petId = "";

			cout << "Digite Segundo un nuevo Mascota Id \n";
			getline(cin, petId);

			if (Menu::Is_number(petId))
			{
				Pet* pet = static_cast<Pet*>(this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()));
				if (pet == NULL)
				{
					cout << "Digite Nuevo nombre de Mascota \n";
					string name = "";
					getline(cin, name);

					cout << "Digite Nuevo tipo de Mascota (Canino o felino)\n";
					string petType = "";
					getline(cin, petType);

					cout << "Digite Raza de Mascota \n";
					string petBreed= "";
					getline(cin, petBreed);

					string year = "";
					cout << "Digite el Anio de Nacimiento Mascota\n";
					getline(cin, year);

					string month = "";
					cout << "Digite el mes de Nacimiento Mascota\n";
					getline(cin, month);

					string day = "";
					cout << "Digite el dia de Nacimiento Mascota\n";
					getline(cin, day);

					string sex = "";
					cout << "Digite si Mascota es Macho o Hembra\n";
					getline(cin, sex);

					string color = "";
					cout << "Digite color de Mascota\n";
					getline(cin, color);

					string isCastrated = "";
					cout << "Digite si o no esta castrada la Mascota\n";
					getline(cin, isCastrated);

					string yearVisit = "";
					cout << "Digite un Anio de Ultima visita Mascota\n";
					getline(cin, yearVisit);

					string monthVisit = "";
					cout << "Digite un mes de Ultima visita Mascota\n";
					getline(cin, monthVisit);

					string dayVisit = "";
					cout << "Digite un dia de Ultima visita Mascota\n";
					getline(cin, dayVisit);

					if (Menu::Is_number(year) && year.length() == 4 &&
						Menu::Is_number(month) && stoi(month) < 13 &&
						Menu::Is_number(day) && stoi(day) < 32 &&
						Menu::Is_number(yearVisit) && yearVisit.length() == 4 &&
						Menu::Is_number(monthVisit) && stoi(monthVisit) < 13 &&
						Menu::Is_number(dayVisit) && stoi(dayVisit) < 32)
					{
						int diffInDays = Menu::GetDateDifferenceInDays(stoi(day), stoi(month), stoi(year), stoi( dayVisit), stoi( monthVisit), stoi(yearVisit));
						if (diffInDays >= 0)
						{
							Pet* pet = new Pet(stoi(petId)
								, name
								, stoi(clientId)
								, petType
								, petBreed
								, day
								, month
								, year
								, ""
								, sex
								, color
								, isCastrated
								, dayVisit
								, monthVisit
								, yearVisit
								, ""
							);
							pet->setBirthDate(pet->getBirthDay() + "/" + pet->getBirthMonth() + "/" + pet->getBirthYear());
							pet->setLastVisitDate(pet->getLastVisitDay() + "/" + pet->getLastVisitMonth() + "/" + pet->getLastVisitYear());

							this->getStore().GetPets()->InsertBalanced(pet);

							cout << "La Mascota "<< pet->getName() << " ha sido ingresada correctamente" << "\n \n";
						}
						else {
							cout << "La fecha de visita no puede ser antes de la de nacimiento de la Mascota\n \n";
						}
					}
				}
				else {
					cout << "El Id Mascota proveido ya existe\n \n";
				}
				
			}
			else {
				cout << "El Id proveido NO es valido\n \n";
			}
		}
		else {
			cout << "El Client Id proveido NO es valido\n \n";
		}
	}
	else {
		cout << "El Id proveido NO es valido o no Existe\n \n";
	}
	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertAppointment() {
	string appointmentId = "";
	
	Menu::ClearMenu();
	cout << "Insertar Nueva Visita \nDigite Primero un nuevo Id \n";
	getline(cin, appointmentId);

	if (Menu::Is_number(appointmentId) && this->getStore().GetAppointments()->SearchById(stoi(appointmentId), this->getStore().GetAppointments()->GetRoot()) == NULL)
	{
		Menu::ClearMenu();
		string petId = "";
		cout << "Digite un Id de Mascota\n";
		getline(cin, petId);

		if (Menu::Is_number(petId))
		{
			Pet* pet = static_cast<Pet*>(this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()));
			if (pet != NULL)
			{
				string year = "";
				cout << "Digite un Anio de Ultima visita Mascota\n";
				getline(cin, year);

				string month = "";
				cout << "Digite un mes de Ultima visita Mascota\n";
				getline(cin, month);

				string day = "";
				cout << "Digite un dia de Ultima visita Mascota\n";
				getline(cin, day);

				string totalInvoiced = "";
				cout << "Digite un Total de Factura\n";
				getline(cin, totalInvoiced);

				string paymentType = "";
				cout << "Digite 1 si es Pago Contado o 2 si es credito\n";
				getline(cin, paymentType);

				if (Menu::Is_number(year) && 
					Menu::Is_number(month) && stoi(month) < 13 &&
					Menu::Is_number(day) && stoi(day) < 32 &&
					Menu::Is_number(totalInvoiced) && stof(totalInvoiced) > 0 &&
					(paymentType == "1" || paymentType == "2")
					)
				{
					Appointment* appointment = new Appointment(stoi(appointmentId),"", stoi(petId),day,month,year,stoi(paymentType), 0.00,stof(totalInvoiced));
					this->getStore().GetAppointments()->Insert(appointment);
					cout << "Visita Insertada Correctamente\n \n";
				}
				else {
					cout << "Algun valor no es correcto por favor intente de nuevo\n \n";
				}
			}
			else {
				cout << "La Mascota con el Id proveido NO Existe y No se puede ingresar la visita\n \n";
			}
		}
		else {
			cout << "El id existe o no es correcto \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertTreatment() {
	string treamentId = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Tratamiento \nDigite Primero un nuevo Id \n";
	getline(cin, treamentId);

	if (
		Menu::Is_number(treamentId)
		&& this->getStore().GetTreatments()->SearchById(stoi(treamentId)) == NULL
		)
	{
		cout << "Digite Nuevo nombre de Tratamiento \n";
		string name = "";
		getline(cin, name);

		string unitPrice = "";
		cout << "Digite un Precio Unitario del tratamiento\n";
		getline(cin, unitPrice);

		if (Menu::Is_number(unitPrice) &&
			Menu::Is_NOT_EmptyOrWhiteSpace(name)
			)
		{
			Treatment* treament = new Treatment(stoi(treamentId),name, stof(unitPrice));
			this->getStore().GetTreatments()->RBInsert(treament);
			cout << "Tratamiento "<< treament->getName() <<" Insertado Correctamente\n \n";
		}
		else {
			cout << "El nombre esta vacio o no es valido o el Id no es valido\n";
		}
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertMedication() {
	string petId = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Medicamento \nDigite un Id existente de Mascota \n";
	getline(cin, petId);

	if (
		Menu::Is_number(petId)
		&& this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()) != NULL
		)
	{
		cout << "Digite Nuevo Id de Medicacion \n";
		string medicationId = "";
		getline(cin, medicationId);

		if (Menu::Is_number(medicationId) && this->getStore().GetMedications()->SearchById(stoi(petId), this->getStore().GetMedications()->GetRoot()) == NULL)
		{
			string petId = "";
			cout << "Digite un Id de Mascota\n";
			getline(cin, petId);

			if (Menu::Is_number(petId))
			{
				Pet* pet = static_cast<Pet*>(this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()));

				if (pet != NULL)
				{
					string medicationName = "";
					cout << "Digite un Nombre de Nuevo Medicamento\n";
					getline(cin, medicationName);

					string year = "";
					cout << "Digite un Anio de Ultima visita Mascota\n";
					getline(cin, year);

					string month = "";
					cout << "Digite un mes de Ultima visita Mascota\n";
					getline(cin, month);

					string day = "";
					cout << "Digite un dia de Ultima visita Mascota\n";
					getline(cin, day);

					string unitPrice = "";
					cout << "Digite Costo Unitario\n";
					getline(cin, unitPrice);

					string quantity = "";
					cout << "Digite La  Cantidad\n";
					getline(cin, quantity);

					string treatmentId = "";
					cout << "Digite el Id tratamiento\n";
					getline(cin, treatmentId);

					string totalPrice = "";
					cout << "Digite un Total de Factura\n";
					getline(cin, totalPrice);

					if (Menu::Is_number(year) &&
						Menu::Is_number(month) && stoi(month) < 13 &&
						Menu::Is_number(day) && stoi(day) < 32 &&
						Menu::Is_number(unitPrice) && stof(unitPrice) > 0 &&
						Menu::Is_number(totalPrice) && stof(totalPrice) > 0 &&
						Menu::Is_number(quantity) && stoi(quantity) >= 0 &&
						Menu::Is_number(treatmentId)
						)
					{
						int diffInDays = Menu::GetDateDifferenceInDays(stoi(pet->getBirthDay()), stoi(pet->getBirthMonth()), stoi(pet->getBirthYear()), stoi(day), stoi(month), stoi(year));
						if (diffInDays >= 0)
						{
							Treatment* treatment = static_cast<Treatment*>(this->getStore().GetTreatments()->SearchById(stoi(treatmentId)));
							if (treatment != NULL)
							{
								Medication* medication = new Medication(stoi(medicationId), medicationName, pet->getId(), stoi(day), stoi(month), stoi(year), stoi(treatmentId), stof(unitPrice), stoi(quantity), stof(totalPrice));
								this->getStore().GetMedications()->Insert(medication);
								cout << "Medicamento " << medication->getName() << " Insertado Correctamente\n \n";
							}
							else {
								cout << "El Id del tratamiento No es valido o no es valido\n";
							}
						}
						else {
							cout << "La fecha de ultima visita No es posterior a la fecha de nacimiento de Mascota\n";
						}
					}
					else {
						cout << "Alguno de los datos ingresados No es valido\n";
					}
				}
				else {
					cout << "El Id de mascota esta vacio o Id No es valido\n";
				}
			}
			else {
				cout << "El Id de mascota esta vacio o Id No es valido\n";
			}
		}
		else {
			cout << "El Id esta vacio o Id ya existe\n";
		}
	}
	else {
		cout << "El id NO existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

/// <summary>
/// Seacrh
/// </summary>

void AppManager::SearchCountry() {
	Menu::ClearMenu();
	string countryId = "";
	cout << "Digite un Id para buscar en Arbol de paises\n";
	getline(cin, countryId);

	if (Menu::Is_number(countryId))
	{
		Object* country = this->getStore().GetCountries()->SearchById(stoi(countryId), this->getStore().GetCountries()->GetRoot());
		if (country != NULL)
		{
			cout << "\"" << country->getId() << "  " << country->getName() << "  " << "\"" << "\n";
		}
		else {
			cout << "Pais Con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchCity() {
	Menu::ClearMenu();
	string countrytId = "";
	cout << "Digite un Id de Pais\n";
	getline(cin, countrytId);

	if (Menu::Is_number(countrytId))
	{
		string cityId = "";
		cout << "Digite un Id de Ciudad buscar en Arbol de paises\n";
		getline(cin, cityId);
		Object* city = this->getStore().GetCities()->SearchById(stoi(cityId), this->getStore().GetCities()->GetRoot());
		if (city != NULL)
		{
			cout << "\"" << city->getId() << "  " << city->getName() << "  " << "\"" << "\n";
		}
		else {
			cout << "La Ciudad con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchClient() {
	Menu::ClearMenu();
	string countrytId = "";
	cout << "Digite un Id de Pais\n";
	getline(cin, countrytId);

	if (Menu::Is_number(countrytId))
	{
		string cityId = "";
		cout << "Digite un Id de Ciudad buscar en Arbol de paises\n";
		getline(cin, cityId);
		Object* city = this->getStore().GetCities()->SearchById(stoi(cityId), this->getStore().GetCities()->GetRoot());
		if (city != NULL)
		{
			string clientId = "";
			cout << "Digite un Id de Cliente a Buscar\n";
			getline(cin, clientId);
			Client* client = static_cast<Client*>(this->getStore().GetClients()->SearchById(stoi(clientId), this->getStore().GetClients()->GetRoot()));
			if (client != NULL && client->getCityId() == stoi(cityId))
			{
				cout << "El Id del Cliente : " << client->getId() << "  Nombre : " << client->getName() << " Direccion : " << client->getAddress()
					<< " Ultima visita : " << client->getDay() << "/" << client->getMonth() << "/" << client->getYear() << " Telefono " << client->getPhone()
					<< " Descuento : " << client->getDiscount() << " Total debido : " << client->getBalance();
			}
			else {
				cout << "El Id del Cliente no se encontro \n \n";
			}
		}
		else {
			cout << "La Ciudad con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchPet() {
	Menu::ClearMenu();
	string petId = "";
	cout << "Digite un Id de Mascota\n";
	getline(cin, petId);

	if (Menu::Is_number(petId))
	{
		Pet* pet = static_cast<Pet*>(this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()));
		if (pet != NULL)
		{
			cout << "\" La mascota con identificacion " << pet->getId() << " Llamada " << pet->getName() << "  " << pet->getCastrated() << " esta castrada \"" << "\n";
		}
		else {
			cout << "La Mascota con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchAppointment() {
	Menu::ClearMenu();
	string appointmentId = "";
	cout << "Digite un Id de Visita\n";
	getline(cin, appointmentId);

	if (Menu::Is_number(appointmentId))
	{
		Appointment* appointment = static_cast<Appointment*>(this->getStore().GetAppointments()->SearchById(stoi(appointmentId), this->getStore().GetAppointments()->GetRoot()));
		if (appointment != NULL)
		{
			cout << "\n" << "Mascota Id : " << appointment->getPetId() << "\nUltima visita : " << appointment->getDay() << " / " << appointment->getMonth() << " / " << appointment->getYear() << "\nTotal Factura : " << fixed << setprecision(2) << appointment->getTotalInvoiced() << ((appointment->getPaymentType() == 1) ? "\nForma de pago : CONTADO" : "\nForma de pago : CREDITO") << "\n";
		}
		else {
			cout << "La Vista con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchTreatment() {
	Menu::ClearMenu();
	string treatmentId = "";
	cout << "Digite un Id de Tratamiento\n";
	getline(cin, treatmentId);

	if (Menu::Is_number(treatmentId))
	{
		Treatment* treatment = static_cast<Treatment*>(this->getStore().GetTreatments()->SearchById(stoi(treatmentId)));
		if (treatment != NULL)
		{
			cout << "Informacion de Tratamiento\nId : " << treatment->getId() << "\nNombre : " << treatment->getName() << "\nPrecio Unitario : " << fixed << setprecision(2) << treatment->getPrice() << "\n";
		}
		else {
			cout << "El Tratamiento con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchMedication() {
	string petId = "";

	Menu::ClearMenu();
	cout << "Buscar Medicamento \nDigite un Id existente de Mascota \n";
	getline(cin, petId);

	if (
		Menu::Is_number(petId)
		&& this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()) != NULL
		)
	{
		string medicationId = "";
		cout << "Digite un Id existente de Medicamento \n";
		getline(cin, medicationId);

		if (Menu::Is_number(medicationId))
		{
			Medication* medication= this->getStore().GetMedications()->SearchLastMedication(stoi(medicationId), stoi(petId),this->getStore().GetMedications()->GetRoot());
			if (medication != NULL)
			{
				cout << "El Medicamento es : " << medication->getId() << " cantidad " << medication->getQuantity() << " unit price : " << medication->getUnitPrice() << " last Visit : " << medication->getLastVisitDay() << "/" 
					<< medication->getLastVisitMonth() << "/" << medication->getLastVisitYear() << " costo total " << medication->getTotalPrice() << " treatment Id : " << medication->getTreatmentId();
			}
			else {
				cout << "El Medicamento NO existe \n";
			}
		}
		else {
			cout << "El id NO existe o no es correcto \n";
		}
	}
	else {
		cout << "El id NO existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

/// <summary>
/// Update
/// </summary>

void AppManager::UpdateCountry() {
	Menu::ClearMenu();
	string countryId = "";
	cout << "Digite un Id para buscar en Arbol de paises\n";
	getline(cin, countryId);

	if (Menu::Is_number(countryId))
	{
		string name = "";
		cout << "Digite el nuevo nombre del pais\n";
		getline(cin, name);
		if (Menu::Is_NOT_EmptyOrWhiteSpace(name))
		{
			bool countryUpdated = this->getStore().GetCountries()->UpdateById(stoi(countryId), name , this->getStore().GetCountries()->GetRoot());
			if (countryUpdated)
			{
				Object* country = this->getStore().GetCountries()->SearchById(stoi(countryId), this->getStore().GetCountries()->GetRoot());
				cout << "\"" << country->getId() << "  " << country->getName() << "  " << "\"" << "\n";
			}
			else {
				cout << "Pais Con el Id proveido NO Existe\n \n";
			}
		}
		else {
			cout << "El nombre proveido no es valido\n \n";
		}
		
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::UpdateCity() {
	Menu::ClearMenu();
	string countryId = "";
	cout << "Digite un Id para buscar en Arbol de paises para posterior update de ciudad\n";
	getline(cin, countryId);

	if (Menu::Is_number(countryId) && this->getStore().GetCountries()->SearchById(stoi(countryId), this->getStore().GetCountries()->GetRoot()) != NULL)
	{
		string cityId = "";
		cout << "Digite un Id de ciudad valido\n";
		getline(cin, cityId);
		if (Menu::Is_number(cityId) && this->getStore().GetCities()->SearchById(stoi(cityId), this->getStore().GetCities()->GetRoot()) != NULL)
		{
			string name = "";
			cout << "Digite el nuevo nombre de la ciudad \n";
			getline(cin, name);
			if (Menu::Is_NOT_EmptyOrWhiteSpace(name))
			{
				bool cityUpdated = this->getStore().GetCities()->UpdateById(stoi(cityId), name, this->getStore().GetCities()->GetRoot());
				if (cityUpdated)
				{
					Object* city = this->getStore().GetCities()->SearchById(stoi(cityId), this->getStore().GetCities()->GetRoot());
					cout << "\"" << city->getId() << "  " << city->getName() << "  " << "\"" << "\n";
				}
				else {
					cout << "Pais Con el Id proveido NO Existe\n \n";
				}
			}
		}
		else {
			cout << "El Id proveido no es valido\n \n";
		}
	}
	else {
		cout << "El id del Pais no existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::UpdateClient() {
	Menu::ClearMenu();
	string clientId = "";
	cout << "Digite un Id de Cliente a Buscar\n";
	getline(cin, clientId);
	Client* client = static_cast<Client*>(this->getStore().GetClients()->SearchById(stoi(clientId), this->getStore().GetClients()->GetRoot()));
	if (client != NULL)
	{
		Menu::ClearMenu();
		Menu::DisplayClientDataMenu();
		string option = "";
		string countryId = "";
		string cityId = "";
		getline(cin, option);

		string input = "";

		if (Menu::Is_number(option))
		{
			bool isUpdate = false;
			switch (stoi(option))
			{
			case 1:
				cout << "Digite un Nuevo Nombre \n";
				input = "";
				getline(cin, input);
				client->setName(input);
				this->getStore().GetClients()->UpdateElementById(stoi(clientId), client, this->getStore().GetClients()->GetRoot());
				isUpdate = true;
				break;
			case 2:
				cout << "Digite un Nueva Direccion \n";
				input = "";
				getline(cin, input);
				client->setAddress(input);
				this->getStore().GetClients()->UpdateElementById(stoi(clientId), client, this->getStore().GetClients()->GetRoot());
				isUpdate = true;
				break;
			case 3:
			case 4:
				cout << "Digite un Id para buscar en Arbol de paises para posterior update de ciudad\n";
				countryId = "";
				getline(cin, countryId);

				if (Menu::Is_number(countryId) && this->getStore().GetCountries()->SearchById(stoi(countryId), this->getStore().GetCountries()->GetRoot()) != NULL)
				{
					cout << "Digite un Id de ciudad valido\n";
					cityId = "";
					getline(cin, cityId);
					if (Menu::Is_number(cityId) && this->getStore().GetCities()->SearchById(stoi(cityId), this->getStore().GetCities()->GetRoot()) != NULL)
					{
						client->setCountryId(stoi(countryId));
						client->setCityId(stoi(cityId));
						isUpdate = true;
					}
					else {
						cout << "El Id proveido no es valido\n \n";
					}
				}
				else {
					cout << "El id del Pais no existe o no es correcto \n";
				}

				break;
			case 5:
				cout << "Digite un Nuevo Telefono \n";
				input = "";
				getline(cin, input);
				if (Menu::Is_number(input))
				{
					client->setPhone(input);
					isUpdate = true;
				}
				else {
					cout << "La opcion NO es Valida \n";
				}
				break;
			default:
				if (stoi(option) != 6) {
					cout << "La opcion NO es Valida \n";
				}
				break;
			}

			if (isUpdate)
			{
				cout << "Se actulizo el cliente \n\n";
				cout << "El Id del Cliente : " << client->getId() << "  Nombre : " << client->getName() << " Direccion : " << client->getAddress()
					<< " Ultima visita : " << client->getDay() << "/" << client->getMonth() << "/" << client->getYear() << " Telefono " << client->getPhone()
					<< " Descuento : " << client->getDiscount() << " Total debido : " << client->getBalance() << "\n\n";
			}
			else if (Menu::Is_number(option) && stoi(option) != 6) {
				cout << "El dato proveido NO es Valido para actualizar el cliente \n";
			}
		}
		else  if (Menu::Is_number(option) && stoi(option) != 6) {
			cout << "La opcion NO es Valida \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::UpdatePet() {
	Menu::ClearMenu();
	string clientId = "";
	cout << "Digite un Id de Cliente Para Actualizar Mascota\n";
	getline(cin, clientId);

	if (Menu::Is_number(clientId))
	{
		Pet* pet = static_cast<Pet*>(this->getStore().GetPets()->SearchPetByClientId(stoi(clientId), this->getStore().GetPets()->GetRoot()));

		string petName = "";
		cout << "Digite un nuevo nombre para Mascota\n";
		getline(cin, petName);

		string petIsCatrated = "";
		cout << "Digite \"Si\" o \"No\" Para Actualizar Si esta castrado\n";
		getline(cin, petIsCatrated);
		if (pet != NULL && petName.length() > 0 && petIsCatrated.length() > 0)
		{
			pet->setName(petName);
			pet->setCastrated(petIsCatrated);
			this->getStore().GetPets()->UpdateElementById(pet->getId(), pet, this->getStore().GetPets()->GetRoot());
			cout << "\"" << "El animal " << petIsCatrated << " Castrado " << "  " << petName << "  " << "\"" << "\n";
		}
		else {
			cout << "La Mascota con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id cliente NO existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::UpdateAppointment() {
	Menu::ClearMenu();
	string appointmentId = "";
	cout << "Digite un Id de visita para posterior actualizacion forma de pago\n";
	getline(cin, appointmentId);

	string petId = "";
	cout << "Digite un Id de mascota para posterior actualizacion forma de pago de la visita\n";
	getline(cin, petId);

	if (Menu::Is_number(appointmentId) && Menu::Is_number(petId))
	{
		string paymentType = "";
		cout << "Digite un 1 si la forma de pago es contado o 2 si es credito\n";
		getline(cin, paymentType);
		if (Menu::Is_number(paymentType) && (paymentType == "1" || paymentType == "2"))
		{
			Appointment* appointment = static_cast<Appointment*>(this->getStore().GetAppointments()->SearchById(stoi(appointmentId), this->getStore().GetAppointments()->GetRoot()));
			appointment->setPaymentType(stoi(paymentType));
			bool appointmentUpdated = this->getStore().GetAppointments()->UpdateElementById(stoi(appointmentId), appointment, this->getStore().GetAppointments()->GetRoot());
			if (appointmentUpdated)
			{
				cout << "\" La Forma de pago para Id visita : " << appointment->getId() << "  ahora es : \n" << (appointment->getPaymentType() == 1 ? "Forma de pago : CONTADO " : "Forma de pago : CREDITO ") << "  " << "\"" << "\n";
			}
			else {
				cout << "Hubo un error actualizando la visita por favor intentelo mas tarde\n \n";
			}
		}
		else {
			cout << "La forma de pago no es valida\n \n";
		}
	}
	else {
		cout << "El id no existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::UpdateTreatment() {
	Menu::ClearMenu();
	string treatmentId = "";
	cout << "Digite un Id de Tratamiento para actualizar precio unitario\n";
	getline(cin, treatmentId);

	if (Menu::Is_number(treatmentId))
	{
		Treatment* treatment = static_cast<Treatment*>(this->getStore().GetTreatments()->SearchById(stoi(treatmentId)));
		if (treatment != NULL)
		{
			string unitPrice = "";
			cout << "Digite un Precio Unitario\n";
			getline(cin, unitPrice);
			if (Menu::Is_number(unitPrice))
			{
				treatment->setPrice(stof(unitPrice));
				bool isTreatmentUpdate = this->getStore().GetTreatments()->UpdateElementById(stoi(treatmentId), treatment);
				if (isTreatmentUpdate)
				{
					cout << "Informacion de Tratamiento\nId : " << treatment->getId() << "\nNombre : " << treatment->getName() << "\nEl Precio Unitario se actualizo a : " << fixed << setprecision(2) << treatment->getPrice() << "\n";
				}
				else {
					cout << "Error al Actualizar el precio unitario del tratamiento brindado \n \n";
				}
			}
			else {
				cout << "El Precio proveido NO es valido \n \n";
			}
		}
		else {
			cout << "El Tratamiento con el Id proveido NO Existe\n \n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::UpdateMedication() {
	string petId = "";

	Menu::ClearMenu();
	cout << "Buscar Medicamento \nDigite un Id existente de Mascota \n";
	getline(cin, petId);

	if (
		Menu::Is_number(petId)
		&& this->getStore().GetPets()->SearchById(stoi(petId), this->getStore().GetPets()->GetRoot()) != NULL
		)
	{
		string medicationId = "";
		cout << "Digite un Id existente de Medicamento \n";
		getline(cin, medicationId);
		string qty = "";
		string unitPrice = "";
		string totalPrice = "";
		if (Menu::Is_number(medicationId))
		{
			Medication* medication = this->getStore().GetMedications()->SearchLastMedication(stoi(medicationId), stoi(petId), this->getStore().GetMedications()->GetRoot());
			if (medication != NULL)
			{
				//hERE
				Menu::ClearMenu();
				Menu::DisplayMedicationDataMenu();
				string option = "";
				string countryId = "";
				string cityId = "";
				getline(cin, option);

				string input = "";

				if (Menu::Is_number(option))
				{
					bool isUpdate = false;
					switch (stoi(option))
					{
					case 1:
						cout << "Digite Nueva Cantidad\n";
						qty = "";
						getline(cin, qty);

						if (Menu::Is_number(qty))
						{
							medication->setQuantity(stoi(qty));
							isUpdate = true;
						}
						else {
							cout << "El cantidad proveida no es valido \n";
						}
						break;
					case 2:
						cout << "Digite Nuevo Precio\n";
						unitPrice = "";
						getline(cin, unitPrice);

						if (Menu::Is_number(unitPrice))
						{
							medication->setUnitPrice(stoi(unitPrice));
							isUpdate = true;
						}
						else {
							cout << "El Precio proveido no es valido \n";
						}
						break;
					case 3:
						cout << "Digite Nuevo Precio Total\n";
						totalPrice = "";
						getline(cin, totalPrice);

						if (Menu::Is_number(totalPrice))
						{
							medication->setTotalPrice(stof(totalPrice));
							isUpdate = true;
						}
						else {
							cout << "El Precio total proveido no es valido \n";
						}

						break;

					default:
						if (stoi(option) != 4) {
							cout << "La opcion NO es Valida \n";
						}
						break;
					}
					if (isUpdate)
					{
						cout << "Se actulizo el Medicamento \n\n";
						cout << "El Id del Medicamento : " << medication->getId() << "  Cantidad : " << medication->getQuantity() << " Precio Unitario : " << medication->getUnitPrice()
							<< " Precio Total : " << medication->getTotalPrice() << "\n\n";
					}
					else if (Menu::Is_number(option) && stoi(option) != 4) {
						cout << "El dato proveido NO es Valido para actualizar el medicamento \n";
					}
				}
					
				//HERE
			}
			else {
				cout << "El Medicamento NO existe \n";
			}
		}
		else {
			cout << "El id NO existe o no es correcto \n";
		}
	}
	else {
		cout << "El id NO existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

/// <summary>
/// Other Helper Functions
/// </summary>

Client* AppManager::GetValidRegisteredClient(string clientId)
{

	Object* obj = NULL;//this->getStore()->GetClients().GetObjectById(stoi(clientId));

	if (obj)
	{
		Client* c = static_cast<Client*>(obj);

		cout << "El Cliente : " << c->getName() << " es Valido para realizar compras." << endl;

		cout << "\nPresione una tecla para continuar." << endl;

		return c;
	}

	cout << "El Cliente no es valido para comprar en la tienda" << endl;

	return NULL;
}

void AppManager::QueueClient(Client* c)
{

	//this->getClientsQueue()->Push(c);

}

void AppManager::BillClient()
{
	Client* client = new Client();//static_cast<Client*>(clientsQueue->Pop());

	Store currentStore = getStore();

	List currentInventory;//currentStore.getInventory();

	float totalPrice = 0.00;

	if (client != NULL && client->getGroceryItems()->Length() != 0)
	{
		totalPrice = client->getGroceryItems()->Sum(currentInventory);

		client->getGroceryItems()->Display("Item");

		currentStore.setSales(client->getGroceryItems()->Join(currentStore.getSales()));

		client->setTotalInvoiced(client->getTotalInvoiced() + totalPrice);

		client->setInvoices(client->getInvoices() + 1);

		getProcessedClients()->Push(client);

		cout << "\nTotal a Pagar : " << totalPrice << " Colones. " << endl;

		cout << "\nPresione una tecla para volver al menu anterior." << endl;
	}
	else {
		cout << "No Hay Clientes en Cola \nPresione una tecla para volver al menu anterior." << endl;
	}
}

void AppManager::CheckIfShelfShouldBeLoaded() {
	
	Store currentStore = getStore();

	List* currentSales = currentStore.getSales();

	List* currentAisles = new List();//currentStore.getAisles();

	List* currentHotItems = currentStore.getHotItems();

	if (currentSales != NULL)
	{
		//currentSales->GetItemsToRefillShelf(currentStore.getInventory(), currentAisles, currentHotItems);
		cout << "\nProductos en Gondolas han sido rellenados" << endl;
	}
	cout << "\nPresione una tecla para volver al menu anterior." << endl;
}

void AppManager::CheckIfInvetoryShouldBeLoaded()
{
	Store currentStore = getStore();

	List* currentSales = currentStore.getSales();

	List* currentAisles = new List();//currentStore.getAisles();

	if (currentSales != NULL)
	{
		//currentSales->GetItemsToRefillInventory(currentStore.getInventory(), currentAisles );
		cout << "\nProductos en Inventario han sido rellenados" << endl;
	}
	else {
		cout << "No Es Necesario Rellenar Inventatio\nPresione una tecla para volver al menu anterior." << endl;
	}
};

/// <summary>
/// Reports
/// </summary>
void AppManager::ShowReports()
{
	Menu::ClearMenu();

	Menu::DisplayReportMenu();

	string confirmData = "";

	int sum = 0;
	string response = "";
	do {
		getline(cin, confirmData);

		if (Menu::Is_number(confirmData))
		{
			switch (stoi(confirmData))
			{
			case 1:
				Menu::ClearMenu();
				cout << "Pre Orden de Paises \n \n";
				this->getStore().GetCountries()->PreOrder(this->getStore().GetCountries()->GetRoot(), "");
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 2:
				Menu::ClearMenu();
				cout << "\n \n Reporte Ciudad \n \n";
				SearchCity();
				cout << "\n \n Pre Orden de Ciudades \n \n";
				this->getStore().GetCities()->PreOrder(this->getStore().GetCities()->GetRoot(), "");
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 3:
				Menu::ClearMenu();
				cout << "Clientes de la Tienda \n \n";
				this->getStore().GetClients()->PreOrder(this->getStore().GetClients()->GetRoot(), "client");
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 4:
				Menu::ClearMenu();
				cout << "Pre Orden de Mascotas de la Tienda \n \n";
				//Fix
				this->getStore().GetPets()->PreOrder(this->getStore().GetPets()->GetRoot(), "pet");
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 5:
				Menu::ClearMenu();
				cout << "Pre Orden de Visitas de una Mascota\n \n";
				this->getStore().GetAppointments()->PreOrder(this->getStore().GetAppointments()->GetRoot(), "appointment");
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 6:
				Menu::ClearMenu();
				cout << "Tratamientos de una Mascota\n \n";
				this->getStore().GetTreatments()->preorder();
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 7:
				Menu::ClearMenu();
				cout << "Medicacion de una Mascota\n \n";
				this->getStore().GetMedications()->PreOrder(this->getStore().GetMedications()->GetRoot(),"medication");
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 8:
				Menu::ClearMenu();
				cout << "Clientes con mas saldo\n \n";
				
				response = this->getStore().GetClients()->GetClientReport(this->getStore().GetClients()->GetRoot(), "greaterBalance", sum);
				cout << response;
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 9:
				Menu::ClearMenu();
				cout << "Clientes con mas credito\n \n";
				response = this->getStore().GetClients()->GetClientReport(this->getStore().GetClients()->GetRoot(), "greaterCredit", sum);
				cout << response;
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 10:
				Menu::ClearMenu();
				cout << "Clientes con mas descuentos\n \n";
				response = this->getStore().GetClients()->GetClientReport(this->getStore().GetClients()->GetRoot(), "greaterDiscount", sum);
				cout << response;
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 11:
				Menu::ClearMenu();
				cout << "Ultimos Tratamientos\n \n";
				this->getStore().GetTreatments()->inorder();
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			case 12:
				Menu::ClearMenu();
				cout << "Tratamientos mas utilizados\n \n";
				this->getStore().GetTreatments()->postorder();
				cout << "\n \nPresione una Tecla para volver al menu \n \n";
				break;
			default:
				cout << "Opcion NO Valida\n \n";
				cout << "Presione una Tecla para volver al menu \n \n";
				cin.get();
				confirmData = "";
			}
		}
		else {
			Menu::ClearMenu();
			Menu::DisplayReportMenu();
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::Displaymenu();
}