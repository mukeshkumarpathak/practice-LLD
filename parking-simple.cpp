#include<bits/stdc++.h>
using namespace std;

enum VehicleType{
  CAR, BIKE
};

class Slots{
  private:
    int slotId;
    bool availability;
    int vehicleId;
    VehicleType vehicleType;
  public:
    Slots(){}
    Slots(int slotId, VehicleType vehicleType){
      this->slotId = slotId;
      this->availability = true;
      this->vehicleId = -1;
      this->vehicleType = vehicleType;  
    }
    
    virtual int getSlotId() { return slotId; }
    virtual int getAvailability() { return availability; }
    virtual int getVehicleId() { return vehicleId; }
    virtual int getVehicleType() { return vehicleType; }
    
};


class Vehicle{
  public:
    virtual int getVehicleId()=0;
    virtual VehicleType getVehicleType()=0;
};

class Car: Vehicle{
  int id;
  public:
    Car(int id){ this->id=id; }
    virtual int getVehicleId() { return id; }
    virtual VehicleType getVehicleId() { return (VehicleType::CAR); }
};
class Bike: Vehicle{
  int id;
  public:
    Bike(int id){ this->id=id; }
    virtual int getVehicleId() { return id; }
    virtual VehicleType getVehicleId() { return (VehicleType::BIKE); }
};

class ParkingLot{
  public:
    virtual void park(Vehicle *Vehicle)=0;
    virtual void remove(Vehicle *Vehicle)=0;
    virtual void showAvailableSlots()=0;
};





