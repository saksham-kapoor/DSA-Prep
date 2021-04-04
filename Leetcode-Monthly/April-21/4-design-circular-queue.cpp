class MyCircularQueue
{
    int front, rear, size;
    vector<int> q;

public:
    MyCircularQueue(int k)
    {
        front = rear = -1;
        size = k;
        q.resize(k);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;
        q[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return q[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return q[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */