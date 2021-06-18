/*
    Explanation:
    let f = number of complete weeks
    let r = number of days left after 'f' cycles
    
    part 1 -> complete weeks
    for week 1, sum = 7(7 + 1) / 2 = 28
    for week 2, sum = 28 + 7
    for week 3, sum = 28 + 7 + 7
    .
    .
    .
    for week f, sum = 28 + (f - 1) * 7
    
    adding
    for all complete weeks, sum = f * 28 + (0 + 7 + (7 + 7) + (7 + 7 + 7) ...)
                                = f * 28 + 7(1 + 2 + 3 + .... (f - 1))
                                = f * 28 + 7 * (f - 1) * f / 2
 
    part 2 -> left over days, i.e r
    if week 1 was going on, sum = r * (r + 1) / 2
    if week 2 was going on, sum = r * (r + 1) / 2 + r * 1
    .
    .
    .
    if week f + 1 was going on, sum = r * (r + 1) / 2 + r * f

    THEREFORE FINAL ANSWER
    = f * 28 + 7 * (f - 1) * f / 2  +  r * (r + 1) / 2 + r * f 

*/

class Solution
{
public:
    int totalMoney(int n)
    {
        int f = n / 7, r = n % 7;
        return f * 28 + f * (f - 1) / 2 * 7 + r * (r + 1) / 2 + f * r;
    }
};