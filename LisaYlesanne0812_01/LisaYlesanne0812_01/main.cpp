//
//  main.cpp
//  LisaYlesanne0812_01
//
//  Created by Mark Kalda on 08.12.2020.
//

#include <iostream>
#include <vector>
#include <math.h>


class Punkt{
    friend double showDistance(Punkt);
protected:
    int x, y;
    
public:
    Punkt(){
        std::cout << "empty constructor created" << "\n";
    }
    
    Punkt(int a, int b){
        x = a;
        y = b;
    }
    
    void insertData() {
        std::cout << "Please, insert x coordinate: ";
        std::cin >> x;
        std::cout << "Please, insert y coordiante: ";
        std::cin >> y;
    }
    
    virtual void showData() {
        std::cout << "x value is: " << x << " and y values is: " << y << "\n";
    }
    
    void addPunkt(Punkt p){
        x = x + p.x;
        y = y + p.y;
    }
    
    friend double showDistance();
    
};

class RuumiPunkt : public Punkt {
protected:
    int z;
public:
    
    RuumiPunkt(){
        
    }
    RuumiPunkt (int a, int b, int c) : Punkt(a,b){
        z = c;
    }
    
    void setPoints(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
    
    void showData() {
        std::cout << "x value is: " << x << ", value y is: " << y << " and value z is: "<< z <<"\n";
    }
    
};

double showDistance(Punkt p){
    return sqrt(pow((p.x - 0), 2) + pow((p.y - 0), 2));
}

int main(int argc, const char * argv[]) {
    Punkt punkt(1, 2);
    Punkt punkt2(3, 4);
    
    punkt.showData(); // not virtual - x value is: 1 and y values is: 2
    punkt2.showData(); // not virtual - x value is: 3 and y values is: 4
    
    std::cout << "----------------" << std::endl;
    
    punkt2.addPunkt(punkt);
    std::cout << "Punkti punkt kaugus koordinaatide alguspunktist on: " << showDistance(punkt) << "\n";
    std::cout << "Punkti punkt2 kaugus koordinaatide alguspunktist on: " << showDistance(punkt2)<< "\n";
    std::cout << "----------------" << std::endl;
    
    RuumiPunkt rp (1, 2, 3);
    RuumiPunkt rp2;
    rp2.setPoints(5, 3, 7);
    
    punkt2.showData();
    rp2.showData();
    std::cout << "----------------" << std::endl;
    Punkt a(2,5);
    RuumiPunkt *ptr_a = &rp2;
    
    Punkt &refa = a;
    refa.showData();//x value is: 2 and y values is: 5
    refa = rp;
    //&refa = *ptr_a; impossible
    refa.showData();//x value is: 1 and y values is: 2
    
    std::cout << "----------------" << std::endl;
    std::cout << "ptr_a\t" << ptr_a << std::endl;   //0x7ffeefbff348
    std::cout << "&ptr_a\t" << &ptr_a << std::endl; //0x7ffeefbff338
    std::cout << "&rp2\t" << &rp2 << std::endl;     //0x7ffeefbff348
    std::cout << "&a\t" << &a << std::endl;         //0x7ffeefbff340
    std::cout << "&refa\t" << &refa << std::endl;   //0x7ffeefbff340
    
    std::cout << "----------------" << std::endl;
    
    std::vector <Punkt*> points = {&punkt, &punkt2, &rp, &rp2};
    
    for (Punkt* p : points){
        p->showData();
    }
    
    /*
     x value is: 1 and y values is: 2
     x value is: 4 and y values is: 6
     x value is: 1, value y is: 2 and value z is: 3
     x value is: 5, value y is: 3 and value z is: 7
     */
    
    return 0;
}
