#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

double **D;
std::vector<int> T_x;
std::vector<int> T_y;
std::vector<double> T_z;
//double *p_x;
//double *p_y;

const int n = 43; // кол-во строчек
int m = 3; //кол-во столбцов

int R = 70;		///cylinder radius
const int Ns = 16;    /// Number of cell along the cylinder diameter
const int Nd = 6;     /// Number section(layer) sections
double PI = 180; /// radian 
double sigma_s = 58 / 3; // взятое значение 28/3 слишком мало, поэтому берем 58/3
double sigma_d = 2 * PI / 9;

double p_x[Ns];
double p_y[Ns];

void Read()
{
	std::ifstream F;

	int a; int b; double c;
	//char ch;
	D = new double*[n];
	F.open("1_1.txt", std::ios::in);
	// проверка на открытие файла
	if (F)
	{
		//while (!F.eof())
		//{
			//F >> a;
			for (size_t i = 0; i < n; i++)
			{
				D[i] = new double[m];
				for (size_t j = 0; j < m; j++)
				{
						F >> D[i][j];				
				}

			//}
			//std::cout << a << " ";
		}
		F.close();
	}
	else std::cout << "File invalid" << std::endl;


}

void CreateSection(double xm, double ym, double teta)
{
//	double **S;
	
	
	//double p_x = 0;
	//double p_y = 0;
	int DeltaS = 2 * R / Ns;
	int DeltaD = 2 * PI / Nd;
	
	//p_y = new double[Ns];
//	S = new double*[Ns];
	int k = 0;

	//std::cout << xm + DeltaS*(cos(teta)*(0 - (Ns + 1) / 2) + sin(teta)*(0 - (Ns + 1) / 2)) << " " << std::endl;
	std::cout << std::endl;
	for (int i = 0; i <= Ns-1; i++)
	{
		
		//S[i] = new double[Ns];
		for (int j = 0; i < Ns-1; i++)
		{
			p_x[i] = xm + DeltaS*(cos(teta)*(i - (Ns + 1) / 2) + sin(teta)*(j - (Ns + 1) / 2));
			p_y[i] = ym + DeltaS*(-sin(teta)*(i - (Ns + 1) / 2) + cos(teta)*(j - (Ns + 1) / 2));
			//S[i][j] = p_x;

			//P[i][j] = p_x;
			//P[i][j] = p_y;
			//std::cout << p_x[i] << " ";
		}
		//std::cout << p_x[i] << " " << std::endl;
	}
	
	//for (int i = 0; i <= Ns; i++)
	//std::cout << p_x[i] << std::endl; //" "<<*p_y << std::endl;
	//return p_x;
}

double EvklidDiss(int xm, int ym, int xt, int yt )
{
	double Du;
	return Du = sqrt((pow(xm - xt,2) + pow(ym - yt, 2)));
}
void NumberNeghb(double p_x, double p_y)
{
	int num = 0;
	double Dis;
	for (int i = 0; i < n; i++)
	{
		//for (int j = 0; j < n; j++)
		//{
			Dis = EvklidDiss(D[i][0], D[i][1], int(p_x), int(p_y));
			//std::cout << Dis << " ";
			if (Dis < 3 * sigma_s)
			{
				num = +1;
				T_x.push_back(D[i][0]);
				T_y.push_back(D[i][1]);
				T_z.push_back(D[i][2]);
			}
		//}

	}
	for (int i = 0; i < T_x.size(); i++) {
		std::cout << T_x[i] << " ";
		
	}
	std::cout << std::endl;
	for (int i = 0; i < T_x.size(); i++) {
		std::cout << T_y[i] << " ";//<< std::endl;
	}
}
/*	T = new double*[num];
	for (int i = 0; i < num; i++)
	{
		T[i] = new double[Ns];
		for (int j = 0; j < num; j++)
		{
			T[i][j] = p_x;
		}
	}
}*/

double CalculateDifference(double teta_m, double teta_t)
{
	double dfi;
	double diff_teta = teta_m - teta_t;
	if (diff_teta<-PI)
		dfi = 2 * PI + m;
	if ((diff_teta>-PI) && (diff_teta < PI))
		dfi = m;
	if (diff_teta >= PI)
		dfi = -2 * PI + m;
	return dfi;
}


double Fun(double x)
{
	
	return 1 / (sigma_d*sqrt(2 * PI))*exp(-x*x / 2 * pow(sigma_d, 2));
}

// вычисление инеграла под Гауссианой? (заменить на cos(x)^2)
// методом Симпсона
double CalculateIntegral(double alfa)
{
	double a, b, eps = 10^(-2);
	double deltaD = 2 * PI / Nd;
	a = alfa + deltaD / 2;
	b = alfa - deltaD / 2;
	double I = eps + 1, I1 = 0;
	for (int N = 2; (N <= 4) || (fabs(I1 - I)>eps); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N);//Шаг интегрирования.
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += Fun(a + h*i);//Значения с нечётными индексами, которые нужно умножить на 4.
			sum2 += Fun(a + h*(i + 1));//Значения с чётными индексами, которые нужно умножить на 2.
		}
		sum = Fun(a) + 4 * sum4 + 2 * sum2 - Fun(b);//Отнимаем значение f(b) так как ранее прибавили его дважды. 
		I = I1;
		I1 = (h / 3)*sum;
	}
	std::cout << I1 << std::endl;
	return I1;
}

void DirectionalContr(int xt, int yt, double teta_m, double teta_t)
{
	double deltaD = 2 * PI / Nd;
	double dfik[Nd];

	for (int k = 0; k < Nd - 1; k++)
	{
		dfik[k] = -PI + (k - 1 / 2)*deltaD;
	}

	double M1;
	double alfa[Nd];
	M1 = CalculateDifference(teta_m, teta_t);
	for (int i = 0; i < Nd; i++)
	{
		alfa[i] = CalculateDifference(dfik[i], M1);
	}

	double C_d_m[Nd];
	for (int i = 0; i < Nd; i++)
	{
		C_d_m[i] = CalculateIntegral(alfa[i]);
		std::cout << C_d_m[i] << std::endl;
	}
	
	
}

int main(int argc, char* argv[])
{

	Read();
	CreateSection(D[0][0], D[0][1], D[0][2]);

	// проверка EvclidDiss
/*	double diss[n];
	// std::cout << D[i][0]<<" "<<D[i][1] << std::endl;
	for (int i = 0; i < n; i++){
		diss[i] = EvklidDiss(D[i][0], D[i][1], int(p_x[1]), int(p_y[1]));
		std::cout << diss[i] << std::endl;
	}
*/	

/*	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			std::cout << D[i][j] << "  ";
		std::cout << std::endl;
	}*/
	//std::cout << D[0][0]<<" "<<D[0][1]<<" "<<D[0][2] << std::endl;
	

	 NumberNeghb(p_x[1], p_y[1]);
	// DirectionalContr(xt, yt, teta_m, teta_t)
	/* for (int i = 0; i < Ns-1; i++){
		 std::cout << p_x[i] << "  ";
		 std::cout << p_y[i] << "  "<<std::endl;
	 }*/
	 delete[] D;
		system("pause");
		return 0;

}


