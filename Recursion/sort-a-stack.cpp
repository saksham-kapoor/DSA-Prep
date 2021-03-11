/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert(stack<int> &s, int x)
{
    if (s.empty() || s.top() <= x)
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}

void SortedStack ::sort()
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    sort();
    insert(s, temp);
}