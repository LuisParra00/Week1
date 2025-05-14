#include <iostream>
#include <string>
using namespace std;

struct Car {
    string licensePlate;
    Car* next;

    Car(string plate) : licensePlate(plate), next(nullptr) {}
};

class DriveThru {
private:
    Car* front;
    Car* rear;

public:
    DriveThru() : front(nullptr), rear(nullptr) {}

    void enqueueCar(const string& plate) {
        Car* newCar = new Car(plate);
        if (!rear) {
            front = rear = newCar;
        } else {
            rear->next = newCar;
            rear = newCar;
        }
        cout << "Car " << plate << " has arrived at the drive-thru.\n";
    }

    void serveCar() {
        if (!front) {
            cout << "No cars to serve.\n";
            return;
        }
        cout << "Serving car " << front->licensePlate << ".\n";
        Car* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void showQueue() {
        if (!front) {
            cout << "No cars in the drive-thru.\n";
            return;
        }
        cout << "Cars in the drive-thru: ";
        Car* temp = front;
        while (temp) {
            cout << "[" << temp->licensePlate << "] -> ";
            temp = temp->next;
        }
        cout << "DONE\n";
    }

    ~DriveThru() {
        while (front) {
            Car* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    DriveThru dt;
    int choice;
    string plate;

    do {
        cout << "\nDrive-Thru Menu:\n";
        cout << "1. Add Car to Queue\n";
        cout << "2. Serve Next Car\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter license plate: ";
                cin >> plate;
                dt.enqueueCar(plate);
                break;
            case 2:
                dt.serveCar();
                break;
            case 3:
                dt.showQueue();
                break;
            case 4:
                cout << "Exiting drive-thru..\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
