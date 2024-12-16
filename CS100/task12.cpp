#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <list>
#include <iomanip>

const float PI = 3.14159f;

/***********************************************************************
* Declaration/Definition of the base-class Shape *
***********************************************************************/
class Shape 
{
public:
    // constructors and destructor
    Shape(float a,float b){
       size1=a;
       size2=b;
    };
    Shape(float a){
        size1=a;
    }
    ~Shape(){};
    // Accessors; you should decide which should be virtual or pure virtual.
    virtual float CalculateArea()=0;
    virtual float CalculatePerimeter()=0;
    virtual int NumberCorners()=0;

private:
    float size1;
    float size2;
    // member variables;
};


/***********************************************************************
* Declaration/Definition of the child-classes *
***********************************************************************/
class Rectangle:public Shape{
public:
Rectangle(float a,float b):public Shape(a,b){
size1 = a;
size2 = b;
};
~Rectangle(){
        std::cout << "A Rectangle has been destroyed.";
    };
float CalculateArea(float size1,float size2){
    return size1*size2;
};
float CalculatePerimeter(float size1,float size2){
    return size1*2+size2*2;
}
int NumberCorners(){
    return 4;
}
private:
float size1;
float size2;
}; // ...
class Square:public Shape{
public:
Square(float a):public Shape(a){
size1 = a;
};
~Shape(){
        std::cout << "A Square has been destroyed.";
    };
float CalculateArea(float size1){
    return size1*size1;
};
float CalculatePerimeter(float size1){
    return size1*4;
}
int NumberCorners(){
    return 4;
}
private:
float size1;
}; // ...
class Triangle:public Shape{
public:
Triangle(float a,float b):public Shape(a,b){
size1 = a;
size2 = b;
};
~Shape(){
        std::cout << "A Triangle has been destroyed.";
    };
float CalculateArea(int size1,int size2){
    return size1*size2*0.5;
};
float CalculatePerimeter(int size1,int size2){
    return size1+size2+sqrt(size1*size1+size2*size2);
}
int NumberCorners(){
    return 3;
}
private:
float size1;
float size2;
}; // ...
class Circle:public Shape{
public:
Circle(float a):public Shape(a){
size1 = a;
};
~Shape(){
        std::cout << "A Circle has been destroyed.";
    };
float CalculateArea(int size1){
    return PI*size1*size1;
};
float CalculatePerimeter(int size1,int size2){
    return 2*PI*size1;
}
int NumberCorners(){
    return 0;
}
private:
float size1;
}; // ...

/************************************************************************
* Main Function which is creating/reporting database (do not change!) *
************************************************************************/
int main() 
{
    //initialize an empty list of shapes
    std::list<Shape*> shapeDatabase;
    //interact with the user: ask the user to enter shapes one by one
    while(1) 
    {
        //print instructions as to how to enter a shape
        std::cout << "Enter a type (Circle, Triangle, Square, or Rectangle) ";
        std::cout << "and one or two size parameters, ";
        std::cout << "separated with blank spaces:\n";
        float size1;
        float size2;
        //check which shape has been requested and store in the database
        std::string shapeType;
        std::cin >> shapeType;
        if( shapeType == std::string("Circle") ) 
        {
            std::cin >> size1;
            shapeDatabase.push_back( new Circle(size1) );
        }
        else if ( shapeType == std::string("Triangle") ) 
        {
            std::cin >> size1 >> size2;
            shapeDatabase.push_back( new Triangle(size1,size2) );
        }
        else if ( shapeType == std::string("Square") ) 
        {
            std::cin >> size1;
            shapeDatabase.push_back( new Square(size1) );
        }
        else if (shapeType == std::string("Rectangle") ) 
        { 
            std::cin >> size1 >> size2;
            shapeDatabase.push_back( new Rectangle(size1,size2) );
        }
        else 
        {
            std::cout << "Unrecognized shape!!\n";
        }
        //check if the user wants to add more shapes
        std::cout << "Do you want to add more shapes? (Enter Y or N)\n";
        std::string answer;
        std::cin >> answer;
        if( answer != std::string("Y") )
            break;
    }
    //iterate through the list and output the area, perimeter,
    //and number of corners of each entered shape
    std::list<Shape *>::iterator it = shapeDatabase.begin();
    int shapeCounter = 0;
    while( it != shapeDatabase.end() ) 
    {   
        std::cout << "Properties of shape " << shapeCounter++ << ":\n";
        std::cout << "Area: " << std::setprecision(5) << (*it)->CalculateArea() << "\n";
        std::cout << "Perimeter: " << std::setprecision(5) << (*it)->CalculatePerimeter() << "\n";
        std::cout << "Corners: " << (*it)->NumberCorners() << "\n";
        std::cout << std::endl;
        it++;
    }

    it = shapeDatabase.begin();
    while( it != shapeDatabase.end() ) 
    {
        delete (*it);
        it = shapeDatabase.erase(it);
    }
    
    return 0;
}
