// N teams, each match eliminates 1 team
// so N-1 matches will eliminate N-1 teams and leave out the winner

class Solution
{
public:
    int numberOfMatches(int n)
    {
        return n - 1;
    }
};