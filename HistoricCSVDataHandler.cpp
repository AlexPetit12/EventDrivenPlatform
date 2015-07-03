/**
 * \file HistoricCSVDataHandler.cpp
 * \brief HistoricCSVDataHandler class source file
 * \date 2015-06-28
 */

#include "HistoricCSVDataHandler.h"
#include <boost/tokenizer.hpp>

#include <string>
#include <typeinfo>


HistoricCSVDataHandler::HistoricCSVDataHandler()
:continueBacktest(true), barIndex(0)
{
};

HistoricCSVDataHandler::HistoricCSVDataHandler(std::queue<Event> events,
		std::string csvDir, std::vector<std::string>& symbolsList)
:events(events), csvDir(csvDir), symbolsList(symbolsList), continueBacktest(true), barIndex(0)
{
	for(std::string& symbol : symbolsList)
	{
		std::string path = csvDir + symbol + ".csv";
		fileStreams[symbol] = new std::ifstream(path);
	}
};

HistoricCSVDataHandler::~HistoricCSVDataHandler()
{
	for(std::string& symbol : symbolsList)
	{
		delete fileStreams[symbol];
	}
};

Bar HistoricCSVDataHandler::getNewBar(std::string symbol)
{
	std::string csvLine;
	std::getline(*fileStreams[symbol], csvLine);

	// stores csv line
	typedef boost::tokenizer<boost::escaped_list_separator<char>> Tokenizer;
	Tokenizer token(csvLine);

	std::vector<std::string> v(7);
	v.assign(token.begin(), token.end());

	Bar B(v[0], std::stof(v[1]), std::stof(v[2]), std::stof(v[3]), std::stof(v[4]), std::stoll(v[5]), std::stof(v[6]));
	return B;
};
