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
    int output = 0x0;
    int output2; 
    for(;;)
    {
        if ( Pin_1_Read() == 1 ) {
            HELFT_A_Write(output) ;
            output2 = output >> 5 ;
            HELFT_B_Write(output2) ;
            CyDelay(500) ;
            output++ ;
        }
    }
}

/* [] END OF FILE */
