//
//  main.cpp
//  CPS616 lab2
//
//  Created by Momin Chaudhry on 2020-02-14.
//  Copyright © 2020 Momin Chaudhry. All rights reserved.
//

#include <iostream>
float powerLGN(float x, int y);
float powerN(float x, int y);

int main(int argc, const char * argv[]) {
    int powN = powerN(2,22);
        printf("Linear time: pow(x,y) = %d \n", powN);
        
        int powLGN = powerLGN(2,22);
        printf("Lg n time: pow(x,y) = %d \n", powLGN);
}

float powerN(float x, int y) {
    float result = 1;
    for (int i = 0; i < y; i++) result = result*x;
    return result;
}

float powerLGN(float x, int y) {
    float result = 1;
    if(y == 0) return result;
    
    result = powerLGN(x, y / 2);
    if (y % 2 == 0) result =  result * result;
    else
    {
        if (y <= 0) result =  (result * result) / x;
        else result =  result * result * x;
    }
    return result;
}
