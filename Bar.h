/**
 * \file Bar.h
 * \brief Bar class interface
 * \date 2015-06-28
 */

#include <string>

#ifndef BARS_H_
#define BARS_H_

/**
* \class Bar
* \brief Bar is a base class
*
*      Bar handles the creation of bar objects.
*
* Attributs:<br>
*  std::string Date: bar's datetime
*  float Open: bar's opening price
*  float High: bar's high
*  float Low: bar's low
*  float Close: bar's closing price
*  float AdjClose: bar's adjusted close
*  long long volume: bar's volume
*
*/
class Bar
{
public:
	Bar();
	Bar(std::string Date, double Open, double High, double Low, double Close, double AjdClose, long long Volume);

	Bar & operator=(const Bar &rhs);

	std::string date;

	double open;
	double high;
	double low;
	double close;
	double adjClose;

	long long volume;
};



#endif /* BARS_H_ */
