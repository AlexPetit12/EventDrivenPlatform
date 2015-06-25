/*
 * \file SignalEvent.h
 * \brief SignalEvent class interface
 * \author Alexandre Petit
 * \date 2015-06-24
 */

#ifndef SIGNALEVENT_H_
#define SIGNALEVENT_H_

#include "Event.h"

#include <string>


/**
* \class SignalEvent
* \brief SignalEvent is an inherited class from class Event
*
*     SignalEvent handles the event of sending a signal from
*     a Strategy object. It is received by a Portfolio object.
*
* Attributs:<br>
* 	const std::string EVENT_TYPE: event type ("SIGNAL")
* 	std::string strategyId: strategy identifier
* 	std::string symbol: ticker symbol
* 	std::string dateTime: time at which the signal is generated
* 	std::string signalType: signal type "LONG" or "SHORT"
* 	float signalStrength: an adjustment factor
*/
class SignalEvent: public Event
{
public:
	SignalEvent();
	SignalEvent(std::string strategyId, std::string symbol, std::string dateTime,
			std::string signalType, float signalStrength);

	const std::string EVENT_TYPE = "SIGNAL";

	std::string strategyId;
	std::string symbol;
	std::string dateTime;
	std::string signalType;

	float signalStrength;
};




#endif /* SIGNALEVENT_H_ */
