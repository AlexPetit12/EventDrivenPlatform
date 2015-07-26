/**
 * \file Portfolio.cpp
 * \brief Portfolio class source file
 * \date 2015-07-22
 */

#include "Portfolio.h"

#include <iostream>


Portfolio::Portfolio(DataHandler *dataHandler, std::queue<Event> events, std::string startDat, double initialCapital)
:dataHandler(dataHandler), eventsQueue(events), symbolsVector(dataHandler->getSymbols()), startDate(startDat), initialCapital(initialCapital)
{
	allPositions.push_back(constructPositions());
	allHoldings.push_back(constructHoldings());
}

std::map<std::string, long long> Portfolio::constructPositions()
{
	std::map<std::string, long long> m;

	for(std::string& symbol : symbolsVector)
	{
		m[symbol] = 0;
	}

	return m;
}

std::map<std::string, double> Portfolio::constructHoldings()
{
	std::map<std::string, double> m;

	for(std::string& symbol : symbolsVector)
	{
		m[symbol] = 0.0;
	}

	return m;
}
