///@File: main.cpp ( MinutiaCylinderCode)
///@Brief: Buildig grid of section of a cylinder
///@Author: Kuksova Svetlana
///@Date: 17 April 2016

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "CreateCylinder.h"

int main(int argc, char* argv[])
{
	CreateCylinder vlen, vlen1;
	//D = new double*[n];
	vlen.Read();
	vlen.Show();
	
	
	/*CreateCylinder x; // объявление объекта
	CreateCylinder y;
	CreateCylinder teta;
	int xm1, ym1;
	double tetam1;
	xm1 = x.xm;
	ym1 = y.ym;
	tetam1 = teta.teta;*/
	//vlen1.SetCoord();
	
	//vlen.CreateSectionOfCylinder()

	//vlen1.CreateSectionOfCylinder(xm, ym, tetam);
	/*for (int i = 0; i < Ns - 1; i++){
		std::cout << p_x[i] << "  ";
		std::cout << p_y[i] << "  " << std::endl;
	}*/
	system("pause");
	return 0;

}

