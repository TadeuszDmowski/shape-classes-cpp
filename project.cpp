#include <iostream>
using namespace std;

//Defining Math namespace for Shapes classes
namespace Math {
    //Defining Shape class with type T
    template <class T>
    class Shape{
        //Protected variables
        protected:
            T width;
            T height;
        public:
            //Constructor
            Shape(T w, T h): width(w), height(h) {}
            //Function printing shape's type(no type)
            virtual void type(){
                cout << "I'm a shape of no type\n";
            }
            //Function returning shape's area(0)
            virtual T area(){
                return 0;
            }

    };

    //Defining Rectangle class inheriting from Shape
    template <class T>
    class Rectangle : public Shape<T>{
        public:
            using Shape<T>::width;
            using Shape<T>::height;
            //Constructor
            Rectangle(T w, T h): Shape<T>(w, h) {};
            //Function printing rectangle's type
            void type() override{
                cout << "I'm a rectangle of width " << width
                          << " and height " << height << "\n";
            }
            //Function printing given rectangle
            void draw(){
                cout << "Drawing(simplified to integers)\n";
                //Rows
                for(int i=0;i<int(height);i++){
                    cout << "\n";
                    //Columns
                    for(int j=0;j<int(width);j++){
                        //Sides
                        if(i==0 || j==0 || i==int(height)-1 || j==int(width)-1){
                            cout << ".";
                        } else{
                            cout << " ";
                        }
                    }
                }
                cout << "\n\n";
            }
            //Function returning rectangle's area
            T area() override{
                return width*height;
            }
            //Function returning inscribed circle's diameter 
            T inscribedCircleDiameter(){
                return min(width,height);
            }
    };

    //Defining (right-angled) Triangle class inheriting from Shape
    template <class T>
    class Triangle : public Shape<T>{
        public:
            using Shape<T>::width;
            using Shape<T>::height;
            //Constructor
            Triangle(T w, T h): Shape<T>(w, h) {};
            //Function printing triangle's type
            void type() override{
                cout << "I'm a right-angled triangle of width " << width
                          << " and height " << height << "\n";
            }
            //Function printing given triangle
            void draw(){
                cout << "Drawing(simplified to integers)\n";
                int hi = (int)height; int wi = (int)width;
                //Rows
                for(int i=0;i<hi;i++){
                    cout << "\n";
                    //Columns
                    int ai = (int)(i*wi/hi)+1;
                    for(int j=0;j<ai;j++){
                        //Sides
                        if(i==0 || j==0 || i==hi-1 || j==wi-1){
                            cout << ".";
                        }
                        //Hypotenuse 
                        else if(j==ai-1){
                            cout << ".";
                        } else{
                            cout << " ";
                        }
                    }
                }
                cout << "\n\n";
            }
            //Function returning triangle's area
            T area() override{
                return width*height/2;
            }
            //Function returning inscribed circle's diameter 
            T inscribedCircleDiameter(){
                T hypotenuse = sqrt(width*width+height*height);
                return width+height-hypotenuse;
            }
    };

    //Defining Circle class inheriting from Shape
    template <class T>
    class Circle : public Shape<T>{
        //Adding diameter as protected variable
        protected:
            T diameter;
        public:
            using Shape<T>::width;
            using Shape<T>::height;
            //Constructor
            Circle(T d): Shape<T>(d, d), diameter(d) {};
            //Function printing rectangle's type
            void type() override{
                cout << "I'm a circle of diameter " << diameter << "\n";
            }
            //Function printing given circle
            void draw(){
                cout << "Drawing(simplified to integers)\n";
                //Setting radius
                double r = (double)diameter/2-0.5;
                for(int i=0;i<=diameter;i++){
                    cout << "\n";
                    for(int j=0;j<=r || (r-i)*(r-i)+(r-j)*(r-j)<=r*r+1;j++){
                        //Drawing circumference
                        if((r-i)*(r-i)+(r-j)*(r-j)<=r*r+1){
                            cout << " .";
                        }
                        else{
                            cout << "  ";
                        }
                    }
                }
                cout << "\n\n";
            }
            //Function returning circle's area
            T area() override{
                return M_PI*(diameter/2)*(diameter/2);
            }
            //Function returning inscribed square's side
            T inscribedSquareSide(){
                return diameter/sqrt(2);
            }
            
    };
};

using namespace Math;

int main(){
    //Height, width variables
    double height, width;

    //Rectangle
    //Taking values for height,width of rectangle as inputs
    cout << "Please type rectangle's width:";
    cin >> width;
    cout << "Please type rectangle's height:";
    cin >> height;
    //Creating rectangle of given width and height
    Rectangle<double> Rec1(width, height);
    //Printing rectangle's type
    Rec1.type();
    //Drawing rectangle(simplified to integers)
    Rec1.draw();
    //Printing rectangle's area
    cout << "Rectangle's area: " << Rec1.area() << "\n";
    //Printing diameter of circle inscribed in rectangle
    cout << "Diameter of circle inscribed in rectangle: " << Rec1.inscribedCircleDiameter() << "\n\n";

    //Triangle
    //Taking values for height,width of (right-angled) triangle as inputs
    cout << "Please type (right-angled) triangle's width:";
    cin >> width;
    cout << "Please type (right-angled) triangle's height:";
    cin >> height;
    //Creating (right-angled) triangle of given width and height
    Triangle<double> Tri1(width, height);
    //Printing (right-angled) triangle's type
    Tri1.type();
    //Drawing triangle(simplified to integers)
    Tri1.draw();
    //Printing (right-angled) triangle's area
    cout << "Triangle's area: " << Tri1.area() << "\n";
    //Printing diameter of circle inscribed in triangle
    cout << "Diameter of circle inscribed in triangle: " << Tri1.inscribedCircleDiameter() << "\n\n";

    //Circle
    //Taking values for diameter of circle as input
    cout << "Please type circle's diameter:";
    cin >> width;
    //Creating circle of given diameter
    Circle<double> Cir1(width);
    //Printing circle's type
    Cir1.type();
    //Drawing circle(simplified to integers)
    Cir1.draw();
    //Printing circle's area
    cout << "Circle's area: " << Cir1.area() << "\n";
    //Printing side of square inscribed in circle
    cout << "Side of square inscribed in circle: " << Cir1.inscribedSquareSide() << "\n\n";
    return 0;
}
