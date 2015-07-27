/*
 * \file OrderEvent.cpp
 * \brief OrderEvent class source file
 * \date 2015-06-24
 */

#include "OrderEvent.h"

#include <iostream>

/*
 * \brief OrderEvent empty constructor
 */
OrderEvent::OrderEvent()
:quantity(0)
{
};

/*
 * \brief OrderEvent constructor with parameters
 * \param[in] symbol: the ticker symbol, for example "AAPl"
 * \param[in] orderType: "MKT" (market) or "LMT" (limit)
 * \param[in] direction: "BUY" or "SELL"
 * \param[in] quantity: the quantity of underlyings
 */
OrderEvent::OrderEvent(std::string symbol, std::string orderType, std::string direction, long long quantity)
:symbol(symbol), orderType(orderType), direction(direction), quantity(quantity)
{
};

/*
 * \brief printOrder which prints informations concerning the order
 */
void OrderEvent::printOrder()
{
	std::cout
			<< "Order: "
			<< "Symbol: " << this->symbol << ", "
			<< "Type: " << this->orderType << ", "
			<< "Direction: " << this->direction << ", "
			<< "Quantity: " << this->quantity << std::endl;
};

