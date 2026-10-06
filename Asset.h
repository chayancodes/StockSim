// Code that contains all of the classes and base functions. Made by Chayan, 25BCE10620

#include <iostream>
using namespace std;

class Asset {
    protected:
        string symbol;
        int quantity;
        double buy_price;
        double curr_price; //current price
    public:
        //constructors:
        Asset(string s, int q, double b, double c){symbol=s;quantity=q;buy_price=b,curr_price=c;}
        Asset(const Asset& o){
            symbol=o.symbol;quantity=o.quantity;buy_price=o.buy_price;curr_price=o.curr_price;
        }
        virtual ~Asset() {};

        //functions:
        virtual double getValue() const=0;
        virtual void display() const=0;
        virtual string getType() const=0;

        double getPnL() const;
        string getSymbol() const;
        int getQuantity() const;
        void setQuantity(int q);
        void setCurrentPrice(double p);
        
        friend ostream& operator<<(ostream& os, const Asset& a);

        friend bool operator>(const Asset& a, const Asset& b);
        friend bool operator<(const Asset& a, const Asset& b);
        friend bool operator==(const Asset& a, const Asset& b);
};
