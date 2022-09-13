#include <iostream>
#include "/home/qapfuc/Documents/Nizhny-Novgorod-State-University/Fourth LAB/vectorLib/MyMatrix.h"
#include "/home/qapfuc/Documents/Nizhny-Novgorod-State-University/Fourth LAB/vectorLib/MyVector.h"

int main(){
	MyVector<float> b{5,129,76.6};
	MyMatrix<double> y(2,2);
	MyMatrix<float> yy(3,3);
	MyMatrix<double> res(2,1);


	std::cin>>yy;
	std::cout<<yy<<std::endl;
	yy=yy*b;
}