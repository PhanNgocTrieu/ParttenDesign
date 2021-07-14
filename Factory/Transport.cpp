#include <iostream>



/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */
class Product
{
    public:
    virtual ~Product();
    virtual std::string Behavior() const = 0;
};

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class RoadLogisticProduct : Product
{
    std::string Behavior() const override {
        return "Transportation by Road!\n";
    }
};
class SeaLogisticProduct : Product
{
    std::string Behavior() const override {
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
    virtual Product* Deliver() const = 0;
};

int main()
{
    return 0;
}