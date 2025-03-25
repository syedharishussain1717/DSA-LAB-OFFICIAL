// Syed Haris Hussain Shah
// L1F23BSCS0697

#include <iostream>
using namespace std;

// abstract class 
class Shape {
public:
	virtual void area() = 0;
};

// derived Circle class
class Circle : public Shape {
private:
	double radius;
	const double pie = 3.142;
public:
    Circle() {
	this->radius = 0;
    }
	Circle(double radius) {
		this->radius = radius;
	}
	void area() override {
		double area = pie * radius * radius;
		cout << "The area of this Circle is: " << area << endl;
	}
};

// derived rectangle class

class Rectangle : public Shape {
private:
	double length;
	double width;
public:
	Rectangle() {
		this->width = 0;
		this->length = 0;
	}
	Rectangle(double width, double length) {
		this->width = width;
		this->length = length;
	}
	void area() override {
		double area = length * width;
		cout << "The area of this Reactangle is: " << area << endl;

	}
};
int main() {

	// creating objects of both derived classes

	Shape* circle = new Circle(12);
	circle->area();

	Shape* rectangle = new Rectangle(23,24);
	rectangle->area();

        delete circle;
        delete rectangle;
	return 0;
}

