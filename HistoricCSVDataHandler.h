/**
 * \file HistoricCSVDataHandler.h
 * \brief HistoricCSVDataHandler class interface
 * \date 2015-06-28
 */

#ifndef HISTORICCSVDATAHANDLER_H_
#define HISTORICCSVDATAHANDLER_H_

#include "DataHandler.h"
#include "Event.h"

#include <map>
#include <queue>

class HistoricCSVDataHandler: public DataHandler
{
public:
	HistoricCSVDataHandler();
	HistoricCSVDataHandler(std::queue<Event> events, std::string csvDir,
			std::vector<std::string> symbolsList);

	std::vector<std::string> csvHeaders = {"Date", "Open", "High", "Low", "Close", "Volume", "AjdClose"};

	std::queue<Event> events;
	std::string csvDir;
	std::vector<std::string> symbolsList;
	std::map<std::string, std::vector<Bar>> latestSymbolsData;

	bool continueBacktest;

	long long barIndex;
};



#endif /* HISTORICCSVDATAHANDLER_H_ */
