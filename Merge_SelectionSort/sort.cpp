//Momin Chaudhry
//500831162
//CPS616 Lab 1

#include <iostream>
#include <chrono>

void callMerge(int n);
void callSelection(int n);
void callModifiedMerge(int n);
void merge(int arr[],int left, int centre, int right);
void modifiedMerge(int arr[], int left, int right);
void mergeSort(int arr[],int left, int right);
void selectionSort(int arr[], int n, int start);

int main(int argc, const char * argv[]) {
    int n = 10; //LENGTH OF ARRAY
    
    callMerge(n);
    callSelection(n);
    callModifiedMerge(n);
    
    printf("\n");
    
    n = 50;
    
    callMerge(n);
    callSelection(n);
    callModifiedMerge(n);
    
    printf("\n");
    
    n = 75;
    
    callMerge(n);
    callSelection(n);
    callModifiedMerge(n);
    
    printf("\n");
    
    n = 100;
    
    callMerge(n);
    callSelection(n);
    callModifiedMerge(n);
    
    printf("\n");
    
    n = 1000;
    
    callMerge(n);
    callSelection(n);
    callModifiedMerge(n);
    
    printf("\n");
    
    n = 10000;
    
    callMerge(n);
    callSelection(n);
    callModifiedMerge(n);
    
    printf("\nAs you can see, combining merge and selection sort");
    printf(" is only more efficient when the array size becomes very large");
    printf(" or very small (>10000 or <75)\n\n");
    return 0;
}

void callModifiedMerge(int n) {
    int arr[n];
    for (int count = 0; count < n; count++)
    {
        arr[count]=1+rand()%(n*4);
    }
    
    auto start = std::chrono::steady_clock::now();
    modifiedMerge(arr,0,n);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    std::cout<<"Modified Merge sort - size: ";
    std::cout<<n;
    printf("\n");
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
}

void callMerge(int n) {
    int arr[n];
    for (int count = 0; count < n; count++)
    {
        arr[count]=1+rand()%(n*4);
    }
    
    auto start = std::chrono::steady_clock::now();
    mergeSort(arr,0,n);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    std::cout<<"Merge sort - size: ";
    std::cout<<n;
    printf("\n");
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
}

void callSelection(int n) {
    int arr[n];
    for (int count = 0; count < n; count++)
    {
        arr[count]=1+rand()%(n*4);
    }
    
    auto start1 = std::chrono::steady_clock::now();
    selectionSort(arr, n, 0);
    auto end1 = std::chrono::steady_clock::now();
    auto diff1 = end1 - start1;
    
    std::cout<<"Selection sort - size: ";
    std::cout<<n;
    printf("\n");
    std::cout << std::chrono::duration <double, std::milli> (diff1).count() << " ms" << std::endl;
}

void modifiedMerge(int arr[], int left, int right) {
    if (left < right)
    {
        int centre = left+(right-left)/2;
  
        if (right-left <= 75) {
            selectionSort(arr, right-left, left);
        } else {
            mergeSort(arr, left, centre);
            mergeSort(arr, centre+1, right);
            merge(arr, left, centre, right);
        }
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right)
    {
        int centre = left+(right-left)/2;
        mergeSort(arr, left, centre);
        mergeSort(arr, centre+1, right);
        merge(arr, left, centre, right);
    }
}

void merge(int arr[], int left, int centre, int right) {
    int n1 = (centre - left + 1), n2 = (right - centre);
    int leftArr[n1], rightArr[n2];
  
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[centre + 1+ j];
  
    int i = 0, j = 0, idx = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[idx] = leftArr[i];
            i++;
        }
        else {
            arr[idx] = rightArr[j];
            j++;
        }
        idx++;
    }
    while (i < n1) {
        arr[idx] = leftArr[i];
        i++;
        idx++;
    }
    while (j < n2) {
        arr[idx] = rightArr[j];
        j++;
        idx++;
    }
}

void selectionSort(int arr[], int n, int start) {
    int min;
    for (int i = start; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min]) min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
