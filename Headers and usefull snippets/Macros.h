#ifndef MACROS.H
#define  MACROS
/*CODE STARTS HERE*/

//Use this to find a minimum between two values. Works just like in Excel with function in function.
#define min(x,y) (x) < (y) ? (x) : (y)


#define printErrord(errorCode)  //printError(errorCode, "No message")
        void printError(int errorCode, char *msg)
{
	printf("Error code: %d (%s)\n", errorCode, msg);
}

int main(int argc, char *argv[])
{
	printError(9, "Bad alloc");
	printErrord(8);
}

/*
int (*Matrix)[2] - passing pointers to 2D arrays
for(int i=0; i<MaxEmployees;i++){
        Employees[i].ID = i+1;
        strcpy(Employees[i].Name,"John Doe"); - fotr strings copy
*/

#endif /* MACROS */