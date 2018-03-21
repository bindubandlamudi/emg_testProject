/**
  EMG Peak to Peak Filter Header file 

  @File Name
    peak_filter.h

  @Description
    This is the implementation file for processing of EMG Signal data from an EMG click by MikroElektronika       
    This file buffers and performs operations on the pk_data Circular Buffer 
    The pk_data buffer is helpful in calculating a neutral peak value for a certain window of acquired samples
*/

/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _PEAK_FILTER_H
#define	_PEAK_FILTER_H

/*******************************************************************************************************/
/*******************************************************************************************************/


/**
  Section: Included Files
*/
#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/mcc.h"
#include "signal_buffer.h"


/*******************************************************************************************************/
/*******************************************************************************************************/

/**
 Section: Macro Definitions
*/

// Size of (circular) buffer for Peak Filter i.e., Twice the maximum gap
#define PK_DATA_WINDOW (2*MAX_PK_GAP+1)


/*******************************************************************************************************/
/*******************************************************************************************************/


/**
 Section: Variable Declarations
*/


// Buffer for Peak Filter and indices for the Circular Buffer
uint16_t pk_data[PK_DATA_WINDOW];

/*
 Arrays in C start from the Index 0. A 0 index on the circular buffer indicates there is already an element present in Array[0] 
 Hence we begin the front and rear pointers of each circular buffer with '-1', so that every advance in the pointer indicates the buffer has an element
 This implementation is used for all three circular buffers used : sb_data (Signal Buffer), pk_data (Peak to Peak Filter) and, ma_data (Moving Average Filter) 
 */
int8_t pk_front = -1;
int8_t pk_rear = -1;


/*******************************************************************************************************/
/*******************************************************************************************************/


/**
  Section: Function definitions
*/ 

/**
  @Function
    Color_Initialize
  @Summary
    Initializes the Color sensor Click Board

  @Description
    This routine issues commands to initialize the color sensor click board. The module does a I2C write
    to the enable the click board.

  @Param
    None

  @Returns
    None

 */
bool pkdata_isfull(void);


/*******************************************************************************************************/
/*******************************************************************************************************/


/**
  @Function
    Color_Initialize
  @Summary
    Initializes the Color sensor Click Board

  @Description
    This routine issues commands to initialize the color sensor click board. The module does a I2C write
    to the enable the click board.

  @Param
    None

  @Returns
    None

 */
bool pkdata_isempty(void);


/*******************************************************************************************************/
/*******************************************************************************************************/


/**
  @Function
    Color_Initialize
  @Summary
    Initializes the Color sensor Click Board

  @Description
    This routine issues commands to initialize the color sensor click board. The module does a I2C write
    to the enable the click board.

  @Param
    None

  @Returns
    None

 */
bool pkdata_insert(uint16_t element);


/*******************************************************************************************************/
/*******************************************************************************************************/


/**
  @Function
    Color_Initialize
  @Summary
    Initializes the Color sensor Click Board

  @Description
    This routine issues commands to initialize the color sensor click board. The module does a I2C write
    to the enable the click board.

  @Param
    None

  @Returns
    None

 */
bool pkdata_remove(void);


#endif	/* _PEAK_FILTER_H */
/**
 End of File
*/
