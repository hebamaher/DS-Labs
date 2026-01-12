#ifndef NODE_H
#define NODE_H

class Node
{
    public:
       int data;
       Node * next;
       Node * prev;

       Node(int _data)
       {
           // set data
           data = _data;

           next = prev = NULL;

       }

    protected:

    private:
};

#endif // NODE_H
