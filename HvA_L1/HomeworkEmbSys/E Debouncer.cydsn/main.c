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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    ADC_SAR_1_Start() ; 
    ADC_SAR_1_StartConvert() ;
    
    int output = 10 ;
    
    output = 0b0000000001 ;
    
    for(;;)
    {
        output = ADC_SAR_1_GetResult16() ;
        HELFT_A_Write(output) ;
        HELFT_B_Write(output>>5) ;
        
        
    }
}

/* [] END OF FILE */
