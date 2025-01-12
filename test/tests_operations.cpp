#include <gtest/gtest.h>
#include "operations.h"

TEST(Operation_Sum__Test, Positive_Numbers)
{
    EXPECT_EQ(sum(1, 3), 4) << "falha a soma de 2 numeros simples"; // Teste comum
    EXPECT_EQ(sum(1.5, 1.5), 3);                                    // Teste com numeros reais
    EXPECT_EQ(sum(1.5, 1), 2.5);                                    // Teste com retorno de numeros reais
    EXPECT_EQ(sum(1.5, 1), 2.5);                                    // Teste com retorno de numeros reais
}
TEST(Operation_Sum__Test, Negative_Numbers)
{
    EXPECT_EQ(sum(2, -1), 1);       // Teste com entrada negativa retorno positivo
    EXPECT_EQ(sum(-2, 1), -1);      // Teste com retorno negativo
    EXPECT_EQ(sum(-2.5, -1), -3.5); // Teste com entrada e retono real negativo
}

TEST(Operation_Sub__Test, Positive_Numbers)
{
    EXPECT_EQ(sub(2, 1), 1);      // Teste comum
    EXPECT_EQ(sub(5, 1.5), 3.5);  // Teste com numeros reais
    EXPECT_EQ(sub(1, 2), -1);     // Teste comum retorno negativo
    EXPECT_EQ(sub(1.5, 2), -0.5); // Teste com retorno de numeros reais negativo
}
TEST(Operation_Sub__Test, Negative_Numbers)
{
    EXPECT_EQ(sub(2, -1), 3);       // Teste com entrada negativa retorno positivo
    EXPECT_EQ(sub(-2, 1), -3);      // Teste com entrada negativa retorno negativo
    EXPECT_EQ(sub(-2.5, -1), -1.5); // Teste com entrada e retono real negativo
}

TEST(Operation_Mult__Test, Positive_Numbers)
{
    EXPECT_EQ(mult(2, 0), 0);      // Teste 0
    EXPECT_EQ(mult(2, 1), 2);      // Teste 1
    EXPECT_EQ(mult(2, 1.5), 3);    // Teste com numeros reais
    EXPECT_EQ(mult(1.75, 2), 3.5); // Teste com retorno de numeros reais negativo
}
TEST(Operation_Mult__Test, Negative_Numbers)
{
    EXPECT_EQ(mult(0, -1), 0);      // Teste entada negativo e zero
    EXPECT_EQ(mult(2, -1), -2);     // Teste com entrada negativa retorno positivo
    EXPECT_EQ(mult(-2, 1), -2);     // Teste com entrada negativa retorno negativo
    EXPECT_EQ(mult(-2.5, -1), 2.5); // Teste com entrada positivo retorno negativo
    EXPECT_EQ(mult(-2.5, 2), -5);   // Teste com entrada real negativo
}

TEST(Operation_Divi__Test, Positive_Numbers)
{
    EXPECT_THROW(divi(2, 0), std::invalid_argument); // Teste 0
    EXPECT_EQ(divi(0, 2), 0);                        // Teste 0
    EXPECT_EQ(divi(2, 1), 2);                        // Teste 1
    EXPECT_NEAR(divi(2, 1.5), 1.33, 0.01);           // Teste com numeros reais
    EXPECT_EQ(divi(1.75, 2), 0.875);                 // Teste com retorno de numeros reais negativo
}
TEST(Operation_Divi__Test, Negative_Numbers)
{
    EXPECT_THROW(divi(-2, 0), std::invalid_argument); // Teste 0
    EXPECT_EQ(divi(0, -2), 0);                        // Teste 0
    EXPECT_EQ(divi(-2, -1), 2);                       // Teste 1
    EXPECT_NEAR(divi(2, -1.5), -1.33, 0.01);          // Teste com numeros reais
    EXPECT_EQ(divi(1.75, -2), -0.875);                // Teste com entrada real negativo
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
