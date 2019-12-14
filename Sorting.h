#include <string>

using namespace std;

class Sorting
{
public:
    Sorting(string filePath);
    ~Sorting();

    int arraySize; //so I can easily use the array size
    double* myArray; //base array for comparing sorted arrays to

    double* arr1;
    double* arr2;
    double* arr3;
    double* arr4;
    double* arr5;

    void process(); //main function
    //void output(double arr[], string sortName);

    void swap(double* a, double* b); //swap helper function
    void printArray(double arr[]); //prints all elements of array
    void printEx(double arr[]); //prints first and last element of array

    void bubbleSort(double arr[]);
    void selectionSort(double arr[]);
    void insertionSort(double arr[]);

    void merge(double arr[], int leftIndex, int mid, int rightIndex); //mergeSort helper function
    void mergeSort(double arr[], int leftIndex, int rightIndex);

    void quickSortStep(double arr[], int a, int b); //quickSort helper function
    void quickSort(double arr[]);
    
 

    

};