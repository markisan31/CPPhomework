//
//  main.cpp
//  LisaYlesanne0812_03
//
//  Created by Mark Kalda on 13.12.2020.
//

#include <iostream>
#include <vector>

template <typename T>
T findMax(std::vector<T> arr){
    T max = arr[0];
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    return max;
}

template <typename T>
int findElementsId(std::vector<T> arr, T element){
    int id = 0;
    for (int i = 0; i < arr.size() ; ++i) {
        if (element == arr[i]) {
            id = i;
        }
    }
return id;
}

class Punkt{
private:
    int x, y;
    
public:
    Punkt(){
        
    }
    
    Punkt(int a, int b){
        x = a;
        y = b;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    
    Punkt operator+(Punkt& punkt){
        return (Punkt(x + punkt.getX(), y + punkt.getY()));
    }
    
    friend bool operator==(Punkt punkt1, Punkt punkt2){
        return punkt1.getX() == punkt2.getX() && punkt1.getY() == punkt2.getY() ? true : false;
    }
    
    friend bool operator>(Punkt punkt1, Punkt punkt2){
        return punkt1.getX() > punkt2.getX() && punkt1.getY() > punkt2.getY() ? true : false;
    }
    
};

Punkt getSum (std::vector<Punkt> arr){
    Punkt sum (0, 0);
    for(Punkt x : arr){
        sum = sum + x;
    }
    return sum;
}
template <class T1, class T2>
class kaheElemendiClass{
private:
    T1 a;
    T2 b;
public:
    kaheElemendiClass(){
        
    }
    
    kaheElemendiClass(T1 ax, T2 by){
        a = ax;
        b = by;
    }
    
    T1 getA(){
        return a;
    }
    
    T2 getB(){
        return b;
    }
    
};

int main(int argc, const char * argv[]) {
    Punkt p1(2, 3);
    Punkt p2(7, 9);
    Punkt p3(2, 1);
    Punkt p4 = p1 + p2;
    
    std::vector <Punkt> arr = {p1, p2, p3};
    std::vector <int> arr2 = {0, -1, 45, 29, 80, 80, 28};
    
    std::cout << "(" << p4.getX() << ":" << p4.getY() << ")" << std::endl;
    std::cout <<"Summaarne punkt on: (" << getSum(arr).getX() << ":" << getSum(arr).getY() << ")" << std::endl;
    std::cout << "--------------" << std::endl;
    
    std::cout << "Maksimaalne v22rtus massiviis on: (" << findMax(arr).getX() << ":" << findMax(arr).getY() << ")" << std::endl;
    std::cout << "Maksimaalne v22rtus massiviis on: " << findMax(arr2) << std::endl;
    
    std::cout << "--------------" << std::endl;
    
    std::cout << "Elemendi p2 id massiviis: " << findElementsId(arr, p2) << std::endl;
    std::cout << "Elemendi 45 id massiviis: " << findElementsId(arr2, 45) << std::endl;
    
    std::cout << "--------------" << std::endl;

    kaheElemendiClass<Punkt, bool> kec = kaheElemendiClass<Punkt, bool> (p1, true);
    std::cout << "(" << kec.getA().getX() << ":" << kec.getA().getY() <<"), " << kec.getB() << std::endl;
    
    return 0;
}
