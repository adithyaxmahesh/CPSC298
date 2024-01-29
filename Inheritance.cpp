#include <iostream>
#include <string>
#include <cmath>

class Shape {
protected:
    double width, height;
    std::string m_strType;

public:
    Shape(double width, double height, const std::string& type)
        : width(width), height(height), m_strType(type) {}

    virtual ~Shape() {}

    virtual void scale(double factor) = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    void displayProperties() const {
        std::cout << "Shape Type: " << m_strType << std::endl;
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : Shape(width, height, "Rectangle") {}

    virtual ~Rectangle() {}

    void scale(double factor) override {
        width *= factor;
        height *= factor;
    }

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

class Circle : public Shape {
public:
    Circle(double diameter)
        : Shape(diameter, diameter, "Circle") {}

    virtual ~Circle() {}

    void scale(double factor) override {
        width *= factor;
        height *= factor;
    }

    double area() const override {
        return M_PI * width * width / 4;
    }

    double perimeter() const override {
        return M_PI * width;
    }
};

int main() {
    Shape* p_shapes[2];

    p_shapes[0] = new Circle(2.0); 
    p_shapes[1] = new Rectangle(3.0, 2.0); 

    for (int i = 0; i < 2; ++i) {
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << p_shapes[i]->perimeter() << std::endl;

        p_shapes[i]->scale(2.0);

        p_shapes[i]->displayProperties();
        std::cout << "Area after scaling: " << p_shapes[i]->area() << std::endl;
        std::cout << "Perimeter after scaling: " << p_shapes[i]->perimeter() << std::endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete p_shapes[i];
    }

    return 0;
}
