int minE = -1;
void push(stack<int> &s, int a)
{
    if (s.size() == 0)
    {
        s.push(a);
        minE = a;
    }
    else
    {
        if (a >= minE)
            s.push(a);
        else
        {
            s.push(2 * a - minE);
            minE = a;
        }
    }
}

bool isFull(stack<int> &s, int n)
{
    return (s.size() == n) ? true : false;
}

bool isEmpty(stack<int> &s)
{
    return (s.size() == 0) ? true : false;
}

int pop(stack<int> &s)
{
    int x;
    if (s.top() < minE)
    {
        x = minE;
        minE = 2 * minE - s.top();
        s.pop();
        return x;
    }
    x = s.top();
    s.pop();
    return x;
}

int getMin(stack<int> &s)
{
    if (s.empty())
        return -1;
    return minE;
}