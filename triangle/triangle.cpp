// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

namespace
{
	void ReplaceDot(string & str)
	{
		replace_if(str.begin(), str.end(), [](char a){ return a == '.'; }, ',');
	}
}

class CIncorrectInputError : public runtime_error
{
public:
	CIncorrectInputError() : runtime_error("Ошибка: Переданы неккоректные аргументы!") {};
};

class CNonTriangleError: public runtime_error
{
public:
	CNonTriangleError() : runtime_error("Не треугольник") {};
};

class CTriangle
{
public:
	CTriangle(float fSideLen, float sSideLen, float tSiedLen)
		: m_fSideLen(fSideLen), m_sSideLen(sSideLen), m_tSideLen(tSiedLen) {};

	string GetType()
	{
		CheckSidesCorrectness();
		auto sum = m_fSideLen + m_sSideLen + m_tSideLen;
		auto sideWithMaxLen = max({ m_fSideLen, m_sSideLen, m_tSideLen });

		if ((sum - sideWithMaxLen) <= sideWithMaxLen)
		{
			throw CNonTriangleError();
		}

		return (m_fSideLen == m_sSideLen) && (m_fSideLen == m_tSideLen) ? "Равносторонний"
			: ((m_fSideLen == m_sSideLen) || (m_tSideLen == m_fSideLen) || (m_sSideLen == m_tSideLen)) ? "Равнобедренный"
			: "Обычный";
	}

private:
	void CheckSidesCorrectness() const
	{
		if (m_fSideLen == 0
			|| m_sSideLen == 0
			|| m_tSideLen == 0)
		{
			throw CNonTriangleError();
		}
		else if (m_fSideLen < 0
			|| m_sSideLen < 0
			|| m_tSideLen < 0)
		{
			throw CIncorrectInputError();
		}
	}

	float m_fSideLen;
	float m_sSideLen;
	float m_tSideLen;
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 4)
	{
		cout << "Формат ввода: triangle.exe длинаПервойСтороны длинаВторойСтороны длинаТретьейСтороны";
	}
	else
	{
		try
		{
			string first = argv[1];
			string second = argv[2];
			string third = argv[3];
			ReplaceDot(first);
			ReplaceDot(second);
			ReplaceDot(third);

			CTriangle triangle(stof(first), stof(second), stof(third));
			std::cout << triangle.GetType();
			return 0;
		}
		catch (const runtime_error & err)
		{
			std::cout << err.what();
		}
		catch (...)
		{
			std::cout << "Ошибка: Переданы неккоректные аргументы!";
		}
	}
    return 1;
}

