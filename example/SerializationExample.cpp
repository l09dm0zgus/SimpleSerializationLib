// SerializationTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Serializable.h>

class Point : public Serializable
{
    public:
        void setX(float x)
        {
            this->x = x;
        }
        void setY(float y)
        {
            this->y = y;
        }
        float getX()
        {
            return x;
        }
        float getY()
        {
            return y;
        }
        void save(SerializationFileWriterBuilder& stream) override
        {
            stream << ADDITIONAL_KEY(point) << NVP(x) << ADDITIONAL_KEY(point) << NVP(y);
        }
        void load(SerializationFileReaderBuilder& stream) override
        {
            GET_NVP_VALUE_BY_ADDITIONAL_KEY(point, x) >> x;
            GET_NVP_VALUE_BY_ADDITIONAL_KEY(point, y) >> y;
        }
    private:
        float x;
        float y;

};  
class Circle : public Serializable
{
    public:
        void setRadius(float radius)
        {
            this->radius = radius;
        }
        float getRadius()
        {
            return radius;
        }
        void setPosition(const Point& position)
        {
            this->position = position;
        }
        Point getPosition()
        {
            return position;
        }
        void save(SerializationFileWriterBuilder& stream) override
        {
            stream << &position << ADDITIONAL_KEY(circle) << NVP(radius);
        }
        void load(SerializationFileReaderBuilder& stream) override
        {
            GET_NVP_VALUE_BY_ADDITIONAL_KEY(circle, radius) >> radius;
            stream >> &position;
        }
    private:
        float radius;
        Point position;
};

int main()
{
    SerializationFileWriterBuilder writer;
    SerializationFileReaderBuilder reader;

    Point position;
    position.setX(-1.4);
    position.setY(5.0);

    Circle* circle = new Circle();
    circle->setRadius(15.0);
    circle->setPosition(position);

    writer.openFile("test.txt");
    writer << circle;
    writer.closeFile();

    delete circle;
    circle = nullptr;

    circle = new Circle();
    reader.openFile("test.txt");
    reader.readFile();
    reader >> circle;
    reader.closeFile();

    std::cout << "Circle X:" << circle->getPosition().getX() << " Circle Y:" << circle->getPosition().getY() << " Circle radius:" << circle->getRadius() << std::endl;
}
