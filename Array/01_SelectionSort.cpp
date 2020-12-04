#include "utility.h"

void selectionSort(vector<int>& arr){
    int n = arr.size();
    if (n < 2){
        return;
    }
    for (int i = 0; i < n - 1; ++i){
        int minIndex = i;
        for (int j = i + 1; j < n; ++j){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
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
        selectionSort(arr1);
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
