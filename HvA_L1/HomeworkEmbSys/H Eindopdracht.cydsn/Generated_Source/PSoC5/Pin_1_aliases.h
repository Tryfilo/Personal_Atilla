/*******************************************************************************
* File Name: Pin_1.h  
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

#if !defined(CY_PINS_Pin_1_ALIASES_H) /* Pins Pin_1_ALIASES_H */
#define CY_PINS_Pin_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_1_0			(Pin_1__0__PC)
#define Pin_1_0_INTR	((uint16)((uint16)0x0001u << Pin_1__0__SHIFT))

#define Pin_1_1			(Pin_1__1__PC)
#define Pin_1_1_INTR	((uint16)((uint16)0x0001u << Pin_1__1__SHIFT))

#define Pin_1_2			(Pin_1__2__PC)
#define Pin_1_2_INTR	((uint16)((uint16)0x0001u << Pin_1__2__SHIFT))

#define Pin_1_3			(Pin_1__3__PC)
#define Pin_1_3_INTR	((uint16)((uint16)0x0001u << Pin_1__3__SHIFT))

#define Pin_1_4			(Pin_1__4__PC)
#define Pin_1_4_INTR	((uint16)((uint16)0x0001u << Pin_1__4__SHIFT))

#define Pin_1_INTR_ALL	 ((uint16)(Pin_1_0_INTR| Pin_1_1_INTR| Pin_1_2_INTR| Pin_1_3_INTR| Pin_1_4_INTR))

#endif /* End Pins Pin_1_ALIASES_H */


/* [] END OF FILE */
