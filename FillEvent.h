/*
 * \file FillEvent.cpp
 * \brief FillEvent class interface
 * \date 2015-06-25
 */

#ifndef FILLEVENT_H_
#define FILLEVENT_H_

#include "Event.h"

#include <string>


/**
* \class FillEvent
* \brief FillEvent is an inherited class from class Event
*
*     FillEvent manages filled order. It stores the quantity
*     of the instrument, the price and the commission of the
*     trade from the brokerage.
*
* Attributs:<br>
* 	const std::string EVENT_TYPE: event type ("FILL")
* 	std::string timeIndex: the bar-resolution
* 	std::string symbol: ticker symbol
* 	std::string exchange: the exchange where the order was filled
* 	std::string direction: "BUY" or "SELL"
* 	long quantity: quantity of underlyings
* 	float commission: the commission (might be sent from the brokerage)
* 	float fillCost: the holdings value
*/
class FillEvent: public Event
{
public:
	FillEvent();
	FillEvent(std::string timeIndex, std::string symbol, std::string exchange,
			std::string direction, long quantity, float fillCost, float commission);

	float calculateCommission();

	const std::string EVENT_TYPE = "FILL";

	std::string timeIndex;
	std::string symbol;
	std::string exchange;
	std::string direction;

	long quantity;

	float commission;
	float fillCost;
};



#endif /* FILLEVENT_H_ */
