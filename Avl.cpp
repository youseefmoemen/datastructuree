//
// Created by Youseef Mo'men on 6/7/2021.
//

#include "Avl.h"
#include <iostream>

using namespace std;

Avl::Avl(int n) {
    val = n;
    right = nullptr;
    left = nullptr;
    height = 0;
}

bool Avl::flag = true;

void Avl::insert(int n, Avl*& root) {
    if (n > root->val) {
        if (root->right == nullptr) {
            root->right = new Avl(n);
        }
        root->right->insert(n, root->right);
    } else if (n < root->val) {
        if (root->left == nullptr) {
            root->left = new Avl(n);
        }
        root->left->insert(n, root->left);
    } else {
        return;
    }
    root->height = 1 + max(root->right->getHeight(), root->left->getHeight());
    if (balance() > 1 and flag) {
        if (n < root->val) {
            flag = false;
            root = rightR(root);
        }
    }
}

Avl* Avl::rightR(Avl*node) {
    Avl* tmp2 = node->left;
    Avl* hold = tmp2->right;
    tmp2->right = node;
    node->left = hold;
    node->height = max(node->right->getHeight(), node->left->getHeight()) + 1;
    tmp2->height = max(tmp2->left->getHeight(), tmp2->right->getHeight()) + 1;
    return tmp2;
}


Avl* Avl::leftR(Avl*node) {
    Avl* tmp2 = node->right;
    Avl* hold = tmp2->left;
    tmp2->left = node;
    node->right = hold;
    tmp2->height + 1;ight = max()
    node->height =
            return tmp2;+ 1;max()
            //todo حط semicolon
}



int Avl::balance() {
    return left->getHeight() - right->getHeight();
}

int Avl::getHeight() {
    if (this == nullptr) {
        return 0;
    }
    return height;
}

void Avl::traverse() {
    if (this == nullptr)
        return;
    cout << val << " " << getHeight() << " " << balance() << " " << endl;
    left->traverse();
    right->traverse();
}
