#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

#include "ComplexNumber.h"

int SIZE;

int N[] = {10,50,100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,200000,300000,400000,500000};

// string filenames[] = {"./data/data_10.txt", "./data/data_50.txt", "./data/data_100.txt", "./data/data_200.txt", "./data/data_300.txt", "./data/data_400.txt", "./data/data_500.txt", "./data/data_600.txt", "./data/data_700.txt", "./data/data_800.txt", "./data/data_900.txt", "./data/data_1000.txt", "./data/data_2000.txt", "./data/data_3000.txt", "./data/data_4000.txt", "./data/data_5000.txt", "./data/data_6000.txt", "./data/data_7000.txt", "./data/data_8000.txt", "./data/data_9000.txt", "./data/data_10000.txt", "./data/data_20000.txt", "./data/data_30000.txt", "./data/data_40000.txt", "./data/data_50000.txt", "./data/data_60000.txt", "./data/data_70000.txt", "./data/data_80000.txt", "./data/data_90000.txt", "./data/data_100000.txt", "./data/data_200000.txt", "./data/data_300000.txt", "./data/data_400000.txt", "./data/data_500000.txt", "./data/data_600000.txt", "./data/data_700000.txt", "./data/data_800000.txt", "./data/data_900000.txt", "./data/data_1000000.txt", "./data/data_2000000.txt", "./data/data_3000000.txt", "./data/data_4000000.txt", "./data/data_5000000.txt", "./data/data_6000000.txt", "./data/data_7000000.txt", "./data/data_8000000.txt", "./data/data_9000000.txt", "./data/data_10000000.txt", "./data/data_20000000.txt", "./data/data_30000000.txt", "./data/data_40000000.txt", "./data/data_50000000.txt", "./data/data_60000000.txt", "./data/data_70000000.txt", "./data/data_80000000.txt", "./data/data_90000000.txt", "./data/data_100000000.txt"};

// Reads a file and returns a list of ComplexNumbers
// Input: Filename
// Output: List of ComplexNumbers
//
// Time Complexity: O(n)
// Space Complexity: O(n)
ComplexNumber* readFile(string filename) {
  string line;
  ifstream myfile (filename);

  getline (myfile,line);
  SIZE = stoi(line);

  ComplexNumber* fileData = new ComplexNumber[SIZE];

  if (myfile.is_open())
  {
    int i = 0;
    while ( getline (myfile,line) )
    {
      int real, imaginary;
      sscanf(line.c_str(), "%d, %d", &real, &imaginary);
      fileData[i] = (ComplexNumber(real, imaginary));
      
      i++;
      }

    myfile.close();
  }

  else cout << "Unable to open file"; 

  return fileData;
};


// Swaps the values of two `ComplexNumber` pointers
// Input: Two ComplexNumber pointers
// Output: None
// 
// Time Complexity: O(1)
// Space Complexity: O(1)
void swap(ComplexNumber* a, ComplexNumber* b) {
  ComplexNumber t = *a;
  *a = *b;
  *b = t;
};


// Partitions the array into two halves
// Input: Array of ComplexNumbers, low index, high index
// Output: Index of the pivot
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// int partitionLeft (ComplexNumber* arr, int low, int high) {
//   double pivot = arr[low].l1Norm();
//   int i = low + 1;
  
//   for (int j = low+1; j <= high; j++) {
//     if (arr[j].l1Norm() < pivot) {
//       swap(&arr[i], &arr[j]);
//       i++;
//     }

//   }
//   swap(&arr[i - 1], &arr[low]);

//   return i - 1;
// };

int partitionLeft (ComplexNumber* arr, int low, int high) {
  ComplexNumber pivot = arr[low];
  int i = low + 1;
  
  for (int j = low+1; j <= high; j++) {
    if (arr[j] < pivot) {
      swap(&arr[i], &arr[j]);
      i++;
    }

  }
  swap(&arr[i - 1], &arr[low]);

  return i - 1;
};

// Sorts the array using the quicksort algorithm
// Input: Array of ComplexNumbers, low index, high index
// Output: None
//
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
void quickSortLeft(ComplexNumber* arr, int low, int high) {
  if (low < high) {

    int pi = partitionLeft(arr, low, high);

    quickSortLeft(arr, low, pi - 1);
    quickSortLeft(arr, pi + 1, high);
  }
};

// Partitions the array into two halves
// Input: Array of ComplexNumbers, low index, high index
// Output: Index of the pivot
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// int partitionMedian (ComplexNumber* arr, int low, int high) {
//   double pivot = arr[(low + high) / 2].l1Norm();
//   int i = low;
//   int j = high;

//   while (i <= j) {
//     while (arr[i].l1Norm() < pivot) {
//       i++;
//     }
//     while (arr[j].l1Norm() > pivot) {
//       j--;
//     }

//     if (i <= j) {
//       swap(&arr[i], &arr[j]);
//       i++;
//       j--;
//     }
//   }

//   return i;
// };

int partitionMedian (ComplexNumber* arr, int low, int high) {
  ComplexNumber pivot = arr[(low + high) / 2];
  int i = low;
  int j = high;

  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }

    if (i <= j) {
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    }
  }

  return i;
};

// Sorts the array using the quicksort algorithm
// Input: Array of ComplexNumbers, low index, high index
// Output: None
//
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
void quickSortMedian(ComplexNumber* arr, int low, int high) {
  if (low < high) {

    int pi = partitionMedian(arr, low, high);

    quickSortMedian(arr, low, pi - 1);
    quickSortMedian(arr, pi, high);
  }
};


int main () {

  for (int i = 0; i < sizeof(N)/sizeof(N[0]); i++) {
    ComplexNumber* data_1 = readFile("./data/data_"+to_string(N[i])+".txt");

    clock_t startLeft = clock();
    quickSortLeft(data_1, 0, SIZE - 1);
    clock_t endLeft = clock();

    double elapsedLeft = double(endLeft - startLeft) / CLOCKS_PER_SEC;

    ComplexNumber* data_2 = readFile("./data/data_"+to_string(N[i])+".txt");

    clock_t startMedian = clock();
    quickSortMedian(data_2, 0, SIZE - 1);
    clock_t endMedian = clock();

    double elapsedMedian = double(endMedian - startMedian) / CLOCKS_PER_SEC;
    cout << N[i] << "," << elapsedLeft << "," << elapsedMedian << "\n";
  }

  return 0;
}