/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
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
#include "Anim.h"

//this fonction make the animation of nyan cat, it's not really usefull but it does a good demo
void Nyan(colorStruct* matrixColor)
{
    //color initialisation
    colorStruct pink;
    pink.R = 255;
    pink.G = 100;
    pink.B = 180;
    colorStruct beige;
    beige.R = 255;
    beige.G = 180;
    beige.B = 115;
    colorStruct gray;
    gray.R = 50;
    gray.G = 50;
    gray.B = 50;
    colorStruct purple;
    purple.R = 255;
    purple.G = 20;
    purple.B = 153;
    colorStruct white;
    white.R = 255;
    white.G = 255;
    white.B = 255;
    colorStruct darkGray;
    darkGray.R = 10;
    darkGray.G = 10;
    darkGray.B = 10;
    //sky
    colorStruct darkBlue;
    darkBlue.R = 0;
    darkBlue.G = 0;
    darkBlue.B = 10;
    //rainbow
    colorStruct red;
    red.R = 255;
    red.G = 0;
    red.B = 0;
    colorStruct orange;
    orange.R = 255;
    orange.G = 128;
    orange.B = 0;
    colorStruct yellow;
    yellow.R = 255;
    yellow.G = 255;
    yellow.B = 0;
    colorStruct green;
    green.R = 0;
    green.G = 255;
    green.B = 0;
    colorStruct blue;
    blue.R = 0;
    blue.G = 0;
    blue.B = 255;
    colorStruct purple2;
    purple2.R = 255;
    purple2.G = 0;
    purple2.B = 255;
    
    //other
    static int row1,row2 = 152;
    int row = 0;
    int rainbow;
    int i,i2 = 0;
    static uint8_t two = 0;
    static int p = 0,p2 = 0,u4 = 0,u2 = 0,p3 = 0;
    if(p >= 1)
    {
        p2++;
        row1+=8;
        if (row1 >=256+NLED-96)
        {
            two = 1;
            row2+=8;
        }
        if ( row1 > 920)
        {
            row1 = row2;
            row2 = 152;
            two = 0;
        }
        p = 0;
        if (p2 >= 4)    //tail and leg tempo
        {
            p3++;
            p2 = 0;
            if (u4 == 0)
            {
                u4 = 1;
            }
            else
            {
                u4 = 0;
            }
             if (p3 >= 2)   //head tempo
            {
                p3 = 0;
                if (u2 == 0)
                {
                    u2 = 1;
                }
                else
                {
                    u2 = 0;
                }
            }
        }
    }
    p++;
    colorStruct Convert[NLED+512];  
    
    for (i = 0;i<NLED;i++)          //sync of the arrays
    {
        matrixColor[i] = darkBlue;   //setting of the blue in the backgroud
        if ((i%23 == 1)&&((i/7)%2 == 1)&&((i/3)%2 == 1))    //stars in a "random" patern
        {
            matrixColor[i] = white;
        }
        if ((i%51 == 1)&&((i/5)%2 == 1)&&((i/11)%2 == 1))    //stars in a "random" patern
        {
            matrixColor[i] = white;
        }
        Convert[i+256] = matrixColor[i];
    }
    for (i2 = 0;i2<=two;i2++)
    {
        if (i2 == 0)
        {
            row = row1;
        }
        else
        {
            row = row2;
        }
        //rainbow
        rainbow = row+16;
        for (0;(rainbow >= row-20*8)&&(rainbow >= 0);rainbow = rainbow-8)
        {
            if ((rainbow/40)%2 == 1)   
            {
                Convert[rainbow+u4] = red;
                Convert[rainbow+1+u4] = orange;
                Convert[rainbow+2+u4] = yellow;
                Convert[rainbow+3+u4] = green;
                Convert[rainbow+4+u4] = blue;
                Convert[rainbow+5+u4] = purple2;
                
            }
            else 
            {
                Convert[(rainbow+1)-u4] = red;
                Convert[(rainbow+2)-u4] = orange;
                Convert[(rainbow+3)-u4] = yellow;
                Convert[(rainbow+4)-u4] = green;
                Convert[(rainbow+5)-u4] = blue;
                Convert[(rainbow+6)-u4] = purple2;
            }
        }

        //beige set
        Convert[row+17] = beige;    //...XXXXXXX...
        Convert[row+18] = beige;    //..XX.....XX..
        Convert[row+19] = beige;    //..X.......X..
        Convert[row+20] = beige;    //..X.......X..
        Convert[row+21] = beige;    //..X.......X..
        Convert[row+24] = beige;    //..XX.....XX..
        Convert[row+25] = beige;    //...XXXXXXX...
        Convert[row+29] = beige;    //.............
        Convert[row+30] = beige;
        Convert[row+32] = beige;
        Convert[row+38] = beige;
        Convert[row+40] = beige;
        Convert[row+46] = beige;
        Convert[row+48] = beige;
        Convert[row+54] = beige;
        Convert[row+56] = beige;
        Convert[row+62] = beige;
        Convert[row+64] = beige;
        Convert[row+70] = beige;
        Convert[row+72] = beige;
        Convert[row+73] = beige;
        Convert[row+81] = beige;
        Convert[row+82] = beige;
        Convert[row+78] = beige;
        Convert[row+77] = beige;
        Convert[row+85] = beige;
        Convert[row+84] = beige;
        Convert[row+83] = beige;


        //pink set
        Convert[row+26] = pink;    //.............
        Convert[row+27] = pink;    //....XXXXX....
        Convert[row+28] = pink;    //...XXXXXXX...
        Convert[row+33] = pink;    //...XXXXXXX...
        Convert[row+34] = pink;    //...XXXXXXX...
        Convert[row+35] = pink;    //....XXXXX....
        Convert[row+36] = pink;    //.............
        Convert[row+37] = pink;    //.............
        Convert[row+41] = pink;
        Convert[row+42] = pink;
        Convert[row+43] = pink;
        Convert[row+44] = pink;
        Convert[row+45] = pink;
        Convert[row+49] = pink;
        Convert[row+50] = pink;
        Convert[row+51] = pink;
        Convert[row+52] = pink;
        Convert[row+53] = pink;
        Convert[row+57] = pink;
        Convert[row+58] = pink;
        Convert[row+59] = pink;
        Convert[row+60] = pink;
        Convert[row+61] = pink;
        Convert[row+65] = pink;
        Convert[row+74] = pink;
        Convert[row+66] = pink;
        Convert[row+67] = pink;
        Convert[row+68] = pink;
        Convert[row+69] = pink;
        Convert[row+75] = pink;
        Convert[row+76] = pink;

        //purple set
        Convert[row+34] = purple;
        Convert[row+28] = purple;
        Convert[row+59] = purple;
        Convert[row+61] = purple;
        Convert[row+44] = purple;
        Convert[row+65] = purple;

        //mooving parts
        if (u4 == 0)     //leg and tail
        {
            Convert[row+1 ] = gray;     
            Convert[row+2 ] = gray;     
            Convert[row+11] = gray;     
            Convert[row+23] = gray;     
            Convert[row+39] = gray;     
            Convert[row+71] = gray;  
            Convert[row+87] = gray;
        }
        else
        {    
            Convert[row+4 ] = gray;     
            Convert[row+11] = gray;     
            Convert[row+31] = gray;     
            Convert[row+47] = gray;     
            Convert[row+79] = gray;  
            Convert[row+95] = gray;
        }
        if (u2 == 0)//head
        {
            Convert[row+66] = gray;     
            Convert[row+75] = gray;    
            Convert[row+76] = darkGray;
            Convert[row+77] = gray;
            Convert[row+78] = gray;
            Convert[row+83] = gray;
            Convert[row+84] = gray;
            Convert[row+85] = gray;
            Convert[row+86] = gray;
            Convert[row+67] = gray;
            Convert[row+68] = gray;
            Convert[row+69] = gray;
            Convert[row+91] = gray;
            Convert[row+92] = darkGray;
            Convert[row+93] = gray;
            Convert[row+94] = gray;
            Convert[row+98] = gray;
            Convert[row+99] = gray;
            Convert[row+100] = gray;
            Convert[row+101] = gray;
        }
        else
        {
            Convert[row+66] = gray;     
            Convert[row+76] = gray;    
            Convert[row+75] = darkGray;
            Convert[row+77] = gray;
            Convert[row+97] = gray;
            Convert[row+83] = gray;
            Convert[row+84] = gray;
            Convert[row+85] = gray;
            Convert[row+74] = gray;
            Convert[row+67] = gray;
            Convert[row+68] = gray;
            Convert[row+65] = gray;
            Convert[row+92] = gray;
            Convert[row+91] = darkGray;
            Convert[row+93] = gray;
            Convert[row+90] = gray;
            Convert[row+98] = gray;
            Convert[row+99] = gray;
            Convert[row+100] = gray;
            Convert[row+82] = gray;
        }
        
    }
    
    
    
    for (i = 0;i<NLED;i++)          //re-sync of the arrays
    {
        matrixColor[i] = Convert[i+256];
    }
    WriteToLED();
}


//this fonction is used to display a chaine of charachter on the matrix.
bool Text (char* charChain,colorStruct color,colorStruct* matrixColor,bool rainbow)
{   
    static int row = 0;
    static int reset = 0;  //use to know when to reset the text
    static uint8_t u = 0;
    static int nbChar;
    int i = 0;
    bool dispOver = false;
    colorStruct off,white;
    static colorStruct caracArray[40];
    off.R = 0;
    off.G = 0;
    off.B = 0;
    white.R = 255;
    white.B = 255;
    white.G = 255;
    for (i = 0;reset == 0;i++)
    {
        if (charChain[i] == '\0')   //the \0 indicate the last character of the array
        {
            reset = NLED/8+i*6; //the reset variable is set to the number of row of the matrix in order to make the last charactere go all around before reseting 
            nbChar = i;
        }
    }
    reset --;
    if (reset == 0)
    {
        u = 0;
        row = 0;
        FullColor(&matrixColor[0],off);
    }
    if (nbChar < NLED/(8*6))//test if the neumber off charactere can be dysplayed all at once on the matrix
    {
        if (row == NLED/8)
        {
            row = 0;
            reset = 0;
            u = 0;
        }
    }
    if (rainbow == 1)
    {
        color = RainbowPick(u);
        u+=5;
    }
    
    
    for (i = 0;i<NLED-8;i++)    //shift all the matrix by one row
    {
        matrixColor[i] = matrixColor[i+8];
    }
    if (row%6 == 0)     //update the new char every time one is displayed complitely on the matrix
    {
        for (i = 0;i <40;i++)
        {
            caracArray[i] = off;
        }
        ConvertChar(&caracArray[0],charChain[row/6],color);
    }
    for (i = 0;(i<8)&&(row%6==5);i++)   //set the last row to off 
    {
        matrixColor[NLED-8+i] = off;
    }
    for (i = 0;(i<40)&&(row%6<5);i++)
    {
        matrixColor[NLED-8+i] = caracArray[i+(row%6)*8];    //set the last line of the matrix 
    }
    if (nbChar >= NLED/(8*6))
    {
        for (i = 0;i<8;i++)   //set the first row to white to meke some sort of separation between the begining and the end.
        {
            matrixColor[i] = white;
        }
    }
    WriteToLED();
    row++;
}


//this fonction dysplay the battery level on the matrix
//for now the fonction is made so 14V dysplay a full battery and 10 an empty one.
//the fonction is far from perfect since the fonction basicaly dyspaly the input tension one for one between 10V and 14V
//but the base of it work great.
void Battery (colorStruct* matrixColor) 
{ 
    int row;
    S_ADCResults resultAdc;
    int i,u;
    colorStruct white;
    white.R = 255;
    white.G = 255;
    white.B = 255;
    colorStruct off;
    off.R = 0;
    off.G = 0;
    off.B = 0;
    
    FullColor(&matrixColor[0],off);
    
    resultAdc = BSP_ReadAllADC();    
    resultAdc.Chan0 = (1816/1024.0)*resultAdc.Chan0-1000;//conversion from 10bit to volt (100 equal 1V)
    for (row = 0; row < NLED+ 103; row += 128)
    {
        matrixColor[row+2 ] = white;
        matrixColor[row+5 ] = white;
        matrixColor[row+3 ] = white;
        matrixColor[row+4 ] = white;
        matrixColor[row+8 ] = white;
        matrixColor[row+9 ] = white;
        matrixColor[row+10] = white;
        matrixColor[row+11] = white;
        matrixColor[row+12] = white;
        matrixColor[row+13] = white;
        matrixColor[row+14] = white;
        matrixColor[row+15] = white;
        matrixColor[row+16] = white;
        matrixColor[row+24] = white;
        matrixColor[row+32] = white;
        matrixColor[row+40] = white;
        matrixColor[row+48] = white;
        matrixColor[row+56] = white;
        matrixColor[row+64] = white;
        matrixColor[row+72] = white;
        matrixColor[row+80] = white;
        matrixColor[row+88] = white;
        matrixColor[row+96] = white;
        matrixColor[row+98] = white;
        matrixColor[row+99] = white;
        matrixColor[row+100] = white;
        matrixColor[row+101] = white;
        matrixColor[row+102] = white;
        matrixColor[row+103] = white;
        matrixColor[row+23] = white;
        matrixColor[row+31] = white;
        matrixColor[row+39] = white;
        matrixColor[row+47] = white;
        matrixColor[row+55] = white;
        matrixColor[row+63] = white;
        matrixColor[row+71] = white;
        matrixColor[row+79] = white;
        matrixColor[row+87] = white;
        matrixColor[row+95] = white;
        matrixColor[row+97] = white;
        
        for (i = 0;i<10;i++)
        {
            if (i*40 >= 400-resultAdc.Chan0)
            {
                for (u = 1;u<7;u++)
                {
                    matrixColor[row+16+(i*8)+u] = RainbowPick(85);
                }
            }
        }
    }
        
    WriteToLED();
}

