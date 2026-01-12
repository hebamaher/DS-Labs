#include <iostream>
#include "LinkedList.h"
#include <vector>
//#include "Stack.h"
using namespace std;

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.display();

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.reverseQueue();
    q.display();

    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cout << "Front element: " << cq.peek() << endl;

    int arr[] = {1, 3, 2, 4 };
    nextGreater(arr, 4);


//    Stack * stc = new Stack(5);
//
//    // 10    5    -20
//    stc->Push(10);
//    stc->Push(5);
//    stc->Push(-20);
//
//    int popvalue;
//    if(stc->Pop(popvalue))
//        cout<<popvalue;    // -20
//
//    if(stc->Pop(popvalue))
//        cout<<popvalue;    // 5
//
//    if(stc->Peek(popvalue))
//        cout<<popvalue;    // 10
//
//    if(!stc->Pop(popvalue))
//        cout<<"stack is empty";
//
//    else cout<<popvalue;


}
