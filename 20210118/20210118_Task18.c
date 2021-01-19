#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>

void KoledniGirliandi (void);

int main()
{ 
    KoledniGirliandi();
    return 0;
}

void KoledniGirliandi (void)
{
  int LightBulb = 255;
    int Clicker = 128;
    char Lights [8] = {'.','.','.','.','.','.','.','.'};

    for (int i=0; i<8; i++)
    {
      if(LightBulb&Clicker) 
        Lights[i]='*';
      (LightBulb>>=1);
      (Clicker>>=1); 
      for(int j=0;j<8;j++)
        printf("%c",Lights[j]);
      printf("\n");
      for(int j=0; j<8; j++)
        Lights[j] = '.';
      sleep(1);
    }
}

