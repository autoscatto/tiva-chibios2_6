/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012,2013 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

/**
 * @file    GCC/ARMCMx/LPC8xx/cmparams.h
 * @brief   ARM Cortex-M0+ parameters for the LPC8xx.
 *
 * @defgroup ARMCMx_LPC8xx LPC8xx Specific Parameters
 * @ingroup ARMCMx_SPECIFIC
 * @details This file contains the Cortex-M0+ specific parameters for the
 *          LPC8xx platform.
 *          (Taken from the device header file where possible)
 * @{
 */

#ifndef _CMPARAMS_H_
#define _CMPARAMS_H_

/**
 * @brief   Cortex core model.
 */
#define CORTEX_MODEL            CORTEX_M4

/**
 * @brief   Memory Protection unit presence.
 */
#define CORTEX_HAS_MPU          1

/**
 * @brief   Floating Point unit presence.
 */
#define CORTEX_HAS_FPU          1

/**
 * @brief   Number of bits in priority masks.
 */
#define CORTEX_PRIORITY_BITS    3

/**
 * @brief   Number of interrupt vectors.
 * @note    This number does not include the 16 system vectors and must be
 *          rounded to a multiple of 8.
 */
#define CORTEX_NUM_VECTORS      112

/* The following code is not processed when the file is included from an
   asm module.*/
#if !defined(_FROM_ASM_)

/* If the device type is not externally defined, for example from the Makefile,
   then a file named board.h is included. This file must contain a device
   definition compatible with the include file.*/
#if !defined(TM4C1290NCPDT) && !defined(TM4C1290NCZAD)                        \
  && !defined(TM4C1292NCPDT) && !defined(TM4C1292NCZAD)                       \
  && !defined(TM4C1294KCPDT) && !defined(TM4C1294NCPDT)                       \
  && !defined(TM4C1294NCZAD) && !defined(TM4C1297NCZAD)                       \
  && !defined(TM4C1299KCZAD) && !defined(TM4C1299NCZAD)                       \
  && !defined(TM4C129CNCPDT) && !defined(TM4C129CNCZAD)                       \
  && !defined(TM4C129DNCPDT) && !defined(TM4C129DNCZAD)                       \
  && !defined(TM4C129EKCPDT) && !defined(TM4C129ENCPDT)                       \
  && !defined(TM4C129ENCZAD) && !defined(TM4C129LNCZAD)                       \
  && !defined(TM4C129XKCZAD) && !defined(TM4C129XNCZAD)
#include "board.h"
#endif

/* Including the device CMSIS header. Note, we are not using the definitions
   from this header because we need this file to be usable also from
   assembler source files. We verify that the info matches instead.*/
#include "tm4c129x.h"

#if !CORTEX_HAS_MPU != !__MPU_PRESENT
#error "CMSIS __MPU_PRESENT mismatch"
#endif

#if !CORTEX_HAS_FPU != !__FPU_PRESENT
#error "CMSIS __FPU_PRESENT mismatch"
#endif

#if CORTEX_PRIORITY_BITS != __NVIC_PRIO_BITS
#error "CMSIS __NVIC_PRIO_BITS mismatch"
#endif

#endif /* !defined(_FROM_ASM_) */

#endif /* _CMPARAMS_H_ */
/** @} */
