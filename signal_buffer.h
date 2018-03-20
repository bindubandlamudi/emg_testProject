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

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SIGNAL_BUFFER_H
#define	_SIGNAL_BUFFER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/mcc.h"

// Size of (circular)buffer for acquired EMG samples
#define SB_DATA_WINDOW 50

// Sampling frequency of signal. 50Hz = 20ms (Timer interrupt configured to 20ms)
#define SAMPLE_FREQUENCY 50
#define MIN_FREQUENCY 25
#define MAX_FREQUENCY 150

// The minimum distance in data points that two registered peaks can be
#define MIN_PK_GAP ((int)(SAMPLE_FREQUENCY / MAX_FREQUENCY))
// The maximum distance two consecutive peaks can be without significantly shifting the calculated neutral-point  
#define MAX_PK_GAP ((int)(SAMPLE_FREQUENCY / MIN_FREQUENCY))

uint16_t sb_data[SB_DATA_WINDOW];
int8_t sb_front = -1;               
int8_t sb_rear = -1;

bool sbuf_isfull(void);
bool sbuf_isempty(void);
bool sbuf_insert(uint16_t element);
bool sbuf_remove(void);
uint16_t sbuf_peek(void);


#endif	/* _SIGNAL_BUFFER_H */

