//
// Created by 研究用 on 2017/08/29.
//

#ifndef LESSON5_PIDCONTROL_PID_H
#define LESSON5_PIDCONTROL_PID_H

#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "XY.h"

using namespace std;


class PID {
private:
    vector<XY> path, OriginalPath,PreviousPath;

public:
    PID();
    void show_path();
    void show_change_path();
    void write_change_path();
    void smooth_path();
    bool judge_smoothness();

};


#endif //LESSON5_PIDCONTROL_PID_H
