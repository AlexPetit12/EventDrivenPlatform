/**
 * \file Portfolio.h
 * \brief Portfolio class interface
 * \date 2015-07-22
 */

#ifndef PORTFOLIO_H_
#define PORTFOLIO_H_

#include "DataHandler.h"
#include "Event.h"
#include "FillEvent.h"
#include "HistoricCSVDataHandler.h"
#include "OrderEvent.h"
#include "SignalEvent.h"
#include <boost/variant.hpp>

#include <queue>


class Portfolio
{
public:
	Portfolio(DataHandler& dataHandler, std::queue<Event> events, std::string startDat, double initalCapital = 100000.0);

	std::map<std::string, boost::variant<long long, std::string>> constructAllPositions();
	std::map<std::string, boost::variant<double, std::string>> constructAllHoldings();

	std::map<std::string, long long> constructPositions();
	std::map<std::string, double> constructHoldings();

	OrderEvent generateNaiveOrder(SignalEvent signal);

	void updateTimeIndex(Event& event);
	void updatePositionsFromFill(FillEvent fill);
	void updateHoldingsFromFill(FillEvent fill);
	void updateFill(FillEvent fill);
	void updateSignal(SignalEvent signalEvent);
	void createEquityCurve();
	void outputSummary();

	DataHandler& dataHandler;
	std::queue<Event> eventsQueue;
	std::vector<std::string> symbolsVector;
	std::string startDate;
	double initialCapital;

	std::vector<std::map<std::string, boost::variant<long long, std::string>>> allPositions;
	std::vector<std::map<std::string, boost::variant<double, std::string>>> allHoldings;

	std::map<std::string, long long> currentPositions;
	std::map<std::string, double> currentHoldings;

	std::vector<double> dailyReturnsVector;
	std::vector<double> equityCurveVector = {1.0};

};



#endif /* PORTFOLIO_H_ */
