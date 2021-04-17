class Solution
{
public:
    string removeDuplicates(string S)
    {
        string str;

        for (char i : S)
            if (str.size() != 0 && str.back() == i)
                str.pop_back();
            else
                str.push_back(i);

        return str;
    }
};

// class Solution {
// public:
//     string removeDuplicates(string S) {
//         stack<char> chars;

//         for(auto i:S) {
//             if(!chars.empty() && chars.top() == i) chars.pop();
//             else chars.push(i);
//         }

//         string newStr;

//         while(!chars.empty()) {
//             newStr.push_back(chars.top());
//             chars.pop();
//         }

//         reverse(newStr.begin(), newStr.end());

//         return newStr;
//     }
// };