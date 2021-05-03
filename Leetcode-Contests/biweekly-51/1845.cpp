class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> minSeat;

public:
    SeatManager(int n)
    {
        for (int i = n; i >= 1; --i)
        {
            minSeat.push(i);
        }
    }

    int reserve()
    {
        int seatNumber = minSeat.top();
        minSeat.pop();

        return seatNumber;
    }

    void unreserve(int seatNumber)
    {
        // insert at correct place in stack
        minSeat.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */