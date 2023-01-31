/* ------------------------------------------------------------------------- */
/* Commodore 128 Programmer's Reference Guide                                */
/* Program 3-2. Buffer Return                                                */
/* ------------------------------------------------------------------------- */
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef unsigned char uchar;

#define COUNT   7                       // # of chars in buffer            
                                        //
#define NDX     ((uchar *) 0xD0)        // Num characters in keyboard buffer
#define KEYBUF  ((uchar *) 0x034A)      // Keyboard buffer


/* ------------------------------------------------------------------------- */
int main()
{
    int i;
  
    // Specify # of chars in buffer
    *NDX = COUNT;

    // Place chars in buffer
    for (i = 0; i < COUNT; ++i)
        KEYBUF[i] = CH_ENTER;
  
    sleep(2);
    clrscr();
    cputsxy(0, 7, "? chr$(156) : rem purple text");
    cputsxy(0, 12, "list");

    // Use stdio for HOME control key (decimal 19)
    puts("\x13");

    // When program ends, buffer empties and executes 7 returns.
    // This changes char color to purple and lists the program automatically
    // as if you pressed the return key manually.
    return EXIT_SUCCESS;
}
