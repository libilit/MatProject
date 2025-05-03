//Libili445@gmail.com
// A MAIN FUNCTION THAT DEMONSTRATES THE USE OF THE SquareMat CLASS
#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept>
using namespace matrix;

int main (){
    try{
        SquareMat A(3);
        SquareMat B(3);

        A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
        A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
        A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;
        B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
        B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
        B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;

        std::cout << "Matrix A:\n" << A;
        std::cout << "Matrix B:\n" << B;

        SquareMat C = A + B;
        std::cout << "Matrix C (A + B):\n" << C;
        C = A - B;
        std::cout << "Matrix C (A - B):\n" << C;
        C = A * B;
        std::cout << "Matrix C (A * B):\n" << C;
        C = A * 2;
        std::cout << "Matrix C (A * 2):\n" << C;
        C = 2 * A;
        std::cout << "Matrix C (2 * A):\n" << C;
        C = A % B;
        std::cout << "Matrix C (A % B):\n" << C;
        C = A % 2;
        std::cout << "Matrix C (A % 2):\n" << C;
        C = A / 2;
        std::cout << "Matrix C (A / 2):\n" << C;
        C = A ^ 2;
        std::cout << "Matrix C (A ^ 2):\n" << C;

        A++;
        std::cout << "Matrix A after increment (A++):\n" << A;
        ++A;
        std::cout << "Matrix A after increment (++A):\n" << A;
        A--;
        std::cout << "Matrix A after decrement (A--):\n" << A;
        --A;
        std::cout << "Matrix A after decrement (--A):\n" << A;
        
        std::cout << "Transpose of A:\n" << ~A;
        std::cout << "Determinant of A: " << !A << std::endl;

        A += B;
        std::cout << "A += B:\n" << A;

        A -= B;
        std::cout << "A -= B:\n" << A;

        A *= B;
        std::cout << "A *= B:\n" << A;

        A *= 2.0;
        std::cout << "A *= 2:\n" << A;
        A %= B;
        std::cout << "A %= B:\n" << A;
        A %= 5;
        std::cout << "A %= 5:\n" << A;
        A /= 2.0;
        std::cout << "A /= 2:\n" << A;
        std::cout << "A[1][2] = " << A[1][2] << "\n";
        A[1][2] = 42;
        std::cout << "A after setting A[1][2] = 42:\n" << A;

    }
     catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;


 }

