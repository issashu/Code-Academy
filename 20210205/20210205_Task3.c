/*
Задача 3.Какво е грешното на този код?

void my_strcpy(char *t, char *s){ 
    for(; *t; t++, s++)
        *s = *t;
}

Кода няма ясен край на итерацията. Има вероятност да излезем извън дефинираната чаяст на пойнтера.
*/

