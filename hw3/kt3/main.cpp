#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

using namespace std;

vector<string> all_data;
vector<int> one_city_temp;
vector<vector <int>> temps;
vector<string> places;

int coldest_temp(vector<int> a) {
    int minimum = a[0];

    for (int i = 0; i < a.size(); i++) {
        if (minimum > a[i]) {
            minimum = a[i];
        }
    }

    return minimum;
}

int warmest_temp(vector<int> a) {
    int maximum = a[0];

    for (int i = 0; i < a.size(); i++) {
        if (maximum < a[i]) {
            maximum = a[i];
        }
    }

    return maximum;
}

double average_temp(vector<int> a) {
    double sum_of_temps = 0;

    for (int i = 0; i < a.size(); i++) {
        sum_of_temps += a[i];

    }

    double result = sum_of_temps / a.size();

    return result;
}

double average_temp_without_extremes(vector<int> a) {
    double sum_of_temps = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == warmest_temp(a) || a[i] == coldest_temp(a)) {
            continue;
        } else {
            sum_of_temps += a[i];
        }
    }

    double result = sum_of_temps / (a.size() - 2);

    return result;
}

bool is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(),
        s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}

void process_data(string full_line, int c) {
    size_t index_of_first_digit = 0;
    vector<char> cstr(full_line.c_str(), full_line.c_str() + full_line.size() + 1);

    for (char c : cstr) {
        if (isdigit(c)) {
            index_of_first_digit = full_line.find(c);
            break;
        }
    }

    places.push_back(full_line.substr(0, index_of_first_digit - 1));

    string temporary;
    for (size_t i = index_of_first_digit; i < full_line.size(); i++){
        if (full_line.substr(i, 1) == " "){
            one_city_temp.push_back(stoi(temporary));
            temporary = "";
            continue;
        } else {
            temporary += full_line.substr(i, 1);
        }
    }
    one_city_temp.push_back(stoi(full_line.substr(full_line.size() - 2)));
    temps.push_back(one_city_temp);
}

void show_data(vector<int> a, string city) {
    printf("Coldest temperature for %s was %d \n", city.c_str(), coldest_temp(a));
    printf("Warmest temperature for %s was %d \n", city.c_str(), warmest_temp(a));
    printf("Average temperature for %s was %.1f \n", city.c_str(), average_temp(a));
    printf("Average temperature without extremes for %s was %.1f \n", city.c_str(), average_temp_without_extremes(a));
}

int main(int argc, const char * argv[]) {
    vector <string> bufer;
    string line, user_answer;
    int count = 0, count_of_shows = 0;
    const string file_name = "temp";
    
    cout << "Hello, enter file name: ";
    cin >> user_answer;
    
    if (user_answer == file_name){
        ifstream fin(file_name + ".txt");
        if (fin.is_open())
        {
          while ( getline (fin,line) )
          {
              if(!line.empty()){
                  all_data.push_back(line);
                  count += 1;
              }
              
          }
          fin.close();
        }

        for (int i = 0; i < all_data.size(); i++){
                process_data(all_data[i], i);
        }
        
        show_data(temps[count_of_shows], places[count_of_shows]);
        
        count_of_shows += 1;
            
        for (int i = count_of_shows; count_of_shows < places.size(); i++) {
            cout << "There are more data to show. Do You want to see it? y/n: ";
            cin >> user_answer;
            if (user_answer == "y") {
                show_data(temps[count_of_shows], places[count_of_shows]);
                count_of_shows += 1;
                if (count_of_shows == places.size())
                    cout << "There are no more data in this file" << endl;
            } else if (user_answer == "n"){
                cout << "Good bye" << endl;
                break;
            }
        }
    } else {
        cout << "You entered wrong file name, bye." << endl;
    }
}
