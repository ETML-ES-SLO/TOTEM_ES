/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

colorStruct matrixColor[NLED]; 
uint8_t brightness = 20;        //brightness in percent



void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    static int u = 0,i = 0;
    S_ADCResults resultAdc;
    static int valPeriod = 30000;
    static char charChain[200] = "Totem";
    static colorStruct color;
    static colorStruct off;
    off.R = 0;
    off.G = 0;
    off.B = 0;
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            
            //DRV_TMR0_Start();
            
            DRV_SPI0_Initialize();
            DRV_TMR0_Start();
            
            appData.state = APP_STATE_SERVICE_TASKS;
            FullColor(&matrixColor[0],off);
            WriteToLED();
            color.B = 100;
            color.R = 0;
            color.G = 0;
            PLIB_TMR_Period16BitSet(TMR_ID_1,valPeriod);   
            
            BSP_InitADC0();
            
            APP_UpdateState (APP_STATE_WAIT);
            
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            //AutoBrightness();
            if (PLIB_TMR_Period16BitGet(TMR_ID_1) != valPeriod)
            {
                PLIB_TMR_Period16BitSet(TMR_ID_1,valPeriod);
            }
            
            //Battery (&matrixColor);
            //Text (&charChain[0],color,&matrixColor[0],true);
            Nyan(&matrixColor[0]);
            //FullColor(&matrixColor[0],color);
            //WriteToLED();
            
            /*
            //mooving rainbow
            for (i = 0; i<NLED;i++)
            {
                matrixColor[i]=RainbowPick((i+u)*2);
            }
            u+=8;
            WriteToLED();
            
            if (u == 0)
            {
                matrixColor[0].R = 255;
                color.G = 0;
                color.B = 0;
    PLIB_PORTS_PinToggle(0,1,6);
            WriteToLED();
    PLIB_PORTS_PinToggle(0,1,6);
            u = 1;
            }*/ 
            APP_UpdateState (APP_STATE_WAIT);
            break;
        }
        case APP_STATE_WAIT:
        {
            
            break;
        }

        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


//fonction that will set the brightness base on the exterior brightness.
//the fonction haven't been tested proprely on various luminosity so it probably need somne tuning
//if the software tuning isn't enough, see the resistor R11 on the board.
void AutoBrightness(void)
{
    //the speed at which the luminosity change rely on the interupt 1 (the fastest the interrupt the fastest the luminosity change).
    S_ADCResults resultAdc;
    static int i = 0;   //i is used to avoid brutal luminosity transition 
    resultAdc = BSP_ReadAllADC();
    resultAdc.Chan1 = log10f(resultAdc.Chan1)*(1024/log10f(1024));  //the luminosity that the ADC read is on a log scale so this formula change it to linear.
    //due to the non-linearity of the reading value the lowest the luminosity is the lowest the resolution is.
    brightness = resultAdc.Chan1/20+1;
    if (i < brightness *3)
    {
        i++;
    }
    else if(i > brightness*3)
    {
        i--;
    }
    brightness = i/3;
}

void FullColor(colorStruct* matrixColor,colorStruct color)  //Set the same color on the matrix
{
    int i;
    for(i = 0;i < NLED;i++)
    {
        matrixColor[i] = color;
    }
}

colorStruct RandomColor(void)           //return a "random" color from the rainbow fonction
{
    return RainbowPick(rand()/16777216);    //this fonction need to be call externally (from a button for instance) to be truly random since it's based on the internal clock of the pic
}

colorStruct RainbowPick (uint8_t colorIndex)    //return a color within the rainbow spectrum.
{                                               //the fonction can't return white and have a resolution of 256 color.
    colorStruct color;                          //the color go from 0 red to 85 green to 170 blue and 255 back to red
    color.R = 0;
    color.G = 0;
    color.B = 0;
    if ( colorIndex >= 170)
    {
        color.B = (85- ( colorIndex-170))*3;
        color.R = (colorIndex-170)*3;
    }
    else if (colorIndex >= 85)
    {
        color.G = (85 -(colorIndex - 85))*3;
        color.B = (colorIndex-85)*3;
    }
    else
    {
        color.R = (85 - colorIndex)*3;
        color.G = colorIndex*3;
    }
    return color;
}
 
void APP_UpdateState ( APP_STATES NewState )
{
    appData.state = NewState;
}


void BSP_InitADC0(void) //this fonction were copy from the Mc32DriverAdc.c file
{
    // Configure l'ADC

    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, 0x00C0) ;   // liste des AN à scanner 
    PLIB_ADC_ResultFormatSelect(ADC_ID_1, ADC_RESULT_FORMAT_INTEGER_16BIT);
    PLIB_ADC_ResultBufferModeSelect(ADC_ID_1, ADC_BUFFER_MODE_TWO_8WORD_BUFFERS);
    PLIB_ADC_SamplingModeSelect(ADC_ID_1, ADC_SAMPLING_MODE_MUXA);

    PLIB_ADC_ConversionTriggerSourceSelect(ADC_ID_1, ADC_CONVERSION_TRIGGER_INTERNAL_COUNT);
    PLIB_ADC_VoltageReferenceSelect(ADC_ID_1, ADC_REFERENCE_VDD_TO_AVSS );
    PLIB_ADC_SampleAcquisitionTimeSet(ADC_ID_1, 0x1F);
    PLIB_ADC_ConversionClockSet(ADC_ID_1, SYS_CLK_FREQ, 32);

    // Rem CHR le nb d'échantillon par interruption doit correspondre au nb d'entrées
    // de la liste de scan
    PLIB_ADC_SamplesPerInterruptSelect(ADC_ID_1, ADC_2SAMPLES_PER_INTERRUPT);
    PLIB_ADC_MuxAInputScanEnable(ADC_ID_1);

    // Enable the ADC module
    PLIB_ADC_Enable(ADC_ID_1);

 }

S_ADCResults BSP_ReadAllADC()//this fonction were copy from the Mc32DriverAdc.c file
{
    S_ADCResults result;
    ADC_RESULT_BUF_STATUS BufStatus;

    // Auto start sampling
    // PLIB_ADC_SampleAutoStartEnable(ADC_ID_1);

    // Attente fin de conversion
    //    while (!PLIB_ADC_ConversionHasCompleted(ADC_ID_1))

    // Stop sample/convert
    PLIB_ADC_SampleAutoStartDisable(ADC_ID_1);

    // traitement avec buffer alterné
    BufStatus = PLIB_ADC_ResultBufferStatusGet(ADC_ID_1);
    if (BufStatus == ADC_FILLING_BUF_0TO7) {
        result.Chan0 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 0);
        result.Chan1 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 1);
    } else {
        result.Chan0 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 8);
        result.Chan1 = PLIB_ADC_ResultGetByIndex(ADC_ID_1, 9);
    }

    // Auto start sampling
    PLIB_ADC_SampleAutoStartEnable(ADC_ID_1);

    return result;
}
/*******************************************************************************
 End of File
 */
