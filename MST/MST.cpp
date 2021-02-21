//
//  main.cpp
//  cps616_lab4
//
//  Created by Momin Chaudhry on 2020-03-11.
//  Copyright © 2020 Momin Chaudhry. All rights reserved.
//

#include <iostream>
#include <map>
#include <list>

int V = 4;
std::pair<int, int>* MST (int adj[4][4]);

std::pair<int, int>* MST (int adj[4][4]) {
    bool* visited = new bool[V];
    int* distance = new int[V];
    int* parent = new int[V];
    int mstIdx = 0;
    
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        distance[i] = 99999;
        parent[i] = -1;
    }
    
    std::pair<int, int> *mst = new std::pair<int, int>[V-1];
    int vtx = 0;
    bool done = false;
    
    distance[vtx] = 0;
    
    while (!done) {
        visited[vtx] = true;
        
        //update table for adjacent verticies
        for (int i = 0; i < V; i++) {
            if(adj[vtx][i] != 0 && adj[vtx][i] < distance[i]) {
                distance[i] = adj[vtx][i];
                parent[i] = vtx;
            }
        }
        
        //find next vertex to visit
        int oldVtx = vtx;
        int min = 1000;
        for (int i = 0; i < V; i++) {
            if(visited[i]) {
                for (int j = 0; j < V; j++) {
                    if(adj[i][j] != 0 && adj[i][j] < min) {
                        min = adj[i][j];
                        vtx = j;
                    }
                }
            }
        }
        
        //add edge to mst
        mst[mstIdx] = std::pair<int, int>(oldVtx, vtx);
        mstIdx++;
        
        //check if all verticies have been visited, if so we have our mst
        done = true;
        for(int i = 0; i < V; i++) {
            if (visited[i] == false) {
                done = false;
                break;
            }
        }
    }
    
    return mst;
}

int main ()
{
    int adj[4][4] = {
    {0, 5, 3, 2},
    {5, 0, 0, 7},
    {3, 0, 0, 2},
    {2, 7, 2, 0}};
    std::pair<int, int>* mst = MST(adj);
    
    for (int i = 0; i < V-1; i++) {
        printf ("Decimals: %d %d %d\n", i, mst[i].first, mst[i].second);
    }
    
    
}
