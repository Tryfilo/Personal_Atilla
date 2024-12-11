/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char buffer[12] ;
char *convertInt(int in) {
    sprintf(buffer,"%d",in) ;
    return buffer;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_1_Start() ;
    ADC_SAR_1_Start() ;
    ADC_SAR_1_StartConvert() ;
    PWM_1_Start() ;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    
    int analogValue ;
    int dimmerSetting ;
    for(;;)
    {
        /* Place your application code here. */
        ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT) ;
        analogValue = ADC_SAR_1_GetResult16() ;
        UART_1_PutString(convertInt(analogValue)) ;
        UART_1_PutString("\n\r") ;
        
        dimmerSetting = analogValue >> 2 ;
        Control_Reg_1_Write(analogValue) ;
        Control_Reg_2_Write(analogValue>>5) ;
        
        PWM_1_WriteCompare(dimmerSetting) ;
        
        CyDelay(500) ;
    }
}

/* [] END OF FILE */
