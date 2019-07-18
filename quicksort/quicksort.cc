#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partion(vector<int>& vec, int l, int r) {
    int pivot = vec[l];
    while (l < r) {
        while (l < r && vec[r] >= pivot) {
            r--;
        }
        vec[l] = vec[r];

        while (l < r && vec[l] <= pivot) {
            l++;
        }
        vec[r] = vec[l];
    }
    vec[l] = pivot;
    return l;
}

void quicksort(vector<int>& vec, int l, int r) {
    if (vec.empty() || l >= r) {
        return;
    }
    int mid = partion(vec, l, r);
    quicksort(vec, l, mid - 1);
    quicksort(vec, mid + 1, r);
}

void test1() {
    vector<int> vec{2, 4, 3, 4, 1, 5}; // 1, 2, 3, 4, 4, 5
    quicksort(vec, 0, vec.size() - 1);
    for_each(vec.begin(), vec.end(), [](const int& i){cout<<i<<" ";});
    cout<<endl;
}

void test2() {
    vector<int> vec{2, 4, 3, 4, 1, 5, 1}; // 1, 1, 2, 3, 4, 4, 5
    quicksort(vec, 0, vec.size() - 1);
    for_each(vec.begin(), vec.end(), [](const int& i){cout<<i<<" ";});
    cout<<endl;
}

void test3() {
    vector<int> vec{1}; // 1, 2, 3, 4, 4, 5
    quicksort(vec, 0, vec.size() - 1);
    for_each(vec.begin(), vec.end(), [](const int& i){cout<<i<<" ";});
    cout<<endl;
}

void test4() {
    vector<int> vec{1, 1}; // 1, 2, 3, 4, 4, 5
    quicksort(vec, 0, vec.size() - 1);
    for_each(vec.begin(), vec.end(), [](const int& i){cout<<i<<" ";});
    cout<<endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
}
