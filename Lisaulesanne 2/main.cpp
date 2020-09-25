//
//  main.cpp
//  lisaylesanne_2
//
//  Created by Mark Kalda on 24.09.2020.
//  Copyright © 2020 Mark Kalda. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

void ask(){
    const float distance= 384400;
    float proposal = 0;
    do{
        cout << "Pakku vahemaat. V2ljumiseks kirjuta 0: ";
        cin >> proposal;
        if (abs(distance - proposal) / 100 < 0.03){
            cout << "Palju qnne, sa vqitsid" << endl;
            break;
        } else if (proposal == 0){
            cout << "Lahkud nii kiiresti? kurb:(" << endl;
            break;
        } else if ((distance - proposal) / 100 > 0.03){
            cout << "Sinu pakkumine on liiga v2ike" << endl;
        } else if ((proposal - distance) / 100 > 0.03){
            cout << "Sinu pakkumine on liiga suur" << endl;
        }
        
    } while (abs(distance - proposal) / 100 > 0.03);
    
}

int main(int argc, const char * argv[]) {
    ask();
    return 0;
}


