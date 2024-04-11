#include "order.h"

order::order()
{
    numProducts = 0;
    products = new product *[numProducts + 1];
    products[0] = nullptr;
}

void order::addProduct(product &d)
{

    products[numProducts] = d.clone();
    product **dcpy;
    dcpy = products;
    products = new product *[++numProducts + 1];
    for (int i = 0; i < numProducts; i++)
    {
        products[i] = dcpy[i];
    }
    delete[] dcpy;
}

/* void order::addDrinks(drink **d, int numD)
{
    int oldNum = numProducts;
    numProducts += numD;
    drink **dcpy;
    dcpy = products;
    products = new drink *[numProducts + 1];
    for (int i = 0; i < oldNum; i++)
    {
        products[i] = dcpy[i];
    }
    int j = 0;
    for (int i = oldNum; i < numProducts; i++)
    {
        products[i] = new drink(*d[j++]);
    }
} */

order::order(const order &otherOrder)
{
    products = nullptr;
    numProducts = 0;
    copyOrder(otherOrder);
}

order::~order()
{
    for (int i = 0; i < numProducts; i++)
    {
        delete products[i];
    }
    delete[] products;
}

std::string order::tostring() const
{
    std::ostringstream out;
    out << "This order has " << numProducts << " products:" << std::endl;
    for (int i = 0; i < numProducts; i++)
    {
        out << products[i]->tostring() << std::endl;
        out << std::setw(25) << std::setfill('-') << "-" << std::endl;
    }
    return out.str();
}

const order &order::operator=(const order &cpyOrder)
{
    if (this != &cpyOrder)
    {
        copyOrder(cpyOrder);
    }
    return *this;
}

product &order::operator[](int index)
{
    return *products[index];
}

void order::copyOrder(const order &cpyOrder)
{
    if (numProducts > 0)
    {
        for (int i = 0; i < numProducts; i++)
        {
            delete products[i];
        }
        delete[] products;
    }

    this->numProducts = cpyOrder.numProducts;
    this->products = new product *[this->numProducts + 1];
    for (int i = 0; i < numProducts; i++)
    {
        this->products[i] = cpyOrder.products[i]->clone();
    }
}
