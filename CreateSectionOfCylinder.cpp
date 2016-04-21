///@File: CreateSectionOfCylinder.cpp
///@Brief: Contains implementation of LaplacianEdgeDetector class
///@Author: Kuksova Svetlana
///@Date: 14 April 2016



#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "CreateCylinder.h"

///////////////////////////////////////////////////////////////////////////////
void CreateCylinder::CreateSectionOfCylinder(int xm, int ym, double teta)
{
	int DeltaS = 2 * R / Ns;
	int DeltaD = 2 * PI / Nd;
	//double p_x = 0;		/// center the cells
	//double p_y = 0;		/// center the cells
	//CreateCylinder p_x;
	//CreateCylinder p_y;
	std::vector<double> P(Ns*Ns);

	for (size_t i = 0; i <= Ns-1; i++)
	{
		for (size_t j = 0; i < Ns - 1; i++)
		{
			p_x = xm + DeltaS*(cos(teta)*(i - (Ns + 1) / 2) + (sin(teta)*(j - (Ns + 1) / 2)));
			p_y = ym + DeltaS*(-sin(teta)*(i - (Ns + 1) / 2) + (cos(teta)*(j - (Ns + 1) / 2)));
			P.push_back(p_x);
			P.push_back(p_y);
		}
	}
	//std::cout << p_x << ' '<< p_y ;
	while (! P.empty() )
	{
		std::cout << P.back() << ' ';
	}
	
	return p_x;
}