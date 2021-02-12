/*
 Задача 11.
Напишете програма, в която се въвеждат пореден номер, име, фамилия, възраст на участници в маратон. 
Изискването е за името и фамилията да не се използват масиви с фиксирана дължина. 
След като въвеждането завърши, изведете списък с участниците.
*/





void Reallocate(char *p){
    int i = 0, max = 256;
char *ptr = malloc(max);

/* do whatever until i reaches 255 */

if (i + 1 >= max) {
    void *tmp = realloc (ptr, max + 256);
    if (!tmp) {
        fprintf (stderr, "error: realloc - memory exhausted.\n")
        /* handle error */
    }
    ptr = tmp;
    max += 256;
}
}