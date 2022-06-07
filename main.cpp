#include <iostream>
#include <fstream>

struct Adress
{
    std::string city;
    std::string street;
    int building;
    int appartment;

    void print() {
        std::cout << this->city << ", " << 
        this->street << ", " << 
        this->building << ", " << 
        this->appartment << "\n";
    }
};


int main() {
    std::ifstream input("in.txt");
    int count = 0;
    input >> count;

    if (count <= 0) {
        std::cerr << "Ошибка во входном файле";
        return 1;
    }

    Adress *list = new Adress[count];
    for (int i = 0; i < count; i++) {
        Adress *p = (list + i);
        input >> p->city;
        input >> p->street;
        input >> p->building;
        input >> p->appartment;
    }
    for (int i = count - 1; i >= 0; i--) {
        Adress a = *(list + i);
        a.print();
    }
    delete[] list;

    if (!input.eof()) {
        std::cerr << "Ошибка во входном файле";
        return 1;
    }
    
    input.close();
    return 0;
}