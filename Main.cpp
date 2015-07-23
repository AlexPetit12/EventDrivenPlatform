/**
 * \file Main.cpp
 * \brief Main source file
 * \date 2015-06-24
 */

#include "FillEvent.h"
#include "HistoricCSVDataHandler.h"
#include "MarketEvent.h"
#include "OrderEvent.h"
#include "Portfolio.h"
#include "SignalEvent.h"

#include <iostream>

int main(void)
{
//	MarketEvent M;
//	std::cout << M.EVENT_TYPE << std::endl;
//
//	SignalEvent S("CO", "GOOG", "15/25/06", "LONG", 0.5);
//	std::cout << S.strategyId << " " << S.symbol << " " << S.dateTime << " " << S.signalType << " " << S.signalStrength << std::endl;
//
//	OrderEvent O("GOOG", "MKT", "BUY", 10);
//	O.printOrder();
//
//	FillEvent F("timeIndex", "GOOG", "ALPHA", "BUY", 1002, 150000.50, 10);
//	std::cout << F.timeIndex << " " << F.symbol << " " << F.exchange << " " << F.direction << " "
//			<< F.quantity << " " << F.fillCost << " " << F.commission << std::endl;

	std::queue<Event> events;
	std::string csvDir = "";
	std::vector<std::string> symbols = {"M", "G"};
	HistoricCSVDataHandler *H = new HistoricCSVDataHandler(events, csvDir, symbols);


	std::vector<Bar> v;
	H->updateBars();
	H->updateBars();
	v = H->getLatestBars("M", 2);
	std::cout << v[0].close << v[1].close << std::endl;
	std::string date = H->getLatestBarDate("M");
	std::cout << date << std::endl;
	float open = H->getLatestBarOpen("M");
	std::cout << open << std::endl;
	std::cout << (H->symbolsVector)[0];
	Portfolio P(H, events, date);
	std::cout << P.symbolsVector[0];

	delete H;

	return 0;
}
