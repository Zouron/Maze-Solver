#include<iostream>
#include<cstring>
#include "coordinates.h"
using namespace std;
#ifndef MAZE_H_
#define MAZE_H_

const int MAZEHEIGHT = 12;	//Height of maze
const int MAZEWIDTH = 29;	//Width of maze
const int DEADEND = 3;		//Marker to indicate deadend



 // 8 represents the starting point and 9 for the exit.
 // Assume that the starting point is always  in the first column and the destination is always in the last column.

class Maze
{
	private:
		Coordinates start;		//Starting coordinate of the maze.
		Coordinates finish;		//Finish coordinate indicating the end.
		
		int maze[MAZEHEIGHT][MAZEWIDTH]
                  ={// 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
                   	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //0
	                  {1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //1
	                  {1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1}, //2
	                  {1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,9}, //3
	                  {8,0,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}, //4
	                  {1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1}, //5
	                  {1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1}, //6
	                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}, //7
	                  {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //8
	                  {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //9
	                  {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //0
	                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};//1
		//The maze represented as a 2d array. 1 represent walld, 0 is empty spaces.
		//8 is the start and 9 is the finish
		//Changes can me made to the maze inlcude the number of rows and columns.
		//Maze must be complete with a solvable path and without loops.
	public:
	void displayMaze();
	//This is a function that will display the maze onto the console.
	
	Coordinates getStart();
	//A function to get the starting coordinates of the maze.
	
	Coordinates getFinish();
	//A function to get the ending coordinates of the maze.
	
	Maze();
	//Default constructor of the maze that initialized the values.
	
	int whatsHere(Coordinates);
	//A function that will return what is at a particular location in the maze.
	
	void markAsDeadend(Coordinates);
	//A function that will put a marked in the maze to indicate a path is
	//a dead end.
};

void Maze::markAsDeadend(Coordinates location)
{
	int posx = location.getX();
	int posy= location.getY();
	maze[posx][posy] = DEADEND;
}

int Maze::whatsHere(Coordinates location)
{
	return maze[location.getX()][location.getY()];
}

Maze::Maze()
{
	
	for(int i=0;i<MAZEHEIGHT;i++)
	{
		//Find and initialize the start and end coordinates.
		if(maze[i][0]==8) start=Coordinates(i,0);
		if(maze[i][MAZEWIDTH-1]==9) finish=Coordinates(i,MAZEWIDTH-1);
	}
}

void Maze::displayMaze()
{
	for(int i=0;i<MAZEHEIGHT;i++)
	{
		for(int j=0;j<MAZEWIDTH;j++)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
	}
}

Coordinates Maze::getStart()
{
	return start;
}

Coordinates Maze::getFinish()
{
	return finish;
}

#endif /* MAZE_H_ */