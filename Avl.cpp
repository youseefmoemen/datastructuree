//
// Created by Youseef Moment on 6/7/2021.
//

//#include "Avl.h"
#include <iostream>

using namespace std;

Avl::Avl(int n) {
    val = n;
    right = nullptr;
    left = nullptr;
    height = 0;
}

bool Avl::flag = true;

void Avl::insert(int n, Avl *&root) {
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
        } else {
            cout << "B\n";
            Avl *hold = root->left;
            hold = leftR(hold);
            root->left = hold;
            root = rightR(root);
        }
    }
    if (balance() < -1) {
        if (n > root->val and n > root->right->val) {
            cout << "C\n";
            root = leftR(root);
        } else {
            cout << "D\n";
            Avl *hold = root->right;
            hold = rightR(hold);
            root->right = hold;
            root = leftR(root);
        }
    }
}

Avl *Avl::successor(Avl *node) {
    Avl *hold = node->right;
    while (hold->left != nullptr) {
        hold = hold->left;
    }
    return hold;
}

void Avl::Delete(int n, Avl *&root) {
    if (n > root->val) {
        Delete(n, root->right);
    } else if (n < root->val) {
        Delete(n, root->left);
    } else {
        if (root->right == nullptr and root->left == nullptr) {
            root = nullptr;
        } else if (root->left == nullptr or root->right == nullptr) {
            if (root->right != nullptr) {
                root = root->right;
            } else if (root->left != nullptr) {
                root = root->left;
            }
        }else{
            Avl* hold = successor(root);
            swap(hold->val, root->val);
            Delete(n, hold);
        }
    }
}

Avl *Avl::rightR(Avl *node) {
    //node 3
    Avl *tmp2 = node->left; //tmp2 2
    Avl *hold = tmp2->right; //hold null
    tmp2->right = node; // 2 right -> 3
    node->left = hold; //3 left -> null
    if (hold != nullptr)
        node->height = max(node->right->getHeight(), node->left->getHeight()) + 1;
    else
        node->height = max(node->right->getHeight(), node->left->getHeight());
    tmp2->height = max(tmp2->left->getHeight(), tmp2->right->getHeight()) + 1;
    return tmp2;
}

Avl *Avl::leftR(Avl *node) {
    Avl *tmp2 = node->right;
    Avl *hold = tmp2->left;
    tmp2->left = node;
    node->right = hold;
    if (hold != nullptr)
        node->height = max(node->right->getHeight(), node->left->getHeight()) + 1;
    else
        node->height = max(node->right->getHeight(), node->left->getHeight());
    tmp2->height = max(tmp2->left->getHeight(), tmp2->right->getHeight()) + 1;
    return tmp2;
}

int Avl::balance() {
    return left->getHeight() - right->getHeight();
}

int Avl::getHeight() {
    if (this == NULL) {
        return 0;
    }
    return height;
}

void Avl::preOrder() {
    if (this == NULL)
        return;
    cout << val << " " << getHeight() << " " << balance() << " " << endl;
    left->preOrder();
    right->preOrder();
}

void Avl::inOrder() {
    if (this == NULL)
        return;
    left->inOrder();
    cout << val << " " << getHeight() << " " << balance() << " " << endl;
    right->inOrder();
}

void Avl::postOrder() {
    if (this == NULL)
        return;
    left->preOrder();
    right->preOrder();
    cout << val << " " << getHeight() << " " << balance() << " " << endl;
}
