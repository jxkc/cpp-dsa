#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

/*
 * TODO Add Commenting.
 * TODO Add References.
 * TODO Create Docs for this.
 *
 * */

template <typename T>
struct DoubleLinkedList {

		struct Node {
				T data;
				Node* next;
				Node* prev;

				Node();
				Node(T n);
		};

		// Head of list.
		Node* head;

		DoubleLinkedList();     // Default
		DoubleLinkedList(T n);  // Pass in first value for data.
        ~DoubleLinkedList();    // Destructor.

		// Add to the end.
		void push_back(T n);

        // Remove from end.
		void pop_back();

		void traverse();
};


template <typename T>
DoubleLinkedList<T>::Node::Node() {
		data = T();
		next = nullptr;
		prev = nullptr;
}

template <typename T>
DoubleLinkedList<T>::Node::Node(T n) {
		data = n;
		next = nullptr;
		prev = nullptr;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
		head = nullptr;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(T n) {
		head = new Node(n);
        head->next = head;
        head->prev = head;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {

    if(!head) {
        return;
    }

    Node* curr = head;
    Node* next = nullptr;

    do {
        next = curr->next;
        delete curr; 
        curr = next;
    } while (curr != head);

    head = nullptr;
}

// O(n)
// Adds 'n' to end of List.
// TODO Implement a tail to the list and it becomes O(1)
template <typename T>
void DoubleLinkedList<T>::push_back(T n) {
		Node* _new = new Node(n);

		// If there is no head, make one.
		if(!head) {
				head = _new;
				head->next = head; 
				head->prev = head; 
				return;
		}

		Node* temp = head;
		while(temp->next != head) {
				temp = temp->next;
		}

		temp->next = _new;
		_new->prev = temp;
		_new->next = head;

		head->prev = _new;
}

// O(1)
// Access the end of the list and delete it.
template <typename T>
void DoubleLinkedList<T>::pop_back() {
    if(!head) {
        return;
    }

    
    Node* last = head->prev; 

    if(last == head) {
        delete head;
        head = nullptr;
    } 
    else {
        last->prev->next = head;
        head->prev = last->prev;
        last->next = nullptr;
        last->prev = nullptr;


        delete last;
    }

}

template <typename T>
void DoubleLinkedList<T>::traverse() {

        if(!head) {
            std::cout << "List is empty.\n";
            return;
        }

		Node* temp = head;
   
        do {
            std::cout << "Value: " << temp->data << "\n";
            temp = temp->next;
        } while (temp != head);

}

#endif
