#include <iostream>
#include <string>
using namespace std;

void printPowerSet(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << op << " ";
        return;
    }

    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin());

    printPowerSet(ip, op1);
    printPowerSet(ip, op2);
}

int main()
{
    string s = "abc";
    string op = "";
    printPowerSet(s, op);
    return 0;
}