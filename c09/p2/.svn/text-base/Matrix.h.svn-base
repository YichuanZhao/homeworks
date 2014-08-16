#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ostream>
#include <cstring>


template<typename T>
class Matrix{
private:
  int numRows;
  int numColumns;
  std::vector<T>* rows;
public:
  Matrix(){
    numRows = 0;
    numColumns = 0; 
    rows = NULL;
  }
  Matrix(int r, int c) {
    numRows = r;
    numColumns = c;
    rows = new std::vector<T>[r];
    for(int i =0;i<r;i++){
      rows[i].resize(c);    
    }       
  }

  Matrix(const Matrix<T> & rhs){
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = new std::vector<T>[numRows];
    for(int i=0; i<numRows;i++){
      rows[i].resize(numColumns);
      for(int j=0;j<numColumns;j++){
	rows[i][j] = rhs.rows[i][j];      
      }
    }
  }

  ~Matrix() {
    //for(int i=0;i<numRows;i++){
    //  delete rows[i];
    //}
    delete[] rows;
  }

  Matrix<T> &operator=(const Matrix<T> & rhs) {
    if(*this == rhs){
      return *this;
    }
    numRows =rhs.numRows;
    numColumns = rhs.numColumns;
    //
    rows = new std::vector<T>[numRows];
    for(int i=0;i<numRows;i++){
      rows[i].resize(numColumns);
      for(int j=0;j<numColumns;j++){
	rows[i][j] = rhs.rows[i][j];
      }
    }
  
    return *this;
  }

  int getRows() const {
    return numRows;
  }
  int getColumns() const {
    return numColumns;
  }
  std::vector<T> & operator[](int index) const {
    assert(index>=0 && index<numRows);
    return rows[index];
  }

  bool operator==(const Matrix<T> & rhs) const {
    if(numRows == rhs.numRows){
      if(numColumns == rhs.numColumns){
	for(int i=0; i<numRows;i++){
	  for(int j=0;j<numColumns;j++){
	    if((rows[i])[j] != (rhs.rows[i])[j]){
	      return false; 
	      break;	  
	    }
	  }
	}
	return true;
      }
      return false;
    }
    return false;
  }

  Matrix<T> operator+(const Matrix<T> & rhs) const {
    assert((numRows == rhs.numRows)&&(numColumns ==rhs.numColumns));
    /*IntMatrix* answer = new IntMatrix(rhs);
      answer.rows = new IntArray*[numRows];

      for(int i=0; i<numRows;i++){
      answer.rows[i] = new IntArray(numColumns);
      }
    */
    Matrix<T> answer;
    answer.numRows = numRows;
    answer.numColumns = numColumns;
    answer.rows = new std::vector<T>[numRows];
    for(int i=0; i<numRows;i++){
      answer.rows[i].resize(numColumns);
      for(int j=0;j<numColumns;j++){
        answer.rows[i][j] = rows[i][j] + rhs.rows[i][j];
      }
    }
    return answer;

  }

};

template <typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs) { 
  if(rhs.getRows()<=0){
    s<<"[ "<<" ]";
  } 
  else{
    s<<"[ ";
 for(int i=0;i<rhs.getRows();i++){
    s<<"{";
      for(int j=0;j<rhs.getColumns();j++){  
	if(j<rhs.getColumns()-1){      
	  s<<rhs[i][j]<<", ";
	}
	if(j==rhs.getColumns()-1){
	  s<<rhs[i][j];
	}
      }
      if(i<rhs.getRows()-1){
	s<<"}"<<","<<"\n";
      }
    if(i==rhs.getRows()-1){
      s<<"}"<<" ]";
    }
  }
  }
  return s;
}

#endif
