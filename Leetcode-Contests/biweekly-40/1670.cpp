// DESIGN FRONT MIDDLE BACK QUEUE

class FrontMiddleBackQueue
{
    deque<int> a, b;

    // whan a.size() > b.size()
    void a2b()
    {
        if (a.size() <= b.size())
            return;
        b.push_front(a.back());
        a.pop_back();
    }

    // b.size() > a.size() + 1
    void b2a()
    {
        if (b.size() <= a.size() + 1)
            return;
        a.push_back(b.front());
        b.pop_front();
    }

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        a.push_front(val);
        a2b();
    }

    void pushMiddle(int val)
    {
        a.push_back(val);
        a2b();
    }

    void pushBack(int val)
    {
        b.push_back(val);
        b2a();
    }

    int popFront()
    {
        if (a.size() == 0 && b.size() == 0)
            return -1;
        if (a.size() == 0)
        {
            int x = b.front();
            b.pop_front();
            return x;
        }
        int x = a.front();
        a.pop_front();
        b2a();
        return x;
    }

    int popMiddle()
    {
        if (a.size() == 0 && b.size() == 0)
            return -1;
        if (a.size() == b.size())
        {
            int x = a.back();
            a.pop_back();
            return x;
        }

        int x = b.front();
        b.pop_front();
        return x;
    }

    int popBack()
    {
        if (a.size() == 0 && b.size() == 0)
            return -1;
        int x = b.back();
        b.pop_back();
        a2b();
        return x;
    }
};