#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int i, int heap_size) {
    int left = 2 * i + 1;        
    int right = 2 * i + 2;       
    int largest = i;             


    if (left < heap_size && arr[left] > arr[largest])
        largest = left;

    if (right < heap_size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, heap_size);
    }
}
void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, i, n);
    }
}
void HeapSort(int arr[], int n) {
    BuildMaxHeap(arr, n);
 for (int i = n - 1; i > 0; i--) {
       swap(arr[0], arr[i]);
        MaxHeapify(arr, 0, i);
    }
}

int main() {
    int n;

   
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    HeapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
