//
// Created by Youseef Mo'men on 6/7/2021.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H


class Avl {
    int val;
    Avl* right;
    Avl* left;
    int height;
    static bool flag;
public:
    explicit Avl(int);
    void insert(int, Avl* &);
    int balance();
    int getHeight();
    void preOrder();
    void inOrder();
    void postOrder();
    Avl* rightR(Avl*);
    Avl* leftR(Avl*);
};


#endif //AVL_AVL_H
