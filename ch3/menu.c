#include <conio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */
void do_first()
{
    cputs("\rDoing first item ");       // Extra space clears existing text
}


/* ------------------------------------------------------------------------- */
void do_second()
{
    cputs("\rDoing second item");
}


/* ------------------------------------------------------------------------- */
void do_third()
{
    cputs("\rDoing third item");
    cclear(2);                          // Clear existing text
}


/* ------------------------------------------------------------------------- */
void do_fourth()
{
    cputs("\rDoing fourth item");
}


/* ------------------------------------------------------------------------- */
int main()
{
    char a = -1;

    clrscr();

    // Menu skeleton
    cputs("1. First item\r\n");
    cputs("2. Second item\r\n");
    cputs("3. Third item\r\n");
    cputs("4. Fourth item\r\n");
    cputs("\r\nSelect an item from above\r\n\r\n");

    while (a)
    {
        a = cgetc() - '0';
        switch (a)
        {
            case 1: do_first();     break;
            case 2: do_second();    break;
            case 3: do_third();     break;
            case 4: do_fourth();    break;

            case 0:
                cputs("\rSo long and thanks...\r\n\r\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}
