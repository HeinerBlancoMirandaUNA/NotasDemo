#pragma once
#include <iostream>
#include "node.h"
#include "student.h"

enum ListPosition {
    First,
    Last,
    Next,
    Back
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    T dummy;
    int listSize;

    void deleteOperation (){

        Node<T>* temp = current;

        if (listSize == 1) {
            tail = nullptr;
            head = nullptr;
            current = nullptr;

        } else if (current->previous == nullptr) {
            current = current->next;
            head = current;
            head->previous = nullptr;

        } else if (current->next == nullptr) {

            current = current->previous;
            tail = current;
            tail->next = nullptr;

        } else {
            current->previous->next = current->next;
            current->next->previous = current->previous;
            current = current->next;
        }

        delete temp;
        listSize--;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {
        listSize = 0;
        std::cout << "!!!!!ListCreated" ;
    }

    virtual ~DoublyLinkedList() {
        go(First);
        while(isValid()) {
            del(1);
        }
    }

    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;

    }

    void del(int toDelete) {
        go(First);
        int counter = 1;
        while (isValid()) {
            if (counter == toDelete) {
                deleteOperation();
                return;
            }
            go(Next);
            counter++;
        }
        return;
    }

    void go(ListPosition here) {
        if (here == First) {current = head;}
        if (here == Last) {current = tail;}
        if (!isValid()) {return;};
        if (here == Back) {current = current->previous;}
        if (here == Next) {current = current->next;}
    }

    T getItem() {
        if (!isValid()) { return dummy; }
        return current->data;
    }

    bool isValid() {
        return current;
    }

    int getSize() {
        return listSize;
    }

};



