/**
 * \file HistoricCSVDataHandler.cpp
 * \brief HistoricCSVDataHandler class source file
 * \date 2015-06-28
 */

#include "HistoricCSVDataHandler.h"

#include <boost/tokenizer.hpp>

HistoricCSVDataHandler::HistoricCSVDataHandler()
:continueBacktest(true), barIndex(0)
{
};

HistoricCSVDataHandler::HistoricCSVDataHandler(std::queue<Event> events,
		std::string csvDir, std::vector<std::string> symbolsList)
:events(events), csvDir(csvDir), symbolsList(symbolsList), continueBacktest(true), barIndex(0)
{
	// initializes map of symbols
	for(std::string& symbol : this->symbolsList)
	{
		this->latestSymbolsData[symbol];
	}
};
