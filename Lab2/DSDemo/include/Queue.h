#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue(int _size)
        {
            arr = new int[_size];
            frot = rear = -1;
        }

        bool Enqueue(int val)
        {
            //O(1)
            if(IsFull())
                return false;

            if(IsEmpty())
                frot++;
            rear++;
            arr[rear] = val;
            return true;

        }

        bool Dequeue(int &val)
        {
            //O(n)
            if(IsEmpty())
                return false;
            val = arr[frot];
            shift(); // loop N
            rear--;

            if(IsEmpty())
                frot = -1;

        }


    protected:

    private:
        int queueSize;
        int frot, rear;
        int *arr;

        void shift()
        {
            for(int i = frot; i<rear;++i)
                arr[i] = arr[i+1];
        }

};

#endif // QUEUE_H
