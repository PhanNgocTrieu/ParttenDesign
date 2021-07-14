#include <iostream>

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */
class Product
{
public:
    virtual ~Product() {}
    virtual std::string Behavior() const = 0;
};

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class RoadLogisticProduct : public Product
{
public:
    RoadLogisticProduct() {}
    std::string Behavior() const override
    {
        return "Transportation by Road!\n";
    }
};
class SeaLogisticProduct : public Product
{
public:
    SeaLogisticProduct() {}
    std::string Behavior() const override
    {
        return "Transportation by Sea!\n";
    }
};

/**
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */
class LogicApp
{
public:
    virtual ~LogicApp() {}
    virtual Product *Deliver() const = 0;

    std::string SomeOperation() const
    {
        // Call the factory method to create a Product object.
        Product *product = this->Deliver();
        // Now, use the product.
        std::string result = "Creator: The same creator's code has just worked with " + product->Behavior();
        delete product;
        return result;
    }
};

class RoadLogistic : public LogicApp
{
public:
    Product *Deliver() const override
    {
        return new RoadLogisticProduct();
    }
};

class SeaLogistic : public LogicApp
{
public:
    Product *Deliver() const override
    {
        return new SeaLogisticProduct();
    }
};

int main()
{
    LogicApp *Logic = new RoadLogistic();
    LogicApp *Logic2 = new SeaLogistic();
    std::cout << Logic->SomeOperation() << std::endl;
    std::cout << Logic2->SomeOperation() << std::endl;

    delete Logic;
    delete Logic2;
    return 0;
}