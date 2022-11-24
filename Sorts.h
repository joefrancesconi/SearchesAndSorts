/*
 * Name: Joe Francesconi
 * Date Submitted: 2/25/2022
 * Lab Section: 005
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>
template <class T> std::vector<T> quickSort(std::vector<T>);
template <class T> void quickSorter(std::vector<T>&, int);
template <class T> std::vector<T> merge(std::vector<T>, std::vector<T>);
template <class T> std::vector<T> mergeSort(std::vector<T>);
template <class T> void swap(std::vector<T>&, int, int);
template <class T> int partit(std::vector<T>&, int);
//Merge two halves together and return vector
template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right){
    std::vector<T> lst;
    int i = 0;
    int j = 0;
    
    while (i < left.size() && j < right.size()){
        if (left[i] <= right[j]){
            lst.push_back(left[i]);
            i++;
        }else{
            lst.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()){
        lst.push_back(left[i]);
        i++;
    }
    while (j < right.size()){
        lst.push_back(right[j]);
        j++;
    }
    return lst;
}

//recursive merge sort
template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    int low = 0;
    int high = lst.size() - 1;
    
    if (low >= high){
        return lst;
    }
    int middle = lst.size() / 2;
    int m = lst.size() - middle;

    std::vector<T> left;
    std::vector<T> right;
    
    for (int i = 0; i < middle; i++){
        left.push_back(lst[low + i]);
    }
    for (int j = 0; j < m; j++){
        right.push_back(lst[middle + j]);
    }

    //R calls
    left = mergeSort(left);
    right = mergeSort(right);
    lst = merge(left, right);
    
    return lst;
}

template <class T>
void swap(std::vector<T>&lst, int pivot, int x){
    lst.push_back(lst[x]);
    lst[x] = lst[pivot];
    lst[pivot] = lst.back();
    lst.pop_back();
}

template <class T>
int partit(std::vector<T>&lst, int pivot){
    swap(lst, pivot, 0);
    pivot = 0;

    for (int i =1; i < lst.size(); i++){
        if (lst[i] <= lst[0]){
            pivot++;
            swap(lst, pivot, i);
        }
    }
    swap(lst, pivot, 0);
    return pivot;
}


template <class T>
void quickSorter(std::vector<T>&lst, int pivot){
    std::vector<T> first;
    std::vector<T> second;

    for (int i = 0; i < pivot; i++){
        first.push_back(lst[i]);
    }
    for(int i = pivot + 1; i < lst.size(); i++){
        second.push_back(lst[i]);
    }
    first = quickSort(first);
    second = quickSort(second);

    int j = 0;
    for (j = 0; j < first.size(); j++){
        lst[j] = first[j];
    }
    j++;
    for (int i = 0; i  < second.size(); i++){
        lst[j] = second[i];
        j++;
    }
}

//recursive quick sort
template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    if (lst.size() <= 1){
        return lst;
    }
    int size = lst.size();
    int pivot = 0;

    srand(time(NULL));
    pivot = rand()%size;

    pivot = partit(lst, pivot);

    quickSorter(lst, pivot);

    return lst;
}
