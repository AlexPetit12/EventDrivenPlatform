/**
 * \file Main.cpp
 * \brief Main source file
 * \date 2015-06-24
 */

#include "FillEvent.h"
#include "MarketEvent.h"
#include "OrderEvent.h"
#include "SignalEvent.h"

#include <iostream>

int main(void)
{
	MarketEvent M;
	std::cout << M.EVENT_TYPE << std::endl;

	SignalEvent S("CO", "GOOG", "15/25/06", "LONG", 0.5);
	std::cout << S.strategyId << " " << S.symbol << " " << S.dateTime << " " << S.signalType << " " << S.signalStrength << std::endl;

	OrderEvent O("GOOG", "MKT", "BUY", 10);
	O.printOrder();

	FillEvent F("timeIndex", "GOOG", "ALPHA", "BUY", 1002, 150000.50, 10);
	std::cout << F.timeIndex << " " << F.symbol << " " << F.exchange << " " << F.direction << " "
			<< F.quantity << " " << F.fillCost << " " << F.commission << std::endl;

	return 0;
}
