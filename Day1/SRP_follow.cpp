#include <iostream>
#include <vector>
using namespace std;
class Product
{
public:
    string name;
    double price;
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};
class ShoppingCart
{

    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
       
        products.push_back(p);
    }
    const vector<Product *> getProducts()
    {
        return products;
    }
    double calculateTotals()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};
class ShoppingCartPrinter{
private:
ShoppingCart*cart;
public:
ShoppingCartPrinter(ShoppingCart *cart){
    this->cart=cart;
}

void printInvoice(){
    for(auto p:cart->getProducts()){
         cout << p->name << " : $" << p->price << endl;
    }
    cout<<"Total Price"<<cart->calculateTotals();
}
};
class ShoppingCartStorage{
    private:
    ShoppingCart*cart;
    public:
    ShoppingCartStorage(ShoppingCart*cart){
        this->cart=cart;
    }
    void saveToDatabase(){
        cout<<"Save To Database";
    }

};
int main()
{
   ShoppingCart*cart=new ShoppingCart();
   cart->addProduct(new Product("Laptop",16590));
   cart->addProduct(new Product("Mobile",5985));
    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    ShoppingCartStorage *db = new ShoppingCartStorage(cart);
    db->saveToDatabase();
}