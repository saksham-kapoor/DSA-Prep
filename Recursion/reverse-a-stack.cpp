#include <iostream>
#include <stack>
using namespace std;

// recursive function to print stack
void print(stack<int> s)
{
    if (s.empty())
        return;
    cout << s.top() << " ";
    s.pop();
    print(s);
}

// recursive function to initialize stack
void init(stack<int> &s, int size)
{
    if (size == 0)
        return;
    int x;
    cin >> x;
    s.push(x);
    init(s, size - 1);
}

// recursive function to insert at sorted position
void insert(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}

// recursive function to reverse stack
void reverse(stack<int> &s)
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
}

int main()
{
    stack<int> s;
    int size = 5;
    init(s, 5);
    print(s);
    cout << "\n";
    reverse(s);
    print(s);
    return 0;
}