#pragma once
#include <iostream>
#include <string>
#include "TreeNode.h"
#include <fstream> 
#include "Object.h"
#include "Pet.h"
#include "Appointment.h"
#include "Medication.h"

using namespace std;

class BinaryTree {

private:
	TreePointerNode root;
	bool InsertNode(Object* obj, TreePointerNode node);
	//Insert AVL
	TreePointerNode InsertBalancedNode(Object*, TreePointerNode node, bool &Hh);

public:
	bool hh = false;

	BinaryTree() {
		this->root = NULL;
	}

	BinaryTree(Object* obj) {
		this->root = new TreeNode(obj);
	}

	void SetRoot(TreeNode* element) {
		this->root = element;
	}

	TreeNode* GetRoot() {
		return this->root;
	}

	bool IsEmpty() { return root == NULL; }

	bool Insert(Object*);

	Object* SearchById(int id, TreeNode* node);

	Pet* SearchPetByClientId(int id, TreeNode* node);

	Appointment* SearchAppointmentByIdAndPetId(int id, int petId, TreeNode* node);

	Medication* SearchLastMedication(int id, int petId, TreeNode* node);

	bool UpdateById(int id, string name, TreeNode* node);

	bool UpdateElementById(int id, Object* obj, TreeNode* node);

	//AVL
	void InsertBalanced(Object*);
	
	TreePointerNode RotateDoubleLeft(TreePointerNode node, TreePointerNode node1);

	TreePointerNode RotateDoubleRight(TreePointerNode node, TreePointerNode node1);

	TreePointerNode RotateLeft(TreePointerNode node, TreePointerNode node1);

	TreePointerNode RotateRight(TreePointerNode node, TreePointerNode node1);

	void InOrder(TreeNode*, string type);

	void PreOrder(TreeNode*, string type);

	void PostOrder(TreeNode*, string type);

	//AA TREE

	string GetClientReport(TreeNode* node, string type, int& sum);
};