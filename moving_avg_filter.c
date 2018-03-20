
#include "signal_buffer.h"
#include "moving_avg_filter.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


bool madata_isfull() {
    if ((ma_front == ma_rear + 1) || (ma_front == 0 && ma_rear == MA_DATA_WINDOW - 1))
        return true;
    else
        return false;
}

bool madata_isempty() {
    if (ma_front == -1)
        return true;
    else
        return false;
}

bool madata_insert(uint16_t element) {
    if (madata_isfull()) {
        // Can't insert data because buffer is full
        return false;
    } else {
        if (ma_front == -1)
            ma_front = 0;
        ma_rear = (ma_rear + 1) % MA_DATA_WINDOW;
        ma_data[ma_rear] = element;
        return true;
    }
}

bool madata_remove() {
    uint16_t element;
    if (madata_isempty()) {
        return false;
    } else {
        element = ma_data[ma_front];
        if (ma_front == ma_rear) {
            ma_front = -1;
            ma_rear = -1;
        } else {
            ma_front = (ma_front + 1) % MA_DATA_WINDOW;
        }
        return true;
    }
}