/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simple_filters.h
 * Author: Federico
 *
 * Created on 23 maggio 2024, 12.13
 */

#ifndef SIMPLE_FILTERS_H
#define SIMPLE_FILTERS_H

#include "stdint.h"

void moving_average_filter(uint32_t [], uint32_t [], uint16_t, uint8_t);
void low_pass_filter(uint32_t [], uint32_t [], uint16_t, float);
void high_pass_filter_flat(uint32_t [], uint16_t);
#endif /* SIMPLE_FILTERS_H */

