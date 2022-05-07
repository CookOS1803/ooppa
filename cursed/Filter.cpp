#include "Filter.h"
#include <numeric>

IMEX::IntFilter::IntFilter()
{
	Clear();
}

int IMEX::IntFilter::GetMin() const
{
	return min;
}

int IMEX::IntFilter::GetMax() const
{
	return max;
}

void IMEX::IntFilter::SetMin(int newMin)
{
	min = newMin;
}

void IMEX::IntFilter::SetMax(int newMax)
{
	max = newMax;
}

void IMEX::IntFilter::Clear()
{
	min = std::numeric_limits<int>::min();
	max = std::numeric_limits<int>::max();
}

bool IMEX::IntFilter::operator()(int value) const
{
	return value >= min and value <= max;
}

IMEX::StringFilter::StringFilter()
{
}

auto IMEX::StringFilter::GetSubstring() const -> std::string_view
{
	return substring;
}

void IMEX::StringFilter::SetSubstring(std::string_view s)
{
	substring = s;
}

bool IMEX::StringFilter::operator()(std::string_view value) const
{
	return substring.empty() or value.contains(substring);
}

void IMEX::StringFilter::Clear()
{
	substring.clear();
}

IMEX::EnumFilter::EnumFilter()
{
	Clear();
}

auto IMEX::EnumFilter::GetValue() const -> int
{
	return value;
}

void IMEX::EnumFilter::SetValue(int newValue)
{
	value = newValue;
}

void IMEX::EnumFilter::Clear()
{
	value = std::numeric_limits<int>::min();
}

bool IMEX::EnumFilter::operator()(int check) const
{
	return value == std::numeric_limits<int>::min() or value == check;
}
