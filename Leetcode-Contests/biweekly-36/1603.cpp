class ParkingSystem
{
    array<int, 4> A;

public:
    ParkingSystem(int big, int medium, int small)
        : A{0, big, medium, small} // initialization is imp!
    {
    }

    bool addCar(int carType)
    {
        return --A[carType] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */