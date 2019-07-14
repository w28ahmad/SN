#include <iostream>
#include <string>
#include "trust.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::stoi;

int main(){
	string size;
	cin>> size;
	bool** matrix = new bool* [stoi(size)];

// Creating and printing an adjacency matrix
	matrix = generate_matrix(matrix, stoi(size));
//	cout << " Adjacency Matrix " <<endl;
//	print_matrix(matrix, stoi(size));
//	cout<< "--------------------------------------" <<endl;

// Creating and printing reflexive matrix
	matrix = reflexive_closure(matrix, stoi(size));
//	cout<< " Reflexive Matrix " <<endl;
//	print_matrix(matrix, stoi(size));
//	cout<< "--------------------------------------" <<endl;

// Creating and printing trasitive matrix
//	cout<< "Transitive Matrix " << endl;
	matrix = trasitive_closure(matrix, stoi(size));
//	print_matrix(matrix, stoi(size));
//	cout<< "-------------------------------------" << endl;
	
// Finding the Equivalence Classes
//	cout<< "Equivalence Classes" << endl;
	test_symmetric_closure(matrix, stoi(size));
		
	delete[] matrix;
	return 0;
}

// Find Equivalence Classes
void test_symmetric_closure(bool**& matrix,int size){
	/* This next section of for-loops is going to compare each element in the matrix with all the elements underneath and give a value of 1 or 0 in eq_class matrix
	 * So if row 1 and row 2 are equal in matrix, row 1 in eq_class is going to be all ones
	 * Note that each row is going to be compared with all the rows underneath it so this is not going to be a square matrix
	 */
	int row_size = (size-1)*(size)/2;
	int** eq_class = new int* [row_size] {0};
	int current_row = 0;

	for(int row = 0; row < row_size; row++){
		eq_class[row] = new int[size] {0};
	}


	for(int col =0; col < size; col++){
		current_row = 0;
		for(int row = 0; row < size; row++){
			for(int k = row+1; k < size; k++){
				if(matrix[row][col] == matrix[k][col]){
					eq_class[current_row][col] = 1;
				}
				current_row++;
			}
		}
	}

//  This shows what the eq_matrix looks like
//	print_matrix(eq_class, size, row_size);

/*
 * This next section is going to use the eq_class to find all the rows that are all ones and then find the corresponding id
 */
	current_row = 0;
	int section_count = 0;
	int* already_checked = new int [size] {0};

	for(int section= size -1; section >= 0; section--){
		bool in_checked = true;
		for(int k = 0; k < size; k++){
			if(already_checked[k] == section_count+1){
				in_checked = false;
			}
		}
		if (in_checked){	
			cout<<"{" <<section_count +1;
		}
		for(int row = 0; row < section; row++){
			bool is_eq = true;
			already_checked[section_count] = section_count+1;

			for(int col = 0; col < size; col++){
				if(eq_class[current_row][col]== 0){
					is_eq = false;
				}
			}
			if(is_eq){	
				bool not_in_checked = true;
				for(int i = 0; i<size; i++){
					if(already_checked[i] == section_count+row+2){
						not_in_checked = false;
					}	
				}
				if(not_in_checked){
					cout<< "," <<section_count+row+2 ;	
					already_checked[section_count+row+1] = section_count+row+2;
				}
			}
			current_row++;
		}
		if(in_checked){
			cout<< "}"<<endl;
		}
		section_count++;
	}
	
	delete[] already_checked;
	delete[] eq_class;
}

bool** trasitive_closure(bool**& matrix, int size){
//implementing Warshall's Algorithm
	
	for(int adj = 0; adj < size; adj++){
		for(int row = 0; row < size; row++){
			for(int col = 0; col < size; col++){
				if(matrix[row][col] || (matrix[row][adj] && matrix[adj][col])){
					matrix[row][col] = 1;
				}else{
					matrix[row][col] = 0;
				}
			}
		}
	}	

	return matrix;
}

//Reflexive
bool** reflexive_closure(bool**& matrix, int size){
	
	for (int i = 0; i < size; i++){
		matrix[i][i] = 1;
	}

	return matrix;
}

// function for generating the matrix from the txt file
bool** generate_matrix(bool**& matrix, int size){
	for(int i = 0; i < size; i++){
		matrix[i] = new bool[size];
		for(int j = 0; j < size; j++){
			matrix[i][j] = 0;
		}
	}

	string input;
	string rel;
	for(int i = 0; i < size; i++){
		cin>>input;
		while(1){
			cin>> rel;
			if(stoi(rel) == 0|| stoi(input) == 0){
				break;
			}else{
				matrix[stoi(input)-1][stoi(rel)-1] = 1;
			}
		}
	}
	return matrix;
}

// function for printing the matrix
template <typename type>
void print_matrix(type**& matrix, int size, int row_size){
	int default_row_size = size;
	if(row_size != 0){
		default_row_size = row_size;
	}
	for(int i = 0; i < default_row_size; i++){
		cout<< "| ";
		for(int j=0; j < size; j++){
			cout<< matrix[i][j]<<" ";
		}
		cout<< "|"<<endl;
	}

}
