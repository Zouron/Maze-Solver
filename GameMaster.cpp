#include<iostream>
#include "maze.h"
#include "robot.h"
using namespace std;



int main()
{
    Maze mymaze;
    mymaze.displayMaze();

    cout<<"Start: "<<mymaze.getStart()<<endl;
    cout<<"Finish: "<<mymaze.getFinish()<<endl;
    
    Robot jerry(mymaze.getStart());
    jerry.displayLocation();
    jerry.solveMaze(mymaze);
    
    cout<<endl<<endl;
    
    cout<<"Maze was completed in "<< jerry.noOfMoves()<<" moves."<<endl;
    cout<<"Deadends are indicated as below:"<<endl;
    mymaze.displayMaze();
    return 0;
}