#include<iostream>
using namespace std;
int temp;
void swap_largest(int arr[], int n, int i) 
{ 
int largest = i; // Initialize largest as root 
int left = 2*i + 1; 
int right = 2*i + 2; 

// If left child is larger than root 
if (left < n && arr[left] > arr[largest]) 
largest = left; 

// If right child is larger than largest
if (right < n && arr[right] > arr[largest]) 
largest = right; 

// If largest is not root
if (largest != i) 
{ 
temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;
// Recursively call the swap_largest 
swap_largest(arr, n, largest); 
} 
} 
void heap(int arr[], int n) 
{ 

// Build heap from an unsorted array (rearrange array) 
for (int i = n / 2 - 1; i >= 0; i--) 
swap_largest(arr, n, i); 

// One by one extract an element from heap 
for (int i = n - 1; i >= 0; i--) 
{ 

// Move current root to end 
temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;

// call swap_largest on the reduced heap 
swap_largest(arr, i, 0); 
} 
}
int print(int arr[], int n)
{
for(int i = 0; i < n; i++)
{
cout << arr[i] << " ";
}
}

int main()
{
int n, i;
cin >> n;
int arr[n];
for(i = 0; i < n; i++)
{
cin >> arr[i];
}
heap(arr, n);
print(arr, n);
}
