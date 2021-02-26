#ifndef MACROS.H
#define  MACROS
/*CODE STARTS HERE*/
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


#endif /* MACROS */