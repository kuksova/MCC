///@File: CreateCylinder.h
///@Brief: Contains definition of CreateCylinder class
///@Author: Kuksova Svetlana
///@Date: 17 April 2015

#pragma once 

const int Ns = 16;    /// Number of cell along the cylinder diameter

class CreateCylinder
{
	
public:

	int xm;
	int ym;
	double teta;
	double **D;
	//CreateCylinder();
	//~CreateCylinder();

	// Read coordinates of minutia from text file.
	void Read();
	void SetCoord(int coor_xm, int coor_ym, double coor_teta);
	void Show()
	{
		std::cout << xm << " " << ym << " " << teta << std::endl;
	}
	void CreateSectionOfCylinder(int xm, int ym, double teta);

private:
	// подумать о том, чтобы это все в структуру конвертнуть
	//struct Params
	//{
		int R = 70;		///cylinder radius
		
		int Nd = 6;     /// Number section(layer) sections
		double PI = 180; /// radian 
		//double P;
		//double p_x = 0;
		//double p_y = 0;
		int n = 6; // кол-во строчек
		int m = 3; //кол-во столбцов
	//};
	//Params parameter;
	
	int vlen;
	double p_x[Ns];
	double p_y[Ns];

	// Create grid - section of a cilynder associted to a minutia (xm,ym,teta)
	// похоже нельзя, чтобы метод был в private
	//void CreateSectionOfCylinder(int xm, int ym, double teta);
};
/*
CreateCylinder::CreateCylinder()
{
}

CreateCylinder::~CreateCylinder()
{
}*/