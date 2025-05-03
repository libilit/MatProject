#include "SquareMat.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

namespace matrix {
    SquareMat::SquareMat(int n)  {
        if (n <= 0) {
            throw std::invalid_argument("Matrix size must be positive");
        }
        size = n;
        mat = new double*[size];
        for (int i = 0; i < size; i++){
            mat [i] = new double[size];
            for (int j = 0; j < size; j++){
                mat [i][j] = 0;
            }
        }
    }
    SquareMat::SquareMat(const SquareMat& other) {
        size = other.size;
        mat = new double*[size];
        for (int i = 0; i < size; ++i) {
            mat[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
    SquareMat& SquareMat::operator= (const SquareMat& other){
        if (this == &other) {
            return *this;  
        }
        if (this != &other) {
            for (int i = 0; i < size; ++i) {
                delete[] mat[i];
            }
            delete[] mat;

            size = other.size;
            mat = new double*[size];
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
        return *this;
    }
    SquareMat::~SquareMat() {
        for (int i = 0; i < size; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
int SquareMat::getSize() const {
    return size;
}

    SquareMat SquareMat::operator+(const SquareMat& other) const{
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
    SquareMat SquareMat::operator-(const SquareMat& other) const{
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;

    }
    SquareMat SquareMat::operator-() const{
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = -mat[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat& other) const{
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match");
        }
    
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < size; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
    
        return result;

    }
    SquareMat SquareMat::operator*(double scalar) const {
    if (size == 0) {
        throw std::invalid_argument("Cannot multiply scalar with empty matrix");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat[i][j] * scalar;
        }
    }
    return result;
}
    SquareMat operator*(double scalar, const SquareMat& other) {
    return other * scalar; 
}
    SquareMat SquareMat::operator%(const SquareMat& other) const{
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] * other.mat[i][j];
            }
        }
        return result;
    }
    SquareMat SquareMat::operator%(int scalar) const{
        if (scalar == 0) {
            throw std::invalid_argument("Cannot perform modulo by zero");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = static_cast<int>(mat[i][j]) % scalar;
            }
        }
        return result;
    }
    SquareMat SquareMat::operator/(double scalar) const{
        if (scalar == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] / scalar;
            }
        }
        return result;
    }
    SquareMat SquareMat::identity(int size) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be positive for identity matrix");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            result.mat[i][i] = 1.0;
        }
        return result;
    }
    SquareMat SquareMat::operator^(int power) const{
        if (power ==0) {
            return identity(size);
        }
        if (power < 0) {
            throw std::invalid_argument("Negative powers are not supported.");
        }
        SquareMat result = *this; 
        for (int i = 1; i < power; ++i) { 
        result = result * *this;  
        }
    return result;
    }
    SquareMat& SquareMat::operator++(){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                mat[i][j]++;
            }
        }
        return *this;
    }
    SquareMat SquareMat::operator++(int){
        SquareMat temp = *this;
        for (int i = 0; i < size; ++i) {
             for (int j = 0; j < size; ++j) {
                mat[i][j]++;
        }
        }
        return temp;
    }
    SquareMat& SquareMat::operator--(){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                mat[i][j]--;
            }
        }
        return *this;
    }
    SquareMat SquareMat::operator--(int){
        SquareMat temp = *this;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                mat[i][j]--;
            }
        }
        return temp;
    }
    SquareMat SquareMat::operator~() const{
        if (size == 0) {
            throw std::invalid_argument("Cannot calculate transpose of an empty matrix");
        }
        if (size == 0) {
            throw std::invalid_argument("Cannot calculate Transpose of an empty matrix");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
    double SquareMat::operator!() const{
        if (size == 0) {
            throw std::invalid_argument("Cannot calculate determinant of an empty matrix");
        }
        if (size == 1) {
            return mat[0][0];
        }
        if (size == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }
        double det = 0;
        for (int i = 0; i < size; ++i) {
            SquareMat subMatrix(size - 1);
            for (int j = 1; j < size; ++j) {
                int subCol = 0;
                for (int k = 0; k < size; ++k) {
                    if (k == i) continue;
                    subMatrix.mat[j - 1][subCol++] = mat[j][k];
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * !subMatrix;
        }
        return det;
        }
    SquareMat::Row::Row(double* row, int size) : row(row), size(size) {}
    double& SquareMat::Row::operator[](int col) {
        if (col < 0 || col >= size) {
            throw std::out_of_range("Index out of range");
        }
        return row[col];
    }
    
    const double& SquareMat::Row::operator[](int col) const {
        if (col < 0 || col >= size) {
            throw std::out_of_range("Index out of range");
        }
        return row[col];
    }
SquareMat::Row SquareMat::operator[](int row) {
    if (row < 0 || row >= size) {
        throw std::out_of_range("Row index out of range");
    }
    return Row(mat[row], size);  
}

const SquareMat::Row SquareMat::operator[](int row) const {
    if (row < 0 || row >= size) {
        throw std::out_of_range("Row index out of range");
    }
    return Row(mat[row], size);  
}

        
    double SquareMat::sum() const {
            if (size == 0) {
                throw std::invalid_argument("Cannot calculate sum of an empty matrix");
            }
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    sum += mat[i][j];  
                }
            }
            return sum;
        }
     
    bool SquareMat::operator==(const SquareMat& other)const {
            return sum() == other.sum();    
        }
    bool SquareMat::operator!=(const SquareMat& other)const {
            return !(*this == other);  
        }
    bool SquareMat::operator<(const SquareMat& other)const {
            return sum() < other.sum();  
        }
    bool SquareMat::operator<=(const SquareMat& other)const {
            return sum() <= other.sum();  
        }
    bool SquareMat::operator>(const SquareMat& other)const {
            return sum() > other.sum();  
        }
    bool SquareMat::operator>=(const SquareMat& other) const{
            return sum() >= other.sum();  
        }
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
            if (size != other.size) {
                throw std::invalid_argument("Matrix sizes do not match");
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mat[i][j] += other.mat[i][j];
                }
            }
            return *this;
        }
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match");
        }
            if (size != other.size) {
                throw std::invalid_argument("Matrix sizes do not match");
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mat[i][j] -= other.mat[i][j];
                }
            }
            return *this;
        }
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
            if (size != other.size) {
                throw std::invalid_argument("Matrix sizes do not match");
            }
            SquareMat result(size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    result.mat[i][j] = 0;
                    for (int k = 0; k < size; ++k) {
                        result.mat[i][j] += mat[i][k] * other.mat[k][j];
                    }
                }
            }
            *this = result;
            return *this;
        }
    SquareMat& SquareMat::operator*=(double scalar) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mat[i][j] *= scalar;
                }
            }
            return *this;
        }
    SquareMat& SquareMat::operator%=(const SquareMat& other) {
            if (size != other.size) {
                throw std::invalid_argument("Matrix sizes do not match");
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mat[i][j] *= other.mat[i][j];
                }
            }
            return *this;
        }        
    SquareMat& SquareMat::operator%=(int scalar) {
            if (scalar == 0) {
                throw std::invalid_argument("Cannot perform modulo by zero");
            }
        
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = std::fmod(mat[i][j], scalar);
                }
            }
        
            return *this;
        }
    SquareMat& SquareMat::operator/=(double scalar) {
            if (scalar == 0) {
                throw std::invalid_argument("Cannot divide by zero");
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    mat[i][j] /= scalar;
                }
            }
            return *this;
        } 
        std::ostream& operator<<(std::ostream& os, const SquareMat& matrix) {
            for (int i = 0; i < matrix.size; ++i) {
                for (int j = 0; j < matrix.size; ++j) {
                    os << matrix.mat[i][j];
                    if (j < matrix.size - 1) os << " "; // הוסף רווח רק אם זה לא הערך האחרון בשורה
                }
                os << std::endl; // מעבר שורה אחרי כל שורה
            }
            return os;
        }
                  
}