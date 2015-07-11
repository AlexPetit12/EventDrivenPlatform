/**
 * \file HistoricCSVDataHandler.cpp
 * \brief HistoricCSVDataHandler class source file
 * \date 2015-06-28
 */

#include "HistoricCSVDataHandler.h"
#include <boost/tokenizer.hpp>

#include <cctype>
#include <string>


/*
 * \brief HistoricCSVDataHandler constructor with parameters
 * \param[in] events: queue of events
 * \param[in] csvDir: path of directory containing csv files
 * \param[in] symbolsList: list of symbols
 */
HistoricCSVDataHandler::HistoricCSVDataHandler(std::queue<Event> events,
		std::string csvDir, std::vector<std::string>& symbolsVector)
:events(events), csvDir(csvDir), symbolsVector(symbolsVector), continueBacktest(true), barIndex(0)
{
	openConvertCsvFiles();
};

/*
 * \brief HistoricCSVDataHandler destructor
 */
HistoricCSVDataHandler::~HistoricCSVDataHandler()
{
	for(std::string& symbol : symbolsVector)
	{
		delete fileStreams[symbol];
	}
};

/*
 * \brief openConvertCsvFiles method
 */
void HistoricCSVDataHandler::openConvertCsvFiles()
{
	for(std::string& symbol : symbolsVector)
	{
		std::string path = csvDir + symbol + ".csv";
		fileStreams[symbol] = new std::ifstream(path);
	}
};

/*
 * \brief getNewBar method
 * param[in] symbol : the symbol for which the Bar is returned
 * \return Returns a Bar object after having read data in the corresponding symbol's csv file
 */
Bar HistoricCSVDataHandler::getNewBar(std::string symbol)
{
	std::string csvLine;
	std::getline(*fileStreams[symbol], csvLine);

	// stores csv line
	typedef boost::tokenizer<boost::escaped_list_separator<char>> Tokenizer;
	Tokenizer token(csvLine);

	std::vector<std::string> v(7);
	v.assign(token.begin(), token.end());

	Bar B(v[Date], std::stof(v[Open]), std::stof(v[High]), std::stof(v[Low]), std::stof(v[Close]), std::stoll(v[Volume]), std::stof(v[AjdClose]));
	return B;
};

Bar HistoricCSVDataHandler::getLatestBar(std::string symbol)
{
	return latestSymbolsData[symbol].back();
};

void HistoricCSVDataHandler::updateBars()
{
	for(std::string &symbol : symbolsVector)
	{
		latestSymbolsData[symbol].push_back(getNewBar(symbol));
	}
};
