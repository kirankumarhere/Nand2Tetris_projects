// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.

(RESTART)
@SCREEN
D=A
@0
M=D	//PUT SCREEN START LOCATION IN RAM0

///////////////////////////
(KBDCHECK)

@KBD
D=M
@BLACK
D;JGT	//JUMP IF ANY KBD KEYS ARE PRESSED(jump if result greater than zero)
@WHITE
D;JEQ	//ELSE JUMP TO WHITEN(jump if result equals zero)

@KBDCHECK
0;JMP
///////////////////////////
(BLACK)
@1
M=-1	//WHAT TO FILL SCREEN WITH (-1=11111111111111)
@CHANGE
0;JMP

(WHITE)
@1
M=0	//WHAT TO FILL SCREEN WITH
@CHANGE
0;JMP
//////////////////////////
(CHANGE)
@1	//CHECK WHAT TO FILL SCREEN WITH
D=M	//D CONTAINS BLACK OR WHITE

@0
A=M	//A register GETs ADDRESS OF SCREEN PIXEL TO FILL from M[0] and now M points to that adress in A reg.
M=D	//FILL IT...here M points to screen pixel to fill.

@0
D=M+1	//INC TO NEXT PIXEL
@KBD
D=A-D	//KBD-SCREEN=A

@0
M=M+1	//INC TO NEXT PIXEL
A=M

@CHANGE
D;JGT	//IF A=0 EXIT AS THE WHOLE SCREEN IS BLACK
/////////////////////////
@RESTART
0;JMP

