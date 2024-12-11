/*******************************************************************************
* File Name: HELFT_B_1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_HELFT_B_1_ALIASES_H) /* Pins HELFT_B_1_ALIASES_H */
#define CY_PINS_HELFT_B_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define HELFT_B_1_0			(HELFT_B_1__0__PC)
#define HELFT_B_1_0_INTR	((uint16)((uint16)0x0001u << HELFT_B_1__0__SHIFT))

#define HELFT_B_1_1			(HELFT_B_1__1__PC)
#define HELFT_B_1_1_INTR	((uint16)((uint16)0x0001u << HELFT_B_1__1__SHIFT))

#define HELFT_B_1_2			(HELFT_B_1__2__PC)
#define HELFT_B_1_2_INTR	((uint16)((uint16)0x0001u << HELFT_B_1__2__SHIFT))

#define HELFT_B_1_3			(HELFT_B_1__3__PC)
#define HELFT_B_1_3_INTR	((uint16)((uint16)0x0001u << HELFT_B_1__3__SHIFT))

#define HELFT_B_1_4			(HELFT_B_1__4__PC)
#define HELFT_B_1_4_INTR	((uint16)((uint16)0x0001u << HELFT_B_1__4__SHIFT))

#define HELFT_B_1_INTR_ALL	 ((uint16)(HELFT_B_1_0_INTR| HELFT_B_1_1_INTR| HELFT_B_1_2_INTR| HELFT_B_1_3_INTR| HELFT_B_1_4_INTR))

#endif /* End Pins HELFT_B_1_ALIASES_H */


/* [] END OF FILE */
