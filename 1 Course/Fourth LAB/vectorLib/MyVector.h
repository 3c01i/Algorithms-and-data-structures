#pragma once

template <class ClassName>
class MyVector{
protected:
		ClassName* ArrayVector;
		int ArraySize = 3;
public:
		ClassName GetArrayVector(int index){
			return ArrayVector[index];
		}
		int GetSize(){
			return ArraySize;
		}
		//Конструкторы
		MyVector(){
			ArrayVector = new ClassName[ArraySize];
			for( int i=0; i<ArraySize; i++){
				ArrayVector[i]=0;
			}
		}
		MyVector(int Size){
			ArraySize=Size;
			ArrayVector = new ClassName[ArraySize];
			for( int i=0; i<ArraySize; i++){
				ArrayVector[i]=0;
			}
		}
		MyVector(const std::initializer_list<ClassName> &list):MyVector(list.size()){
			int count = 0;
			for (auto &element : list)
			{
				ArrayVector[count] = element;
				++count;
			}
		}
		MyVector(const MyVector<ClassName> &other){
			ArraySize=other.ArraySize;
			ArrayVector = new  ClassName[ArraySize];
			for( int i=0;i<ArraySize;i++){
				ArrayVector[i]=other.ArrayVector[i];
			}
		}
		~MyVector(){
				delete [] ArrayVector;
		}

		//Операторы
		int& operator[](const int index){
			return ArrayVector[index];
		};
		MyVector operator=(MyVector<ClassName> other){
			if (ArraySize==other.ArraySize) {
				for (int i = 0; i < ArraySize; i++) {
					ArrayVector[i] = other.ArrayVector[i];
				}
				return *this;
			} else {
				std::cout<<"The number of elements is not correct. Check the vector."<<std::endl;
				abort();
			}
		};
		MyVector operator+(MyVector<ClassName> other){
			if (ArraySize==other.ArraySize) {
				MyVector<ClassName> temp(ArraySize);
				for (int i = 0; i < ArraySize; i++) {
					temp.ArrayVector[i] = ArrayVector[i] + other.ArrayVector[i];
				}
				return temp;
			}else{
				std::cout<<"The number of elements is not correct. Check the vector."<<std::endl;
				abort();
			}
		};
		MyVector operator-(MyVector<ClassName> other){
			if (ArraySize==other.ArraySize) {
				MyVector<ClassName> temp(ArraySize);
				for (int i = 0; i < ArraySize; i++) {
					temp.ArrayVector[i] = ArrayVector[i] - other.ArrayVector[i];
				}
				return temp;
			} else {
				std::cout<<"The number of elements is not correct. Check the vector."<<std::endl;
				abort();
			}
		};
		MyVector operator*(MyVector<ClassName> other){
			if (ArraySize==other.ArraySize) {
				MyVector<ClassName> temp(ArraySize);
				for (int i = 0; i < ArraySize; i++) {
					temp.ArrayVector[i] = ArrayVector[i] * other.ArrayVector[i];
				}
				return temp;
			} else {
				std::cout<<"The number of elements is not correct. Check the vector."<<std::endl;
				abort();
			}
		};
		MyVector operator/(MyVector<ClassName> other){
			if (ArraySize==other.ArraySize) {
				MyVector<ClassName> temp(ArraySize);
				for (int i = 0; i < ArraySize; i++) {
					temp.ArrayVector[i] = (ArrayVector[i])/(other.ArrayVector[i]);
				}
				return temp;
			} else {
				std::cout<<"The number of elements is not correct. Check the vector."<<std::endl;
				abort();
			}
		};

		friend std::ostream& operator<< (std::ostream& os, MyVector<ClassName> &Input){
			for( int i=0; i<Input.ArraySize;i++){
				os<<Input.ArrayVector[i]<<std::endl;
			}
			return os;
		};

		friend std::istream& operator>>(std::istream &in, MyVector<ClassName>& Output){
			for( int i=0; i<Output.ArraySize;i++){
				in>>Output.ArrayVector[i];
			}
			return in;
		};
};
template <class ClassName>
bool operator==(MyVector<ClassName> &First,MyVector<ClassName> &Second){
	if(First.ArraySize!=Second.ArraySize){
		return false;
	}
	for( int i=0;i<First.ArraySize;i++){
		if(First.ArrayVector[i]!=Second.ArrayVector[i]){
			return false;
		}
	}
	return true;
}
template <class ClassName>
bool operator!=(MyVector<ClassName> &First,MyVector<ClassName> &Second){
	return not(First==Second);
}