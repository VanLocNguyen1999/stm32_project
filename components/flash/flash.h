/*
 * flash.h
 *
 *  Created on: Jan 18, 2025
 *      Author: vanlo
 */

#ifndef COMPONENTS_FLASH_FLASH_H_
#define COMPONENTS_FLASH_FLASH_H_

#include "board.h"
#include "flash_hardware.h"
#include "string.h"

static inline uint64_t flash_read_uint64(uint32_t addr)
{
	return *(uint64_t*)addr;
}
static inline void flash_read(uint8_t* dst, uint8_t* src_addr, const uint32_t size)
{
    memcpy(dst, src_addr, size);
}


static inline FLASH_STATUS flash_erase_pages(uint16_t start_page, uint16_t number_pages)
{
	return flash_hardware_erase_pages(start_page,number_pages);
}

FLASH_STATUS flash_erase_and_write(uint32_t addr, uint8_t* p_data, const uint32_t size);

static inline FLASH_STATUS flash_write_uint64(uint32_t addr, uint64_t data)
{
	return flash_hardware_write_double_words(addr, data);
}
FLASH_STATUS flash_write_page(uint16_t page, uint8_t* p_page_data);
FLASH_STATUS flash_write(uint32_t addr, uint8_t* p_data, const uint32_t size);

#endif /* COMPONENTS_FLASH_FLASH_H_ */
