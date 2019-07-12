
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

using std::string;
using std::cout;
using std::endl;

int main(void) {
   LinkedList* list = new LinkedList();
   list->addFront(99);
   list->addFront(-1);
   list->addFront(7);

   cout << "List Size: " << list->size() << endl;
   for (int i = 0; i < list->size(); ++i) {
      cout << "\t Element[" << i << "]: " << list->get(i) << endl; 
   }

   return EXIT_SUCCESS;
}
