
#include "LinkedList.h"

#include <iostream>
#include <string>

#define EXIT_SUCCESS    0

using std::string;
using std::cout;
using std::endl;

int main(void) {
    LinkedList* list = new LinkedList();
   list->addFront(99);
   list->addBack(21);
   list->addFront(-1);
   list->addFront(7);
   list->addFront(2);
   list->addAt(2,-9);
   list->addBack(212);
   list->addFront(-11);
  
   list->deleteAt(5);
   list->deleteAt(2);
   list->deleteAt(0);

   cout << "List Size: " << list->size() << endl;
   cout<<"Randomize list"<<endl;
   list->shuffle();
   for (int i = 0; i < list->size(); ++i) {
      cout << "\t Element[" << i << "]: " << list->get(i) << endl;
   }

   list->clear();
   try{
   list->deleteFront();
   }catch(const std::runtime_error& e){
      cout<<"OOPs"<<endl;
   }
   list->addFront(99);
   list->addFront(-1);
   list->addFront(7);
  
   cout << "List Size using counter: " << list->getSize() << endl;
   for (int i = 0; i < list->size(); ++i) {
      cout << "\t Element[" << i << "]: " << list->get(i) << endl;
   }


   cout << endl;
   cout << "contains(-1): " << list->contains(-1) << endl;

   try {
      list->deleteFront();
      cout << "Delete successful, new size: " << list->size() << endl;
      cout << "List Size using counter: " << list->getSize() << endl;
   } catch (std::string& error) {
      std::cerr << "Caught error: " << error << endl;
   }

   cout << "WATCH THE ORDERING OF DELETE!" << endl;
   delete list;

   return EXIT_SUCCESS;
}

