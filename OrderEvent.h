/**
 * \file OrderEvent.h
 * \brief OrderEvent class interface
 * \date 2015-06-24
 */

#include "Event.h"

#include <string>

#ifndef ORDEREVENT_H_
#define ORDEREVENT_H_

/**
* \class OrderEvent
* \brief OrderEvent is an inherited class from class Event
*
*     OrderEvent handles the event of sending an Order to an execution system.
*
* Attributs:<br>
* 	const std::string EVENT_TYPE: event type ("ORDER")
* 	std::string symbol: ticker symbol
* 	std::string orderType: "MKT" (market) or "LMT" (limit)
* 	std::string direction: "BUY" or "SELL"
* 	long quantity: quantity of underlyings
*/
class OrderEvent: public Event
{
public:
	OrderEvent();
	OrderEvent(std::string symbol, std::string orderType, std::string direction, long quantity);

	void printOrder();

	const std::string EVENT_TYPE = "ORDER";

	std::string symbol;
	std::string orderType;
	std::string direction;

	long quantity;
};



#endif /* ORDEREVENT_H_ */
