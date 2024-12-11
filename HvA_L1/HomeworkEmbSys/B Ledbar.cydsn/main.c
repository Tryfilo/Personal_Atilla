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

    for(;;)
    {
        HELFT_B_Write(1);
        CyDelay(1000);
        HELFT_B_Write(2);
        CyDelay(100);
        HELFT_A_Write(15);
        CyDelay(1000);
        HELFT_A_Write(31);
        CyDelay(1000);
    }
}

/* [] END OF FILE */
