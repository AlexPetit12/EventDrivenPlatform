/**
 * \file DataHandler.h
 * \brief DataHandler class interface
 * \date 2015-06-26
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include <string>
#include <vector>

#include "Bar.h"
#include "MarketEvent.h"

class DataHandler
{
public:
	DataHandler();

	//virtual ~DataHandler();

	//virtual Bar getNewBar(std::string symbol) = 0;

	//virtual Bar getLatestBar(std::string symbol) = 0;
	//virtual std::vector<Bar> getLatestBars(std::string symbol, long long N = 1) = 0;

	//virtual float getLatestBarValue(std::string symbol) = 0;
	//virtual std::vector<float> getLatestBarsValues(std::string symbol, long long N = 1) = 0;

	//virtual std::string getLatestBarDatetime(std::string symbol) = 0;

	//virtual void updateBars() = 0;
};



#endif /* DATAHANDLER_H_ */
