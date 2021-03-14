#include <iostream>
#include <string>
using namespace std;

void permute_cases(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        return;
    }

    string op1, op2;
    op1 = op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(ip[0] - 32);
    ip.erase(ip.begin());

    permute_cases(ip, op1);
    permute_cases(ip, op2);
}

int main()
{
    string ip = "abc", op = "";
    permute_cases(ip, op);
    return 0;
}