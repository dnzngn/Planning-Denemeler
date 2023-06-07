// C++ program to find groups of unknown
// Points using K nearest neighbour algorithm.
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct Point
{
    string val;	 // Group of point
    double x{}, y{};	 // Co-ordinate of point
    double distance{}; // Distance from test point
};


// This function finds classification of point p using k nearest neighbour algorithm. It assumes only two
// groups and returns  if p belongs to group Black, else White (belongs to group 1).

string classifyAPoint(Point arr[], int n, int k, const Point& p)
{
    // Fill distances of all points from p
    for (int i = 0; i < n; i++)
        arr[i].distance = sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + (arr[i].y - p.y) * (arr[i].y - p.y));

    // Sort the Points by distance from p, Used to sort an array of points by increasing order of distance
    sort(arr, arr+n, [](Point& p1, Point& p2){return p1.distance < p2.distance;});

    // Now consider the first k elements and only two groups

    string val1{"Black"},val2{"White"};
    int freq1 = 0;	 // Frequency of group 0
    int freq2 = 0;	 // Frequency of group 1

    for (int i = 0; i < k; i++)
    {
        if (arr[i].val == val1)
            freq1++;
        else if (arr[i].val == val2)
            freq2++;
    }

    return (freq1 > freq2 ? val1 : val2);
}

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
