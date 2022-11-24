/*
 * Name: Joe Francesconi
 * Date Submitted: 2/25/2022
 * Lab Section: 005
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
//linear search returning position
int linearSearch(std::vector<T> data, T target){
    int position = -1;
    
    for (int i = 0; i < data.size(); i++){
        if (data[i] == target){
            position = i;
            break;
        }
    }
    
    return position;
}


template <class T>
//binary search returning position
int binarySearch(std::vector<T> data, T target){
    int low = 0;
    int high = data.size() - 1;
    
    while (low <= high){
        int middle = low + (high - low) / 2;
        
        if (data[middle] == target){
            return middle;
        }
        
        if (data[middle] > target){
            high = middle - 1;
        }
        
        if (data[middle] < target){
            low = middle + 1;
        }
    }
    return -1;
}
