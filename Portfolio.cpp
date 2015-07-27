/**
 * \file Portfolio.cpp
 * \brief Portfolio class source file
 * \date 2015-07-22
 */

#include "Portfolio.h"

#include <iostream>


Portfolio::Portfolio(DataHandler& dataHandler, std::queue<Event> events, std::string startDat, double initialCapital)
:dataHandler(dataHandler), eventsQueue(events), symbolsVector(dataHandler.getSymbols()), startDate(startDat), initialCapital(initialCapital)
{
	this->currentPositions = constructPositions();
	this->currentHoldings = constructHoldings();
	this->allPositions.push_back(constructAllPositions());
	this->allHoldings.push_back(constructAllHoldings());
}

std::map<std::string, boost::variant<long long, std::string>> Portfolio::constructAllPositions()
{
	std::map<std::string, boost::variant<long long, std::string>> m;

	for(std::string& symbol : this->symbolsVector)
		m[symbol] = 0;

	m["Datetime"] = this->startDate;

	return m;
}

std::map<std::string, boost::variant<double, std::string>> Portfolio::constructAllHoldings()
{
	std::map<std::string, boost::variant<double, std::string>> m;

	for(std::string& symbol : this->symbolsVector)
		m[symbol] = 0.0;

	m["Datetime"] = this->startDate;
	m["Cash"] = this->initialCapital;
	m["Commission"] = 0.0;
	m["Total"] = this->initialCapital;

	return m;
}

std::map<std::string, long long> Portfolio::constructPositions()
{
	std::map<std::string, long long> m;

	for(std::string& symbol : this->symbolsVector)
		m[symbol] = 0;

	return m;
}

std::map<std::string, double> Portfolio::constructHoldings()
{
	std::map<std::string, double> m;

	for(std::string& symbol : this->symbolsVector)
		m[symbol] = 0.0;

	return m;
}

void Portfolio::updateTimeIndex(Event& event)
{
	// retrieve latest date time
	std::string latestDatetime = this->dataHandler.getLatestBarDate(symbolsVector[0]);

	// update positions
	std::map<std::string, boost::variant<long long, std::string>> positions;

	positions["Datetime"] = latestDatetime;

	for(std::string& symbol : this->symbolsVector)
		positions[symbol] = this->currentPositions[symbol];

	allPositions.push_back(positions);

	// update holdings
	std::map<std::string, boost::variant<double, std::string>> holdings;

	holdings["Datetime"] = latestDatetime;
	holdings["Cash"] = this->currentHoldings["Cash"];
	holdings["Commission"] = this->currentHoldings["Commission"];
	holdings["Total"] = this->currentHoldings["Total"];

	for(std::string& symbol : this->symbolsVector)
	{
		double marketValue = this->currentPositions[symbol] * this->dataHandler.getLatestBarAjdClose(symbol);
		holdings[symbol] = marketValue;
		holdings["Total"] =  boost::get<double>(holdings["Total"]) + marketValue;
	}

	allHoldings.push_back(holdings);
}

void Portfolio::updatePositionsFromFill(FillEvent fill)
{
	double fillDirection = 0.0;

	if(fill.direction == "BUY")
		fillDirection = 1.0;
	else if(fill.direction == "SELL")
		fillDirection = -1.0;

	this->currentPositions[fill.symbol] += fillDirection * fill.quantity;
}

void Portfolio::updateHoldingsFromFill(FillEvent fill)
{
	double fillDirection = 0;

	if(fill.direction == "BUY")
		fillDirection = 1.0;
	else if(fill.direction == "SELL")
		fillDirection = -1.0;

	double fillCost = this->dataHandler.getLatestBarAjdClose(fill.symbol);
	double cost = fillDirection * fillCost * fill.quantity;
	this->currentHoldings[fill.symbol] += cost;
	this->currentHoldings["Commission"] += fill.commission;
	this->currentHoldings["Cash"] -= (cost + fill.commission);
	this->currentHoldings["Total"] -= (cost + fill.commission);
}

void Portfolio::updateFill(FillEvent fill)
{
	updatePositionsFromFill(fill);
	updateHoldingsFromFill(fill);
}

OrderEvent Portfolio::generateNaiveOrder(SignalEvent signal)
{
	OrderEvent O;

	std::string symbol = signal.symbol;
	std::string signalType = signal.signalType;

	int marketQuantity = 100;
	long long currentQuantity = this->currentPositions[symbol];
	std::string orderType = "MKT";

	if(signalType == "LONG" && currentQuantity == 0)
		OrderEvent O(symbol, orderType, "BUY", marketQuantity);
	if(signalType == "SHORT" && currentQuantity == 0)
		OrderEvent O(symbol, signalType, "SELL", marketQuantity);
	if(signalType == "EXIT" && currentQuantity > 0)
		OrderEvent O(symbol, signalType, "SELL", currentQuantity);
	if(signalType == "EXIT" && currentQuantity < 0)
		OrderEvent O(symbol, signalType, "BUY", -1 * currentQuantity);

	return O;
}

void Portfolio::updateSignal(SignalEvent signalEvent)
{
	eventsQueue.push(generateNaiveOrder(signalEvent));
}

void Portfolio::createEquityCurve()
{
	// calculate daily returns and equity curve
	for(unsigned long long i = 1; i < this->allHoldings.size(); i++)
	{
		double dailyReturn = (boost::get<double>(allHoldings[i]["Total"]) - boost::get<double>(allHoldings[i - 1]["Total"])) / boost::get<double>(allHoldings[i]["Total"]);
		this->dailyReturnsVector.push_back(dailyReturn);

		double cumulativeProduct = this->equityCurveVector[i - 1] * (1.0 + dailyReturn);
		this->equityCurveVector.push_back(cumulativeProduct);
	}
}

void Portfolio::outputSummary()
{
	double totalReturn = this->equityCurveVector.back();

}
