#include<iostream>
#include<stack>
using namespace std;
const Coordinates UP(-1,0);         //Direction facing up
const Coordinates DOWN(1,0);        //Direction facing down
const Coordinates LEFT(0,-1);       //Direction facing left
const Coordinates RIGHT(0,1);       //Direction facing right

class Robot
{
    private:
        Coordinates position;       //The current position of the robot
        Coordinates prev;           //The previous position of the robot
        stack<Coordinates> path;    //The path taken by the robot as a stack
        int movesTaken=0;           //The total number of moves taken by the robot
    public:
    Robot(Coordinates);
    //Default constructor that sets the position of the robot
    //at the stat of the maze.
    
    stack<Coordinates> getPath();
    //Function to 
    
    int noOfMoves();
    //Function to return the number of moves taken by the robot.
    //This is initialized to zero when the robot is created.
    
    void moveTo(Coordinates);
    //Function that makes the robot to move the given direction
    //Postcondition: The robot will have moved to the position that
    //      as indicated by the coordinates in the parameter. The
    //      the move count is incremented here, the position is pushed
    //      to the stack and the location is displayed to show progress.
    
    void move(Maze&);
    //Function to check which path is clear to traverse in the maze.
    //Once a clear is found, the robot moves in that direction but
    //only if it is not the previous direction. The robot will not
    //go backwards unless it meets a deadend.
    
    void displayLocation();
    //This function displays he current location of the robot in the maze.
    
    bool isClear(Coordinates,Maze);
    //This function checks to see if a given location in the maze is clear.
    //If there is no wall returns true otherwise returns false.
    
    void solveMaze(Maze&);
    //This is the main function that runs the loop for the robot
    //to finish the maze.
    
    bool atIntersection(Maze&);
    //This functions returns a bool to tell us if the current position is
    //an intersection or not. Returns true if it is otherwuse false. This
    //is done by counting the number of paths available. If it is equal or
    //more than 2 the postion is an intersection.
    
    void backtrack(Maze&);
    //This function checks to see if the previous postion is an intersection.
    //If it is, the current position is marked as a dead to indicated the path
    //leads to a deadend. We also call the function to to take one step back
    //from here.
    
    void goBack(Maze&);
    //This is the main function that runs the loop to get the robot to the
    //previous intersection. The loop runs till the robot is at the intersection.
    
    Coordinates location();
    //This function returns the coordinates of the current location of the
    //robot in the maze.
    
    void stepBackwards();
    //This function makes the robot to take one step backwards. This also
    //counts towards to the total movement.
    
};

stack<Coordinates> Robot::getPath()
{
    return path;
}

int Robot::noOfMoves()
{
    return movesTaken;
}

Coordinates Robot::location()
{
    return position;
}

void Robot::solveMaze(Maze& maze)
{
    while(!(position==maze.getFinish()))
    {
        if(atIntersection(maze))
        {
            //Marking as intersection to return to later
            position.markAsIntersection();
            move(maze);
        }
        else
            move(maze);
    }
    
}

void Robot::move(Maze& maze)
{
    //If not at an intersection the first and only available path will be taken
    //Each direction is checked and making sure the clear path is not the
    //same path that we came from.
    if(isClear(RIGHT,maze)&& !(position+RIGHT==prev))
        moveTo(RIGHT);
    else if(isClear(DOWN,maze)&& !(position+DOWN==prev))
        moveTo(DOWN);
    else if(isClear(UP,maze)&& !(position+UP==prev))
        moveTo(UP);
    else if(isClear(LEFT,maze)&& !(position+LEFT==prev))
        moveTo(LEFT);
    else
    //If no paths availble its a dead end ... have to back track to intersection
    {
        cout<<"Reached a dead end... Going back."<<endl;
        goBack(maze);
        
    }
}

void Robot::moveTo(Coordinates diff)
{
    movesTaken++;
    prev=position;                  //Previous is current position
    position=position+diff;         //Position is incremented with the direction
    position.removeIntersection();  //Intersection is reset to false
    path.push(prev);                //Pushing the the traversed path on the stack
    displayLocation();
}

void Robot::goBack(Maze& maze)
{
    cout<<"The backtracked path: ";
    //Backtrack till we reach the intersection
    while(!position.isIntersection())
    {
        backtrack(maze);
        displayLocation();
    }
       
}

void Robot::backtrack(Maze& maze)
{
    //While backtracking if the previous is an intersection we mark
    //the current postion as a deadend pathway to avoid traversing it
    if(prev.isIntersection())
    {
        maze.markAsDeadend(position);
        cout<<endl<<"At the intersection ";
    }
    stepBackwards();
}


void Robot::stepBackwards()
{
    movesTaken++;
    position = path.top();  //Position is the top the stack
    path.pop();             //Pop top
    prev = path.top();      //Set the previous position to the top
}

void Robot::displayLocation()
{
    cout<<"("<<position<<") ";
}

Robot::Robot(Coordinates p)
{
    position = p;
    prev = p;
    path.push(p);
    cout<<"robot created at "<<position<<endl;
}

bool Robot::isClear(Coordinates dir, Maze maze)
{
    Coordinates checkPosition = position+dir;
    int loc = maze.whatsHere(checkPosition);
    //If 0 or 9 we can go on it as 9 is end position
    if(loc==0||loc==9)
        return true;
    return false;
}


bool Robot::atIntersection(Maze& maze)
{
    //If direction is clear and not the direction we came from
    //it is a traversable path.
    int pathCount=0;
    if(isClear(UP,maze)&& !(position+UP==prev))
        pathCount++;
    if(isClear(DOWN,maze)&& !(position+DOWN==prev))
        pathCount++;
    if(isClear(LEFT,maze)&& !(position+LEFT==prev))
        pathCount++;
    if(isClear(RIGHT,maze)&& !(position+RIGHT==prev))
        pathCount++;
    
    if(pathCount>=2)
        return true;
    return false;
}