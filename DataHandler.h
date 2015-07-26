/**
 * \file DataHandler.h
 * \brief DataHandler class interface
 * \date 2015-06-26
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include "Bar.h"
#include "MarketEvent.h"

#include <string>
#include <vector>


class DataHandler
{
public:
	DataHandler();

	virtual ~DataHandler();

	virtual Bar getNewBar(std::string symbol) = 0;

	virtual Bar getLatestBar(std::string symbol) = 0;
	virtual std::vector<Bar> getLatestBars(std::string symbol, long long N = 1) = 0;

	virtual std::string getLatestBarDate(std::string symbol) = 0;
	virtual double getLatestBarOpen(std::string symbol) = 0;
	virtual double getLatestBarHigh(std::string symbol) = 0;
	virtual double getLatestBarLow(std::string symbol) = 0;
	virtual double getLatestBarClose(std::string symbol) = 0;
	virtual long long getLatestBarVolume(std::string symbol) = 0;
	virtual double getLatestBarAjdClose(std::string symbol) = 0;

	//virtual std::vector<float> getLatestBarsValues(std::string symbol, long long N = 1) = 0;

	virtual void updateBars() = 0;
	virtual std::vector<std::string> getSymbols() = 0;
};



#endif /* DATAHANDLER_H_ */
