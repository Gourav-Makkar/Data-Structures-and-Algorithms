class ParkingSystem {
public:
    int s1,s2,s3;
    ParkingSystem(int big, int medium, int small) {
        s1=big,s2=medium,s3=small;
    }
    
    bool addCar(int car) {
        if(car==1)
        {
            if(s1==0)
                return false;
            s1--;
            return true;
        }
        if(car==2)
        {
            if(s2==0)
                return false;
            s2--;
            return true;
        }
        if(car==3)
        {
            if(s3==0)
                return false;
            s3--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */