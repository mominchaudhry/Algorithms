//CPS616 lab 5
//Momin Chaudhry 500831162

#include <iostream>

int canBook(int* arrive_dates, int* leave_dates, int n);

int main() {
    int arrive_dates[] = {1,3,5,6,6};
    int leave_dates [] = {2,6,8,7,8};
    int n = 3;
    int t =  canBook(arrive_dates,leave_dates,n);
    printf("%d \n", t);

    return 1;
}

int canBook(int* arrive_dates, int* leave_dates, int k) {
    int x = 1;
    int n = sizeof(arrive_dates);
    std::sort(arrive_dates, arrive_dates + n);
    std::sort(leave_dates, leave_dates + n);
    for (int i = 0; i < n-1; i++) {
        if (leave_dates[i] > arrive_dates[i]) x++;
        if (k < x) return 0;
    }
    return 1;
}
