/*
 * Strategy.h
 *
 *  Created on: Jul 18, 2015
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

#include "SignalEvent.h"


/**
* \class Strategy
* \brief Strategy is a base class
*
*     The Strategy class provides an interface for
*     all subsequent strategy handling objects. Its
*     main goal is to generate Signal objects.
*
*/
class Strategy
{
public:
	virtual ~Strategy();
	virtual void calculateSignals() = 0;
};



#endif /* STRATEGY_H_ */
