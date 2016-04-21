///@File: CreateCylinder.cpp
///@Brief: Contains implementation of LaplacianEdgeDetector class
///@Author: Kuksova Svetlana
///@Date: 17 April 2016

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include "CreateCylinder.h"

///////////////////////////////////////////////////////////////////////////////
void CreateCylinder::Read()
{
	std::ifstream F;
	D = new double*[n];
	F.open("1_1.txt", std::ios::in);
	// проверка на открытие файла
	if (F)
	{
		for (int i = 0; i < n; i++)
		{
			D[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				F >> D[i][j];
			}
		}
		F.close();
	}
	else std::cout << "File invalid" << std::endl;

	SetCoord(D[0][0], D[0][1], D[0][2]);
	/*for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++)
	std::cout << D[i][j] << "  ";
	std::cout << std::endl;
	}*/
}

///////////////////////////////////////////////////////////////////////////////
void CreateCylinder::SetCoord(int coor_xm, int coor_ym, double coor_teta)
{
	xm = coor_xm;
	ym = coor_ym;
	teta = coor_teta;

	std::cout << xm << " " << ym << " " << teta<<" 1"<<std::endl;

	//std::cout << D[0][0] << " " << D[0][1] << " " << D[0][2] << std::endl;
	CreateSectionOfCylinder(xm, ym, teta);
}

///////////////////////////////////////////////////////////////////////////////
void CreateCylinder::CreateSectionOfCylinder(int xm, int ym, double teta)
{
	int DeltaS = 2 * R / Ns;
	int DeltaD = 2 * PI / Nd;
	double p_x[Ns];
	double p_y[Ns];

	//std::cout << xm + DeltaS*(cos(teta)*(0 - (Ns + 1) / 2) + sin(teta)*(0 - (Ns + 1) / 2)) << " " << std::endl;
	std::cout << std::endl;
	for (int i = 0; i <= Ns - 1; i++)
	{
		for (int j = 0; i < Ns - 1; i++)
		{
			p_x[i] = xm + DeltaS*(cos(teta)*(i - (Ns + 1) / 2) + sin(teta)*(j - (Ns + 1) / 2));
			p_y[i] = ym + DeltaS*(-sin(teta)*(i - (Ns + 1) / 2) + cos(teta)*(j - (Ns + 1) / 2));
		}
		//std::cout << p_x[i] << " " << std::endl;
	}

	for (int i = 0; i <= Ns; i++)
		std::cout << p_x[i] << " " << p_y[i] << std::endl; //" "<<*p_y << std::endl;
	//return p_x;
}