#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <sstream> //I used this library for the last test of the print function.
#include <stdexcept>
namespace matrix {
TEST_CASE ("MATRIX CREATION") {
        CHECK_THROWS_AS(SquareMat(-1), std::invalid_argument);
        SquareMat mat(3);
        CHECK(mat[0][0] == 0);
        CHECK(mat[0][1] == 0);
        CHECK(mat[0][2] == 0);
        CHECK(mat[1][0] == 0);
        CHECK(mat[1][1] == 0);
        CHECK(mat[1][2] == 0);
        CHECK(mat[2][0] == 0);
        CHECK(mat[2][1] == 0);
        CHECK(mat[2][2] == 0);
        CHECK (mat.getSize() == 3);
    }
TEST_CASE("COPY CONSTRUCTOR") {
        SquareMat original(3);
        original[0][0] = 1.0;
        original[1][1] = 2.0;
        original[2][2] = 3.0;

        SUBCASE("Copied matrix has same values") {
            SquareMat copy = original;
    
            CHECK(copy[0][0] == 1.0);
            CHECK(copy[1][1] == 2.0);
            CHECK(copy[2][2] == 3.0);
            CHECK(copy.getSize() == 3);
        }
            SUBCASE("Changing original does not affect copy") {
                SquareMat copy = original;
                original[0][0] = 42.0;
                CHECK(copy[0][0] == 1.0);
                CHECK(original[0][0] == 42.0);
            }
        
}
TEST_CASE("OPERATOR =") {
    
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SUBCASE("M1=M2") {
        SquareMat m2(2);
        m2 = m1;
        CHECK(m2.getSize() == 2);
        CHECK(m2[0][0] == 1);
        CHECK(m2[0][1] == 2);
        CHECK(m2[1][0] == 3);
        CHECK(m2[1][1] == 4);
        m1[0][0] = 9;
        CHECK(m2[0][0] == 1); // לא השתנה
    }

    SUBCASE("M1=M1") {
        m1 = m1;
        CHECK(m1[0][0] == 1);
        CHECK(m1[0][1] == 2);
        CHECK(m1[1][0] == 3);
        CHECK(m1[1][1] == 4);
    }
}
TEST_CASE("OPERATOR +") {
    CHECK_THROWS_AS(SquareMat(1)+SquareMat(2), std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat result = m1 + m2;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 6);
    CHECK(result[0][1] == 8);
    CHECK(result[1][0] == 10);
    CHECK(result[1][1] == 12);
}
TEST_CASE("OPERATOR -") {
    CHECK_THROWS_AS(SquareMat(1)-SquareMat(2), std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat result = m1 - m2;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == -4);
    CHECK(result[0][1] == -4);
    CHECK(result[1][0] == -4);
    CHECK(result[1][1] == -4);
}
TEST_CASE ("OPERATOR (-M)"){
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = -m;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == -1);
    CHECK(result[0][1] == -2);
    CHECK(result[1][0] == -3);
    CHECK(result[1][1] == -4);
}
TEST_CASE("OPERATOR *") {
    CHECK_THROWS_AS(SquareMat(1)*SquareMat(2), std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat result = m1 * m2;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 19);
    CHECK(result[0][1] == 22);
    CHECK(result[1][0] == 43);
    CHECK(result[1][1] == 50);
}
TEST_CASE("OPERATOR * SCALAR") {
    CHECK_THROWS_AS(SquareMat(0)*1, std::invalid_argument);
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat result = m * 2.0;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 6);
    CHECK(result[1][1] == 8);
}
TEST_CASE("SCALAR * OPERATOR") {
    CHECK_THROWS_AS(1*SquareMat(0), std::invalid_argument);
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat result = 2.0 * m;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 6);
    CHECK(result[1][1] == 8);
}
TEST_CASE("OPERATOR %") {
    CHECK_THROWS_AS(SquareMat(1) % SquareMat(2), std::invalid_argument);

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat result = m1 % m2;

    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 1 * 5);  
    CHECK(result[0][1] == 2 * 6);  
    CHECK(result[1][0] == 3 * 7);  
    CHECK(result[1][1] == 4 * 8);  
}
TEST_CASE("OPERATOR % SCALAR") {
    CHECK_THROWS_AS(SquareMat(1)%0, std::invalid_argument);
    SquareMat m(2);
    m[0][0] = 5;
    m[0][1] = 10;
    m[1][0] = 15;
    m[1][1] = 20;

    SquareMat result = m % 3;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 1);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 2);
}
TEST_CASE("OPERATOR / SCALAR") {
    CHECK_THROWS_AS(SquareMat(1)/0, std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 4;
    m1[0][1] = 8;
    m1[1][0] = 12;
    m1[1][1] = 16;
    SquareMat result = m1 / 2;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 6);
    CHECK(result[1][1] == 8);
}
TEST_CASE("I MATRIX") {
    CHECK_THROWS_AS(SquareMat::identity(0), std::invalid_argument);

   SquareMat id= SquareMat::identity (3);
   for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        if (i == j)
            CHECK(id[i][j] == 1);
        else
            CHECK(id[i][j] == 0);
    }
}
}
TEST_CASE("OPERATOR ^") {
    CHECK_THROWS_AS(SquareMat(1)^(-2), std::invalid_argument);
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = m ^ 2;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 7);
    CHECK(result[0][1] == 10);
    CHECK(result[1][0] == 15);
    CHECK(result[1][1] == 22);
}
TEST_CASE("OPERATOR ++") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = m++;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 2);
    CHECK(result[1][0] == 3);
    CHECK(result[1][1] == 4);
    CHECK(m[0][0] == 2);
    CHECK(m[0][1] == 3);
    CHECK(m[1][0] == 4);
    CHECK(m[1][1] == 5);
}
TEST_CASE ("OPERSTOR ++ 2"){
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = ++m;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 3);
    CHECK(result[1][0] == 4);
    CHECK(result[1][1] == 5);
}
TEST_CASE("OPERATOR --") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = m--;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 2);
    CHECK(result[1][0] == 3);
    CHECK(result[1][1] == 4);
    CHECK(m[0][0] == 0);
    CHECK(m[0][1] == 1);
    CHECK(m[1][0] == 2);
    CHECK(m[1][1] == 3);
}
TEST_CASE ("OPERSTOR -- 2"){
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = --m;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 1);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 3);
}
TEST_CASE("OPERATOR ~"){
    CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    SquareMat result = ~m;
    CHECK(result.getSize() == 2);
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 3);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 4);
}
TEST_CASE("OPERATOR !") {
    CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
    SquareMat m1(1);
    m1[0][0] = 5;
    double result1 = !m1;  
    CHECK(result1 == 5.0);
    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[1][0] = 3;
    m2[1][1] = 4;
    double result2 = !m2;  
    CHECK(result2 == -2.0);
    SquareMat m3(3);
    m3[0][0] = 1;
    m3[0][1] = 2;
    m3[0][2] = 3;
    m3[1][0] = 4;
    m3[1][1] = 5;
    m3[1][2] = 6;
    m3[2][0] = 7;
    m3[2][1] = 8;
    m3[2][2] = 9;
    double result3 = !m3; 
    CHECK(result3 == 0.0);
}

TEST_CASE("operator [] ") {
    SquareMat m(2);  
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    CHECK(m[0][0] == 1);
    CHECK(m[0][1] == 2);
    CHECK(m[1][0] == 3);
    CHECK(m[1][1] == 4);
    CHECK_THROWS_AS(m[2][0], std::out_of_range);  
    CHECK_THROWS_AS(m[0][-1], std::out_of_range); 
}
TEST_CASE("SUM MATRIX") {
    SquareMat m1(2); 
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    CHECK(m1.sum() == 10.0); 
}
TEST_CASE("OPERTOR ==, !=, <, <=, >, >=") {     
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[1][0] = 3;
    m2[1][1] = 4;
    CHECK(m1 == m2);  
    m2[0][0] = 5; 
    CHECK(m1 != m2); 
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[1][0] = 3;
    m2[1][1] = 6; 
    CHECK(m1 < m2);  
    SquareMat m3(2);
    m3[0][0] = 1;
    m3[0][1] = 2;
    m3[1][0] = 3;
    m3[1][1] = 4;  
    CHECK(m1 <= m3); 
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;  
    CHECK(m2 > m1); 
    m3[0][0] = 1;
    m3[0][1] = 2;
    m3[1][0] = 3;
    m3[1][1] = 4;  
    CHECK(m3 >= m1);
}
TEST_CASE("OPERATOR +=") {
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;
    m1 += m2;
    CHECK(m1[0][0] == 6);
    CHECK(m1[0][1] == 8);
    CHECK(m1[1][0] == 10);
    CHECK(m1[1][1] == 12);
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 += m3, std::invalid_argument); 
}

TEST_CASE("OPERATOR -=") {
    SquareMat m1(2);
    m1[0][0] = 5;
    m1[0][1] = 6;
    m1[1][0] = 7;
    m1[1][1] = 8;
    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[1][0] = 3;
    m2[1][1] = 4;
    m1 -= m2;
    CHECK(m1[0][0] == 4);
    CHECK(m1[0][1] == 4);
    CHECK(m1[1][0] == 4);
    CHECK(m1[1][1] == 4);
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 -= m3, std::invalid_argument); 
}
TEST_CASE("OPERATOR *=") {
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;
    m1 *= m2;
    CHECK(m1[0][0] == 19);
    CHECK(m1[0][1] == 22);
    CHECK(m1[1][0] == 43);
    CHECK(m1[1][1] == 50);
    SquareMat m3(3);
    CHECK_THROWS_AS(m1 *= m3, std::invalid_argument); 
}
TEST_CASE("OPERATOR *= SCALAR") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    m *= 2.0;
    CHECK(m[0][0] == 2);
    CHECK(m[0][1] == 4);
    CHECK(m[1][0] == 6);
    CHECK(m[1][1] == 8);
}
TEST_CASE("OPERATOR %=") {
    CHECK_THROWS_AS(SquareMat(1)%=0, std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 5;
    m1[0][1] = 10;
    m1[1][0] = 15;
    m1[1][1] = 20;
    m1 %= 3;
    CHECK(m1[0][0] == 2);
    CHECK(m1[0][1] == 1);
    CHECK(m1[1][0] == 0);
    CHECK(m1[1][1] == 2);
}
TEST_CASE("OPERATOR % MATRIX"){
    CHECK_THROWS_AS(SquareMat(1)%=SquareMat(2), std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 5;
    m1[0][1] = 10;
    m1[1][0] = 15;
    m1[1][1] = 20;
    SquareMat m2(2);
    m2[0][0] = 3;
    m2[0][1] = 4;
    m2[1][0] = 5;
    m2[1][1] = 6;
    m1 %= m2;
    CHECK(m1[0][0] == 15);
    CHECK(m1[0][1] == 40);
    CHECK(m1[1][0] == 75);
    CHECK(m1[1][1] == 120);
}
TEST_CASE("PERATOR /="){
    CHECK_THROWS_AS(SquareMat(1)/=0, std::invalid_argument);
    SquareMat m1(2);
    m1[0][0] = 4;
    m1[0][1] = 8;
    m1[1][0] = 12;
    m1[1][1] = 16;
    m1 /= 2.0;
    CHECK(m1[0][0] == 2);
    CHECK(m1[0][1] == 4);
    CHECK(m1[1][0] == 6);
    CHECK(m1[1][1] == 8);
}
TEST_CASE("OPERATOR <<"){
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    std::ostringstream oss;
    oss << m;
    std::string expected_output = "1 2\n3 4\n";
    CHECK(oss.str() == expected_output);
}
}
