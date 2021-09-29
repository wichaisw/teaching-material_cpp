#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<time.h>

using namespace std;

void bubbleSort(int [], int);
void swap(int*, int*);
void randomNumber(int [], int);
void logArrayMembers(int [], int);
void binarySearch(int [], int, int, int, int);

 int main(){
     int targetNum;
     int numArr[50]{};
     int numArrSize = 50;

     randomNumber(numArr, numArrSize);

//    int numArr[50] = { 1, 1, 9, 10, 27, 28, 31, 31, 33, 34,
//36, 38, 39, 40, 40, 42, 42, 45, 45, 46,
//49, 50, 54, 56, 59, 59, 59, 60, 64, 66,
//66, 67, 67, 68, 71, 72, 73, 75, 78, 80,
//83, 87, 88, 89, 91, 94, 94, 96, 96, 98 };

     bubbleSort(numArr, numArrSize);
     cout << endl;


     cout << "Sorted Array" << endl;
     logArrayMembers(numArr, numArrSize);
     cout << endl;

     cout << "Enter a number to be searched: ";
     cin >> targetNum;

     binarySearch(numArr, 0, numArrSize - 1, numArrSize, targetNum);


	return 0;		 	 
 }


 void randomNumber(int arr[], int size) {
    srand(time(0));
    int counter = 1;
    cout << "Original Array" << endl;

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << setw(3) << arr[i] << " ";

        if (counter == 10) {
            cout << endl;
            counter = 0;
        }
        counter++;
    }
 }

 void logArrayMembers(int arr[], int size) {
     int counter = 1;
     for (int i = 0; i < size; i++) {
         cout << setw(3) << arr[i] << " ";

         if (counter == 10) {
             cout << endl;
             counter = 0;
         }
         counter++;
     }
 }


 void swap(int *left, int *right)
 {
     int temp = *left;
     *left = *right;
     *right = temp;
 }

 void bubbleSort(int arr[], int n)
 {
     int i, j;
     for (i = 0; i < n - 1; i++) {
         for (j = 0; j < n - i - 1; j++) {
             if (arr[j] > arr[j + 1]) {
                 swap(&arr[j],&arr[j + 1]);
             }
         }
     }
 }

 void binarySearch(int arr[], int left, int right, int arrSize, int num)
 {
     int pointer;
     int occurence = 0;

     while (left <= right) {
         pointer = left + (right - left) / 2;

         if (arr[pointer] == num) {
            cout << "The number is found at sorted index: " << pointer << " ";
            
            int leftValue = pointer - 1;
            int rightValue = pointer + 1;
            occurence = 1;

            while (arr[rightValue] == num) {
                cout << rightValue << " ";
                rightValue++;
                occurence++;
            }

            while (arr[leftValue] == num) {
                cout << leftValue << " ";
                leftValue--;
                occurence++;
            }

            return;
         }

         if (arr[pointer] < num) {
             left = pointer + 1;
         }
         else {
             right = pointer - 1;
         }
     }

     if (occurence == 0) {
        cout << "Number is not found.";
     }
 }
