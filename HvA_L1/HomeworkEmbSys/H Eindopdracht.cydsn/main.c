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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    int pong1[6] = {1, 2, 4, 8, 16, 0} ;
    int pong2[7] = {16, 8, 4, 2, 1, 0, 0} ;
    int Delay[12] = {600, 600, 500, 500, 400, 400, 300, 300, 200, 200, 100, 100} ;
    int lives_display[6] = {0, 1, 3, 7, 15, 31} ;
    int livesA = 5 ;
    int livesB = 5 ;
    int i ;
    int Delaycount = 0 ;
    UART_1_Start() ;
    for (;;) {
        
        UART_1_PutString("Press the left button to start\n\r") ;
        if (Pin_3_Read() == 1) {
    for (;;) {
       
        for (i = 0; i <= 4; i++) {
            Pin_1_Write(pong1[i]) ;
            CyDelay(Delay[Delaycount]) ;
        }
        Pin_1_Write(0) ;
        for (i = 0; i <=5; i++) {
            Pin_2_Write(pong2[i]) ;
            CyDelay(Delay[Delaycount]) ;
            if (Pin_4_Read() == 1) {
                if (i == 3 || i == 4) {
                    Delaycount ++ ;
                    i = 5 ;
                    break ;   
                } else {
                    livesB -- ;
                    i = 6 ;
                    Delaycount = 0 ;
                    Pin_1_Write(lives_display[livesA]) ;
                    Pin_2_Write(lives_display[livesB]) ;
                    CyDelay(400) ;
                    Pin_1_Write(0) ;
                    Pin_2_Write(0) ;
                    if (livesA == 5) {
                    UART_1_PutString("\n\rPlayer 1 has 5 lives") ;
                    } else if (livesA == 4) {
                    UART_1_PutString("\n\rPlayer 1 has 4 lives") ;
                    } else if (livesA == 3) {
                    UART_1_PutString("\n\rPlayer 1 has 3 lives") ;
                    } else if (livesA == 2) {
                    UART_1_PutString("\n\rPlayer 1 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 1 has 1 lives") ;
                    }
                    if (livesB == 5) {
                    UART_1_PutString("\n\rPlayer 2 has 5 lives") ;
                    } else if (livesB == 4) {
                    UART_1_PutString("\n\rPlayer 2 has 4 lives") ;
                    } else if (livesB == 3) {
                    UART_1_PutString("\n\rPlayer 2 has 3 lives") ;
                    } else if (livesB == 2) {
                    UART_1_PutString("\n\rPlayer 2 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 2 has 1 lives") ;
                    }
                    break ;
                }
            } else if (i == 5) {
                livesB -- ;
                Delaycount = 0 ;
                Pin_1_Write(lives_display[livesA]) ;
                Pin_2_Write(lives_display[livesB]) ;
                CyDelay(400) ;
                Pin_1_Write(0) ;
                Pin_2_Write(0) ;
                if (livesA == 5) {
                    UART_1_PutString("\n\rPlayer 1 has 5 lives") ;
                    } else if (livesA == 4) {
                    UART_1_PutString("\n\rPlayer 1 has 4 lives") ;
                    } else if (livesA == 3) {
                    UART_1_PutString("\n\rPlayer 1 has 3 lives") ;
                    } else if (livesA == 2) {
                    UART_1_PutString("\n\rPlayer 1 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 1 has 1 lives") ;
                    }
                    if (livesB == 5) {
                    UART_1_PutString("\n\rPlayer 2 has 5 lives") ;
                    } else if (livesB == 4) {
                    UART_1_PutString("\n\rPlayer 2 has 4 lives") ;
                    } else if (livesB == 3) {
                    UART_1_PutString("\n\rPlayer 2 has 3 lives") ;
                    } else if (livesB == 2) {
                    UART_1_PutString("\n\rPlayer 2 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 2 has 1 lives") ;
                    }
            }
        }
        if (livesB == 0) {
            UART_1_PutString("\n\rPlayer 1 won!") ;
            Pin_1_Write(0) ;
            Pin_2_Write(0) ;
            CyDelay(5000) ;
            break ;
           
        }
          
        for (i = 0; i <= 4; i++) {
            Pin_2_Write(pong1[i]) ;
            CyDelay(Delay[Delaycount]) ;
        }
        Pin_2_Write(0) ;
        for (i = 0; i <=5; i++) {
            Pin_1_Write(pong2[i]) ;
            CyDelay(Delay[Delaycount]) ;
            if (Pin_3_Read() == 1) {
                if (i == 3 || i == 4) {
                    Delaycount ++ ;
                    i = 6;
                    break ;   
                } else {
                    livesA -- ;
                    Delaycount = 0 ;
                    Pin_1_Write(lives_display[livesA]) ;
                    Pin_2_Write(lives_display[livesB]) ;
                    CyDelay(400) ;
                    Pin_1_Write(0) ;
                    Pin_2_Write(0) ;
                    if (livesA == 5) {
                    UART_1_PutString("\n\rPlayer 1 has 5 lives") ;
                    } else if (livesA == 4) {
                    UART_1_PutString("\n\rPlayer 1 has 4 lives") ;
                    } else if (livesA == 3) {
                    UART_1_PutString("\n\rPlayer 1 has 3 lives") ;
                    } else if (livesA == 2) {
                    UART_1_PutString("\n\rPlayer 1 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 1 has 1 lives") ;
                    }
                    if (livesB == 5) {
                    UART_1_PutString("\n\rPlayer 2 has 5 lives") ;
                    } else if (livesB == 4) {
                    UART_1_PutString("\n\rPlayer 2 has 4 lives") ;
                    } else if (livesB == 3) {
                    UART_1_PutString("\n\rPlayer 2 has 3 lives") ;
                    } else if (livesB == 2) {
                    UART_1_PutString("\n\rPlayer 2 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 2 has 1 lives") ;
                    }
                    break ;
                }
            } else if (i == 5) {
                livesA -- ;
                Pin_1_Write(lives_display[livesA]) ;
                Pin_2_Write(lives_display[livesB]) ;
                Delaycount = 0 ;
                CyDelay(400) ;
                Pin_1_Write(0) ;
                Pin_2_Write(0) ;
                if (livesA == 5) {
                    UART_1_PutString("\n\rPlayer 1 has 5 lives") ;
                    } else if (livesA == 4) {
                    UART_1_PutString("\n\rPlayer 1 has 4 lives") ;
                    } else if (livesA == 3) {
                    UART_1_PutString("\n\rPlayer 1 has 3 lives") ;
                    } else if (livesA == 2) {
                    UART_1_PutString("\n\rPlayer 1 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 1 has 1 lives") ;
                    }
                    if (livesB == 5) {
                    UART_1_PutString("\n\rPlayer 2 has 5 lives") ;
                    } else if (livesB == 4) {
                    UART_1_PutString("\n\rPlayer 2 has 4 lives") ;
                    } else if (livesB == 3) {
                    UART_1_PutString("\n\rPlayer 2 has 3 lives") ;
                    } else if (livesB == 2) {
                    UART_1_PutString("\n\rPlayer 2 has 2 lives") ;
                    } else {
                    UART_1_PutString("\n\rPlayer 2 has 1 lives") ;
                    }
            }
        }
        if (livesA == 0 ) {
            UART_1_PutString("\n\rPlayer 2 has won!") ;
            Pin_1_Write(0) ;
            Pin_2_Write(0) ;
            CyDelay(5000) ;
            break ;
        }
    }
} else {
} 
}
} 
/* [] END OF FILE */
