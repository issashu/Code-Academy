/*
 Задача 13.
Направете обединение с членове unsigned short и char. Ограничете използваните битове до 6. 
Инициализирайте и изведете на конзолата.
union <tagUnion> {
 Ctype m_bitField : N;
};
*/
#include <stdio.h>
#include <stdint.h>

union myunion {
    unsigned short Var1:6;
    int8_t Var2:6;
    char var3:6;
} Shorty;

int main(){
    Shorty.Var1 = 255;
    Shorty.Var2 = 126;
    Shorty.var3 = 'c';

    printf("The union limited to 6 bits consists of:\n%d, %d and %c", Shorty.Var1, Shorty.Var2, Shorty.var3);
}