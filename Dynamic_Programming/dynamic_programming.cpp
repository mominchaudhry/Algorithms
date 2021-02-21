//
//  main.cpp
//  CPS616_lab6
//
//  Created by Momin Chaudhry on 2020-04-08.
//  Copyright © 2020 Momin Chaudhry. All rights reserved.
//

#include <iostream>
int knapsack(int* weight, int* value, int n, int W);

int main () {
    int value [] = {210,220,180,120,160,170,90,40,60,10};
    int weight [] = {15,12,10,9,8,7,5,4,3,1};
    int W = 26;
    int n = 10;
    std::cout << knapsack (weight,value,n,W) << std::endl;
    return 0;
}

int knapsack(int* weight, int* value, int n, int W) {
    int K[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i==0 || j==0) K[i][j] = 0;
            else if (weight[i-1] <= j) K[i][j] = std::max(value[i-1] + K[i-1][j-weight[i-1]],  K[i-1][j]);
            else K[i][j] = K[i-1][j];
        }
    }
    return K[n][W];
}
