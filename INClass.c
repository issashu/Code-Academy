#include <stdio.h>




int main(){
int choice;
int  choice1;

int i,j;
int SOLITARE[3][8]={{45,45,45,45,45,45,45,45},
                {9,10,11,12,13,14,15,16},
                {1, 2, 3, 4, 5, 6, 7 , 8,}
                };
for(i=0;i<3;i++){
    for(j=0;j<8;j++){
    printf("\t%d ",SOLITARE[i][j]);
    }
    printf("\n");
}
while(1){

printf("chose a number from 1 to 16 to move\n");
scanf(" %d",&choice);


for(i=0;i<3;i++){

    for(j=0;j<8;j++){
        if(SOLITARE[i][j]==choice){
           
            break;
        }
        
    }
   
   }
printf("arr[%d][%d]\n",i,j);
scanf(" %d",&choice1);

switch (choice1)
{


case 1:/*nadqsno*/
   
   printf("arr[%d][%d]\n",i,j);
    j--;
    SOLITARE[i][j+2]=SOLITARE[i][j];
    SOLITARE[i][j]=45;
    SOLITARE[i][j+1]=45;
    break;

    case 2:/*nagore*/
    i--;
    printf("arr[%d][%d]\n",i,j);
    SOLITARE[i-2][j]=SOLITARE[i][j];
    SOLITARE[i-1][j]=45;   
    SOLITARE[i][j]=45;
    
    break;

}
for( i=0;i<3;i++){
    for(j=0;j<8;j++){
    printf("\t%d ",SOLITARE[i][j]);
    }
    printf("\n");
}
}


}