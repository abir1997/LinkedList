
#include "LinkedList.h"

#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
LinkedList::LinkedList()
{
   head = nullptr;
}

LinkedList::~LinkedList()
{
   clear();
}

int LinkedList::size() const
{
   int count = 0;
   Node *node = this->head;
   while (node != nullptr)
   {
      ++count;
      node = node->next;
   }
   return count;
}

void LinkedList::clear()
{
   cout << "Clearing list" << endl;
   while (this->head != nullptr)
   {
      Node *toDelete = this->head;
      head = toDelete->next;
      delete toDelete;
   }
}

int LinkedList::get(int i)
{
   if(i < 0 || i>=size()){
      throw std::runtime_error("Invalid");
   }
   Node *node = this->head;
   for (int count = 0; count < i; ++count)
   {
      node = node->next;
   }
   return node->data;
}

void LinkedList::addFront(int data)
{
   Node *newNode = new Node(data, this->head);
   if(head==nullptr){
   this->head = newNode;
   }else{
   newNode->next=head;
   this->head = newNode;
   }
}

Node* LinkedList::addBack(Node* node,int data){
   Node* newHead = nullptr;
   if(node == nullptr){
      newHead = new Node(data,nullptr);
   }else{
      node->next= addBack(node->next,data);
      newHead = node;
   }
   return newHead;
}

void LinkedList::addBack(int data)
{
   head = addBack(head,data);
}

bool LinkedList::contains(int value)
{
   bool found = false;

   Node *node = this->head;
   while (node != nullptr && !found)
   {
      found = node->data == value;
      node = node->next;
   }
   return found;
}

void LinkedList::deleteFront()
{
   Node *toDelete = head;
   head = head->next;
   delete toDelete;
}

void LinkedList::deleteBack()
{
   throw std::runtime_error("Not Implemented");
}

void LinkedList::deleteAt(int i)
{
   if (i == 0)
   {
      deleteFront();
   }
   else if (i < this->size())
   {
      Node *node = this->head;
      Node *prev = nullptr;
      for (int count = 0; count < i; ++count)
      {
         prev = node;
         node = node->next;
      }
      prev->next = node->next;
      delete node;
   }
   else
   {
      cout << "ERR" << endl;
   }
}