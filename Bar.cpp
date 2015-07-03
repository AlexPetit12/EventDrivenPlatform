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
Bar::Bar(std::string Date, float Open, float High, float Low, float Close, float AdjClose, long long Volume)
:date(Date), open(Open), high(High), low(Low), close(Close), adjClose(AdjClose), volume(Volume)
{
};
