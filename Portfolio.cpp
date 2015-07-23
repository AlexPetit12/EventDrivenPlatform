/**
 * \file Portfolio.cpp
 * \brief Portfolio class source file
 * \date 2015-07-22
 */

#include "Portfolio.h"

#include <iostream>
Portfolio::Portfolio(DataHandler *dataHandler, std::queue<Event> events, std::string startDat, float initialCapital)
:dataHandler(dataHandler), eventsQueue(events), symbolsVector(dataHandler->getSymbols()), startDate(startDat), initialCapital(initialCapital)
{
	std::cout << this->symbolsVector[0];
}
