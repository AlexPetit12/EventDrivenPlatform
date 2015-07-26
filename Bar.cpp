/*
 * \file Bar.cpp
 * \brief Bar class source file
 * \date 2015-06-28
 */


#include "Bar.h"

/*
 * \brief Bar empty constructor
 */
Bar::Bar()
:date(""), open(0.0), high(0.0), low(0.0), close(0.0), adjClose(0.0), volume(0)
{
};

/*
 * \brief Bar constructor with parameters
 * \param[in] Date: bar's datetime
 * \param[in] Open: bar's opening price
 * \param[in] High: bar's high
 * \param[in] Low: bar's low
 * \param[in] Close: bar's closing price
 * \param[in] AjdClose: bar's adjusted close
 * \param[in] Volume: bar's volume
 */
Bar::Bar(std::string Date, double Open, double High, double Low, double Close, double AdjClose, long long Volume)
:date(Date), open(Open), high(High), low(Low), close(Close), adjClose(AdjClose), volume(Volume)
{
};

Bar& Bar::operator=(const Bar &rhs)
{
	if(this != &rhs)
	{
		this->date = rhs.date;
		this->open = rhs.open;
		this->high = rhs.high;
		this->low = rhs.low;
		this->close = rhs.close;
		this->volume = rhs.volume;
		this->adjClose = rhs.adjClose;
	}

	return *this;
};
