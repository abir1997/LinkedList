
#ifndef WEEK06_LINKEDLIST_H
#define WEEK06_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void clear();
   int get(int i);

   void addFront(int data);
   void addBack(int data);

private:
   Node* head;
};

#endif // WEEK06_LINKEDLIST_H
