#pragma once
#include "Object.h"
class RBTreeNode {

	Object* element;
    RBTreeNode* Ancestor;
    RBTreeNode* Left;
    RBTreeNode* Right;
    int color;

	RBTreeNode() {
		this->element = new Object();
		this->Left = NULL;
		this->Right = NULL;
		this->Ancestor = NULL;
		this->color = 0;
	}

	void SetElement(Object* element) {
		this->element = element;
	}

	Object* GetElement() {
		return this->element;
	}

	void SetLeft(RBTreeNode* left) {
		this->Left = left;
	}

	RBTreeNode* GetLeft() {
		return Left;
	}

	void SetRight(RBTreeNode* right) {
		this->Right = right;
	}

	RBTreeNode* GetRight() {
		return Right;
	}

	void SetAncestor(RBTreeNode* ancestor) {
		this->Ancestor = ancestor;
	}

	RBTreeNode* GetAncestor() {
		return Ancestor;
	}

	void SetColor(int color) {
		this->color = color;
	}

	int GetColor() {
		return color;
	}

    friend class RBTree;
};

typedef RBTreeNode* RBTreePointerNode;