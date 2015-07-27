/*
 * Tools.cpp
 * Created on: Jul 26, 2015
 */

#include "Tools.h"

#include <algorithm>
#include <cmath>


double createSharpRatio(std::vector<double>& dailyReturnsVector, long long periods)
{
	double sum = std::accumulate(dailyReturnsVector.begin(), dailyReturnsVector.end(), 0.0);
	double mean = sum / dailyReturnsVector.size();
	double squaredSum = std::inner_product(dailyReturnsVector.begin(), dailyReturnsVector.end(), dailyReturnsVector.begin(), 0.0);
	double standardDev = std::sqrt(squaredSum / dailyReturnsVector.size() - mean * mean);

	return std::sqrt(periods) * (mean / standardDev);
}


