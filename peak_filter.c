

#include "signal_buffer.h"
#include "peak_filter.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool pkdata_isfull() {
    if ((pk_front == pk_rear + 1) || (pk_front == 0 && pk_rear == PK_DATA_WINDOW - 1))
        return true;
    else
        return false;
}

// Similar Circular Buffer functions for Peak Filter

bool pkdata_isempty() {
    if (pk_front == -1)
        return true;
    else
        return false;
}

bool pkdata_insert(uint16_t element) {
    if (pkdata_isfull()) {
        // Can't insert data because buffer is full
        return false;
    } else {
        if (pk_front == -1)
            pk_front = 0;
        pk_rear = (pk_rear + 1) % PK_DATA_WINDOW;
        pk_data[pk_rear] = element;
        return true;
    }
}

bool pkdata_remove() {
    uint16_t element;
    if (pkdata_isempty()) {
        return false;
    } else {
        element = pk_data[pk_front];
        if (pk_front == pk_rear) {
            pk_front = -1;
            pk_rear = -1;
        } else {
            pk_front = (pk_front + 1) % PK_DATA_WINDOW;
        }
        return true;
    }
}
