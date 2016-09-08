// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class CIncorrectInputError : public runtime_error
{
public:
	CIncorrectInputError() : runtime_error("Ошибка:Одна из введенных длин - некорректна!") {};
};

class CNonTriangleError: public runtime_error
{
public:
	CNonTriangleError() : runtime_error("Не треугольник") {};
};

class CTriangle
{
public:
	CTriangle(int fSideLen, int sSideLen, int tSiedLen)
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

	int m_fSideLen;
	int m_sSideLen;
	int m_tSideLen;
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 4)
	{
		cout << "Формат ввода: triangle.exe firstSide secondSide ThirdSide";
	}
	else
	{
		try
		{
			CTriangle triangle(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));
			std::cout << triangle.GetType();
			return 0;
		}
		catch (const runtime_error & err)
		{
			std::cout << err.what();
		}
		catch (...)
		{
			std::cout << "Ошибка: Одна из введенных длин - некорректна!";
		}
	}
    return 1;
}

