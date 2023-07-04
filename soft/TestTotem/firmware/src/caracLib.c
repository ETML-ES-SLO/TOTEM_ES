/* ************************************************************************** */
/** librairie de caractère

 * autor: Nicolas Fürst
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */

#include "app.h"
#include "caracLib.h"


//Here are all the charctere dysplayable. for now the fonction have all of those:
//.',-_/*+=:()%°$!?0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ
//the only thing that need to be respected if more charactere need to be added is that they need to be call by
//one of the free not extended ascii code.
void ConvertChar (colorStruct *Convert,char character,colorStruct color)
{
    //This fonction convert a char into a "colorStruct" type array, in order to display the character on the matrix.
    //All characters are on a 7 by 5 array of LED.
    
    //0 /8 /16/24/32    
    //1 /9 /17/25/33
    //2 /10/18/26/34
    //3 /11/19/27/35
    //4 /12/20/28/36
    //5 /13/21/29/37
    //6 /14/22/30/38
    switch (character)
    {
        case '.':                        
            Convert[14] = color;  
            break;
        case 39:   //'                      
            Convert[9 ] = color;    
            Convert[8 ] = color;
            break;
        case ',':                      
            Convert[14] = color;    
            Convert[7 ] = color;
            break;
        case '_':                      
            Convert[6 ] = color;    
            Convert[14] = color;
            Convert[22] = color;    
            Convert[30] = color;
            Convert[38] = color; 
            break;
        case '/':                      
            Convert[32] = color;    
            Convert[33] = color;
            Convert[25] = color;    
            Convert[26] = color;
            Convert[12] = color;
            Convert[18] = color;  
            Convert[19] = color;  
            Convert[20] = color;     
            Convert[13] = color;
            Convert[5 ] = color;
            Convert[6 ] = color; 
            break;        
        case '=':                      
            Convert[2 ] = color;    
            Convert[10] = color;
            Convert[18] = color;    
            Convert[26] = color;
            Convert[34] = color;
            Convert[4 ] = color;     
            Convert[12] = color;
            Convert[20] = color;
            Convert[28] = color; 
            Convert[36] = color;
            break;
        case '*':                      
            Convert[17] = color;    
            Convert[18] = color;
            Convert[19] = color;    
            Convert[11] = color;
            Convert[2 ] = color;
            Convert[12] = color;     
            Convert[5 ] = color;
            Convert[27] = color;
            Convert[34] = color; 
            Convert[28] = color;
            Convert[37] = color; 
            break;
        case '+':                      
            Convert[17] = color;    
            Convert[18] = color;
            Convert[19] = color;    
            Convert[20] = color;
            Convert[21] = color;
            Convert[3 ] = color;     
            Convert[11] = color;
            Convert[27] = color;
            Convert[35] = color; 
            break;
        case ':':                      
            Convert[17] = color;    
            Convert[21] = color;
            break;
        case ')':                      
            Convert[8 ] = color;    
            Convert[17] = color;
            Convert[18] = color;    
            Convert[19] = color;
            Convert[20] = color;
            Convert[21] = color;     
            Convert[14] = color;
            break;
        case '(':                      
            Convert[24] = color;    
            Convert[17] = color;
            Convert[18] = color;    
            Convert[19] = color;
            Convert[20] = color;
            Convert[21] = color;     
            Convert[30] = color;
            break;
        case '%':                      
            Convert[1 ] = color;    
            Convert[0 ] = color;
            Convert[9 ] = color;    
            Convert[8 ] = color;
            Convert[33] = color;
            Convert[26] = color;     
            Convert[19] = color;
            Convert[12] = color;
            Convert[5 ] = color; 
            Convert[30] = color;     
            Convert[38] = color;
            Convert[37] = color;
            Convert[29] = color; 
            break;
        case '°':                      
            Convert[1 ] = color;    
            Convert[2 ] = color;
            Convert[11] = color;    
            Convert[19] = color;
            Convert[26] = color;
            Convert[25] = color;     
            Convert[16] = color;
            Convert[8 ] = color;
            break;
        case '?':                      
            Convert[1 ] = color;    
            Convert[8 ] = color;
            Convert[33] = color;    
            Convert[34] = color;
            Convert[27] = color;
            Convert[20] = color;     
            Convert[16] = color;
            Convert[24] = color;
            Convert[22] = color; 
            break;
        case '!':                      
            Convert[16] = color;    
            Convert[17] = color;
            Convert[18] = color;    
            Convert[19] = color;
            Convert[20] = color;
            Convert[22] = color;  
            break;
        case '0':                      
            Convert[33] = color;     //.XXX.
            Convert[24] = color;     //X...X
            Convert[16] = color;     //X..XX
            Convert[8 ] = color;     //X.X.X
            Convert[1 ] = color;     //XX..X    
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //.XXX.
            Convert[19] = color;    
            Convert[4 ] = color;
            Convert[35] = color;    
            Convert[34] = color;
            Convert[36] = color;
            Convert[37] = color;   
            Convert[30] = color;  
            Convert[22] = color;
            Convert[14] = color;   
            Convert[5 ] = color; 
            Convert[12] = color;   
            Convert[26] = color; 
            break;
        case '9':                      
            Convert[33] = color;     //.XXX.
            Convert[24] = color;     //X...X
            Convert[16] = color;     //X...X
            Convert[8 ] = color;     //.XXXX
            Convert[1 ] = color;     //....X    
            Convert[2 ] = color;     //X...X
            Convert[27] = color;     //.XXX.
            Convert[19] = color;    
            Convert[11] = color;
            Convert[35] = color;    
            Convert[34] = color;
            Convert[36] = color;
            Convert[37] = color;   
            Convert[30] = color;  
            Convert[22] = color;
            Convert[14] = color;   
            Convert[5 ] = color; 
            break;
        case '8':                      
            Convert[33] = color;     //.XXX.
            Convert[24] = color;     //X...X
            Convert[16] = color;     //X...X
            Convert[8 ] = color;     //.XXX.
            Convert[1 ] = color;     //X...X    
            Convert[2 ] = color;     //X...X
            Convert[27] = color;     //.XXX.
            Convert[19] = color;    
            Convert[11] = color;
            Convert[4 ] = color;    
            Convert[34] = color;
            Convert[36] = color;
            Convert[37] = color;   
            Convert[30] = color;  
            Convert[22] = color;
            Convert[14] = color;   
            Convert[5 ] = color; 
            break;
        case '7':                      
            Convert[0 ] = color;     //XXXXX
            Convert[8 ] = color;     //....X
            Convert[16] = color;     //....X
            Convert[24] = color;     //...X.
            Convert[32] = color;     //..X..    
            Convert[33] = color;     //..X..
            Convert[34] = color;     //..X..
            Convert[27] = color;    
            Convert[20] = color;
            Convert[21] = color;    
            Convert[22] = color;
            break;
        case '6':                      
            Convert[33] = color;     //.XXX.
            Convert[24] = color;     //X...X
            Convert[16] = color;     //X....
            Convert[8 ] = color;     //XXXX.
            Convert[1 ] = color;     //X...X    
            Convert[2 ] = color;     //X...X
            Convert[27] = color;     //.XXX.
            Convert[19] = color;    
            Convert[11] = color;
            Convert[4 ] = color;    
            Convert[3 ] = color;
            Convert[36] = color;
            Convert[37] = color;   
            Convert[30] = color;  
            Convert[22] = color;
            Convert[14] = color;   
            Convert[5 ] = color; 
            break;
        case '5':                      
            Convert[0 ] = color;     //XXXXX
            Convert[1 ] = color;     //X....
            Convert[2 ] = color;     //X....
            Convert[3 ] = color;     //XXXX.
            Convert[11] = color;     //....X    
            Convert[19] = color;     //X...X
            Convert[27] = color;     //.XXX.
            Convert[8 ] = color;    
            Convert[16] = color;
            Convert[24] = color;    
            Convert[32] = color;
            Convert[36] = color;
            Convert[37] = color;   
            Convert[30] = color;  
            Convert[22] = color;
            Convert[14] = color;   
            Convert[5 ] = color; 
            break;
        case '4':                      
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //XXXXX
            Convert[11] = color;     //....X    
            Convert[19] = color;     //....X
            Convert[27] = color;     //....X
            Convert[35] = color;    
            Convert[34] = color;
            Convert[33] = color;    
            Convert[32] = color;
            Convert[36] = color;
            Convert[37] = color;   
            Convert[38] = color;  
            break;
        case '3':                      
            Convert[1 ] = color;     //.XXX.
            Convert[8 ] = color;     //X...X
            Convert[16] = color;     //....X
            Convert[24] = color;     //.XXX.
            Convert[33] = color;     //....X    
            Convert[34] = color;     //X...X
            Convert[27] = color;     //.XXX.
            Convert[19] = color;    
            Convert[11] = color;
            Convert[36] = color;    
            Convert[37] = color;
            Convert[30] = color;
            Convert[22] = color;   
            Convert[14] = color;  
            Convert[5 ] = color;
            break;
        case '2':                      
            Convert[1 ] = color;     //.XXX.
            Convert[8 ] = color;     //X...X
            Convert[16] = color;     //....X
            Convert[24] = color;     //...X.
            Convert[33] = color;     //..X..    
            Convert[34] = color;     //.X...
            Convert[27] = color;     //XXXXX
            Convert[20] = color;    
            Convert[13] = color;
            Convert[6 ] = color;    
            Convert[14] = color;
            Convert[22] = color;
            Convert[30] = color;   
            Convert[38] = color;
            break;
        case '1':                      
            Convert[9 ] = color;     //..X..
            Convert[16] = color;     //.XX..
            Convert[17] = color;     //..X..
            Convert[18] = color;     //..X..
            Convert[19] = color;     //..X..    
            Convert[20] = color;     //..X..
            Convert[21] = color;     //..X..
            Convert[22] = color;  
            break;
        case '$':              
            Convert[16] = color;     //..X..
            Convert[17] = color;     //.XXXX
            Convert[18] = color;     //X.X..
            Convert[19] = color;     //.XXX.
            Convert[20] = color;     //..X.X    
            Convert[21] = color;     //XXXX.
            Convert[22] = color;     //..X..
            Convert[9 ] = color;    
            Convert[29] = color;
            Convert[25] = color;    
            Convert[33] = color;
            Convert[2 ] = color;
            Convert[36] = color;   
            Convert[13] = color;
            Convert[5 ] = color;
            Convert[11] = color;   
            Convert[27] = color;
            Convert[3 ] = color;
            break;
        case '-':                      
            Convert[3 ] = color;     //.....
            Convert[11] = color;     //.....
            Convert[19] = color;     //.....
            Convert[27] = color;     //XXXXX
            Convert[35] = color;     //.....
                                         //.....
                                         //.....
            break;
        case 'z':
        case 'Z':                      
            Convert[0 ] = color;     //XXXXX
            Convert[8 ] = color;     //....X
            Convert[16] = color;     //...X.
            Convert[24] = color;     //..X..
            Convert[32] = color;     //.X...    
            Convert[33] = color;     //X....
            Convert[26] = color;     //XXXXX
            Convert[19] = color;    
            Convert[12] = color;
            Convert[5 ] = color;    
            Convert[6 ] = color;
            Convert[14] = color;
            Convert[22] = color;   
            Convert[30] = color;
            Convert[38] = color;
            break;
        case 'y':
        case 'Y':                      
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[11] = color;     //.X.X.
            Convert[27] = color;     //..X..    
            Convert[32] = color;     //..X..
            Convert[33] = color;     //..X..
            Convert[34] = color;    
            Convert[20] = color;
            Convert[21] = color;    
            Convert[22] = color;
            break;
        case 'x':
        case 'X':                      
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[10] = color;     //.Y.X.
            Convert[19] = color;     //..X..
            Convert[12] = color;     //.X.X.    
            Convert[5 ] = color;     //X...X
            Convert[6 ] = color;     //X...X
            Convert[32] = color;    
            Convert[33] = color;
            Convert[26] = color;    
            Convert[28] = color;
            Convert[37] = color;
            Convert[38] = color;
            break;
        case 'w':
        case 'W':                      
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X.X.X    
            Convert[5 ] = color;     //XX.XX
            Convert[6 ] = color;     //X...X
            Convert[32] = color;    
            Convert[33] = color;
            Convert[34] = color;
            Convert[35] = color;    
            Convert[36] = color;
            Convert[37] = color;
            Convert[38] = color;
            Convert[13] = color;    
            Convert[20] = color;
            Convert[29] = color;
            break;
        case 'v':
        case 'V':                      
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X...X    
            Convert[13] = color;     //.X.X.
            Convert[32] = color;     //..X..
            Convert[33] = color;    
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color;    
            Convert[29] = color;
            Convert[22] = color;
            break;
        case 'u':
        case 'U':                      
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X...X  
            Convert[5 ] = color;     //X...X  
            Convert[14] = color;     //.XXX.
            Convert[32] = color;
            Convert[33] = color;    
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color;
            Convert[37] = color;    
            Convert[30] = color;
            Convert[22] = color; 
            break;
        case 't':
        case 'T':                          
            Convert[8 ] = color;     //XXXXX    
            Convert[16] = color;     //..X..
            Convert[24] = color;     //..X..
            Convert[17] = color;     //..X..
            Convert[18] = color;     //..X..
            Convert[19] = color;     //..X..
            Convert[20] = color;     //..X..     
            Convert[21] = color;
            Convert[22] = color;    
            Convert[0 ] = color;
            Convert[32] = color;
            break;
        case 's':
        case 'S':                          
            Convert[8 ] = color;     //.XXX.
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X....
            Convert[11] = color;     //.XXX.
            Convert[19] = color;     //....X  
            Convert[27] = color;     //X...X  
            Convert[33] = color;     //.XXX.
            Convert[36] = color;
            Convert[37] = color;
            Convert[30] = color;
            Convert[22] = color;    
            Convert[14] = color;
            Convert[5 ] = color;  
            Convert[16] = color;
            Convert[24] = color;
            break;
        case 'r':
        case 'R':                          
            Convert[0 ] = color;     //XXXX.
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //XXXX.  
            Convert[5 ] = color;     //X...X  
            Convert[6 ] = color;     //X...X
            Convert[8 ] = color;
            Convert[16] = color;
            Convert[24] = color;
            Convert[33] = color;    
            Convert[34] = color;
            Convert[35] = color;
            Convert[37] = color;    
            Convert[38] = color; 
            Convert[12] = color; 
            Convert[20] = color;   
            Convert[28] = color;  
            break;
        case 'q':
        case 'Q':                          
            Convert[8 ] = color;     //.XXX.
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X.X.X  
            Convert[5 ] = color;     //X..X.  
            Convert[14] = color;     //.XX.X
            Convert[22] = color;
            Convert[38] = color;
            Convert[36] = color;
            Convert[35] = color;    
            Convert[34] = color;
            Convert[33] = color;
            Convert[16] = color;    
            Convert[24] = color; 
            Convert[29] = color; 
            Convert[20] = color;    
            break;
        case 'p':
        case 'P':                          
            Convert[0 ] = color;     //XXXX.
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //XXXX.  
            Convert[5 ] = color;     //X....  
            Convert[6 ] = color;     //X....
            Convert[8 ] = color;
            Convert[16] = color;    
            Convert[24] = color;
            Convert[33] = color;
            Convert[34] = color;
            Convert[35] = color;    
            Convert[12] = color;
            Convert[20] = color;
            Convert[28] = color;    
            break;
        case 'o':
        case 'O':                          
            Convert[8 ] = color;     //.XXX.
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X...X  
            Convert[5 ] = color;     //X...X  
            Convert[14] = color;     //.XXX.
            Convert[24] = color;
            Convert[33] = color;    
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color;
            Convert[37] = color;    
            Convert[30] = color;
            Convert[22] = color;
            Convert[16] = color;    
            break;
        case 'n':
        case 'N':                          
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //XX..X
            Convert[3 ] = color;     //X.X.X
            Convert[4 ] = color;     //X..XX  
            Convert[5 ] = color;     //X...X  
            Convert[6 ] = color;     //X...X
            Convert[32] = color;
            Convert[33] = color;    
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color;
            Convert[37] = color;    
            Convert[38] = color;
            Convert[10] = color;
            Convert[19] = color;    
            Convert[28] = color;
            break;
        case 'm':
        case 'M':                          
            Convert[0 ] = color;     //X...X
            Convert[1 ] = color;     //XX.XX
            Convert[2 ] = color;     //X.X.X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X...X  
            Convert[5 ] = color;     //X...X  
            Convert[6 ] = color;     //X...X
            Convert[32] = color;
            Convert[33] = color;    
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color;
            Convert[37] = color;    
            Convert[38] = color;
            Convert[9 ] = color;
            Convert[18] = color;    
            Convert[25] = color;
            break;
        case 'l':
        case 'L':                          
            Convert[0 ] = color;     //X....
            Convert[1 ] = color;     //X....
            Convert[2 ] = color;     //X....
            Convert[3 ] = color;     //X....
            Convert[4 ] = color;     //X....  
            Convert[5 ] = color;     //X....  
            Convert[6 ] = color;     //XXXXX
            Convert[14] = color;
            Convert[22] = color;    
            Convert[30] = color;
            Convert[38] = color;
            break;
        case 'k':
        case 'K':                          
            Convert[1 ] = color;     //X...X    
            Convert[2 ] = color;     //X..X.
            Convert[3 ] = color;     //X.X..
            Convert[4 ] = color;     //XX...
            Convert[5 ] = color;     //X.X..
            Convert[6 ] = color;     //X..X.
            Convert[11] = color;     //X...X  
            Convert[0 ] = color;   
            Convert[18] = color;
            Convert[25] = color;    
            Convert[32] = color;
            Convert[20] = color;
            Convert[29] = color;
            Convert[38] = color;   
            break;
        case 'j':
        case 'J':                          
            Convert[32] = color;     //....X    
            Convert[33] = color;     //....X
            Convert[34] = color;     //....X
            Convert[35] = color;     //....X
            Convert[36] = color;     //X...X
            Convert[37] = color;     //X...X
            Convert[4 ] = color;     //.XXX.  
            Convert[5 ] = color;
            Convert[14] = color;    
            Convert[22] = color;
            Convert[30] = color;
            break;
        case 'i':
        case 'I':                          
            Convert[8 ] = color;     //.XXX.    
            Convert[16] = color;     //..X..
            Convert[24] = color;     //..X..
            Convert[17] = color;     //..X..
            Convert[18] = color;     //..X..
            Convert[19] = color;     //..X..
            Convert[20] = color;     //.XXX.     
            Convert[21] = color;
            Convert[22] = color;    
            Convert[14] = color;
            Convert[30] = color;
            break;
        case 'h':
        case 'H':                          
            Convert[1 ] = color;     //X...X    
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //XXXXX
            Convert[5 ] = color;     //X...X
            Convert[6 ] = color;     //X...X
            Convert[32] = color;     //X...X  
            Convert[0 ] = color;   
            Convert[33] = color;
            Convert[34] = color;    
            Convert[35] = color;
            Convert[36] = color;
            Convert[37] = color;
            Convert[38] = color;    
            Convert[11] = color;
            Convert[19] = color;    
            Convert[27] = color;
            break;
        case 'g':
        case 'G':                          
            Convert[1 ] = color;     //.XXX.    
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X....
            Convert[4 ] = color;     //X....
            Convert[5 ] = color;     //X.XXX
            Convert[8 ] = color;     //X...X
            Convert[16] = color;     //.XXX.     
            Convert[24] = color;
            Convert[33] = color;    
            Convert[14] = color;
            Convert[22] = color;
            Convert[30] = color;
            Convert[37] = color;    
            Convert[36] = color;
            Convert[20] = color;    
            Convert[28] = color;
            break;
        case 'f':
        case 'F':                          
            Convert[8 ] = color;     //XXXXX    
            Convert[16] = color;     //X....
            Convert[24] = color;     //X....
            Convert[32] = color;     //XXXX.
            Convert[1 ] = color;     //X....
            Convert[2 ] = color;     //X....
            Convert[3 ] = color;     //X....     
            Convert[4 ] = color;
            Convert[5 ] = color;    
            Convert[11] = color;
            Convert[19] = color;
            Convert[27] = color;
            Convert[0 ] = color;    
            Convert[6 ] = color;
            break;
        case 'e':
        case 'E':                          
            Convert[0 ] = color;     //XXXXX    
            Convert[1 ] = color;     //X....
            Convert[2 ] = color;     //X....
            Convert[3 ] = color;     //XXXX.
            Convert[4 ] = color;     //X....
            Convert[5 ] = color;     //X....
            Convert[6 ] = color;     //XXXXX     
            Convert[8 ] = color;    
            Convert[16] = color;
            Convert[24] = color;    
            Convert[32] = color;
            Convert[11] = color;
            Convert[19] = color;
            Convert[27] = color;
            Convert[14] = color;
            Convert[22] = color;
            Convert[30] = color;
            Convert[38] = color;
            break;
        case 'd':
        case 'D':                          
            Convert[8 ] = color;     //XXXX.    
            Convert[16] = color;     //X...X
            Convert[24] = color;     //X...X
            Convert[33] = color;     //X...X
            Convert[1 ] = color;     //X...X
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //XXXX.     
            Convert[4 ] = color;
            Convert[5 ] = color;    
            Convert[14] = color;
            Convert[22] = color;
            Convert[30] = color;
            Convert[37] = color; 
            Convert[0 ] = color;    
            Convert[6 ] = color;
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color; 
            break;
        case 'c':
        case 'C':                          
            Convert[8 ] = color;     //.XXX.    
            Convert[16] = color;     //X...X
            Convert[24] = color;     //X....
            Convert[33] = color;     //X....
            Convert[1 ] = color;     //X....
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //.XXX.     
            Convert[4 ] = color;
            Convert[5 ] = color;    
            Convert[14] = color;
            Convert[22] = color;
            Convert[30] = color;
            Convert[37] = color; 
            break;
        case 'b':
        case 'B':                          
            Convert[1 ] = color;     //XXXX.    
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //XXXX.
            Convert[5 ] = color;     //X...X
            Convert[6 ] = color;     //X...X
            Convert[8 ] = color;     //XXXX.     
            Convert[0 ] = color;
            Convert[11] = color;    
            Convert[14] = color;
            Convert[16] = color;
            Convert[24] = color;
            Convert[33] = color;
            Convert[34] = color;
            Convert[27] = color;
            Convert[19] = color;
            Convert[36] = color;
            Convert[37] = color;
            Convert[30] = color;
            Convert[22] = color;
            break;
        case 'a':
        case 'A':                           
            Convert[1 ] = color;     //.XXX.    
            Convert[2 ] = color;     //X...X
            Convert[3 ] = color;     //X...X
            Convert[4 ] = color;     //X...X
            Convert[5 ] = color;     //XXXXX
            Convert[6 ] = color;     //X...X
            Convert[8 ] = color;     //X...X
            Convert[16] = color;
            Convert[24] = color;
            Convert[12] = color;
            Convert[20] = color;
            Convert[28] = color;
            Convert[33] = color;
            Convert[34] = color;
            Convert[35] = color;
            Convert[36] = color;
            Convert[37] = color;
            Convert[38] = color;
            break;
        case 0:
            //if there is no charcter.Do nothing
            break;
        case ' ':
            break;
            
        default:
            Convert[0 ] = color;     //X.X.X    
            Convert[2 ] = color;     //.X.X.
            Convert[9 ] = color;     //X.X.X
            Convert[4 ] = color;     //.X.X.
            Convert[11] = color;     //X.X.X
            Convert[6 ] = color;     //.X.X.
            Convert[13] = color;     //X.X.X   
            Convert[16] = color;
            Convert[18] = color;    
            Convert[20] = color;
            Convert[22] = color;
            Convert[25] = color;    
            Convert[27] = color;
            Convert[29] = color; 
            Convert[32] = color;    
            Convert[34] = color;
            Convert[36] = color;    
            Convert[38] = color;
            break;
    }
}

/* *****************************************************************************
 End of File
 */
