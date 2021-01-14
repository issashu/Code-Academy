#include <stdio.h>

void PrintPatterns();

int main()
{
    PrintPatterns();

}

void PrintPatterns()
{
    //a)
    printf("# # # # # # # # # # #\n");
    printf("  # # # # # # # # #  \n");
    printf("    # # # # # # #    \n");
    printf("      # # # # #      \n");
    printf("        # # #        \n");
    printf("          #          \n");

    // One interval between prints
    printf("\n");

    //b)
    printf("          #          \n");
    printf("        # # #        \n");
    printf("      # # # # #      \n");
    printf("    # # # # # # #    \n");
    printf("  # # # # # # # # #  \n");
    printf("# # # # # # # # # # #\n");

    // One interval between prints
    printf("\n");

    //c)
    printf("          #          \n");
    printf("        # # #        \n");
    printf("      # # # # #      \n");
    printf("    # # # # # # #    \n");
    printf("  # # # # # # # # #  \n");
    printf("# # # # # # # # # # #\n");
    printf("  # # # # # # # # #  \n");
    printf("    # # # # # # #    \n");
    printf("      # # # # #      \n");
    printf("        # # #        \n");
    printf("          #          \n");
}