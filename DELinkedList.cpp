#include "LinkedList.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::endl;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    sizeCount = 0;
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

unsigned int LinkedList::getSize()
{
    return sizeCount;
}

void LinkedList::clear()
{
    while (this->head != nullptr)
    {
        Node *toDelete = this->head;
        head = toDelete->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
    sizeCount = 0;
}

int LinkedList::get(unsigned int i)
{
    Node *node = this->head;
    for (unsigned int count = 0; count < i; ++count)
    {
        node = node->next;
    }
    return node->data;
}

void LinkedList::addFront(int data)
{

    if (this->head == nullptr) //list empty
    {
        Node *newNode = new Node(data, nullptr, nullptr);
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data, this->head, nullptr);
        this->head->prev = newNode;
        this->head = newNode;
    }
    sizeCount++;
}

void LinkedList::addBack(int data)
{
    if (this->head == nullptr)
    {
        Node *newNode = new Node(data, nullptr, nullptr);
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data, nullptr, this->tail);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    sizeCount++;
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
    if (head != nullptr)
    {
        Node *toDelete = head;
        head = head->next; //set new head.

        if (head == nullptr)
        {
            this->tail = nullptr;
        }
        else
        {
            head->prev = nullptr; //set new head's prev to null
        }
        delete toDelete;
        sizeCount--;
    }
    else
    {
        throw std::runtime_error("List is empty");
    }
}

void LinkedList::deleteBack()
{
    Node *toDelete = tail;
    tail = tail->prev;
    if (tail == nullptr)
    {
        this->head = nullptr;
    }
    else
    {
        tail->next = nullptr;
    }
    delete toDelete;
    sizeCount--;
}

void LinkedList::deleteAt(unsigned int i)
{
    if (i == 0)
    {
        deleteFront();
    }
    else if (i < this->getSize())
    {
        Node *node = this->head;

        //find node to be deleted
        for (unsigned int count = 0; count < i; ++count)
        {
            node = node->next;
        }

        if (node == this->tail)
        {
            deleteBack();
        }
        else
        {
            //if node is somewhere in the middle
            //get the previous node
            //set the previous node's nxt ptr to deleted node's nxt ptr
            Node *prev = node->prev;
            prev->next = node->next;

            //get the next node
            //set next node's prev pointer to deleted node's prev pointer
            Node *nxt = node->next;
            nxt->prev = node->prev;
        }
        delete node;
        sizeCount--;
    }
    else
    {
        std::cout << "Invalid index" << endl;
    }
}

Node *LinkedList::getNodeAt(unsigned int i)
{
    Node *retVal = this->head;
    if (i < this->getSize())
    {
        for (unsigned int count = 0; count < i; ++count)
        {
            retVal = retVal->next;
        }
    }
    return retVal;
}

void LinkedList::addAt(unsigned int i, int data)
{

    Node *newNode = new Node(data, nullptr, nullptr);
    if (i == 0)
    {
        addFront(newNode->data);
    }
    else if (i < this->getSize())
    {

        Node *currNode = getNodeAt(i);
        //get currNode's prev node
        Node *prevNode = currNode->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        //make newNode's nxt point point to currNode's nxt
        newNode->next = currNode;
        currNode->prev = newNode;
        sizeCount++;
    }

    else
    {
        std::cout << "Invalid index" << endl;
    }
}

void LinkedList::shuffle(){
    if(head != nullptr && this->getSize() > 1){

        std::vector<int> nodeVec;
        for(unsigned int i=0; i < this->getSize(); ++i){
            nodeVec.push_back(this->get(i));
        }

        std::random_shuffle(nodeVec.begin(),nodeVec.end());
        this->clear();

        for(unsigned int i=0; i < nodeVec.size(); ++i){
            this->addBack(nodeVec.at(i));
        }

        //std::cout<<"After shufffle : "<<this->getSize();
    }else{
        std::cout<<"Nothing to shuffle"<<endl;
    }
}