#include <iostream>
#include "Avl.h"
#include "Avl.cpp"

int main() {
    Avl *avl = new Avl(13);
    avl->insert(15, avl);
    avl->insert(16, avl);
    avl->insert(10, avl);
    avl->insert(11, avl);
    avl->insert(5, avl);
    avl->insert(8, avl);
    avl->insert(4, avl);
    avl->insert(3, avl);
    avl->traverse();
    return 0;
}
