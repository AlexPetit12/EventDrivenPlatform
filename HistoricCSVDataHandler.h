/**
 * \file HistoricCSVDataHandler.h
 * \brief HistoricCSVDataHandler class interface
 * \date 2015-06-28
 */

#ifndef HISTORICCSVDATAHANDLER_H_
#define HISTORICCSVDATAHANDLER_H_

#include "DataHandler.h"
#include "Event.h"

#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <vector>


/**
* \class HistoricCSVDataHandler
* \brief HistoricCSVDataHandler is an inherited class from class DataHandler
*
*     FillEvent manages filled order. It stores the quantity
*     of the instrument, the price and the commission of the
*     trade from the brokerage.
*
* Attributs:<br>
* 	std::queue<Event> events: queue of events
* 	std::string csvDir: path to directory containing csv files
* 	std::vector<std::string> symbolsVector: vector containing symbols
* 	std::map<std::string, std::vector<Bar>> latestSymbolsData: map containing each symbol's data
* 	std::map<std::string, std::ifstream *> fileStreams: map containing each symbol's csv file ifstream
*/
class HistoricCSVDataHandler: public DataHandler
{
public:
	HistoricCSVDataHandler(std::queue<Event> events, std::string csvDir,
			std::vector<std::string>& symbolsVector);

	~HistoricCSVDataHandler();

	void openConvertCsvFiles();

	Bar getNewBar(std::string symbol);
	Bar getLatestBar(std::string symbol);
	std::vector<Bar> getLatestBars(std::string, int n = 1);
	void updateBars();
	std::string getLatestBarDatetime(std::string symbol);

	enum csvHeaders {Date, Open, High, Low, Close, Volume, AjdClose};

	std::queue<Event> events;
	std::string csvDir;
	std::vector<std::string> symbolsVector;
	std::map<std::string, std::vector<Bar>> latestSymbolsData;
	std::map<std::string, std::ifstream *> fileStreams;

	bool continueBacktest;

	long long barIndex;
};



#endif /* HISTORICCSVDATAHANDLER_H_ */
