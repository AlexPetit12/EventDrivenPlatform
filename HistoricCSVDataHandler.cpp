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
		std::string csvDir, std::vector<std::string> symbolsVector)
:eventsQueue(events), csvDir(csvDir), symbolsVector(symbolsVector), continueBacktest(true), barIndex(0)
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
 * param[in] symbol: the symbol for which the Bar is returned
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

/*
 * \brief updateBars method
 */
void HistoricCSVDataHandler::updateBars()
{
	for(std::string &symbol : symbolsVector)
	{
		latestSymbolsData[symbol].push_back(getNewBar(symbol));
	}
};

/*
 * \brief getLatestBar method
 * param[in] symbol: the symbol for which the Bar is returned
 * \return Returns the latest Bar from latestSymbolsData
 */
Bar HistoricCSVDataHandler::getLatestBar(std::string symbol)
{
	return latestSymbolsData[symbol].back();
};

/*
 * \brief getLatestBars method
 * param[in] symbol: the symbol for which the vector of Bars is returned
 * param[in] n: the quantity of bars returned
 * \return Returns the n latest Bars from latestSymbolsData in a vector
 */
std::vector<Bar> HistoricCSVDataHandler::getLatestBars(std::string symbol, long long n)
{
	// safety mechanism to add
	std::vector<Bar> barsVec(latestSymbolsData[symbol].end() - n, latestSymbolsData[symbol].end());
	return barsVec;
}

/*
 * \brief getLatestBarDate method
 * param[in] symbol: the symbol for which the date time is returned
 * \return Returns the latest date for a given symbol
 */
std::string HistoricCSVDataHandler::getLatestBarDate(std::string symbol)
{
	return latestSymbolsData[symbol].back().date;
}

/*
 * \brief getLatestBarOpen method
 * param[in] symbol: the symbol for which the open is returned
 * \return Returns the latest open for a given symbol
 */
double HistoricCSVDataHandler::getLatestBarOpen(std::string symbol)
{
	return latestSymbolsData[symbol].back().open;
}

/*
 * \brief getLatestBarHigh method
 * param[in] symbol: the symbol for which the high is returned
 * \return Returns the latest high for a given symbol
 */
double HistoricCSVDataHandler::getLatestBarHigh(std::string symbol)
{
	return latestSymbolsData[symbol].back().high;
}

/*
 * \brief getLatestBarLow method
 * param[in] symbol: the symbol for which the low is returned
 * \return Returns the latest low for a given symbol
 */
double HistoricCSVDataHandler::getLatestBarLow(std::string symbol)
{
	return latestSymbolsData[symbol].back().low;
}

/*
 * \brief getLatestBarClose method
 * param[in] symbol: the symbol for which the close is returned
 * \return Returns the latest close for a given symbol
 */
double HistoricCSVDataHandler::getLatestBarClose(std::string symbol)
{
	return latestSymbolsData[symbol].back().close;
}

/*
 * \brief getLatestBarVolume method
 * param[in] symbol: the symbol for which the volume is returned
 * \return Returns the latest volume for a given symbol
 */
long long HistoricCSVDataHandler::getLatestBarVolume(std::string symbol)
{
	return latestSymbolsData[symbol].back().volume;
}

/*
 * \brief getLatestBarAjdClose method
 * param[in] symbol: the symbol for which the adjusted close is returned
 * \return Returns the latest adjusted close for a given symbol
 */
double HistoricCSVDataHandler::getLatestBarAjdClose(std::string symbol)
{
	return latestSymbolsData[symbol].back().adjClose;
}

/*
 * \brief getSymbols method
 * \return Returns a vector of symbols
 */
std::vector<std::string> HistoricCSVDataHandler::getSymbols()
{
	return symbolsVector;
}
