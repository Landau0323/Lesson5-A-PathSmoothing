//
// Created by 研究用 on 2017/08/29.
//

#ifndef LESSON5_PIDCONTROL_XY_H
#define LESSON5_PIDCONTROL_XY_H

#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


class XY {
private:
    double x,y;

public:
    XY(double,double);
    void show();
    void show_nonewline();
    void set_XY(double,double);
    double distance(XY);

    double getX() const;
    double getY() const;

};


#endif //LESSON5_PIDCONTROL_XY_H
