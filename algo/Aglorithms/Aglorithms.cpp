// Aglorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
void switchElement(std::vector<int>& vec, int sourceIndex, int targetIndex)
{
    int temp = vec[targetIndex];
    vec[targetIndex] = vec[sourceIndex];
    vec[sourceIndex] = temp;
}

void moveFront(std::vector<int>& vec, int start, int finish, int split)
{
    for (int i = start; i < split; i++)
    {
        switchElement(vec, i, i + finish - split + 1);
    }
}

void moveBack(std::vector<int>& vec, int start, int finish, int split)
{
    for (int i = split; i <= finish; i++)
    {
        switchElement(vec, i, i - split);
    }
}

void moveSplit(std::vector<int>& vec, int k)
{
    moveBack(vec, 0, vec.size() - 1, k);
    moveBack(vec, 7, vec.size() - 1, 1);
    //moveFront(vec, 0, vec.size()-1, k);
    //moveFront(vec, 0, vec.size() - 1-k, k);
}



vector<int> compareTriplets(vector<int> a, vector<int> b) {

    vector<int> result = {0, 0};

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            result[0]++;
        }
        else if (b[i] > a[i])
        {
            result[1]++;
        }
    }

    return result;
}

// Complete the aVeryBigSum function below.
long aVeryBigSum(vector<long> ar) {
    long result = 0;
    for (long x : ar)
    {
        result += x;
    }
    return result;
}

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {

    int result = 0;
    int s = arr.size();

    for (int i = 0; i < s; i++)
    {
        result += arr[i][i] - arr[i][s - i - 1];
    }

    return abs(result);
}


/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {

    if (k == 1) {
        return 1;
    }

    div_t divk2 = div(k, 2);

    int size = s.size();
    if (size < 1) {
        return 0;
    }

    

    map<int, int> divMap = {};

    for (int i = 0; i < k; i++)
    {
        divMap[i] = 0;
    }

    for (int x :s)
    {
        divMap[div(x,k).rem]++;
    }

    int result = 0;

    if (divMap[0] > 0) {
        result++;
    }



        
    for (int i = 1; i < divk2.quot; i++)
    {
        result += max(divMap[i], divMap[k - i]);        
    }

    if (divk2.rem == 0){
        
        if (divMap[(divk2.quot)] > 0) {
            result++;
        }
    }
    else {
        result += max(divMap[divk2.quot], divMap[k - divk2.quot]);
    }

    return result;
}

int main()
{
    std::vector<int> vec = { 1, 7, 2, 4 };
    moveSplit(vec, 3);


    nonDivisibleSubset(3, vec);


    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
