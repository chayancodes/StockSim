#include "Asset.h"
#include <iostream>
using namespace std;

Asset::Asset(string sym, int qty, double buy, double curr){symbol=sym;quantity=qty;buy_price=buy;curr_price=curr;}

Asset::Asset(const Asset& o){
    symbol=o.symbol;quantity=o.quantity;buy_price=o.buy_price;curr_price=o.curr_price;
}

Asset::~Asset() {}

double Asset::getPnL() const {
    return((curr_price-buy_price)*quantity);
}

string Asset::getSymbol() const {return symbol;};
int Asset::getQuantity() const {return quantity;};
void Asset::setQuantity(int q) {quantity=q;};
void Asset::setCurrentPrice(double p){curr_price=p;};

ostream& operator<<(ostream& os, const Asset &a){
    os<<a.getType()<<"  |   "<<a.symbol
    <<"    |    Qty: "<<a.quantity
    <<"    |    Buy: "<<a.buy_price
    <<"    |    Now: "<<a.curr_price
    <<"    |    P&L: "<<a.getPnL();
    return os;
}

bool operator>(const Asset& a, const Asset& b) {return a.getValue()>b.getValue();};
bool operator<(const Asset& a, const Asset& b) {return a.getValue()<b.getValue();};
bool operator==(const Asset& a, const Asset& b) {return a.symbol==b.symbol;};