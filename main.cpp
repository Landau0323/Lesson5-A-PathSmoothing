#include <iostream>
#include "PID.h"

using namespace std;

int main() {
    PID pid;
    pid.smooth_path();

    pid.show_change_path();
    pid.write_change_path();

    return 0;
}