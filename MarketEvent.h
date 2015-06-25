/*
 * \file MarketEvent.h
 * \brief MarketEvent class interface
 * \date 2015-06-24
 */

#ifndef MARKETEVENT_H_
#define MARKETEVENT_H_

#include "Event.h"

#include <string>


/**
* \class MarketEvent
* \brief MarketEvent is an inherited class from class Event
*
*     MarketEvent handles the event of receiving
*     a new market update.
*
* Attributs:<br>
* 	const std::string EVENT_TYPE: event type ("MARKET")
*/
class MarketEvent: public Event
{
public:
	MarketEvent();
	const std::string EVENT_TYPE = "MARKET";
};



#endif /* MARKETEVENT_H_ */
