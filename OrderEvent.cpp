/*
 * \file OrderEvent.cpp
 * \brief OrderEvent class source file
 * \date 2015-06-24
 */

#include "OrderEvent.h"

#include <iostream>

OrderEvent::OrderEvent()
{
	quantity = 0;
};

OrderEvent::OrderEvent(std::string symbol, std::string orderType, std::string direction, long quantity)
:symbol(symbol), orderType(orderType), direction(direction), quantity(quantity)
{
};

void OrderEvent::printOrder()
{
	std::cout
			<< "Order: "
			<< "Symbol: " << this->symbol << ", "
			<< "Type: " << this->orderType << ", "
			<< "Direction: " << this->direction << ", "
			<< "Quantity: " << this->quantity << std::endl;
};

