#pragma once
#include <iostream>
#include <regex>

using namespace std;

class Menu {

public:

	Menu() {}

	static void Displaymenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\tMENU \n ";
		cout << "===================================================== \n";
		cout << " 1.Mantenimiento Base de Datos\n";
		cout << " 2.Reportes \n";
		cout << " 3.Salir \n";
	}

	static void DisplayDataMaintenanceMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Mantenimiento Base de Datos \n ";
		cout << "===================================================== \n";
		cout << " 1.Insertar\n";
		cout << " 2.Buscar\n";
		cout << " 3.Modificar\n";
		cout << " 4.Volver al Menu Principal \n";
	}

	static void DisplayDataTypeMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Mantenimiento Base de Datos \n ";
		cout << "===================================================== \n";
		cout << " 1.Pais\n";
		cout << " 2.Ciudad\n";
		cout << " 3.Cliente\n";
		cout << " 4.Mascota\n";
		cout << " 5.Visitas\n";
		cout << " 6.Tratamiento\n";
		cout << " 7.Medicacion\n";
		cout << " 8.Volver al Menu Anterior \n";
	}

	

	static void DisplayReportMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Reportes de Tienda de Mascotas \n ";
		cout << "===================================================== \n";
		cout << " 1.Paises en Pre Orden\n";
		cout << " 2.Ciudades de un Pais en Pre Orden\n";
		cout << " 3.Clientes\n";
		cout << " 4.Mascotas de un Cliente \n";
		cout << " 5.Visitas de una Mascota \n";
		cout << " 6.Tratamientos \n";
		cout << " 7.Medicacion de una Mascota \n";
		cout << " 8.Cliente con mas Saldo \n";
		cout << " 9.Clientes de Credito \n";
		cout << " 10.Clientes Con mas Descuento \n";
		cout << " 11.Ultimos Tratamientos \n";
		cout << " 12.Tratamiento mas Utilizado \n";
		cout << " 13.Volver al Menu Principal \n";
	}

	static void DisplayClientDataMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Datos a Actualizar de Cliente \n ";
		cout << "===================================================== \n";
		cout << " 1.Nombre\n";
		cout << " 2.Direccion\n";
		cout << " 3.Codigo Pais\n";
		cout << " 4.Codigo City \n";
		cout << " 5.Telefono \n";
		cout << " 6.Volver al Menu Principal \n";
	}

	static void DisplayMedicationDataMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Datos a Actualizar de Medicacion \n ";
		cout << "===================================================== \n";
		cout << " 1.Cantidad \n";
		cout << " 2.Precio\n";
		cout << " 3.Costo total\n";
		cout << " 4.Volver al Menu Principal \n";
	}

	static void ClearMenu() {
		cout << flush;
		system("CLS");
	}

	bool static Is_number(const std::string& s)
	{
		return !s.empty() && std::find_if(s.begin(),
			s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
	}

	bool static Is_NOT_EmptyOrWhiteSpace(const std::string& s)
	{
		return !s.empty() && !(s.find_first_not_of(' ') == s.npos);
	}

	std::string ltrim(const std::string& s) {
		return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
	}

	std::string rtrim(const std::string& s) {
		return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
	}

	std::string trim(const std::string& s) {
		return ltrim(rtrim(s));
	}

	// GFG TAKEN
	struct Date {
		int d, m, y;
	};

	int static CountLeapYears(Date d)
	{
		int years = d.y;

		if (d.m <= 2)
			years--;

		return years / 4
			- years / 100
			+ years / 400;
	}

	int static GetDateDifferenceInDays(int day, int month, int year, int day2, int month2, int year2)
	{
		Date dt1 = { day, month, year };
		Date dt2 = { day2, month2, year2 };

		int monthDays[12]
			= { 31, 28, 31, 30, 31, 30,
			   31, 31, 30, 31, 30, 31 };

		long int n1 = dt1.y * 365 + dt1.d;

		for (int i = 0; i < dt1.m - 1; i++)
			n1 += monthDays[i];

		n1 += CountLeapYears(dt1);

		long int n2 = dt2.y * 365 + dt2.d;
		for (int i = 0; i < dt2.m - 1; i++)
			n2 += monthDays[i];
		n2 += CountLeapYears(dt2);

		//Difference in days
		return (n2 - n1);
	}
	// GFG TAKEN
};