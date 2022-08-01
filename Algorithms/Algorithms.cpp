// TimedSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Connor Swanson
// Activision Blizzard
// 8/1/2022

#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;

void PopulateArray(int arr[], int size, int value);
void BubbleSort(int arr[], int size);

int main()
{
    srand((unsigned)time(0));
    const int kSize = 1000;
    const int kValue = 200;
    int num[kSize];
    int rng = rand() % kValue;

    PopulateArray(num, kSize, kValue);

    auto start = chrono::steady_clock::now();
    BubbleSort(num, kSize);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsedSeconds = end - start;
    cout << "The Bubble Sorting method took " << elapsedSeconds.count() << " seconds!" << endl;
}

void PopulateArray(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % value;
    }
}

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}