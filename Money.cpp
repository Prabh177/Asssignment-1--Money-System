
#include "Money.h"

Money::Money() {
	dollarsObj = 0;
	centsObj = 0; 
}

Money::Money(int dollars, int cents) {
	if (cents > 99 && dollars < 0) {
		dollarsObj = cents / 100;
		centsObj = cents % 100;
	}
	
	else if (cents > 99 && dollars >= 0){
		dollarsObj = cents/100 + dollars;
		centsObj = cents % 100;
	}
	
	else if (dollars < 0 && cents >= 0 && cents < 100) {
		dollarsObj = 0;
		centsObj = cents;
	}
	
	else if (cents < 0 && dollars > 0 ) {
		centsObj = 0;
		dollarsObj = dollars;
	}
	
	else if (cents < 0 && dollars < 0 ){
		dollarsObj = 0;
		centsObj = 0;	
	}
	else{
		dollarsObj = dollars;
		centsObj = cents;
	}
}

int Money::getDollars() const {

		return dollarsObj;
		
}

int Money::getCents() const {
	
	return centsObj % 100;
}

int Money::asCents() const {

	return dollarsObj*100 + centsObj;
}


//Task 3

void Money::addDollars(int dollars) {
	if (dollars < 0){
		dollarsObj = dollarsObj;
	}
	else {
		dollarsObj = dollarsObj + dollars;

	}
}

void Money::addCents(int cents) {
	if (cents < 0){
		centsObj = centsObj;
	}
	else {
		centsObj = centsObj + cents;
		if (centsObj>99){
			dollarsObj = dollarsObj + centsObj/100;
			centsObj = centsObj%100;
		}
	}
}

void Money::subtractDollars(int dollars) {
	if (dollars < 0 || dollarsObj < dollars){
		dollarsObj = dollarsObj;
	}
	
	else {
		dollarsObj = dollarsObj - dollars;
	}
}

void Money::subtractCents(int cents) {

	int newVar  = dollarsObj*100 +centsObj - cents;
	if (cents < 0) {
		dollarsObj = dollarsObj;
		centsObj = centsObj;
	}
	
	else if (newVar < 0 && cents > 0){
		centsObj = centsObj;
	}
	else {
			centsObj = newVar % 100;
			dollarsObj = newVar / 100;
		
	}
	

	
}

//Task 4
	
void Money::add(const Money &other) {
	this -> addDollars(other.getDollars());
	this -> addCents(other.getCents());
}

void Money::subtract(const Money &other) {
	if (this-> asCents() < other.asCents()){

	}
	else{
		int a = other.getDollars();
		int b = other.getCents();
		this -> subtractDollars(a);
		this -> subtractCents(b);
	}
}

void Money::split(Money &other) {
	int x = other.asCents();
	int y = this->asCents();
	int z = (x + y)/2;

	this -> dollarsObj = z/100;
	this -> centsObj = z%100;
	other.dollarsObj = dollarsObj;
	other.centsObj = centsObj;
}

Money::~Money() {

}
