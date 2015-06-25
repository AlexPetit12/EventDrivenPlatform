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

FillEvent::FillEvent(std::string timeIndex, std::string symbol, std::string exchange,
			std::string direction, long quantity, float fillCost, float commission)
:timeIndex(timeIndex), symbol(symbol), exchange(exchange), direction(direction), quantity(quantity), fillCost(fillCost)
{
	this->commission = calculateCommission();
};

float FillEvent::calculateCommission()
{
	float full_cost = 1.3;

	if(this->quantity <= 500)
	{
		full_cost = std::max(1.3, 0.013 * float(this->quantity));
	}
	else
	{
		full_cost = std::max(1.3, 0.008 * float(this->quantity));
	}

	return full_cost;
};
