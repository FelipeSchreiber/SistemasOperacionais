#ifndef FIXED_POINT_H
#define FIXED_POINT_H
typedef int fixed_p;
#define SHIFT_AMOUNT 16//os 16 bits menos significativos serao usados para a parte fracionaria
#define CONVERTER_PARA_FP(A) ((fixed_p)(A << SHIFT_AMOUNT))
#define ADD(A,B) (A + (B << SHIFT_AMOUNT))// soma um inteiro B com o valor em ponto fixo A
#define SUB(A,B) (A - (B << SHIFT_AMOUNT))// subtrai um inteiro B de um valor em ponto fixo A
#define MULT(A,B) ((fixed_p)(((int64_t) A) * B >> SHIFT_AMOUNT))//Multiplica um ponto flutuante por outro. Se nao fizessemos o shift de um deles (consequentemente perdendo precisao) sempre teríamos overflow
#define DIV(A,B) ((fixed_p)((((int64_t) A) << SHIFT_AMOUNT) / B))
#define PARTE_INTEIRA(A) (A >> SHIFT_AMOUNT)//Obtem a parte inteira do numero em ponto fixo
#define ROUND(A) (A >= 0 ? ((A + (1 << (SHIFT_AMOUNT - 1))) >> SHIFT_AMOUNT) : ((A - (1 << (SHIFT_AMOUNT - 1))) >> SHIFT_AMOUNT))//Arredonda um ponto fixo para o inteiro mais proximo.

#endif 
