/*******************************************************************************
* File Name: Pin_3.h  
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

#if !defined(CY_PINS_Pin_3_ALIASES_H) /* Pins Pin_3_ALIASES_H */
#define CY_PINS_Pin_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_3_0			(Pin_3__0__PC)
#define Pin_3_0_INTR	((uint16)((uint16)0x0001u << Pin_3__0__SHIFT))

#define Pin_3_1			(Pin_3__1__PC)
#define Pin_3_1_INTR	((uint16)((uint16)0x0001u << Pin_3__1__SHIFT))

#define Pin_3_2			(Pin_3__2__PC)
#define Pin_3_2_INTR	((uint16)((uint16)0x0001u << Pin_3__2__SHIFT))

#define Pin_3_3			(Pin_3__3__PC)
#define Pin_3_3_INTR	((uint16)((uint16)0x0001u << Pin_3__3__SHIFT))

#define Pin_3_4			(Pin_3__4__PC)
#define Pin_3_4_INTR	((uint16)((uint16)0x0001u << Pin_3__4__SHIFT))

#define Pin_3_INTR_ALL	 ((uint16)(Pin_3_0_INTR| Pin_3_1_INTR| Pin_3_2_INTR| Pin_3_3_INTR| Pin_3_4_INTR))

#endif /* End Pins Pin_3_ALIASES_H */


/* [] END OF FILE */
