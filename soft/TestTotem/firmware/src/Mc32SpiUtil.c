// Mc32SpiUtil.C
// Utilitaire  SPI
//
//	Description : 	fonctions SPI CCS like
//	Auteur 		: 	C. HUBER
//      Création	: 	08.04.2014
//      Modifications   :       09.02.2015 CHR

//  LISTE DES MODIFICATIONS :
//      Utilisation des stdint                  09.02.2015 CHR
//      Adaptation à la plib_spi                09.02.2015 CHR
//      maj version compilateur et Harmony      24.05.2016 CHR
//      Correction de la séquence de lecture    25.05.2016 CHR
//      Version KIT     PCB 11020_B
//	Version		:	V1.2
//	Compilateur	:	XC32 V1.40 + Harmony 1.06
//
/*--------------------------------------------------------*/

// #define MARKER_READ 1

#include "app.h"
#include "Mc32SpiUtil.h"
#include "peripheral\SPI\plib_spi.h"


void spi_write1( uint8_t Val){
   int SpiBusy;
   
   PLIB_SPI_BufferWrite(SPI_ID_1, Val);

   do {
     SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
   } while (SpiBusy == 1);
}

void WriteToLED(){
   int i,u = 0; //counter
   uint8_t R[8],G[8],B[8];  //SPI data  of the color, evry variable contain two bit
   uint8_t red,green,blue;  //8bit data of the color
   int index = 0;
   Nop();
   
   Led_Set();

    for (i = 0;i<NLED;i++)       
    {
        if ((i/8)%2 == 1)   //this part is used to reassigned the number of each LED
        {
            index = i-(i%8);
            index += 7-(i - index);
        }
        else 
        {
            index = i;
        }
        
        
        //red convertion
        red = matrixColor[index].R/100.0 * brightness;
        for (u = 7; u>=0;u--)
        {
            if(red>>7 == 1)
            {
                R[u]=0b1110;  //1
            }
            else
            {
                R[u]=0b1000;  //0
            }
            if (u%2 == 1)   //if u is odd, shift the LSB to MSB
            {
                R[u] = R[u]<<4;
            }
            red = red<<1;
        }
        
        
        //Green convertion
        green = matrixColor[index].G/100.0 * brightness;
        for (u = 7; u>=0;u--)
        {
            if(green>>7 == 1)
            {
                G[u]=0b1110;  //1
            }
            else
            {
                G[u]=0b1000;  //0
            }
            if (u%2 == 1)   //if u is odd, shift the LSB to MSB
            {
                G[u] = G[u]<<4;
            }
            green = green<<1;
        }
        
        
        //Blue convertion
        blue = matrixColor[index].B/100.0 * brightness;
        for (u = 7; u>=0;u--)
        {
            if(blue>>7 == 1)
            {
                B[u]=0b1110;  //1
            }
            else
            {
                B[u]=0b1000;  //0
            }
            if (u%2 == 1)   //if u is odd, shift the LSB to MSB
            {
                B[u] = B[u]<<4;
            }
            blue = blue<<1;
        }
  
        
        //The solution with the "while" is not really pretty but effective.
        //This solution avoid the buffer from running empty or overflow
        //on the other hand all the while stop the program for an important amount of time
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, G[7]+G[6]);     //bit one and two, green
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, G[5]+G[4]);     //bit three and four, greem
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, G[3]+G[2]);     //bit five and six, green
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, G[1]+G[0]);     //bit seven and eight, green
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, R[7]+R[6]);     //bit one and two, red
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, R[5]+R[4]);     //bit three and four, red
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, R[3]+R[2]);     //bit five and six, red
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, R[1]+R[0]);     //bit seven and eight, red
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, B[7]+B[6]);     //bit one and two, blue
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, B[5]+B[4]);     //bit three and four, blue
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, B[3]+B[2]);     //bit five and six, blue
        while(PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 1){}
        PLIB_SPI_BufferWrite(SPI_ID_2, B[1]+B[0]);     //bit seven and eight, blue
    }
    Led_Set();
}

void Led_Set(void)
{
    //This fonction is used to tell the LED to display the trams that they recived
    //Bloc the program for about 50us
    int SpiBusy;
    int i;
    for(i = 0;i<=25;)
    {
        if (PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) == 0)
        {
            PLIB_SPI_BufferWrite(SPI_ID_2,0);
            i ++;
        }
    }
}

uint8_t spi_read1( uint8_t Val){
   int SpiBusy;  
   uint32_t lu;
   
   PLIB_SPI_BufferWrite(SPI_ID_1, Val);
   // Attends fin transmission
   do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ;
   } while (SpiBusy == 1);
   
   // Attend arrivée dans fifo
   while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1));
#ifdef MARKER_READ
   LED3_W  = 1;
#endif
   lu = PLIB_SPI_BufferRead(SPI_ID_1);
#ifdef MARKER_READ
   LED3_W  = 0;
#endif
   return lu;
}

 uint8_t spi_read2( uint8_t Val){
   int SpiBusy;
   uint8_t lu;
   
   PLIB_SPI_BufferWrite(SPI_ID_2, Val);
  
   do {
      SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_2) ;
   } while (SpiBusy == 1);
   
   // Attend arrivée dans fifo
   while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_2));
   
   lu = PLIB_SPI_BufferRead(SPI_ID_2);
   return lu;
}



