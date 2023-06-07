//
// Created by deniz on 07.06.2023.
//

#ifndef KNN_KNN_HPP
#define KNN_KNN_HPP


#include <algorithm>
#include <string>
#include <cmath>

struct Point
{
    std::string val;	 // Group of point
    double x{}, y{};	 // Co-ordinate of point
    double distance{}; // Distance from test point
};


// This function finds classification of point p using k nearest neighbour algorithm. It assumes only two
// groups and returns  if p belongs to group Black, else White (belongs to group 1).

std::string classifyAPoint(Point arr[], int n, int k, const Point& p)
{
    // Fill distances of all points from p
    for (int i = 0; i < n; i++)
        arr[i].distance = std::sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + (arr[i].y - p.y) * (arr[i].y - p.y));



    // Sort the Points by distance from p, Used to sort an array of points by increasing order of distance
    std::sort(arr, arr+n, [](Point& p1, Point& p2){return p1.distance < p2.distance;});

    // Now consider the first k elements and only two groups

    std::string val1{"Black"},val2{"White"};
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

#endif //KNN_KNN_HPP
