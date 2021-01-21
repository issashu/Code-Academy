/*Създайте програма, която подканя човека да въведе проста аритметична операция с две числа от екрана 
- събиране, изваждане, деление, умножение и отпечатва резултата. 
Помислете какви променливи и колко трябва да имате?
Колко са вариантите, които можете да имате, като операции,
има ли изключителни случаи, за които трябва да помислим (напишете си ги)?
Какво ще използвате за управление на процеса ?*/
#include <stdio.h>

int main(){
    float a = 0;
    float b = 0;
    
    int choice;
    while (1){
        printf("Please enter two digits a and b.\n");
        scanf("%f", &a);
        scanf("%f", &b);
        printf("a = %.2f\nb = %.2f\n", a , b);

        printf("If You want to sum a + b press 1.\n");
        printf("If You want to subtrack a - b press 2.\n");
        printf("If You want to multiply a * b press 3.\n");
        printf("If You want to divide a / b press 4.\n");
        printf("If You want to exit press 5.\n");

        while (choice != 1 || choice != 2 || choice != 3 || choice !=4 || choice !=5){
            scanf("%d", &choice);
            float result = 0;
            
            if (choice == 1){
                result = a + b;
                printf("a+b = %.2f", result);
                break;
            }
            else if(choice == 2){
                result = a - b;
                printf("%.2f", result);
                break;
            }
            else if(choice == 3){
                result = a * b;
                printf("%.2f", result);
                break;
            }
            else if(choice == 4){
                if (a != 0 && b != 0){
                    result = a / b;
                    printf("%.2f", result);
                    break;
                }
                else{
                    printf("It is not possible to divide by O, enter another digits");
                    break;
                }
            }
            else if(choice == 5){
                printf("you choce to exit the program.");
                break;
            }
            else
                printf("Invalid choice, press 1, 2,3,4 or 5\n");
        }
        if (choice == 5){
            printf("You choce to exit the program.");
            break;
        }       
    }
    return 0;  
}