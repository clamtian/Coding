#include "utility.h"


void merge(vector<int>& arr, int l, int r){
    if(l == r){
        return;
    }
    int mid = l + (r - l) / 2;
    merge(arr, l, mid);
    merge(arr, mid + 1, r);
    vector<int> help;
    int p = l, q = mid + 1;
    while(p <= mid || q <= r){
        if(p > mid){
            help.push_back(arr[q++]);
        }else if(q > r){
            help.push_back(arr[p++]);
        }else if(arr[q] >= arr[p]){
            help.push_back(arr[p++]);
        }else{
            help.push_back(arr[q++]);
        }
    }
    for(int i = l; i <= r; ++i){
        arr[i] = help[i - l];
    }
}

void mergeSort(vector<int>& arr){
    int n = arr.size();
    if(n < 2){
        return;
    }
    merge(arr, 0, n - 1);
}



vector<int> generateRandomArray(int len, int min, int max){
    vector<int> arr(len);
    for(int i = 0; i < len; ++i){
        arr[i] = (rand() % (max - min)) + min;
    }
    return arr;
}

int main(){

    for(int i = 0; i < 800; ++i){
        vector<int> arr = generateRandomArray((rand() % 20) + 1, -1000, 1000);
        vector<int> arr1 = arr;
        sort(arr.begin(), arr.end());
        mergeSort(arr1);
        if(arr != arr1){
            cout << "arr : ";
            for(int i = 0; i < arr.size(); ++i){
                cout << arr[i] << " ";
            }
            cout << "\narr1 : ";
            for(int i = 0; i < arr.size(); ++i){
                cout << arr1[i] << " ";
            }
            cout << "\n";
        }
    }
    cout << "GodLike!\n" << endl;


}