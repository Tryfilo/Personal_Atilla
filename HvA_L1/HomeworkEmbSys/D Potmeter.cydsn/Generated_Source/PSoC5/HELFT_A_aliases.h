/*******************************************************************************
* File Name: HELFT_A.h  
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

#if !defined(CY_PINS_HELFT_A_ALIASES_H) /* Pins HELFT_A_ALIASES_H */
#define CY_PINS_HELFT_A_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define HELFT_A_0			(HELFT_A__0__PC)
#define HELFT_A_0_INTR	((uint16)((uint16)0x0001u << HELFT_A__0__SHIFT))

#define HELFT_A_1			(HELFT_A__1__PC)
#define HELFT_A_1_INTR	((uint16)((uint16)0x0001u << HELFT_A__1__SHIFT))

#define HELFT_A_2			(HELFT_A__2__PC)
#define HELFT_A_2_INTR	((uint16)((uint16)0x0001u << HELFT_A__2__SHIFT))

#define HELFT_A_3			(HELFT_A__3__PC)
#define HELFT_A_3_INTR	((uint16)((uint16)0x0001u << HELFT_A__3__SHIFT))

#define HELFT_A_4			(HELFT_A__4__PC)
#define HELFT_A_4_INTR	((uint16)((uint16)0x0001u << HELFT_A__4__SHIFT))

#define HELFT_A_INTR_ALL	 ((uint16)(HELFT_A_0_INTR| HELFT_A_1_INTR| HELFT_A_2_INTR| HELFT_A_3_INTR| HELFT_A_4_INTR))

#endif /* End Pins HELFT_A_ALIASES_H */


/* [] END OF FILE */
