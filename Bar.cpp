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
:Open(0.0), High(0.0), Low(0.0), Close(0.0), AdjClose(0.0), Volume(0)
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
:Date(Date), Open(Open), High(High), Low(Low), Close(Close), AdjClose(AdjClose), Volume(Volume)
{
};
