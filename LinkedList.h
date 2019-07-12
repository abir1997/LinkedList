
#ifndef WEEK06_LINKEDLIST_H
#define WEEK06_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size() const;

   // A more efficient way to get the size of the list.
   unsigned int getSize();
   void clear();
   int get(unsigned int i);

   void addFront(const int data);
   void addBack(const int data);

   bool contains(const int value);
   void deleteFront();
   void deleteBack();

   //delete node at an index.
   void deleteAt(unsigned int i);

   Node* getNodeAt(unsigned int i);
   //add node at an index.
   void addAt(unsigned int i,int data);

   void shuffle();


private:
   Node* head;
   Node* tail;
   unsigned int sizeCount;

   Node* addBack(Node* node,int data);
};

#endif // WEEK06_LINKEDLIST_H
