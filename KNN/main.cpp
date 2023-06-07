// C++ program to find groups of unknown

#include "KNN.hpp"
#include <iostream>

using namespace std;

// Driver code
int main()
{
    int n = 17; // Number of data points
    Point arr[n];

    arr[0].x = 1;
    arr[0].y = 12;
    arr[0].val = {"Black"};

    arr[1].x = 2;
    arr[1].y = 5;
    arr[1].val = {"Black"};

    arr[2].x = 5;
    arr[2].y = 3;
    arr[2].val = {"White"};

    arr[3].x = 3;
    arr[3].y = 2;
    arr[3].val = {"White"};

    arr[4].x = 3;
    arr[4].y = 6;
    arr[4].val = {"Black"};

    arr[5].x = 1.5;
    arr[5].y = 9;
    arr[5].val = {"White"};

    arr[6].x = 7;
    arr[6].y = 2;
    arr[6].val = {"White"};

    arr[7].x = 6;
    arr[7].y = 1;
    arr[7].val = {"White"};

    arr[8].x = 3.8;
    arr[8].y = 3;
    arr[8].val = {"White"};

    arr[9].x = 3;
    arr[9].y = 10;
    arr[9].val = {"Black"};

    arr[10].x = 5.6;
    arr[10].y = 4;
    arr[10].val = {"White"};

    arr[11].x = 4;
    arr[11].y = 2;
    arr[11].val = {"White"};

    arr[12].x = 3.5;
    arr[12].y = 8;
    arr[12].val = {"Black"};

    arr[13].x = 2;
    arr[13].y = 11;
    arr[13].val = {"Black"};

    arr[14].x = 2;
    arr[14].y = 5;
    arr[14].val = {"White"};

    arr[15].x = 2;
    arr[15].y = 9;
    arr[15].val = {"Black"};

    arr[16].x = 1;
    arr[16].y = 7;
    arr[16].val = {"Black"};

    /*Testing Point*/
    Point p{};
    p.x = 2.5;
    p.y = 7;

    // Parameter to decide group of the testing point
    int k = 3;
    std::cout << "The value classified to unknown point is " << classifyAPoint(arr, n, k, p) << '\n';
    return 0;
}
