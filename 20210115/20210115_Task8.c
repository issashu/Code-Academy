#include <stdio.h>

int main()
{
    const char cNewLiner = '\n';
    const unsigned cMaxLoop= 1024 *0xFFFF;
    const double cRealValue = 1.0L / 3.0;


printf ("Constants: %u %c", cMaxLoop, cNewLiner);
printf ("Another Constant: %lf %c", cRealValue, cNewLiner);

/*debug:
cNewLiner+=1;
cMaxLoop+=1;
cRealValue+=1;
*/
}