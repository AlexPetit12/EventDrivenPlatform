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
* 	const std::string EVENT_TYPE: event type ("MARKET")
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
