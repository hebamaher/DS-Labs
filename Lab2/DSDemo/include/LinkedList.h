#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;
class LinkedList
{
    public:

        LinkedList()
        {
            head = tail = NULL;
        }

        void add(int data)  // O(1)
        {
            // insert new node
            Node * node = new Node(data);

            // List if it was empty
            if(head == NULL)
            {
                head = tail = node;

            }
            else
            {

                // connect it
                node->prev = tail;
                tail->next = node;
                tail = node;

            }

        }
        // for testing
        void Display()  // O(n)
        {

            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<"\t";

                //move next
                current = current->next;

            }
        }

        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }


        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=NULL)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }

                // tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = NULL;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;

            }
            else return false;
        }



    private:
        Node * head;
        Node * tail;

    Node* getNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
                return current;
            //move next
            current = current->next;
        }
        return NULL;
    }
};

class Stack {
    private:
        Node* topNode;

    public:
        Stack() {
            topNode = NULL;
        }

        bool isEmpty() {
            return topNode == NULL;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = topNode;
            topNode = newNode;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return;
            }
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }

        int top() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return -1;
            }
            return topNode->data;
        }

        void display() {
            Node* current = topNode;
            cout << "Stack: ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

class Queue {
    private:
        Node* front;   // Remove from here
        Node* rear;    // Insert here

    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }

        bool isEmpty() {
            return front == NULL;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);

            if (rear == NULL) {         // Queue is empty
                front = rear = newNode;
                return;
            }

            rear->next = newNode;
            rear = newNode;
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is Empty\n";
                return;
            }

            Node* temp = front;
            front = front->next;

            if (front == NULL) { //one node
                rear = NULL;
            }

            delete temp;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Queue is Empty\n";
                return -1;
            }
            return front->data;
        }

        void display() {
            Node* current = front;
            cout << "Queue: ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void reverseQueue() {
            Stack st;

            while (!isEmpty()) {
                st.push(peek());
                dequeue();
            }

            while (!st.isEmpty()) {
                enqueue(st.top());
                st.pop();
            }
        }

};

class CircularQueue {
    private:
        Node* rear;   // last node, rear->next is front

        bool isEmpty() {
            return rear == NULL;
        }

    public:
        CircularQueue() {
            rear = NULL;
        }

        // Enqueue = insert after rear
        void enqueue(int value) {
            Node* newNode = new Node(value);

            if (isEmpty()) {
                rear = newNode;
                rear->next = rear;  // circular
            } else {
                newNode->next = rear->next;  // newNode->next = front
                rear->next = newNode;        // attach new node
                rear = newNode;              // new node becomes new rear
            }
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is Empty\n";
                return;
            }

            Node* front = rear->next;

            // Only one element
            if (rear == front) {
                delete front;
                rear = NULL;
            } else {
                rear->next = front->next;  // Skip the front node
                delete front;
            }
        }

        // Peek = front element
        int peek() {
            if (isEmpty()) {
                cout << "Queue is Empty\n";
                return -1;
            }
            return rear->next->data;   // front is rear->next
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is Empty\n";
                return;
            }

            Node* temp = rear->next;  // start at front

            cout << "Circular Queue: ";
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != rear->next);

            cout << endl;
        }
};

  // 3 5 9 8
vector<int> nextGreater(int arr[], int n) {
    vector<int> result(n);
    Stack st;

    for (int i = n - 1; i >= 0; i--) {

        while (!st.isEmpty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.isEmpty()) {
            result[i] = -1;
        }
        else {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }

     cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
    return result;
}

#endif // LINKEDLIST_H
