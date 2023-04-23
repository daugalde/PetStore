#pragma once
#include <iostream>
#include "RBTreeNode.h"
using namespace std;

class RBTree {

private:
    RBTreePointerNode root;
    RBTreePointerNode TNULL;

    // Preorder
    void preOrder(RBTreePointerNode node) {
        if (node != TNULL) {
            cout << node->GetElement()->getName() << " ";
            preOrder(node->GetLeft());
            preOrder(node->GetRight());
        }
    }

    // Inorder
    void inOrder(RBTreePointerNode node) {
        if (node != TNULL) {
            inOrder(node->GetLeft());
            cout << node->GetElement()->getName() << " ";
            inOrder(node->GetRight());
        }
    }

    // Post order
    void postOrder(RBTreePointerNode node) {
        if (node != TNULL) {
            postOrder(node->GetLeft());
            postOrder(node->GetRight());
            cout << node->GetElement()->getName() << " ";
        }
    }

    Object* SearchById(RBTreePointerNode node, int id) {
        Object* result = NULL;
        if (node != NULL) {
            if (id == node->GetElement()->getId()) {
                result = node->GetElement();
            }
            else {
                if (id < node->GetElement()->getId()) {
                    result = SearchById(node->GetLeft(),id);
                }
                else if (id > node->GetElement()->getId()) {
                    result = SearchById( node->GetRight(),id);
                }
            }
        }
        return result;
    }

    void RBUpdate(RBTreePointerNode uRoot, RBTreePointerNode uNode) {
        if (root->GetAncestor() == nullptr) {
            root = uNode;
        }
        else if (uRoot == uRoot->GetAncestor()->GetLeft()) {
            uRoot->GetAncestor()->SetLeft(uNode) ;
        }
        else {
            uRoot->GetAncestor()->SetRight(uNode);
        }
        uNode->SetAncestor(uRoot->GetAncestor()) ;
    }

    bool UpdateElementById(int id, Object* obj, RBTreePointerNode node) {
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
 
    // Balanceo despues de inserción
    void InsertBalancedNode(RBTreePointerNode node) {
        RBTreePointerNode uElement;
        while (node->GetAncestor()->GetColor() == 1) {
            if (node->GetAncestor() == node->GetAncestor()->GetAncestor()->GetRight()) {
                uElement = node->GetAncestor()->GetAncestor()->GetLeft();
                if (uElement->GetColor() == 1) {
                    uElement->SetColor(0);
                    node->GetAncestor()->SetColor(0);
                    node->GetAncestor()->GetAncestor()->SetColor(1);
                    node = node->GetAncestor()->GetAncestor();
                }
                else {
                    if (node == node->GetAncestor()->GetLeft()) {
                        node = node->GetAncestor();
                        RotateRight(node);
                    }
                    node->GetAncestor()->SetColor(0);
                    node->GetAncestor()->GetAncestor()->SetColor(1);
                    RotateLeft(node->GetAncestor()->GetAncestor());
                }
            }
            else {
                uElement = node->GetAncestor()->GetAncestor()->GetRight();

                if (uElement->GetColor() == 1) {
                    uElement->SetColor(0);
                    node->GetAncestor()->SetColor(0);
                    node->GetAncestor()->GetAncestor()->SetColor(1);
                    node = node->GetAncestor()->GetAncestor();
                }
                else {
                    if (node == node->GetAncestor()->GetRight()) {
                        node = node->GetAncestor();
                        RotateLeft(node);
                    }
                    node->GetAncestor()->SetColor(0);
                    node->GetAncestor()->GetAncestor()->SetColor(1);
                    RotateRight(node->GetAncestor()->GetAncestor());
                }
            }
            if (node == root) {
                break;
            }
        }
        root->SetColor(0);
    }

    void ShowRBTree(RBTreePointerNode root, string indent, bool last) {
        if (root != TNULL) {
            cout << indent;
            if (last) {
                cout << "Derecha----";
                indent += "   ";
            }
            else {
                cout << "Izquierda----";
                indent += "|  ";
            }

            string sColor = root->color ? "Rojo" : "Negro";
            cout << root->GetElement()->getId() << "(" << sColor << ")" << endl;
            ShowRBTree(root->GetLeft(), indent, false);
            ShowRBTree(root->GetRight(), indent, true);
        }
    }

public:
    RBTree() {
        TNULL = new RBTreeNode;
        TNULL->color = 0;
        TNULL->Left = nullptr;
        TNULL->Right = nullptr;
        root = TNULL;
    }

    void preorder() {
        preOrder(this->root);
    }

    void inorder() {
        inOrder(this->root);
    }

    void postorder() {
        postOrder(this->root);
    }

    Object* SearchById(int id) {
        return SearchById(this->root, id);
    }
    
    void RotateLeft(RBTreePointerNode node) {
        RBTreePointerNode y = node->GetRight();
        node->SetRight(y->GetLeft()) ;
        if (y->GetLeft() != TNULL) {
            y->GetLeft()->SetAncestor(node);
        }
        y->SetAncestor(node->GetAncestor()) ;
        if (node->GetAncestor() == nullptr) {
            this->root = y;
        }
        else if (node == node->GetAncestor()->GetLeft()) {
            node->GetAncestor()->SetLeft(y) ;
        }
        else {
            node->GetAncestor()->SetRight(y);
        }
        y->SetLeft(node);
        node->SetAncestor(y);
    }

    void RotateRight(RBTreePointerNode node) {
        RBTreePointerNode y = node->GetLeft();
        node->SetLeft(y->GetRight()) ;
        if (y->GetRight() != TNULL) {
            y->GetRight()->SetAncestor(node);
        }
        y->SetAncestor(node->GetAncestor())  ;
        if (node->GetAncestor() == nullptr) {
            this->root = y;
        }
        else if (node == node->GetAncestor()->GetRight()) {
            node->GetAncestor()->SetRight(y);
        }
        else {
            node->GetAncestor()->SetLeft(y);
        }
        y->SetRight(node);
        node->SetAncestor(y);
    }

    // Insercion
    void RBInsert(Object* element) {
        RBTreePointerNode node = new RBTreeNode;
        node->SetAncestor(nullptr);
        node->SetElement(element);
        node->SetLeft(TNULL);
        node->SetRight(TNULL);
        node->SetColor(1);

        RBTreePointerNode y = nullptr;
        RBTreePointerNode x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->GetElement()->getId() < x->GetElement()->getId()) {
                x = x->GetLeft();
            }
            else {
                x = x->GetRight();
            }
        }

        node->SetAncestor(y);

        if (y == nullptr) {
            root = node;
        }
        else if (node->GetElement()->getId() < y->GetElement()->getId()) {
            y->SetLeft(node);
        }
        else {
            y->SetRight(node);
        }

        if (node->GetAncestor() == nullptr) {
            node->SetColor(0);
            return;
        }

        if (node->GetAncestor()->GetAncestor() == nullptr) {
            return;
        }

        InsertBalancedNode(node);
    }

    RBTreePointerNode GetRoot() {
        return this->root;
    }

    void ShowRBTree() {
        if (root) {
            ShowRBTree(this->root, "", true);
        }
    }

    bool UpdateElementById(int id, Object* obj) {
        if (root) {
            return UpdateElementById(id, obj, this->root);
        }
        else {
            return false;
        }
    }
};