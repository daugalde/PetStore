#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "BinaryTree.h"
#include "RBTree.h"
#include "Store.h"

using namespace std;

class FileLoader {

private:


public:
	FileLoader() { }

	~FileLoader();

	Store LoadFiles();

	BinaryTree* ReadCountriesFile();

	BinaryTree* ReadCitiesFile(BinaryTree* countries);

	BinaryTree* ReadPetsFile(BinaryTree* clients);

	BinaryTree* ReadAppointmentsFile(BinaryTree* pets);

	RBTree* ReadAndLoadTreatmentsFile();

	BinaryTree* ReadAndLoadMedicationsFile(RBTree* treadments);

	BinaryTree* ReadAndLoadClientFile();
};
