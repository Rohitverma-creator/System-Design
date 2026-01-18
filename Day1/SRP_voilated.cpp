#include<iostream>
#include<vector>
using namespace std;
//Product class  representing items of any E commerce

class Product{
public:
string name;
double price;
Product(string name,double price){
    this->name=name;
    this->price=price;
}
};
// Voilating SRP :Shopping Cart is handling multiple responsibilities
class ShoppingCart{
vector<Product*>products;
public:
void addProduct(Product*p){
    products.push_back(p);
}
const vector<Product*>&getProducts(){
    return products;
}
double calculateTotal(){
    double total=0;
    for(auto p:products){
        total+=p->price;
    }    
    return total;
}
// Print Invoice should be a seperate class-voilate invoice
void printInvoice(){
    cout<<"Shopping Cart Invoice";
    for(auto p:products){
        cout<<p->name<<":$"<<p->price<<endl;
    }
    cout<<"Total :$"<<calculateTotal()<<endl;
}
// save to DB a seperate function
void saveToDatabase(){
    cout<<"Saving shopping cart to DB"<<endl;
}

};
int main(){
ShoppingCart*cart=new ShoppingCart();
cart->addProduct(new Product("Laptop",15000));
cart->addProduct(new Product("Mouse",50));

cart->printInvoice();
cart->saveToDatabase();
return 0;
}