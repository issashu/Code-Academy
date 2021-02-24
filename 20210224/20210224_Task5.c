/*
Задача 5. Напишете макрос с един параметър, който печата
съобщение, само при дефиниран макрос DEBUG. Ако DEBUG не е
дефиниран, не печата нищо.
*/
#include <stdio.h>

#define DEBUG 1

#ifdef DEBUG
    #define DEBUGMSG printf("The cake is not a lie!\n")
#else
    #define DEBUGMSG printf("The cake is a lie\n")
#endif



int main(){
    
    DEBUGMSG;

    return 0;
}
