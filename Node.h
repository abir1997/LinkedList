
#ifndef WEEK06_NODE_H
#define WEEK06_NODE_H
#include <iostream>

class Node {
public:

   Node(int data, Node* next);
   Node(int data, Node* next,Node* prev);
   Node(Node& other);
   ~Node();
  
   int   data;
   Node* next;
   Node* prev;
};

#endif // WEEK06_NODE_H
