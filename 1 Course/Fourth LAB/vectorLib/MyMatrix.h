#pragma once
#include "MyVector.h"

template <class ClassName>
class MyMatrix :public MyVector<ClassName>{
protected:
		ClassName **ArrayMatrix;
		int ArraySize_x = 3;
		int ArraySize_y = 3;
public:
		//Конструкторы
		MyMatrix() {
			ArrayMatrix = new ClassName*[ArraySize_x];
			for (int i = 0; i < ArraySize_x; i++) {
				ArrayMatrix[i] = new ClassName[ArraySize_y];
			}
			for (int i = 0; i < ArraySize_x; i++){
				for (int j = 0; j < ArraySize_y; j++){
					ArrayMatrix[i][j]=0;
				}
			}
		}
		MyMatrix(int x,int y){
			ArraySize_x=x;
			ArraySize_y=y;
			ArrayMatrix = new ClassName*[ArraySize_x];
			for (int i = 0; i < ArraySize_x; i++) {
				ArrayMatrix[i] = new ClassName[ArraySize_y];
			}
			for (int i = 0; i < ArraySize_x; i++){
				for (int j = 0; j < ArraySize_y; j++){
					ArrayMatrix[i][j]=0;
				}
			}
		}
		MyMatrix(const MyMatrix<ClassName> &other){
			ArrayMatrix = new  ClassName*[other.ArraySize_x];
			for (int i = 0; i < other.ArraySize_x; i++) {
				ArrayMatrix[i] = new ClassName[other.ArraySize_y];
			}
			for (int i = 0; i < other.ArraySize_x; i++){
				for (int j = 0; j < other.ArraySize_y; j++){
					ArrayMatrix[i][j]=other.ArrayMatrix[i][j];
				}
			}
		}
		~MyMatrix(){
			for (int i = 0; i < ArraySize_x; i++) {
				delete [] ArrayMatrix[i];
			}
			delete [] ArrayMatrix;
		}

		//Операторы
		auto operator[](const int index){
			return ArrayMatrix[index];
		};
		MyMatrix& operator = (MyMatrix<ClassName> other) {
				for (int i = 0; i < ArraySize_x; i++) {
					for (int j = 0; j < ArraySize_y; j++) {
						ArrayMatrix[i][j] = other.ArrayMatrix[i][j];
					}
				}
				return *this;
			};
		MyMatrix operator+(MyMatrix<ClassName>& other){
			if ((ArraySize_x == other.ArraySize_x) && (ArraySize_y == other.ArraySize_y)) {
				MyMatrix<ClassName> temp(ArraySize_x, ArraySize_y);
				for (int i = 0; i < ArraySize_x; i++) {
					for (int j = 0; j < ArraySize_y; j++) {
						temp.ArrayMatrix[i][j] = ArrayMatrix[i][j] + other.ArrayMatrix[i][j];
					}
				}
				return temp;
			}else{
				std::cout<<"The number of rows does not match the number of columns in the matrices. Check the matrices."<<std::endl;
				abort();
			}
		};
		MyMatrix operator-(MyMatrix<ClassName>& other){
			if ((ArraySize_x == other.ArraySize_x) && (ArraySize_y == other.ArraySize_y)) {
				MyMatrix<ClassName> temp(ArraySize_x, ArraySize_y);
				for (int i = 0; i < ArraySize_x; i++) {
					for (int j = 0; j < ArraySize_y; j++) {
						temp.ArrayMatrix[i][j] = ArrayMatrix[i][j] - other.ArrayMatrix[i][j];
					}
				}
				return temp;
			}else{
				std::cout<<"The number of rows does not match the number of columns in the matrices. Check the matrices."<<std::endl;
				abort();
			}
		};
		MyMatrix operator*(MyMatrix<ClassName>& other){
			if(ArraySize_y==other.ArraySize_x) {
				MyMatrix<ClassName> temp(ArraySize_x, other.ArraySize_y);
				for (int i = 0; i < ArraySize_x; i++) {
					for (int j = 0; j < other.ArraySize_x; j++) {
						for (int k = 0; k < ArraySize_y; k++) {
							temp.ArrayMatrix[i][j] += ArrayMatrix[i][k] * other.ArrayMatrix[k][j];
						}
					}
				}
				return temp;
			}
			else{
				std::cout<<"The number of rows does not match the number of columns in the matrices. Check the matrices."<<std::endl;
				abort();
			}
		};

		MyMatrix operator*(MyVector<ClassName>& other){
			if(ArraySize_y==other.GetSize()) {
				MyMatrix<ClassName> temp(other.GetSize(),1);
				for (int i = 0; i < temp.ArraySize_x; i++) {
					for (int j = 0; j < 1; j++) {
						for (int k = 0; k < other.GetSize(); k++) {
							temp.ArrayMatrix[i][j] += ArrayMatrix[i][k] * other.GetArrayVector(k);
						}
					}
				}
				std::cout<<temp<<std::endl;
				return temp;
			}
			else{
				std::cout<<"The number of rows does not match the number of columns in the matrices. Check the matrices."<<std::endl;
				abort();
			}
		};





		friend std::ostream& operator<< (std::ostream& os, MyMatrix<ClassName> &Input){
			for( int i=0; i<Input.ArraySize_x;i++){
				for( int j=0; j<Input.ArraySize_y;j++) {
					os << Input.ArrayMatrix[i][j]<<" ";
				}
				os<<std::endl;
			}
			return os;
		};
		friend std::istream& operator>>(std::istream &in, MyMatrix<ClassName>& Output){
			for( int i=0; i<Output.ArraySize_x;i++){
				for( int j=0; j<Output.ArraySize_y;j++) {
					in >> Output.ArrayMatrix[i][j];
				}
			}
			return in;
		};

};
template <class ClassName>
bool operator==(MyMatrix<ClassName> &First,MyMatrix<ClassName> &Second){
	if((First.ArraySize_x!=Second.ArraySize_x) || (First.ArraySize_y!=Second.ArraySize_y)){
		return false;
	}
	for( int i=0;i<First.ArraySize_x;i++){
		for( int j=0;j<First.ArraySize_y;j++) {
			if (First.ArrayMatrix[i][j] != Second.ArrayMatrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}
template <class ClassName>
bool operator!=(MyMatrix<ClassName> &First,MyMatrix<ClassName> &Second){
	return not(First==Second);
}