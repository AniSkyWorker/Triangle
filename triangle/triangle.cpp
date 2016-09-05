// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class CIncorrectInputError : public runtime_error
{
public:
	CIncorrectInputError() : runtime_error("���� �� ��������� ���� - �����������!") {};
};

class CNonTriangleError: public runtime_error
{
public:
	CNonTriangleError() : runtime_error("�� �����������") {};
};

class CTriangle
{
public:
	CTriangle(int fSideLen, int sSideLen, int tSiedLen)
		: m_fSideLen(fSideLen), m_sSideLen(sSideLen), m_tSideLen(tSiedLen) {};

	string GetType()
	{
		CheckSidesCorrectness();

		return ((m_fSideLen + m_sSideLen + m_tSideLen) / 3.f) == m_fSideLen ? "��������������"
			: ((m_fSideLen == m_sSideLen) || (m_tSideLen == m_fSideLen) || (m_sSideLen == m_tSideLen)) ? "��������������"
			: "��������������";
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
		cout << "Usage: triangle.exe firstSide secondSide ThirdSide";
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
			std::cout << "���� �� ��������� ���� - �����������";
		}
	}
    return 1;
}

