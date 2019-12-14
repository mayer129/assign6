#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;

Sorting::Sorting(string filePath)
{
    ifstream textFile(filePath);

    if (textFile.is_open() && textFile.good()) //checks if file is good
    {
        string line = "";
        getline(textFile, line);
        arraySize = stoi(line); //sets size of array to variable
        myArray = new double[arraySize]; //initializes all the arrays
        arr1 = new double[arraySize];
        arr2 = new double[arraySize];
        arr3 = new double[arraySize];
        arr4 = new double[arraySize];
        arr5 = new double[arraySize];
        for (int i = 0; i < arraySize; ++i) //inserts values to all the arrays
        {
            getline(textFile, line);
            myArray[i] = stod(line);
            arr1[i] = stod(line);
            arr2[i] = stod(line);
            arr3[i] = stod(line);
            arr4[i] = stod(line);
            arr5[i] = stod(line);
        }
    }
    else
        cout << "Error: Unable to open file" << endl;
    textFile.close();
}

Sorting::~Sorting() //deletes all the arrays from heap
{
    delete[] myArray;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
}

void Sorting::process()
{
    //printArray(myArray);
    //printEx(myArray);

    //Bubble Sort
    auto start = high_resolution_clock::now();
    bubbleSort(arr1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //printArray(arr1);
    cout << "Bubble Sort\nDuration: " << duration.count() << " microseconds\n" << endl;
    //printEx(arr1);

    //Selection Sort
    start = high_resolution_clock::now();
    selectionSort(arr2);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printArray(arr2);
    cout << "Selection Sort\nDuration: " << duration.count() << " microseconds\n" << endl;
    //printEx(arr2);

    //Insertion Sort
    start = high_resolution_clock::now();
    insertionSort(arr3);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printArray(arr3);
    cout << "Insertion Sort\nDuration: " << duration.count() << " microseconds\n" << endl;
    //printEx(arr3);

    //Merge Sort
    start = high_resolution_clock::now();
    mergeSort(arr4, 0, arraySize - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printArray(arr4);
    cout << "Merge Sort\nDuration: " << duration.count() << " microseconds\n" << endl;
    //printEx(arr4);

    //Quick Sort
    start = high_resolution_clock::now();
    quickSort(arr5);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printArray(arr5);
    cout << "Quick Sort\nDuration: " << duration.count() << " microseconds\n" << endl;
    //printEx(arr5);
}

void Sorting::swap(double* a, double* b) //swap helper function
{
    double t = *a;
    *a = *b;
    *b = t;
}

void Sorting::bubbleSort(double arr[])
{
    double temp;
    for (int i = 0; i < arraySize - 1; i++) //i = 0; i < 10; ++i
    {
        for (int j = 0; j < arraySize - i - 1; j++) //j = 0; j < 9; ++j
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Sorting::selectionSort(double arr[])
{
    double temp;
    int minIndex;
    for (int i = 0; i < arraySize - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < arraySize; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void Sorting::insertionSort(double arr[])
{
    double temp;
    int j;
    for (int i = 0; i < arraySize; i++) //int j = 1; j < 10; ++j //marker
    {
        temp = arr[i]; //store markted item
        j = i - 1; //int k = j; //where to start shifting
        while (j >= 0 && arr[j] > temp) //while (k > 0 && arr[k-1] >= temp) //while thing to left is larger, shift
        {
            arr[j + 1] = arr[j]; //arr[k] = arr[k-1];
            j = j - 1; //--k;
        }
        arr[j + 1] = temp; //arr[k] = temp; //put markted item in right spot
    }
}

void Sorting::merge(double arr[], int leftIndex, int mid, int rightIndex) 
{ 
    int i, j, k; //declare variables
    int n1 = mid - leftIndex + 1;
    int n2 =  rightIndex - mid; 
    double left[n1], right[n2]; //helper arrays

    for (i = 0; i < n1; i++) //one side
        left[i] = arr[leftIndex + i]; 
    for (j = 0; j < n2; j++) //other side
        right[j] = arr[mid + 1+ j]; 
  
    i = 0, j = 0, k = leftIndex; 

    while (i < n1 && j < n2) 
    { 
        if (left[i] <= right[j])  //if less
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else //else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) //copy
        arr[k++] = left[i++];
    while (j < n2) //copy
        arr[k++] = right[j++];
} 

void Sorting::mergeSort(double arr[], int leftIndex, int rightIndex) 
{ 
    if (leftIndex < rightIndex) 
    { 
        int mid = leftIndex+(rightIndex-leftIndex)/2;  //find mid point

        mergeSort(arr, leftIndex, mid);  //run 0 - mid
        mergeSort(arr, mid+1, rightIndex);  //run mid - end

        merge(arr, leftIndex, mid, rightIndex); 
    } 
} 

void Sorting::quickSortStep(double arr[],int a,int b)
{
    if (a >= b) return; //if too short
    double pivot = arr[b]; //set pivot point
    int l = a; //begin variable
    int r = b - 1; //end variable
    while (l <= r)
    {
        while (l <= r && arr[l] <= pivot) //left side
            l++;
        while (r >= l && arr[r] >= pivot) //right side
            r--;
        if (l < r) //if less, swap
            swap(&arr[l], &arr[r]);
    }
    swap(&arr[l], &arr[b]); //swap l with end
    quickSortStep(arr, a, l - 1);
    quickSortStep(arr, l + 1, b);
}

void Sorting::quickSort(double arr[])
{
    if (arraySize <= 1) return; //if too short
    quickSortStep(arr, 0, arraySize - 1); //run helper function
} 

void Sorting::printArray(double arr[]) //prints the whole array
{
    for (int i = 0; i < arraySize; ++i)
    {
        cout << i + 1 << ": " << arr[i] << endl;
    }
}

void Sorting::printEx(double arr[]) //print first and last element of the array. useful to see if array was properly sorted
{
    cout << "0: " << arr[0] << endl;
    cout << arraySize << ": " << arr[arraySize - 1] << "\n" <<endl;
}

/*
void Sorting::output(double arr[], string sortName) //was going to use so I didn't have to have so many lines of start and stop time
{
    auto start = high_resolution_clock::now();
    if (sortName == "Bubble Sort")
        bubbleSort(arr);
    else if (sortName == "Selection Sort")
        selectionSort(arr);
    else if (sortName == "Insertion Sort")
        insertionSort(arr);
    else if (sortName == "Merge Sort")
        mergeSort(arr, 0, arraySize - 1);
    else if (sortName == "Quick Sort")
        quickSort(arr, 0, arraySize - 1);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << sortName << "\nDuration: " << duration.count() << " microseconds" << endl;

   // plus or minus 1 microsecond
}*/