#include<bits/stdc++.h>
using namespace std;

enum VehicleType{
  CAR, BIKE
};

class Vehicle;

class Slot{
  private:
    int slotId;
    Vehicle *parkedVehicle;
    VehicleType vehicleType;
  public:
    Slot(){}
    Slot(int slotId, VehicleType vehicleType){
      this->slotId = slotId;
      this->parkedVehicle = NULL;
      this->vehicleType = vehicleType;  
    }
    
    virtual int getSlotId() { return slotId; }
    virtual Vehicle* getParkedVehicle() { return parkedVehicle; }
    virtual int getVehicleType() { return vehicleType; }

    virtual void setParkedVehicle(Vehicle *parkedVehicle) { this->parkedVehicle=parkedVehicle; }

    
};


class Vehicle{
  public:
    virtual int getVehicleId()=0;
    virtual VehicleType getVehicleType()=0;
};

class Car: public Vehicle{
  int id, slotId;
  public:
    Car(int id){ this->id=id; this->slotId=-1; }
    virtual int getVehicleId() { return id; }
    virtual VehicleType getVehicleType() { return (VehicleType::CAR); }
};
class Bike: public Vehicle{
  int id, slotId;
  public:
    Bike(int id){ this->id=id; this->slotId=-1; }
    virtual int getVehicleId() { return id; }
    virtual VehicleType getVehicleType() { return (VehicleType::BIKE); }
};

class ParkingLot{
  public:
    virtual void setSlots(int n, VehicleType vehicleType)=0;
    virtual void park(Vehicle *&vehicle)=0;
    virtual void remove(Vehicle *&vehicle)=0;
    virtual void showAvailableSlots(VehicleType vehicleType)=0;
};

class ParkingLotImpl: public ParkingLot{
    vector<Slot*> slots;
  public:
    ParkingLotImpl(){
    }
    
    virtual void setSlots(int n, VehicleType vehicleType){
      for(int i=0; i<n; i++){
        Slot *slot = new Slot(slots.size()+1, vehicleType);
        slots.push_back(slot);
      }        
    }

    virtual void park(Vehicle *&vehicle){
      VehicleType vehicleType =  vehicle->getVehicleType();
      for(int i=0; i<slots.size(); i++){
        if((slots[i]->getVehicleType()==vehicleType) && ((slots[i]->getParkedVehicle())==NULL)){
          slots[i]->setParkedVehicle(vehicle);
          cout<<"Parked\n";
          return;
        }  
      }
      cout<<"No Slots are Available\n";
      return;
    }

    virtual void remove(Vehicle *&vehicle){

      for(int i=0; i<slots.size(); i++){
        if(slots[i]->getParkedVehicle() == vehicle){
          slots[i]->setParkedVehicle(NULL);
          cout<<"Removed\n";
          return;
        } 
      }
      cout<<"Invalid Vehicle\n";
      return;
    }

    virtual void showAvailableSlots(VehicleType vehicleType){
      cout<<"Available Slots Are - ";
      int c=0;
      for(int i=0; i<slots.size(); i++){
        if((slots[i]->getVehicleType()==vehicleType) && ((slots[i]->getParkedVehicle())==NULL)){
          cout<<"  "<<slots[i]->getSlotId()<<" ";
          c++;
        }      
      }

      if(c==0){
        cout<<"No Slots are Available ";
      }
      return;
  }
    

};

int main(){
  ParkingLot *parkingLot = new ParkingLotImpl();
  parkingLot->setSlots(4, VehicleType::CAR);
  parkingLot->setSlots(8, VehicleType::BIKE);

  Vehicle *mkpvehicle = new Car(81416);
  parkingLot->park(mkpvehicle);

  parkingLot->remove(mkpvehicle);
  Vehicle *mkpvehicle2 = new Car(81416);
  parkingLot->park(mkpvehicle2);  
  
  parkingLot->showAvailableSlots(VehicleType::CAR);

  return 0;
}


