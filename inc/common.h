/*
 * common.h
 *
 *  Created on: Apr 9, 2016
 *      Author: gustavo
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define COMP(_a, _b) memcmp((void *) _a, (void *) _b, sizeof(_a))

#endif /* INC_COMMON_H_ */
