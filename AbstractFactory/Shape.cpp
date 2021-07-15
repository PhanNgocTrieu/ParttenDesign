#include <iostream>

// Product of Shape

/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 * 
 * Rectangle Product in this example - we suppose to have 2 types of Rectangle
 * 1) Scalene Triangle
 * 2) Right Triangle
 */
class RectangleProduct
{
public:
    virtual ~RectangleProduct(){};
    virtual std::string Declaration() const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class SquareProduct : public RectangleProduct
{
public:
    std::string Declaration() const override
    {
        return "The result of the product Rectangel in Square.";
    }
};

class ScaleneProduct : public RectangleProduct
{
    std::string Declaration() const override
    {
        return "The result of the product Rectangel in Scalene.";
    }
};

/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 * 
 * 
 * Triange Product in this example - we suppose to have 2 types of Triangle
 * 1) Scalene Triangle
 * 2) Right Triangle
 */
class TriangleProduct
{
public:
    virtual ~TriangleProduct(){};
    virtual std::string Declaration() const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ScaleneTriangle : public TriangleProduct
{
public:
    std::string Declaration() const override
    {
        return "The result of the product Scalen Triangle.";
    }
};

class RightTriangle : public TriangleProduct
{
    std::string Declaration() const override
    {
        return "The result of the product Right Triangle.";
    }
};

// Abstract Factory Class
class Shape
{
public:
    virtual RectangleProduct *FirstProduct() const = 0;
    virtual TriangleProduct *SecondProduct() const = 0;
};

// Each concrete Factory has a corresponding product variant
class createFristProductOfShape : public Shape
{
public:
    RectangleProduct *FirstProduct() const override
    {
        return new ScaleneProduct();
    }
    TriangleProduct *SecondProduct() const override
    {
        return new ScaleneTriangle();
    }
};

// Each concrete Factory has a corresponding product variant
class createSecondProductOfShape : public Shape
{
public:
    RectangleProduct *FirstProduct() const override
    {
        return new SquareProduct();
    }
    TriangleProduct *SecondProduct() const override
    {
        return new RightTriangle();
    }
};

void ClientCode(const Shape &shape)
{
    const RectangleProduct *product_rec = shape.FirstProduct();
    const TriangleProduct *product_trg = shape.SecondProduct();

    std::cout << product_trg->Declaration() << std::endl;
    std::cout << product_rec->Declaration() << std::endl;
    std::cout << std::endl;
    delete product_trg;
    delete product_rec;
}

int main()
{
    Shape *shape1 = new createFristProductOfShape();
    Shape *shape2 = new createSecondProductOfShape();
    ClientCode(*shape1);
    ClientCode(*shape2);

    delete shape1;
    delete shape2;

    return 0;
}