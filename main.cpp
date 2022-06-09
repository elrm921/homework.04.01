#include <iostream>
#include <fstream>

class Address
{
    public:
        Address() {
            this->city = "0";
            this->street = "0";
            this->building = 0;
            this->appartment = 0;
        }
        void setAddress(std::string city, std::string street, int building, int appartment) {
            this->city = city;
            this->street = street;
            this->building = building;
            this->appartment = appartment;
        }
        void print() {
            std::cout << this->city << ", " << 
            this->street << ", " << 
            this->building << ", " << 
            this->appartment << "\n";
        }
    private:
        std::string city;
        std::string street;
        int building;
        int appartment;
};


int main() {
    std::ifstream input("in.txt");
    int count = 0;
    input >> count;

    if (count <= 0) {
        std::cerr << "Ошибка во входном файле";
        return 1;
    }

    Address *list = new Address[count];
    for (int i = 0; i < count; i++) {
        std::string city, street;
        int building, appartment;

        input >> city;
        input >> street;
        input >> building;
        input >> appartment;

        Address *p = (list + i);
        p->setAddress(city, street, building, appartment);
    }
    for (int i = count - 1; i >= 0; i--) {
        Address *p = (list + i);
        p->print();
    }
    delete[] list;

    if (!input.eof()) {
        std::cerr << "Ошибка во входном файле";
        return 1;
    }
    
    input.close();
    return 0;
}