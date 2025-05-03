#pragma once
#include <iostream>
#include <stdexcept>  // נוספה לזריקת השגיאות

namespace matrix {

    class SquareMat {
    private:
        int size;
        double** mat;

        class Row {
        private:
            double* row;
            int size;

        public:
            Row(double* row, int size);
            double& operator[](int col);
            const double& operator[](int col) const;
        };

    public:
        SquareMat(int n);                             
        SquareMat(const SquareMat& other);            
        SquareMat& operator= (const SquareMat& other);
        ~SquareMat();                                  

        int getSize() const;
        static SquareMat identity(int size);
        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;  
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat& other);
        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int scalar) const;  
        SquareMat operator/(double scalar) const;
        SquareMat operator^(int power) const;
        SquareMat& operator++();        
        SquareMat operator++(int);     
        SquareMat& operator--();        
        SquareMat operator--(int);      
        SquareMat operator~() const;    
        double operator!() const;       
        Row operator[](int row);
        const Row operator[](int row) const; 
        double sum() const;
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;

        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);
        SquareMat& operator/=(double scalar);

        friend std::ostream& operator<<(std::ostream& os, const SquareMat& matrix);
    };

}
