#include<iostream>
using namespace std;

class Coordinates
{
    private:
        int x,y;
        //The x and y coordinates
        bool intersection = false;
        //To check if the current place is an intersection
    public:
        Coordinates();
        //Default constructor initializing the coordinates to zero
        
        Coordinates(int,int);
        //Two argument constructor to set the initial values of the coordinates
        
        int getX();
        //A function to get the value of X.
        
        int getY();
        //A function to get the value of Y.
        void markAsIntersection();
        //A function to mark the position as an intersection.
        
        void removeIntersection();
        //A function to unmark the position as an intersection.
        
        bool isIntersection();
        //A function that returns if the position is an intersection or not.
        
        bool operator==(Coordinates p);
        //An overloaded equals operator to see if two coordinates are equal.
        
        void operator=(Coordinates p);
        //An overloaded assignment operator for coordinates.
        
        Coordinates operator +(Coordinates p);
        //An overloaded addition operator.
        
        friend ostream& operator<<(ostream& os,Coordinates p);
        //overloaded outstream operator.
};

bool Coordinates::isIntersection()
{
    return intersection;
}

void Coordinates::removeIntersection()
{
    intersection = false;
}

void Coordinates::markAsIntersection()
{
    intersection = true;
}

Coordinates::Coordinates()
{
    int x=0,y=0;
}

Coordinates::Coordinates(int a,int b)
{
    x=a;
    y=b;
}

ostream& operator<<(ostream& os, Coordinates p)
{
    os<<p.getX()<<","<<p.getY();
    return os;
}

int Coordinates::getX()
{
    return x;
}

int Coordinates::getY()
{
    return y;
}

void Coordinates::operator=(Coordinates p)
{
    x=p.getX();
    y=p.getY();
    intersection = p.isIntersection();
}

Coordinates Coordinates::operator+(Coordinates p)
{
    Coordinates temp;
    temp.x = this->x + p.getX();
    temp.y = this->y + p.getY();
    return temp;
}

bool Coordinates::operator==(Coordinates p)
{
    return ( x==p.getX() && y==p.getY() );
}