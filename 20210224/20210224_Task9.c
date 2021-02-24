/*
Задача 9. Напишете макрос, който прави идентификатор на низ
(стринг)
*/
#include <stdio.h>

#define STRING(S) #S

int main(){
    printf("%s", STRING(25*5));
}