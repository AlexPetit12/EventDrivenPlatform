/*
 * \file FillEvent.cpp
 * \brief FillEvent class source file
 * \date 2015-06-25
 */

#include "FillEvent.h"

#include <cmath>


/*
 * \brief FillEvent empty constructor
 */
FillEvent::FillEvent()
:quantity(0), commission(0.0), fillCost(0.0)
{
};

/*
 * \brief FillEvent constructor with parameters
 * \param[in] timeIndex: the bar-resolution
 * \param[in] symbol: the ticker symbol, for example "AAPL"
 * \param[in] exchange: the exchange where the order was filled
 * \param[in] direction: "BUY" or "SELL"
 * \param[in] quantity: the quantity of underlyings
 * \param[in] fillCost: the holdings value
 * \param[in] commission: the commission (might be sent from the brokerage)
 */
FillEvent::FillEvent(std::string timeIndex, std::string symbol, std::string exchange,
			std::string direction, long quantity, double fillCost, double commission)
:timeIndex(timeIndex), symbol(symbol), exchange(exchange), direction(direction), quantity(quantity), fillCost(fillCost)
{
	this->commission = calculateCommission();
};

/*
 * \brief calculateCommission method
 *
 *     Calculates commission based
 *     on a certain fee structure
 */
double FillEvent::calculateCommission()
{
	double full_cost = 1.3;

	if(this->quantity <= 500)
	{
		full_cost = std::max(1.3, 0.013 * double(this->quantity));
	}
	else
	{
		full_cost = std::max(1.3, 0.008 * double(this->quantity));
	}

	return full_cost;
};
