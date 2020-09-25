#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <fstream>



using namespace std;
float mark;

float * ask_marks(){
    int mark_size = 5;
    float final_result = 0;
    int count = 0;
    static float arr [5];
    do {
        cout << "Please write your mark: " << endl;
        cin >> mark;
        if (mark < 0 || mark > 10 || fmod(mark,0.5) != 0){
            cout << "It's wrong number, try again: " << endl;
        } else {
            arr[count] = mark;
            count += 1;
        }
    }while (count < mark_size);
    sort(begin(arr), end(arr));
    cout << "Final result: ";
    for (int i = 1; i < 4; i++) {
        final_result += arr[i];
    }
    cout << "[" << final_result << "]";
    return arr;
}

void write_to_file (float * array){
    float * p = array;
    float final_result = 0;
    ofstream myfile;
    myfile.open ("results.txt");
    myfile << "All results(sorted): ";
    for (int i = 0; i < 5; i++) {
        myfile << "[" << p[i] << "]";
    }
    myfile << endl;
    myfile << "Final result: ";
    for (int i = 1; i < 4; i++) {
        final_result += p[i];
    }
    myfile << "[" << final_result << "]";
    myfile.close();
}


int main(int argc, const char * argv[]) {
    write_to_file(ask_marks());
    
    return 0;
}



