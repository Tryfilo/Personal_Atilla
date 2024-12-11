/*******************************************************************************
* File Name: Outdiv2.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Outdiv2_H) /* Pins Outdiv2_H */
#define CY_PINS_Outdiv2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Outdiv2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Outdiv2__PORT == 15 && ((Outdiv2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Outdiv2_Write(uint8 value);
void    Outdiv2_SetDriveMode(uint8 mode);
uint8   Outdiv2_ReadDataReg(void);
uint8   Outdiv2_Read(void);
void    Outdiv2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Outdiv2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Outdiv2_SetDriveMode() function.
     *  @{
     */
        #define Outdiv2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Outdiv2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Outdiv2_DM_RES_UP          PIN_DM_RES_UP
        #define Outdiv2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Outdiv2_DM_OD_LO           PIN_DM_OD_LO
        #define Outdiv2_DM_OD_HI           PIN_DM_OD_HI
        #define Outdiv2_DM_STRONG          PIN_DM_STRONG
        #define Outdiv2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Outdiv2_MASK               Outdiv2__MASK
#define Outdiv2_SHIFT              Outdiv2__SHIFT
#define Outdiv2_WIDTH              1u

/* Interrupt constants */
#if defined(Outdiv2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Outdiv2_SetInterruptMode() function.
     *  @{
     */
        #define Outdiv2_INTR_NONE      (uint16)(0x0000u)
        #define Outdiv2_INTR_RISING    (uint16)(0x0001u)
        #define Outdiv2_INTR_FALLING   (uint16)(0x0002u)
        #define Outdiv2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Outdiv2_INTR_MASK      (0x01u) 
#endif /* (Outdiv2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Outdiv2_PS                     (* (reg8 *) Outdiv2__PS)
/* Data Register */
#define Outdiv2_DR                     (* (reg8 *) Outdiv2__DR)
/* Port Number */
#define Outdiv2_PRT_NUM                (* (reg8 *) Outdiv2__PRT) 
/* Connect to Analog Globals */                                                  
#define Outdiv2_AG                     (* (reg8 *) Outdiv2__AG)                       
/* Analog MUX bux enable */
#define Outdiv2_AMUX                   (* (reg8 *) Outdiv2__AMUX) 
/* Bidirectional Enable */                                                        
#define Outdiv2_BIE                    (* (reg8 *) Outdiv2__BIE)
/* Bit-mask for Aliased Register Access */
#define Outdiv2_BIT_MASK               (* (reg8 *) Outdiv2__BIT_MASK)
/* Bypass Enable */
#define Outdiv2_BYP                    (* (reg8 *) Outdiv2__BYP)
/* Port wide control signals */                                                   
#define Outdiv2_CTL                    (* (reg8 *) Outdiv2__CTL)
/* Drive Modes */
#define Outdiv2_DM0                    (* (reg8 *) Outdiv2__DM0) 
#define Outdiv2_DM1                    (* (reg8 *) Outdiv2__DM1)
#define Outdiv2_DM2                    (* (reg8 *) Outdiv2__DM2) 
/* Input Buffer Disable Override */
#define Outdiv2_INP_DIS                (* (reg8 *) Outdiv2__INP_DIS)
/* LCD Common or Segment Drive */
#define Outdiv2_LCD_COM_SEG            (* (reg8 *) Outdiv2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Outdiv2_LCD_EN                 (* (reg8 *) Outdiv2__LCD_EN)
/* Slew Rate Control */
#define Outdiv2_SLW                    (* (reg8 *) Outdiv2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Outdiv2_PRTDSI__CAPS_SEL       (* (reg8 *) Outdiv2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Outdiv2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Outdiv2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Outdiv2_PRTDSI__OE_SEL0        (* (reg8 *) Outdiv2__PRTDSI__OE_SEL0) 
#define Outdiv2_PRTDSI__OE_SEL1        (* (reg8 *) Outdiv2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Outdiv2_PRTDSI__OUT_SEL0       (* (reg8 *) Outdiv2__PRTDSI__OUT_SEL0) 
#define Outdiv2_PRTDSI__OUT_SEL1       (* (reg8 *) Outdiv2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Outdiv2_PRTDSI__SYNC_OUT       (* (reg8 *) Outdiv2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Outdiv2__SIO_CFG)
    #define Outdiv2_SIO_HYST_EN        (* (reg8 *) Outdiv2__SIO_HYST_EN)
    #define Outdiv2_SIO_REG_HIFREQ     (* (reg8 *) Outdiv2__SIO_REG_HIFREQ)
    #define Outdiv2_SIO_CFG            (* (reg8 *) Outdiv2__SIO_CFG)
    #define Outdiv2_SIO_DIFF           (* (reg8 *) Outdiv2__SIO_DIFF)
#endif /* (Outdiv2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Outdiv2__INTSTAT)
    #define Outdiv2_INTSTAT            (* (reg8 *) Outdiv2__INTSTAT)
    #define Outdiv2_SNAP               (* (reg8 *) Outdiv2__SNAP)
    
	#define Outdiv2_0_INTTYPE_REG 		(* (reg8 *) Outdiv2__0__INTTYPE)
#endif /* (Outdiv2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Outdiv2_H */


/* [] END OF FILE */
