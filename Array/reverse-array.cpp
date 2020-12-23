void recReverse(string &str, int i)
{
    // traverse only half of the array
    if (i >= (str.size() / 2))
        return;

    // swap
    int temp = str[i];
    str[i] = str[str.size() - i - 1];
    str[str.size() - i - 1] = temp;
    i++;
    recReverse(str, i);
}

string itReverse(string str)
{
    int size = str.size(), i = 0, temp;
    for (; i < size / 2; i++)
    {
        temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
    return str;
}

string reverseWord(string str)
{
    // return itReverse(str);
    recReverse(str, 0);
    return str;
}