
#include <iostream>
#include <cstdlib>

const int arraySize = 15;
const int arrayMaxValue = 99;


void printOutArray(int arr[], int size)
{
    // first check input params

    std::cout << "The array is: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}

void mergeSort(int arr[], int left, int right, int tempArr[])
{
    // first, check input params

   // end condition of the recusion
   if (left == right)
      return;

   int pivot = left + (right - left) / 2;

   // divide into smaller problems
   mergeSort(arr, left, pivot, tempArr);
   mergeSort(arr, pivot + 1, right, tempArr);

    // conqure by merging the smaller problem
    int length = right - left + 1;
    int mLeft = left;
    int mRight = pivot + 1;

    for (int i = 0; i < length; i++)
    {
        if (mRight <= right)
        {
            if (mLeft <= pivot)
            {
                 if (arr[mLeft] > arr[mRight])
                     tempArr[i] = arr[mLeft++];
                 else
                     tempArr[i] = arr[mRight++];
            }
            else
                tempArr[i] = arr[mRight++];
        }
        else
        {
            tempArr[i] = arr[mLeft++];
        }
    }

    // put th enumber back to the array
    for (int i = 0; i < length; i++)
    {
        arr[left + i] = tempArr[i];
    }
}

void sortArrayWithMergingSort(int arr[], int size)
{
    // first check input params

    int* tmpArray = new int[size];

    // check if the melloc fails

    mergeSort(arr, 0, size - 1, tmpArray);
}


void swap(int arr[], int l, int r)
{
    // first check input params

    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

void swapWithoutTempStorage(int arr[], int l, int r)
{
    arr[l] = arr[l] ^ arr[r];
    arr[r] = arr[l] ^ arr[r];
    arr[l] = arr[l] ^ arr[r];
}

void heapify(int* arr, int k, int size)
{
    int childLeft = k * 2;
    int childRight = childLeft + 1;

    int tmp = k;

    // check if any child is bigger
    if (childLeft < size)
    {
        if (arr[childLeft] > arr[k])
            tmp = childLeft;
    }
    if (childRight < size)
    {
        if (arr[childRight] > arr[tmp])
           tmp = childRight;
    }
    // any child is bigger
    if (tmp != k)
    {
        // swap(arr, tmp, k);
        swapWithoutTempStorage(arr, tmp, k);
        heapify(arr, tmp, size);
    }
}

bool isHeap(int arr[], int size)
{
    bool itIsHeap = true;

    //int* tmp = arr - 1;
    int* tmp = arr;

    // going foom the end is much easier than starting from the beginning
    for (int i = size - 1; i > 0; i--)
    {
        int k = i;
        int parent = k / 2;
        while (k > 0)
        {
            if (tmp[k] > tmp[parent])
            {
                itIsHeap = false;
                break;
            }

            k = parent;
            parent = k / 2;
        }
    }

    return itIsHeap;
}

void buildHeap(int arr[], int size)
{
    // first check input params

   for (int i = size / 2; i >= 0; i--)
   {
       heapify(arr, i, size);
   }

   std::cout << "After heapifying, the array is " << std::endl;
   printOutArray(arr, size);

   if (isHeap(arr, size))
       std::cout << "It is a heap" << std::endl;
   else
       std::cout << "It is not a heap" << std::endl;
}

void sortArrayWithHeapSort(int arr[], int size)
{
    // first check input params

    // build a heap first
    buildHeap(arr, size);

    // sort it by keeping yeaking out the head
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr, 0, i);
        heapify(arr, 0, i);
    }
}

bool isSorted(int arr[], int size, bool ascending)
{
    // first check input params
    bool sorted = true;

    printOutArray(arr, size);

    if (ascending)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                 sorted = false;
                 break;
            }
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                 sorted = false;
                 break;
            }
        }
    }
    
    return sorted;
}

void generateArray(int arr[], int size)
{
    // first check input params
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % arrayMaxValue;
    }

    std::cout << "The array generated is..." << std::endl;
    printOutArray(arr, size);
}

int main()
{
    int arr[arraySize];

    std::cout << " ==== Merging Sort ==== " << std::endl;
    generateArray(arr, arraySize);
    sortArrayWithMergingSort(arr, arraySize);

    if (isSorted(arr, arraySize, false))
        std::cout << "The array is sorted" << std::endl;
    else
        std::cout << "The array is not sorted" << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << " ==== Heap Sort ==== " << std::endl;
    generateArray(arr, arraySize);
    sortArrayWithHeapSort(arr, arraySize);

    if (isSorted(arr, arraySize, true))
        std::cout << "The array is sorted" << std::endl;
    else
        std::cout << "The array is not sorted" << std::endl;

    return 1;

    std::cout << " ==== Merging Sort ==== " << std::endl;
}
