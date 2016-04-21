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
	// �������� � ���, ����� ��� ��� � ��������� �����������
	//struct Params
	//{
		int R = 70;		///cylinder radius
		
		int Nd = 6;     /// Number section(layer) sections
		double PI = 180; /// radian 
		//double P;
		//double p_x = 0;
		//double p_y = 0;
		int n = 6; // ���-�� �������
		int m = 3; //���-�� ��������
	//};
	//Params parameter;
	
	int vlen;
	double p_x[Ns];
	double p_y[Ns];

	// Create grid - section of a cilynder associted to a minutia (xm,ym,teta)
	// ������ ������, ����� ����� ��� � private
	//void CreateSectionOfCylinder(int xm, int ym, double teta);
};
/*
CreateCylinder::CreateCylinder()
{
}

CreateCylinder::~CreateCylinder()
{
}*/