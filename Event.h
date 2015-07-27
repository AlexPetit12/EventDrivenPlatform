/**
 * \file Event.h
 * \brief Event class interface
 * \date 2015-06-24
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <string>

/**
* \class Event
* \brief Event is a base class
*
*     Event is a base which implements an interface
*     for inherited events MarketEvent, SignalEvent,
*     OrderEvent and FillEvent.
*/
class Event
{
public:
	Event();

	const std::string EVENT_TYPE;
};



#endif /* EVENT_H_ */
