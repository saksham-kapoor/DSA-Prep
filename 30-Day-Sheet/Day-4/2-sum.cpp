/*

Problem -> return indices of two elements who sum up to exactly target

Method 1 -> Nested for loop
            Easy
            O(N^2) TIME
            O(1) SPACE

Method 2 -> Hash Map
            Intuition: we need to store elements along with their indices.
            [element -> index]

            traverse the array
                check if(target - A[i] is present in hash)
                            yes: return required indices
                            no: put A[i] in hash and continue

            O(N) TIME --> As hash table requires O(1) time at average
            O(N) SPACE

*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &A, int target)
    {
        unordered_map<int, int> num_index;

        for (int i = 0; i < A.size(); ++i)
        {

            if (num_index.find(target - A[i]) != num_index.end())
                return {i, num_index[target - A[i]]};

            num_index[A[i]] = i;
        }

        return {};
    }
};