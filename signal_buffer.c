

#include "signal_buffer.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Returns true if Circular Buffer is full
bool sbuf_isfull() {
    if ((sb_front == sb_rear + 1) || (sb_front == 0 && sb_rear == SB_DATA_WINDOW - 1))
        return true;
    else
        return false;
}

// Returns true if Circular Buffer is empty
bool sbuf_isempty() {
    if (sb_front == -1)
        return true;
    else
        return false;
}

// Inserts element into the Circular Buffer
bool sbuf_insert(uint16_t element) {
    if (sbuf_isfull()) {
        // Can't insert data since buffer is full
        return false;
    } 
	
	else {
		
        if (sb_front == -1)
            sb_front = 0;
		
        sb_rear = (sb_rear + 1) % SB_DATA_WINDOW;
        sb_data[sb_rear] = element;
        return true;
    }
}

// Removes element from the Circular Buffer
bool sbuf_remove() {
    uint16_t element;
	
    if (sbuf_isempty()) {
        return false;
    } 
	
	else {
        element = sb_data[sb_front];
        if (sb_front == sb_rear) {
            sb_front = -1;
            sb_rear = -1;
        } else {
            sb_front = (sb_front + 1) % SB_DATA_WINDOW;
        }
        return true;
    }
}

// Returns the first inserted element (FIFO) from the Circular Buffer
uint16_t sbuf_peek(){
  return sb_data[sb_front];
}