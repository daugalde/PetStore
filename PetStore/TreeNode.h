#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class TreeNode {

private:
	Object* element;
	TreeNode* Left;
	TreeNode* Right;
	int balanceFactor = 0;
	int aaLevel = 0;
public:  // Constructors

	TreeNode() {
		this->element = new Object();
		Left = NULL;
		Right = NULL;
	}

	TreeNode(Object* element)
	{
		this->element = element;
		Left = NULL;
		Right = NULL;
	}

	void SetElement(Object* element) {
		this->element = element;
	}

	Object* GetElement() {
		return this->element;
	}

	void SetLeft(TreeNode* left) {
		this->Left = left;
	}

	TreeNode* GetLeft() {
		return Left;
	}

	void SetRight(TreeNode* right) {
		this->Right = right;
	}

	TreeNode* GetRight() {
		return Right;
	}

	void SetBalanceFactor(int balanceFactor) {
		this->balanceFactor = balanceFactor;
	}

	int GetBalanceFactor() {
		return balanceFactor;
	}

	void SetAALevel(int level) {
		this->aaLevel = level;
	}

	int GetAALevel() {
		return this->aaLevel;
	}

	friend class List;
};

typedef TreeNode* TreePointerNode; //Alias