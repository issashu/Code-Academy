/*
Задача 14.
Напишете програма, която да проверява дали 2 стринга (масива) са
анаграми и имат всичките букви на другата дума. Използвайте функции.
Примери за анаграми: реклама: карамел; босилек: обелиск
*/

#include <stdio.h>
#include <stdbool.h>
#define NO_OF_CHARS 256
 
void StringWriter(char* Text1, char* Text2);
bool areAnagram(char* Text1, char* Text2);

int main()
{
    char String1[NO_OF_CHARS] = {'o'};
    char String2[NO_OF_CHARS] = {'o'};

    bool (*AnagramCheck)(char *, char *) = areAnagram;
    void (*Writer)(char *, char *) = StringWriter;

    Writer(String1, String2);
    
    if (AnagramCheck(String1, String2)){
        printf("The two strings are anagram of each other\n");
    }
    else{
        printf("The two strings are not anagram of each other\n");
    }
}

void StringWriter(char* Text1, char* Text2){
    printf("Please enter the first String (mind capitalization!!):\n");
    fgets(Text1, sizeof Text1, stdin);

    printf("Please enter the second String (mind capitalization!!):\n");
    fgets(Text2, sizeof Text2, stdin);
}

bool areAnagram(char* Text1, char* Text2)
{
    int count1[NO_OF_CHARS] = { 0 };
    int count2[NO_OF_CHARS] = { 0 };
    int i = 0;
 
    for (i = 0; Text1[i] && Text2[i]; i++) {
        count1[Text1[i]]++;
        count2[Text2[i]]++;
    }
    //ПРОВЕРКА ДАЛИ НЕ СА РАЗЛИЧНА ДЪЛЖИНА
    if (Text1[i] || Text2[i]){
        return false;
    }
        
    for (i = 0; i < NO_OF_CHARS; i++){
        if (count1[i] != count2[i]){
            return false;
        }
    }

    return true;
}