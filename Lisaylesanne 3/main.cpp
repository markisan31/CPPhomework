#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

float * ask_marks(){
    const int arr_size = 7;
    float hinne = 0;
    int count = 0;
    static float arr [arr_size];
    do {
        cout << "Sisesta hinne number " << count + 1 << " :" << endl;
        cin >> hinne;
        if (hinne < 0 || hinne > 10){
            cout << "It's wrong number, try again: " << endl;
        } else {
            arr[count] = hinne;
            count += 1;
        }
    }while (count < arr_size);
    
    return arr;
}

void show_results(float * arr){
    
    float summa = 0, average = 0, max_dif = 0;
    int degustators_no = 1;
    const int arr_size = 7;
    static float degust_diff[arr_size];
    for (int i = 0; i < arr_size; i++){
        summa += arr[i];
    }
    average = summa / arr_size;
    
    max_dif = fabs(arr[0] - average);
    cout << "Keskmine hinne on: " << average << endl;
    for (int i = 0; i < arr_size; i++){
        degust_diff[i] = fabs(arr[i] - average);
        cout << degust_diff[i] << endl;
        if (degust_diff[i] > max_dif){
            max_dif = degust_diff[i];
            degustators_no = i + 1;
        }
    }
    
    for (int i = 0; i < arr_size; i++){
        if (max_dif == degust_diff[i]){
            cout << "Degusteerija number " << i + 1 << " hinne erines kqige rohkem: " << degust_diff[i] << endl;
        }
    }
    
    ofstream myfile;
    myfile.open ("Degusteerijate_tulemused.txt");
    myfile << "Degusteerijate hinned on j2rgmised: ";
    for (int i = 0; i < arr_size; i++){
        myfile << "[" << arr[i] << "] ";
    }
    myfile << "\nDegusteerijate keskmine hinne: " << average << "\n";
    myfile << "\nDegusteerijate erinevus keskmisest : \n";
    for (int i = 0; i < arr_size; i++){
        myfile << "Degusterrija number " << i + 1 << " erinevus keskhinnest on " << degust_diff[i] << "\n";
    }
    myfile << "\n";
    for (int i = 0; i < arr_size; i++){
        if (max_dif == degust_diff[i]){
            myfile << "Degusteerija number " << i + 1 << " hinne erines kqige rohkem: " << degust_diff[i] << "\n";
        }
    }
    
    myfile.close();
}


int main(int argc, const char * argv[]) {
    
    show_results(ask_marks());
    return 0;
}
