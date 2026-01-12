#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
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
            cout<<"\n";
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

        void insertAfter(int data, int afterData) {
            Node* temp = head;

            while (temp != NULL && temp->data != afterData)
                temp = temp->next;

            if (temp == NULL) {
                cout << "Value " << afterData << " not found.\n";
                return;
            }

            Node* newNode = new Node(data);

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newNode;
            else
                tail = newNode;

            temp->next = newNode;
        }

        void insertBefore(int data, int beforeData){
            Node* temp = head;

            while(temp != NULL && temp->data != beforeData){
                temp = temp->next;
            }

            if(temp == NULL){
                cout << "Value " << beforeData << " not found.\n";
                return;
            }

            Node* newNode = new Node(data);
            newNode->next = temp;
            newNode->prev = temp->prev;

            if(temp->prev != NULL){
                temp->prev->next = newNode;
            }
            else{
                head = newNode;
            }
            temp->prev = newNode;
        }

        int count(){
            Node* temp = head;
            int counter = 0;
            while(temp != NULL){
                temp = temp->next;
                counter++;
            }
            return counter;
        }

        int getDataByIndex(int index){
            int i = 0;
            Node* temp = head;

            while(temp != NULL){
                temp = temp->next;
                if(i == index){
                    return temp->data;
                }
                i++;
            }
            cout << "Invalid Index\n" ;
            return -1;
        }

        void reverse(){
            Node* current = head;
            Node* temp = NULL;

            while (current != NULL) {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;

                current = current->prev;
            }

            if (temp != NULL)
            head = temp->prev;
        }

        LinkedList* reverseNewList() {
            cout << "Tail data = " << tail->data << endl;

            LinkedList* newList = new LinkedList();

            Node* temp = tail;        // start from the end of the original list
            while (temp != NULL) {
                newList->add(temp->data);   // create NEW node with same data
                temp = temp->prev;
            }

            return newList;
        }

        void RemoveEveryKthElement(int k){
            if (k <= 1)
                return;

            int i = 1;
            Node* temp = head;

            while (temp != NULL) {
                Node* nextNode = temp->next;

                if (i % k == 0) {
                    Delete(temp->data);
                }

                temp = nextNode;
                i++;
            }
        }

        LinkedList* Intersection(LinkedList* L){
            Node* l1 = this->head;
            Node* l2 = L->head;
            LinkedList* result = new LinkedList();

            while(l1 != NULL && l2 != NULL){
                if(l1->data > l2->data){
                    l2 = l2->next;
                }
                else if(l1->data < l2->data){
                    l1 = l1->next;
                }
                else{
                    result->add(l1->data);
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
            return result;
        }

        void insertSorted(int data){
            Node * node = new Node(data);
            // List if it was empty
            if(head == NULL){
                head = tail = node;
            }
            else{
                // connect it
                Node *ptr = head;

                while(ptr && ptr->data < data)
                    ptr = ptr->next;

                // reached the end
                if(!ptr){
                    node->prev = tail;
                    tail->next = node;
                    tail = node;
                }
                else if (ptr == head) {
                    node->next = head;
                    head->prev = node;
                    head = node;
                    return;
                }
                else{
                    node->prev = ptr->prev;
                    node->next = ptr;
                    ptr->prev = node;
                }
            }
        }
        // Utility: print list
        void print() {
            Node* temp = head;

            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

#endif // LINKEDLIST_H
