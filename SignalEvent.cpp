/*
 * \file SignalEvent.cpp
 * \brief SignalEvent class source file
 * \date 2015-06-24
 */

#include "SignalEvent.h"

/*
 * \brief SignalEvent empty constructor
 */
SignalEvent::SignalEvent()
:signalStrength(0.0)
{
};

/*
 * \brief SignalEvent constructor with parameters
 * \param[in] strategyId: the identifier for the strategy that generated the signal
 * \param[in] symbol: the ticker symbol, for example "AAPL"
 * \param[in] dateTime: the time at which the signal was generated
 * \param[in] signalType: "LONG" or "SHORT"
 * \param[in] signalStrength: an adjustment factor
 */
SignalEvent::SignalEvent(std::string strategyId, std::string symbol, std::string dateTime,
		std::string signalType, float signalStrength)
:strategyId(strategyId), symbol(symbol), dateTime(dateTime), signalType(signalType), signalStrength(signalStrength)
{
};
