#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string make;
    string model;
    int year;
    double dailyRentalRate;

public:
    Vehicle(string id, string mke, string mdl, int yr, double rate)
        : vehicleID(id), make(mke), model(mdl), year(yr), dailyRentalRate(rate) {}

    virtual double calculateRentalCost(int days) {
        return dailyRentalRate * days;
    }

    virtual void displayDetails() {
        cout << "Vehicle ID: " << vehicleID << "\nMake: " << make << "\nModel: " << model
             << "\nYear: " << year << "\nDaily Rental Rate: $" << dailyRentalRate << "\n";
    }

    // Getter for vehicleID
    string getVehicleID() const {
        return vehicleID;
    }
};

class Car : public Vehicle {
private:
    int numberOfDoors;
    string fuelType;

public:
    Car(string id, string mke, string mdl, int yr, double rate, int doors, string fuel)
        : Vehicle(id, mke, mdl, yr, rate), numberOfDoors(doors), fuelType(fuel) {}

    double calculateRentalCost(int days) {
        return dailyRentalRate * days;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numberOfDoors << "\nFuel Type: " << fuelType << "\n";
    }
};

class Motorcycle : public Vehicle {
private:
    string engineType;
    bool hasSidecar;

public:
    Motorcycle(string id, string mke, string mdl, int yr, double rate, string engine, bool sidecar)
        : Vehicle(id, mke, mdl, yr, rate), engineType(engine), hasSidecar(sidecar) {}

    double calculateRentalCost(int days) {
        double cost = dailyRentalRate * days;
        if (hasSidecar) {
            cost += 20 * days;
        }
        return cost;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Engine Type: " << engineType << "\nHas Sidecar: " << (hasSidecar ? "Yes" : "No") << "\n";
    }
};

class RentalSystem {
private:
    vector<Vehicle> vehicles;

public:
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() {
        for (size_t i = 0; i < vehicles.size(); ++i) {
            vehicles[i].displayDetails();
            cout << "------------------------------------\n";
        }
    }

    Vehicle* findVehicle(string vehicleID) {
        for (size_t i = 0; i < vehicles.size(); ++i) {
            if (vehicles[i].getVehicleID() == vehicleID) {
                return &vehicles[i];
            }
        }
        return NULL;  // Return NULL if not found
    }

    void rentVehicle(string vehicleID, int days) {
        Vehicle* v = findVehicle(vehicleID);
        if (v != NULL) {  // Check if vehicle is found
            double rentalCost = v->calculateRentalCost(days);
            cout << "Rental cost for " << days << " days: $" << rentalCost << "\n";
        } else {
            cout << "Vehicle not available.\n";
        }
    }

    void returnVehicle(string vehicleID) {
        Vehicle* v = findVehicle(vehicleID);
        if (v != NULL) {  // Check if vehicle is found
            cout << "Vehicle " << vehicleID << " has been returned.\n";
        } else {
            cout << "Vehicle not found.\n";
        }
    }
};

int main() {
    RentalSystem rentalSystem;

    rentalSystem.addVehicle(Car("CAR123", "Toyota", "Corolla", 2020, 50, 4, "Gas"));
    rentalSystem.addVehicle(Motorcycle("MOTO456", "Harley", "Sportster", 2018, 30, "V-Twin", true));

    int choice;
    string vehicleID;
    int days;

    do {
        cout << "\n1. Display Available Vehicles\n2. Rent a Vehicle\n3. Return a Vehicle\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rentalSystem.displayAvailableVehicles();
                break;

            case 2:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                cout << "Enter number of days: ";
                cin >> days;
                rentalSystem.rentVehicle(vehicleID, days);
                break;

            case 3:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                rentalSystem.returnVehicle(vehicleID);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

