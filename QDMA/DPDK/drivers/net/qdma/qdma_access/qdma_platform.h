/*
 * Copyright(c) 2019 Xilinx, Inc. All rights reserved.
 *
 * BSD LICENSE
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LIBQDMA_QDMA_PLATFORM_H_
#define LIBQDMA_QDMA_PLATFORM_H_

#include "qdma_access.h"
#include "qdma_access_export.h"
#include "qdma_platform_env.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * DOC: QDMA platform specific interface definitions
 *
 * Header file *qdma_platform_env.h* defines function signatures that are
 * required to be implemented by platform specific drivers.
 */

/*****************************************************************************/
/**
 * qdma_calloc(): allocate memory and initialize with 0
 *
 * @num_blocks:  number of blocks of contiguous memory of @size
 * @size:    size of each chunk of memory
 *
 * Return: pointer to the memory block created on success and NULL on failure
 *****************************************************************************/
void *qdma_calloc(uint32_t num_blocks, uint32_t size);

/*****************************************************************************/
/**
 * qdma_memfree(): free the memory
 *
 * @memptr:  pointer to the memory block
 *
 * Return:	None
 *****************************************************************************/
void qdma_memfree(void *memptr);

/*****************************************************************************/
/**
 * qdma_resource_lock_take() - take lock to access resource management APIs
 *
 * @return	None
 *****************************************************************************/
void qdma_resource_lock_take(void);

/*****************************************************************************/
/**
 * qdma_resource_lock_give() - release lock after accessing resource management
 * APIs
 *
 * @return	None
 *****************************************************************************/
void qdma_resource_lock_give(void);

/*****************************************************************************/
/**
 * qdma_reg_write() - Register write API.
 *
 * @dev_hndl:   device handle
 * @reg_offst:  QDMA Config bar register offset to write
 * @val:	value to be written
 *
 * Return:	Nothing
 *****************************************************************************/
void qdma_reg_write(void *dev_hndl, uint32_t reg_offst, uint32_t val);

/*****************************************************************************/
/**
 * qdma_reg_read() - Register read API.
 *
 * @dev_hndl:   device handle
 * @reg_offst:  QDMA Config bar register offset to be read
 *
 * Return: Value read
 *****************************************************************************/
uint32_t qdma_reg_read(void *dev_hndl, uint32_t reg_offst);

/*****************************************************************************/
/**
 * qdma_reg_access_lock() - Lock function for Register access
 *
 * @dev_hndl:   device handle
 *
 * Return:	0   - success and < 0 - failure
 *****************************************************************************/
int qdma_reg_access_lock(void *dev_hndl);

/*****************************************************************************/
/**
 * qdma_reg_access_release() - Release function for Register access
 *
 * @dev_hndl:   device handle
 *
 * Return:	0   - success and < 0 - failure
 *****************************************************************************/
int qdma_reg_access_release(void *dev_hndl);

/*****************************************************************************/
/**
 * qdma_udelay() - delay function to be used in the common library
 *
 * @delay_usec:   delay in microseconds
 *
 * Return:	0   - success and < 0 - failure
 *****************************************************************************/
void qdma_udelay(uint32_t delay_usec);

/*****************************************************************************/
/**
 * qdma_hw_error_handler() - function to handle the hardware errors
 *
 * @dev_hndl:   device handle
 * @err_idx: error index
 *
 * Return:	0   - success and < 0 - failure
 *****************************************************************************/
void qdma_hw_error_handler(void *dev_hndl, enum qdma_error_idx err_idx);

/*****************************************************************************/
/**
 * qdma_get_device_attr() - function to get the device attributes
 *
 * @dev_hndl:   device handle
 * @dev_cap: pointer to hold the device capabilities
 *
 * Return:	0   - success and < 0 - failure
 *****************************************************************************/
void qdma_get_device_attr(void *dev_hndl, struct qdma_dev_attributes **dev_cap);

#ifdef __cplusplus
}
#endif

#endif /* LIBQDMA_QDMA_PLATFORM_H_ */
