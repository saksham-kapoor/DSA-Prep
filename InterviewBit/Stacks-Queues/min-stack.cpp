class Node
{
public:
    int val, min;
    Node *next;

    Node(int val, int min, Node *next = nullptr)
    {
        this->val = val;
        this->min = min;
        this->next = next;
    }
};

Node *head;

MinStack::MinStack()
{
    head = nullptr;
}

void MinStack::push(int x)
{
    if (head == nullptr)
        head = new Node(x, x);
    else
        head = new Node(x, min(x, head->min), head);
}

void MinStack::pop()
{
    if (head)
        head = head->next;
}

int MinStack::top()
{
    if (head)
        return head->val;
    return -1;
}

int MinStack::getMin()
{
    if (head)
        return head->min;
    return -1;
}
