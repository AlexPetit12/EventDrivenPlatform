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
	Portfolio(DataHandler *dataHandler, std::queue<Event> events, std::string startDat, float initalCapital = 100000.0);

	DataHandler *dataHandler;
	std::queue<Event> eventsQueue;
	std::vector<std::string> symbolsVector;
	std::string startDate;
	float initialCapital;
};



#endif /* PORTFOLIO_H_ */
