//
//  Point.h
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __FakeLoL__Point__
#define __FakeLoL__Point__

#include <iostream>

struct Point {
    double x;
    double y;
    
    explicit Point(double x = 0.0, double y=0.0) : x(x), y(y) { std::cout << "Point created\n"; }
    ~Point() { std::cout << "Point destroyed\n"; }
    
    bool operator==(Point const &lhs) {
        return (this->x == lhs.x) && (this->y == lhs.y);
    }
};

#endif /* defined(__FakeLoL__Point__) */
