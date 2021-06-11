
#include "basics.h"

int totalCents(int dollars, int cents) {
	if (dollars < 0 || cents < 0){
		return (-1);
	}

	else {
		return dollars*100+cents;
	}
}

int sumAsCents(int moneyOneDollars, int moneyOneCents, int moneyTwoDollars, int moneyTwoCents) {
	if (moneyOneDollars < 0 || moneyOneCents < 0 || moneyTwoDollars < 0 || moneyTwoCents < 0){
			return (-1);
		}

	else { 
	return (moneyOneDollars+moneyTwoDollars)*100+moneyTwoCents+moneyOneCents;
	}
}

int split(int moneyOneDollars, int moneyOneCents, int moneyTwoDollars, int moneyTwoCents) {
	if (moneyOneDollars < 0 || moneyOneCents < 0 || moneyTwoDollars < 0 || moneyTwoCents < 0){
		return (-1);
	}
		return ((moneyOneDollars+moneyTwoDollars)*100+moneyTwoCents+moneyOneCents)/2;
}

