//
// Created by 研究用 on 2017/08/29.
//

#include "PID.h"
#include "parameter.h"

#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

PID::PID() {
    //set up the original path
    XY original_path(0,0);
    path.push_back(original_path);
    original_path.set_XY(0,1);
    path.push_back(original_path);
    original_path.set_XY(0,2);
    path.push_back(original_path);
    original_path.set_XY(1,2);
    path.push_back(original_path);
    original_path.set_XY(2,2);
    path.push_back(original_path);
    original_path.set_XY(3,2);
    path.push_back(original_path);
    original_path.set_XY(4,2);
    path.push_back(original_path);
    original_path.set_XY(4,3);
    path.push_back(original_path);
    original_path.set_XY(4,4);
    path.push_back(original_path);

    OriginalPath=PreviousPath=path;
}

void PID::show_path() {
    cout<<"show path"<<endl;
    for(int i=0;i<path.size();i++) path[i].show();
}

void PID::smooth_path() {
    cout<<"smoothen path"<<endl;
    while(1){
        for(int i=1;i<path.size()-1;i++){   //exclude the initial and final points
            //minimizing (yi-xi)^2 (close to the original path), minimizing (yi+1+yi-1-2yi)^2 (smooth path)
            double path_i_x=PreviousPath[i].getX()+alpha*(OriginalPath[i].getX()-PreviousPath[i].getX())
                                                   +beta*(PreviousPath[i+1].getX()+PreviousPath[i-1].getX()-2*PreviousPath[i].getX());
            double path_i_y=PreviousPath[i].getY()+alpha*(OriginalPath[i].getY()-PreviousPath[i].getY())
                                                   +beta*(PreviousPath[i+1].getY()+PreviousPath[i-1].getY()-2*PreviousPath[i].getY());
            path[i].set_XY(path_i_x,path_i_y);
//path[i].show();
        }

        if(judge_smoothness()==true) break;
        PreviousPath=path;
    }
}

bool PID::judge_smoothness() {
    double change=0;
    for(int i=0;i<path.size();i++) change+=path[i].distance(PreviousPath[i]);

cout<<"change:"<<change<<endl;
    if(change<=tolerance) return true;
    else return false;
}

void PID::show_change_path() {
    cout<<"show change of path"<<endl;
    for(int i=0;i<path.size();i++){
        OriginalPath[i].show_nonewline();
        cout<<"->";
        path[i].show_nonewline();
        cout<<endl;
    }
}

void PID::write_change_path() {
    string filename="change_path.dat";
    ofstream fout;  //書き込み用のofstreamを宣言
    fout.open(filename,ios::app);

    cout<<"write results"<<endl;
    for(int i=0;i<path.size();i++) fout<< OriginalPath[i].getX()<<" "<<OriginalPath[i].getY()<<endl;
    fout<<endl<<endl;
    for(int i=0;i<path.size();i++) fout<< path[i].getX()<<" "<<path[i].getY()<<endl;

    fout.close();
}


