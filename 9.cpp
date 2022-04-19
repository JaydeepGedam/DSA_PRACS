#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root)
{
   int largest = root;
   int l = 2 * root + 1;
   int r = 2 * root + 2;

   if (l < n && arr[l] > arr[largest])
      largest = l;

   if (r < n && arr[r] > arr[largest])
      largest = r;

   if (largest != root)
   {
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
   }
}

void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
}

void heapSort(int arr[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   int count = 1;
   for (int i = n - 1; i > 0; i--)
   {
      displayArray(arr, n);
      cout << "    now sort " << count++ << "th element    \n\n";

      swap(arr[0], arr[i]);

      heapify(arr, i, 0);
   }
}

int main()
{

   int n;
   cout << "\nEnter the size of array : ";
   cin >> n;

   int heap_arr[n];

   cout << "\nEnter the elements of array : ";
   for (int i = 0; i < n; i++)
   {
      cin >> heap_arr[i];
   }

   cout << "Input array  :  ";
   displayArray(heap_arr, n);
   cout << "\n\n"
        << "Convert array into MAX HEAP :\n\n";

   heapSort(heap_arr, n);

   displayArray(heap_arr, n);
   cout << "    heap contains only 1 element so it is already sorted";

   cout << "\n\n\nSorted array is  : ";
   displayArray(heap_arr, n);
   cout<<"\n\n";
}