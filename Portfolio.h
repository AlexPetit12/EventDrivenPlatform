/**
 * \file Portfolio.h
 * \brief Portfolio class interface
 * \date 2015-07-22
 */

#ifndef PORTFOLIO_H_
#define PORTFOLIO_H_

#include "DataHandler.h"
#include "HistoricCSVDataHandler.h"
#include "Event.h"

#include <queue>


class Portfolio
{
public:
	Portfolio(DataHandler *dataHandler, std::queue<Event> events, std::string startDat, double initalCapital = 100000.0);

	std::map<std::string, long long> constructPositions();
	//void constructCurrentPositions();
	std::map<std::string, double> constructHoldings();
	//void constructCurrentHoldings();

	DataHandler *dataHandler;
	std::queue<Event> eventsQueue;
	std::vector<std::string> symbolsVector;
	std::string startDate;
	double initialCapital;

	std::vector<std::map<std::string, long long>> allPositions;
	std::map<std::string, long long> currentPositions;

	std::vector<std::map<std::string, double>> allHoldings;
	std::map<std::string, double> currentHoldings;
};



#endif /* PORTFOLIO_H_ */
