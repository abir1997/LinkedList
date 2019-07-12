
#include "Node.h"

using std::cout;
using std::endl;
Node::Node(int data, Node* next) :
   // data(data),
   // next(next),
   // prev(nullptr)
   Node(data,next,nullptr)
{
   // cout << "Node Create: " << data << endl;
}

Node::Node(int data, Node* next,Node* prev) :
   data(data),
   next(next),
   prev(prev)
{
   cout << "Node Create: " << data << endl;
}

Node::Node(Node& other) :
   data(other.data),
   next(other.next)
{
   cout << "Node Copy: " << data << endl;
}

Node::~Node() {
   cout << "Node Deconstructor: " << data << endl;
   next = nullptr;
   prev = nullptr;
}
