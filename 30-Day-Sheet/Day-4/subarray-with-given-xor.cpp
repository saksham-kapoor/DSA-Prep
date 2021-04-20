/*

Concept -> 1 2 3 4 5 6 7 8 9
           |         |
              _xor
              
           |   |     |
             y    k

            _xor = y ^ k
            
            this implies
            
            y = _xor ^ k


*/

int Solution::solve(vector<int> &A, int k)
{
    int num_subarrays = 0;
    unordered_map<int, int> xr;
    int _xor = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        _xor ^= A[i];
        if (_xor == k)
            ++num_subarrays;
        if (xr.find(_xor ^ k) != xr.end())
            num_subarrays += xr[_xor ^ k];
        xr[_xor]++;
    }

    return num_subarrays;
}

// Brute Force
// int Solution::solve(vector<int> &A, int B) {
//     int num_subarrays = 0;

//     for(int i=0; i<A.size(); ++i) {
//         int _xor = 0;
//         for(int j=i; j<A.size(); ++j) {
//             _xor ^= A[j];
//             if(_xor == B) ++num_subarrays;
//         }
//     }

//     return num_subarrays;
// }