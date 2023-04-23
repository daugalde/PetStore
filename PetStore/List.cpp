#include <iostream>
#include "Node.h"
#include "List.h"
#include "Client.h"
#include "Inventory.h"
#include "SoldItem.h"

using namespace std;

bool List::HasAisleId(int id) {
	bool hasElement = false;

	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			if (aux->value->getId() == id)
			{
				hasElement = true;
				return hasElement;
			}
			aux = aux->NextNode;
		}
	}
	return hasElement;
}

bool List::HasProductId(int id) {
	bool hasElement = false;

	//Node* aux;
	//if (head != NULL) {
	//	aux = head;
	//	while (aux)
	//	{
	//		Product* product = static_cast<Product*>(aux->value);
	//		if (product != NULL && product->getProductId() == id)
	//		{
	//			hasElement = true;
	//			return hasElement;
	//		}
	//		aux = aux->NextNode;
	//	}
	//}
	return hasElement;
}

bool List::HasProductMakeId(int id) {
	bool hasElement = false;

	/*Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			Product* product = static_cast<Product*>(aux->value);
			if (product != NULL && product->getMakeId() == id)
			{
				hasElement = true;
				return hasElement;
			}
			aux = aux->NextNode;
		}
	}*/
	return hasElement;
}

int List::Length() {
	int cont = 0;

	PointerNode aux = head;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
	}
};

void List::Push(Object* obj)
{
	if (IsEmpty()) {
		head = new Node( obj);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node( obj);
	}
}

List* List::Join(List* list)
{
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			Item* item = static_cast<Item*>(aux->value);

			if (list->GetObjectByMakeProductId(item->getMakeId()))
			{
				SoldItem* soldItem = static_cast<SoldItem*>(list->GetObjectByMakeProductId(item->getMakeId()));
				soldItem->setCount(soldItem->getCount() + 1);
			}
			else {

				list->Push(new SoldItem(item->getId(), item->getName(), item->getMakeId(), 1));
			}

			aux = aux->NextNode;
		}
	}
	return list;
}

void List::DisplayMostVisitedAisle()
{
	Node* aux;
	if (head != NULL) {
		int maxVisits = 0;
		string maxVisitsName = "";
		aux = head;
		/*while (aux)
		{
			Aisle*  aisle = static_cast<Aisle*>(aux->value);
			if (aisle->getVisits() > maxVisits)
			{
				maxVisits = aisle->getVisits();
				maxVisitsName = aisle->getName();
			}
			aux = aux->NextNode;
		}*/

		if (maxVisits != 0)
		{
			cout << "\nEl Pasillo mas visitados es: " << maxVisitsName << " con " << maxVisits << " visitas" << endl;
		}
		else {
			cout << "No hay Pasillos visitados" << endl;
		}
	}
	else {
		cout << "No hay Pasillos visitados" << endl;
	}
}

void List::DisplayLessVisitedAisle()
{
	Node* aux;
	if (head != NULL) {
		int length = Length();
		int minVisits = 0;
		string minVisitsName = "";
		aux = head;
		/*while (length != 0)
		{
			Aisle* aisle = static_cast<Aisle*>(aux->value);
			if (aisle->getVisits() <= minVisits)
			{
				minVisits = aisle->getVisits();
				minVisitsName = aisle->getName();
			}
			aux = aux->NextNode;
			length--;
		}*/

		if (minVisits >= 0)
		{
			cout << "\nEl Pasillo menos visitados es: " << minVisitsName << " con " << minVisits << " visitas" << endl;
		}
		else {
			cout << "No hay Pasillos visitados" << endl;
		}
	}
	else {
		cout << "No hay Pasillos visitados" << endl;
	}
}

void List::DisplayClientWithLessInvoices()
{
	Node* aux;
	if (head != NULL) {
		int length = Length();
		int minVisits = 0;
		string minVisitsName = "";
		aux = head;
		while (length != 0)
		{
			Client* client = static_cast<Client*>(aux->value);
			if (client->getVisits() >= minVisits)
			{
				minVisits = client->getVisits();
				minVisitsName = client->getName();
			}
			aux = aux->NextNode;
			length--;
		}

		if (minVisits >= 0)
		{
			cout << "\nEl Cliente con menos visitas es: " << minVisitsName << " con " << minVisits << " visitas" << endl;
		}
		else {
			cout << "No hay visitas de clientes" << endl;
		}
	}
	else {
		cout << "No hay visitas de clientes" << endl;
	}
}

void List::DisplayClientWithMostInvoices()
{
	Node* aux;
	if (head != NULL) {
		int maxInvoices = 0;
		string clientName = "";
		aux = head;
		while (aux)
		{
			Client* client = static_cast<Client*>(aux->value);
			if (client->getVisits() > maxInvoices)
			{
				maxInvoices = client->getVisits();
				clientName = client->getName();
			}
			aux = aux->NextNode;
		}

		if (maxInvoices != 0)
		{
			cout << "\nEl Cliente con mas facturaciones es: " << clientName << " con " << maxInvoices << " facturaciones" << endl;
		}
		else {
			cout << "Cliente sin facturacion" << endl;
		}
	}
	else {
		cout << "Cliente sin facturacion" << endl;
	}
}

void List::DisplayGreatestInvoicedAmount()
{
	Node* aux;
	if (head != NULL) {
		float mostInvoicedAmount = 0;
		string clientName = "";
		aux = head;
		while (aux)
		{
			Client* client = static_cast<Client*>(aux->value);
			if (client->getTotalInvoiced() > mostInvoicedAmount)
			{
				mostInvoicedAmount = client->getTotalInvoiced();
				clientName = client->getName();
			}
			aux = aux->NextNode;
		}

		if (mostInvoicedAmount != 0)
		{
			cout << "\nEl mayor monto de una factura es del cliente : " << clientName << " con " << mostInvoicedAmount << " colones." << endl;
		}
		else {
			cout << "No hay Facturacion" << endl;
		}
	}
	else {
		cout << "No hay Facturacion" << endl;
	}
}

void List::DisplayAllProductsByAisleId(int aisleId)
{
	Node* aux;
	if (head != NULL) {
		bool onlyShowOnce = true;
		aux = head;
		while (aux)
		{
			/*Aisle* aisle = static_cast<Aisle*>(aux->value);

			if (aisleId == aisle->getId())
			{
				aisle->getProductAisles()->Display("productAisle");
				return;
			}*/

			aux = aux->NextNode;
		}
		cout << endl;
	}
}

void List::DisplayClientWithGreatestInvoiceCount()
{
	Node* aux;
	if (head != NULL) {
		aux = head;
		string clientName = "";
		int invoicesTotal = 0;
		while (aux)
		{
			Client* client = static_cast<Client*>(aux->value);
			if (client->getInvoices() > invoicesTotal)
			{
				invoicesTotal = client->getInvoices();
				clientName = client->getName();
			}

			aux = aux->NextNode;
		}
		cout << endl;
		if (invoicesTotal != 0)
		{
			cout << "\nEl Cliente con mayor cantidad de facturas es : " << clientName << " con " << invoicesTotal << " Facturas." << endl;
		}
		else {
			cout << "No hay Clientes con mayor Cantidad de facturas." << endl;
		}
	}
	else {
		cout << "No hay Clientes con mayor Cantidad de facturas." << endl;
		cout << "\n Presione Enter para volver al menu anterior." << endl;
	}
}

void List::Display(string type)
{
	Node* aux;
	if (head != NULL) {
		bool onlyShowOnce = true;
		aux = head;
		while (aux)
		{
			if (type == "aisle")
			{
				if (onlyShowOnce)
				{
					cout << "Codigo Pasillo" << "\t" << "Nombre" << endl;
					onlyShowOnce = false;
				}
				//cout << aux->value->getId() << "\t" << aux->value->getName() << static_cast<Aisle*>(aux->value)->type << endl;
			}
			else if (type == "productAisle") {
				//cout << static_cast<ProductAisle*>(aux->value)->getProductId() << "\t" << aux->value->getName() << endl;
			}
			else if (type == "product") {
				//cout << static_cast<Product*>(aux->value)->getMakeId() << "\t" << aux->value->getName() << "\t" << static_cast<Product*>(aux->value)->getShelfQuantity() << "\t" << static_cast<Product*>(aux->value)->getPrice() << endl;
			}
			else if (type == "inventory") {

				if (onlyShowOnce)
				{
					cout << "Codigo Pasillo" << "\t" << "Codigo Marca Producto" << "\t" << "Codigo Marca" << "\t" << "Nombre" << "\t" << "Cantidad en Stock" << "\t" << "Es Canasta basica" << endl;
					onlyShowOnce = false;
				}
				cout << "\n" << aux->value->getId() << "\t" << static_cast<Inventory*>(aux->value)->getProductId() << "\t" << static_cast<Inventory*>(aux->value)->getMakeId() << "\t" << aux->value->getName() << "\t" << static_cast<Inventory*>(aux->value)->getStockQuantity() << "\t" << static_cast<Inventory*>(aux->value)->getIsBasicBasket() << "\n" << endl;
			}
			else if (type == "client") {
				if (onlyShowOnce)
				{
					cout << "Cedula" << "\t" << "Nombre" << "\t" << "Telefono" << "\t" << "Direccion" << endl;
					onlyShowOnce = false;
				}
				cout << aux->value->getId() << "\t" << aux->value->getName() << "\t" << static_cast<Client*>(aux->value)->getPhone() << "\t" << static_cast<Client*>(aux->value)->getAddress() << endl;
			}
			else if ("item") {
				Item* item = static_cast<Item*>(aux->value);
				if (onlyShowOnce)
				{
					cout << "Codigo Pasillo " << "\t" << "Codigo Producto" << "\t" << "Nombre " << "\t" << "Precio " << "\n" << endl;
				}
				cout << item->getId() << "\t" << item->getMakeId() << "\t" << item->getName() << "\t" << item->getPrice();
			}
			else if ("sales") {
				SoldItem* soldItem = static_cast<SoldItem*>(aux->value);
				if (onlyShowOnce)
				{

					cout << "Codigo Pasillo " << "\t" << "Codigo Producto" << "Name" << "\n" << endl;
				}
				cout << soldItem->getId() << "\t" << soldItem->getMakeId() << soldItem->getName();
			}
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

float List::Sum(List inventory)
{
	float total = 0;
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			Item* item = static_cast<Item*>(aux->value);
			int isBasicBasket = static_cast<Inventory*>(GetObjectFromInventory(item->getId()))->getIsBasicBasket();
			if (isBasicBasket == 1)
			{
				total = total + (item->getPrice() * item->getQuantity() * 1.13);
			}
			else {
				total = total + (item->getPrice() * item->getQuantity() * 1.1);
			}
			aux = aux->NextNode;
		}
	}
	return total;
}

bool List::GetItemsToRefillShelf(List inventorylist, List* productList, List* hotItems)
{
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			SoldItem* soldItem = static_cast<SoldItem*>(aux->value);
			Inventory* inventory = static_cast<Inventory*>(inventorylist.GetObjectFromInventory(aux->value->getId()));
			if (soldItem->getCount() <= 2 && inventory->getStockQuantity() != 0)
			{
				hotItems->Push(soldItem);
				//Aisle* aisle = static_cast<Aisle*>(productList->GetObjectById(soldItem->getId()));
				/*if (aisle != NULL)
				{
					ProductAisle* productAisle = static_cast<ProductAisle*>(aisle->getProductAisles()->GetObjectById(aisle->getId()));

					if (productAisle != NULL)
					{

						Product* product = static_cast<Product*>(productAisle->getProducts()->GetObjectByProductId(productAisle->getProductId()));
						
						cout << "Cantidad de Productos antes en Pasillo : " << "\t" << product->getShelfQuantity() << "\n" << endl;

						int refillCount = product->getShelfQuantity() + soldItem->getCount();

						product->setShelfQuantity(refillCount);

						cout << "Nueva Cantidad de Productos Despues en Pasillo : " << "\t" << refillCount << "\n" << endl;

						cout << "\nCantidad de Productos antes en Inventario : " << "\t" << inventory->getStockQuantity() << "\n" << endl;

						int reduceInventoryCount = inventory->getStockQuantity() - soldItem->getCount();

						inventory->setStockQuantity(reduceInventoryCount);

						cout << "\nNueva Cantidad de Productos Despues en Inventario : " << "\t" << reduceInventoryCount << "\n" << endl;
					}
				}*/
				
			}
			aux = aux->NextNode;
		}
	}
	return true;
}

bool List::GetItemsToRefillInventory(List inventorylist, List* productList)
{
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			SoldItem* soldItem = static_cast<SoldItem*>(aux->value);
			Inventory* inventory = static_cast<Inventory*>(inventorylist.GetObjectFromInventory(aux->value->getId()));
			if (soldItem->getCount() <= 2 && inventory->getStockQuantity() != 0)
			{
				/*Aisle* aisle = static_cast<Aisle*>(productList->GetObjectById(soldItem->getId()));
				if (aisle != NULL)
				{
					ProductAisle* productAisle = static_cast<ProductAisle*>(aisle->getProductAisles()->GetObjectById(aisle->getId()));

					if (productAisle != NULL)
					{

						Product* product = static_cast<Product*>(productAisle->getProducts()->GetObjectByProductId(productAisle->getProductId()));

						cout << "Cantidad de Productos antes en Pasillo : " << "\t" << product->getShelfQuantity() << "\n" << endl;

						int refillCount = product->getShelfQuantity() + soldItem->getCount();

						product->setShelfQuantity(refillCount);

						cout << "Nueva Cantidad de Productos Despues en Pasillo : " << "\t" << refillCount << "\n" << endl;

						cout << "\nCantidad de Productos antes en Inventario : " << "\t" << inventory->getStockQuantity() << "\n" << endl;

						int reduceInventoryCount = inventory->getStockQuantity() - soldItem->getCount();

						inventory->setStockQuantity(reduceInventoryCount);

						cout << "\nNueva Cantidad de Productos Despues en Inventario : " << "\t" << reduceInventoryCount << "\n" << endl;
					}
				}*/

			}
			aux = aux->NextNode;
		}
	}
	return true;
}

bool List::GetItemsToInventory() {
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			Inventory* inventory = static_cast<Inventory*>(aux->value);
			if (inventory->getStockQuantity() < 20)
			{
				inventory->setStockQuantity(40);
			}
			aux = aux->NextNode;
		}
	}
	return true;
}

Object* List::GetObjectById(int id) {
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			if (aux->value->getId() == id)
			{
				return aux->value;
			}
			aux = aux->NextNode;
		}
	}
	return NULL;
}

Object* List::GetObjectByProductId(int id) {
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			/*ProductAisle* product = static_cast<ProductAisle*>(aux->value);
			if (product->getProductId() == id)
			{
				return aux->value;
			}*/
			aux = aux->NextNode;
		}
	}
	return NULL;
}

Object* List::GetObjectByMakeProductId(int id) {
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			/*Product* product = static_cast<Product*>(aux->value);
			if (product->getMakeId() == id)
			{
				return aux->value;
			}*/
			aux = aux->NextNode;
		}
	}
	return NULL;
}

Object* List::GetObjectFromInventory(int id)
{
	Node* aux;
	if (head != NULL) {
		aux = head;
		while (aux)
		{
			Inventory* product = static_cast<Inventory*>(aux->value);
			if (product->getId() == id)
			{
				return product;
			}
			aux = aux->NextNode;
		}
	}
	return NULL;
}