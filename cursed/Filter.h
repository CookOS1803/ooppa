#pragma once
#include <string>

namespace IMEX
{
	class IntFilter
	{
		int min;
		int max;

	public:

		IntFilter();

		int GetMin() const;
		int GetMax() const;

		void SetMin(int newMin);
		void SetMax(int newMax);

		void Clear();

		bool operator()(int value) const;
	};

	class StringFilter
	{
		std::string substring;

	public:

		StringFilter();

		auto GetSubstring() const -> std::string_view;

		void SetSubstring(std::string_view s);

		void Clear();

		bool operator()(std::string_view value) const;
	};

	class EnumFilter
	{
		int value;

	public:

		EnumFilter();

		auto GetValue() const -> int;

		void SetValue(int newValue);

		void Clear();

		bool operator()(int check) const;
	};
}

