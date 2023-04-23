#include "TreeNode.h"
#include "BinaryTree.h"
#include <iomanip>
#include <iostream>
#include <fstream> 
#include "Pet.h"
#include "Appointment.h"
#include "Client.h"
using namespace std;

void BinaryTree::InOrder(TreeNode* node, string type) {
	if (node == NULL) {
		return;
	}
	else {
		InOrder(node->GetLeft(),type);
		if (type == "pet")
		{
			Pet* pet = static_cast<Pet*>(node->GetElement());
			cout << "\"" << pet->getId() << "  " << pet->getName() << "  " << pet->getCastrated() << "\"" << "\n";
		}
		else if (type == "appointment")
		{
			Appointment* appointment = static_cast<Appointment*>(node->GetElement());
			cout << "\n" << "Mascota Id : " << appointment->getPetId() << "\nUltima visita : " << appointment->getDay() << " / " << appointment->getMonth() << " / " << appointment->getYear() << "\nTotal Factura : " << fixed << setprecision(2) << appointment->getTotalInvoiced() << ((appointment->getPaymentType() == 1) ? "\nForma de pago : CONTADO" : "\nForma de pago : CREDITO") << "\n";
		}
		else if (type == "medication")
		{
			Medication* medication = static_cast<Medication*>(node->GetElement());
			cout << "El Id del Medicamento : " << medication->getId() << "  Cantidad : " << medication->getQuantity() << " Precio Unitario : " << medication->getUnitPrice()
				<< " Precio Total : " << medication->getTotalPrice() << "\n\n";
		}
		else if (type == "client") {
			Client* client = static_cast<Client*>(node->GetElement());
			cout << "El Id del Cliente : " << client->getId() << "  Nombre : " << client->getName() << " Direccion : " << client->getAddress()
				<< " Codigo Pais : " << client->getCountryId() << " Codigo Ciudad : " << client->getCityId()
				<< " Ultima visita : " << client->getDay() << "/" << client->getMonth() << "/" << client->getYear() << " Telefono " << client->getPhone()
				<< " Descuento : " << client->getDiscount() << " Total debido : " << client->getBalance() << "\n\n";
		}
		else {
			cout << "\"" << node->GetElement()->getId() << "  " << node->GetElement()->getName() << "  " << "\"" << "\n";
		}
		InOrder(node->GetRight(), type);
	}
}

void BinaryTree::PreOrder(TreeNode* node, string type) {
	if (node == NULL) {
		return;
	}
	else {
		if (type == "pet")
		{
			Pet* pet = static_cast<Pet*>(node->GetElement());
			cout << "\"" << pet->getId() << "  " << pet->getName() << "  " << pet->getCastrated() << "\"" << "\n";
		}
		if (type == "appointment")
		{
			Appointment* appointment = static_cast<Appointment*>(node->GetElement());
			cout << "\n" << "Mascota Id : " << appointment->getPetId() << "\nUltima visita : " << appointment->getDay() << " / " << appointment->getMonth() << " / " << appointment->getYear() << "\nTotal Factura : " << fixed << setprecision(2) << appointment->getTotalInvoiced() << ((appointment->getPaymentType() == 1) ? "\nForma de pago : CONTADO" : "\nForma de pago : CREDITO") << "\n";
		}
		else if (type == "medication")
		{
			Medication* medication = static_cast<Medication*>(node->GetElement());
			cout << "El Id del Medicamento : " << medication->getId() << "  Cantidad : " << medication->getQuantity() << " Precio Unitario : " << medication->getUnitPrice()
				<< " Precio Total : " << medication->getTotalPrice() << "\n\n";
		}
		else if (type == "client") {
			Client* client = static_cast<Client*>(node->GetElement());
			cout << "El Id del Cliente : " << client->getId() << "  Nombre : " << client->getName() << " Direccion : " << client->getAddress()
				<< " Codigo Pais : " << client->getCountryId() << " Codigo Ciudad : " << client->getCityId()
				<< " Ultima visita : " << client->getDay() << "/" << client->getMonth() << "/" << client->getYear() << " Telefono " << client->getPhone()
				<< " Descuento : " << client->getDiscount() << " Total debido : " << client->getBalance() << "\n\n";
		}
		else {
			cout << "\"" << node->GetElement()->getId() << "  " << node->GetElement()->getName() << "  " << "\"" << "\n";
		}
		PreOrder(node->GetLeft(), type);
		PreOrder(node->GetRight(), type);
	}
}

void BinaryTree::PostOrder(TreeNode* node, string type) {
	if (node == NULL) {
		return;
	}
	else {
		PostOrder(node->GetLeft(), type);
		PostOrder(node->GetRight(), type);
		if (type == "pet")
		{
			Pet* pet = static_cast<Pet*>(node->GetElement());
			cout << "\"" << pet->getId() << "  " << pet->getName() << "  " << pet->getCastrated() << "\"" << "\n";
		}
		if (type == "appointment")
		{
			Appointment* appointment = static_cast<Appointment*>(node->GetElement());
			cout << "\n" << "Mascota Id : " << appointment->getPetId() << "\nUltima visita : " << appointment->getDay() << " / " << appointment->getMonth() << " / " << appointment->getYear() << "\nTotal Factura : " << fixed << setprecision(2) << appointment->getTotalInvoiced() << ((appointment->getPaymentType() == 1) ? "\nForma de pago : CONTADO" : "\nForma de pago : CREDITO") << "\n";
		}
		else if (type == "medication")
		{
			Medication* medication = static_cast<Medication*>(node->GetElement());
			cout << "El Id del Medicamento : " << medication->getId() << "  Cantidad : " << medication->getQuantity() << " Precio Unitario : " << medication->getUnitPrice()
				<< " Precio Total : " << medication->getTotalPrice() << "\n\n";
		}
		else if (type == "client") {
			Client* client = static_cast<Client*>(node->GetElement());
			cout << "El Id del Cliente : " << client->getId() << "  Nombre : " << client->getName() << " Direccion : " << client->getAddress()
				<< " Codigo Pais : " << client->getCountryId() << " Codigo Ciudad : " << client->getCityId()
				<< " Ultima visita : " << client->getDay() << "/" << client->getMonth() << "/" << client->getYear() << " Telefono " << client->getPhone()
				<< " Descuento : " << client->getDiscount() << " Total debido : " << client->getBalance() << "\n\n";
		}
		else {
			cout << "\"" << node->GetElement()->getId() << "  " << node->GetElement()->getName() << "  " << "\"" << "\n";
		}
	}
}

bool BinaryTree::InsertNode(Object* obj, TreePointerNode node) {
	bool result = false;

	if (obj->getId() < node->GetElement()->getId()) {
		if (node->GetLeft() == NULL) {
			node->SetLeft(new TreeNode(obj));
			result = true;
		}
		else {
			result = InsertNode(obj, node->GetLeft());
		}
	}
	else if (obj->getId() > node->GetElement()->getId()) {
		if (node->GetRight() == NULL) {
			node->SetRight(new TreeNode(obj));
			result = true;
		}
		else {
			result = InsertNode(obj, node->GetRight());
		}
	}
	return result;
}

bool BinaryTree::Insert(Object* obj) {
	if (IsEmpty()) {
		SetRoot(new TreeNode(obj));
		return true;
	}
	else {
		return this->InsertNode(obj, this->root);
	}
}

Object* BinaryTree::SearchById(int id, TreeNode* node) {
	Object* result = NULL;
	if (node != NULL) {
		if (id == node->GetElement()->getId()) {
			result = node->GetElement();
		}
		else {
			if (id < node->GetElement()->getId()) {
				result = SearchById(id, node->GetLeft());
			}
			else if (id > node->GetElement()->getId()) {
				result = SearchById(id, node->GetRight());
			}
		}
	}
	return result;
}

Pet* BinaryTree::SearchPetByClientId(int id, TreeNode* node) {
	Pet* result = NULL;
	if (node != NULL) {
		if (id == static_cast<Pet*>(node->GetElement())->getClientId()) {
			result = static_cast<Pet*>(node->GetElement());
		}
		else {
			if (id < static_cast<Pet*>(node->GetElement())->getClientId()) {
				result = static_cast<Pet*>(SearchPetByClientId(id, node->GetLeft()));
			}
			else if (id > static_cast<Pet*>(node->GetElement())->getClientId()) {
				result = static_cast<Pet*>(SearchPetByClientId(id, node->GetRight()));
			}
		}
	}
	return result;
}

Appointment* BinaryTree::SearchAppointmentByIdAndPetId(int id, int petId,TreeNode* node) {
	Appointment* result = NULL;
	if (node != NULL) {
		if (id == static_cast<Appointment*>(node->GetElement())->getId() && petId == static_cast<Appointment*>(node->GetElement())->getPetId()) {
			result = static_cast<Appointment*>(node->GetElement());
		}
		else {
			if (id < static_cast<Appointment*>(node->GetElement())->getId()) {
				result = static_cast<Appointment*>(SearchAppointmentByIdAndPetId(id, petId, node->GetLeft()));
			}
			else if (id > static_cast<Appointment*>(node->GetElement())->getId()) {
				result = static_cast<Appointment*>(SearchAppointmentByIdAndPetId(id, petId, node->GetRight()));
			}
		}
	}
	return result;
}

bool BinaryTree::UpdateById(int id, string name, TreeNode* node) {
	bool result = false;
	if (node != NULL) {
		if (id == node->GetElement()->getId()) {
			node->GetElement()->setName(name);
			result = true;
		}
		else {
			if (id < node->GetElement()->getId()) {
				result = UpdateById(id, name, node->GetLeft());
			}
			else if (id > node->GetElement()->getId()) {
				result = UpdateById(id, name, node->GetRight());
			}
		}
	}
	return result;
}

bool BinaryTree::UpdateElementById(int id, Object* obj, TreeNode* node) {
	bool result = false;
	if (node != NULL) {
		if (id == node->GetElement()->getId()) {
			node->SetElement(obj);
			result = true;
		}
		else {
			if (id < node->GetElement()->getId()) {
				result = UpdateElementById(id, obj, node->GetLeft());
			}
			else if (id > node->GetElement()->getId()) {
				result = UpdateElementById(id, obj, node->GetRight());
			}
		}
	}
	return result;
}

//AVL

TreePointerNode BinaryTree::InsertBalancedNode(Object* obj, TreePointerNode node, bool &Hh) {
	
	TreePointerNode n1;

	if (node == NULL) {
		node = new TreeNode(obj);
		Hh = true;
	}
	else if (obj->getId() < node->GetElement()->getId()) {

			node->SetLeft(InsertBalancedNode(obj, node->GetLeft(), Hh));

			if (Hh) {
				switch (node->GetBalanceFactor()) {
				case 1:
					node->SetBalanceFactor(0);
					Hh = false;
					break;
				case 0:
					node->SetBalanceFactor(-1);
					break;
				case -1:
					n1 = node->GetLeft();
					if (n1->GetBalanceFactor() == -1) {
						node = RotateLeft(node, n1);//II
					}
					else {
						node = RotateDoubleLeft(node, n1);//ID
					}
					Hh = false;
					break;
				}
			}
		}
		else if (obj->getId() > node->GetElement()->getId()) {
			node->SetRight(InsertBalancedNode(obj, node->GetRight(), Hh));

			if (Hh) {
				switch (node->GetBalanceFactor()) {
				case -1:
					node->SetBalanceFactor(0);
					Hh = false;
					break;
				case 0:
					node->SetBalanceFactor(1);
					break;
				case 1:
					n1 = node->GetRight();
					if (n1->GetBalanceFactor() == 1) {
						node = RotateRight(node, n1);//DD
					}
					else {
						node = RotateDoubleRight(node, n1);//DI
					}
					Hh = false;
					break;
				}
			}
		}
	

	return node;
}

//TODO : Find Correct Name ID
TreePointerNode BinaryTree::RotateDoubleLeft(TreePointerNode node, TreePointerNode node1) {
	TreePointerNode n2;
	n2 = node1->GetRight();
	node->SetLeft(n2->GetRight());
	n2->SetRight(node);
	node1->SetRight(n2->GetLeft());
	n2->SetLeft(node1);

	if (n2->GetBalanceFactor() == 1) {
		node1->SetBalanceFactor(-1);
	}
	else {
		node1->SetBalanceFactor(0);
	}
	if (n2->GetBalanceFactor() == -1) {
		node->SetBalanceFactor(1);
	}
	else {
		node->SetBalanceFactor(0);
	}
	n2->SetBalanceFactor(0);
	//node = n2;
	return n2;
}

// DI
TreePointerNode BinaryTree::RotateDoubleRight(TreePointerNode node, TreePointerNode node1) {
	TreePointerNode n2;
	n2 = node1->GetLeft();
	node->SetRight(n2->GetLeft());
	n2->SetLeft(node);
	node1->SetLeft(n2->GetRight());
	n2->SetRight(node1);

	if (n2->GetBalanceFactor() == 1) {
		node->SetBalanceFactor(-1);
	}
	else {
		node->SetBalanceFactor(0);
	}
	if (n2->GetBalanceFactor() == -1) {
		node1->SetBalanceFactor(1);
	}
	else {
		node1->SetBalanceFactor(0);
	}
	n2->SetBalanceFactor(0);
	//node = n2;
	return n2;
}

//DD
TreePointerNode BinaryTree::RotateRight(TreePointerNode node, TreePointerNode node1) {
	node->SetRight(node1->GetLeft());
	node1->SetLeft(node);

	if (node1->GetBalanceFactor() == 1) {
		node->SetBalanceFactor(0);
		node1->SetBalanceFactor(0);
	}
	else {
		node->SetBalanceFactor(-1);
		node1->SetBalanceFactor(1);
	}
	//node = node1;
	return node1;
}

//II
TreePointerNode BinaryTree::RotateLeft(TreePointerNode node, TreePointerNode node1) {
	node->SetLeft(node1->GetRight());
	node1->SetRight(node);

	if (node1->GetBalanceFactor() == -1) {
		node->SetBalanceFactor(0);
		node1->SetBalanceFactor(0);
	}
	else {
		node->SetBalanceFactor(-1);
		node1->SetBalanceFactor(1);
	}
	//node = node1;
	return node1;
}

void BinaryTree::InsertBalanced(Object* obj) {
	if (IsEmpty())
	{
		this->SetRoot(new TreeNode(obj));
	}
	else {
		this->SetRoot(this->InsertBalancedNode(obj, this->GetRoot(), this->hh));
	}
}

// AA Tree

Medication* BinaryTree::SearchLastMedication(int id, int petId, TreeNode* node) {
	Medication* result = NULL;
	if (node != NULL) {
		if (id == static_cast<Medication*>(node->GetElement())->getId() && petId == static_cast<Medication*>(node->GetElement())->getPetId()) {
			result = static_cast<Medication*>(node->GetElement());
		}
		else {
			if (id < static_cast<Medication*>(node->GetElement())->getId()) {
				result = static_cast<Medication*>(SearchLastMedication(id, petId, node->GetLeft()));
			}
			else if (id > static_cast<Medication*>(node->GetElement())->getId()) {
				result = static_cast<Medication*>(SearchLastMedication(id, petId, node->GetRight()));
			}
		}
	}
	return result;
}

//Reports
string BinaryTree::GetClientReport(TreeNode* node, string type, int& sum) {
	string result = "";
	if (node == NULL) {
		return "No hay Registros";
	}
	else {
		GetClientReport(node->GetLeft(), type, sum);
		Client* client = static_cast<Client*>(node->GetElement());
		if (type == "greaterBalance") {
			
			
			if (client->getBalance() > sum )
			{
				result = client->getName();
				sum = client->getBalance();
			}
		}
		else if (type == "greaterCredit") {
			if (client->getTotalInvoiced() > sum)
			{
				result = client->getName();
				sum = client->getTotalInvoiced();
			}
		}
		else if (type == "greaterDiscount") {
			if (client->getDiscount() > sum)
			{
				result = client->getName();
				sum = client->getDiscount();
			}
		}
		GetClientReport(node->GetRight(), type, sum);
	}
	return result;
}