//
// Created by Igor on 15.02.2022.
//
#include <iostream>
#include <fstream>
#include <cstdlib>

class Point{
private:
    int coordinateX,
    coordinateY;
public:
    Point(int date_x, int date_y){
        setPointPosition(date_x, date_y);
    }
    void setPointPosition(int date_x, int date_y){
        coordinateX = date_x;
        coordinateY = date_y;
    }
    void printPointPosition(){
        std::cout << "position (x, y):" << std::endl;
        std::cout << "(" << coordinateX << ", " << coordinateY << ")" << std::endl;
    }
    void getInformation(){
        std::cout << "This is point with ";
        printPointPosition();
    }
};


int main(int argc, char *argv[])
{
    Point x(-100, 0);
    x.getInformation();
    return 0;
}

