#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList* List = new LinkedList();
//    LinkedList* L1 = new LinkedList();
//    LinkedList* L2 = new LinkedList();
//    //LinkedList* Result;
//
//    L1->add(10);
//    L1->add(20);
//    L1->add(30);
//    L1->add(40);
//
//    L2->add(0);
//    L2->add(20);
//    L2->add(40);
//    L2->add(70);
//
//    List->add(10);
//
//
//    //List->Display();
//
////    if(List->Search(10))
////        cout<<"found\n";
////    else cout<<"Not found\n";
//
//    List->insertAfter(20,10);
//
//    List->insertBefore(0,10);
//
//    List->Display();
//
//    cout<<List->count()<<endl;
//
//    cout<<List->getDataByIndex(1)<<endl;
//
//    List->reverse();
//    List->Display();
//
//    //List->reverse();
//
//    LinkedList* Result = List->reverseNewList();
//    Result->Display();
//
//    //List->Display();
//
//    List->RemoveEveryKthElement(2);
//    List->Display();
//
//    Result = L1->Intersection(L2);
//    Result->Display();


    int values[] = {30, 10, 50, 20, 40, 5, 60, 25};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        cout << "\nInserting " << values[i] << endl;
        List->insertSorted(values[i]);

        cout << "Current list: ";
        List->Display();
        cout << endl;
    }

    cout << "\nFinal sorted list: ";
    List->Display();
    cout << endl;

    //bool deleted = List->Delete(10);

    //cout<<deleted;

    return 0;
}
