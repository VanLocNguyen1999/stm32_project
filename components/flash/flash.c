/*
 * flash.c
 *
 *  Created on: Jan 18, 2025
 *      Author: vanlo
 */


#include "flash.h"

static inline void reset_bytes_of_segment(uint8_t* p_seg_data, const uint16_t len, const uint16_t start_position,
		const  uint16_t end_position)
{
	uint16_t i;
	for (i = 0; i < len; i++)
	{
		if (i >= start_position && i < end_position)
		{
			*(p_seg_data + i) = 0x0F;
		}
	}
}
FLASH_STATUS flash_write_page(uint16_t page, uint8_t* p_page_data)
{
	uint32_t page_addr = page * MCU_FLASH_PAGE_DIFF + MCU_FLASH_LOWEST_ADDR;
	return flash_write(page_addr, p_page_data, MCU_FLASH_PAGE_DIFF);
}

/*Only erase and write flash region which has size <= size of 1 pages (2kB)*/
FLASH_STATUS flash_erase_and_write(uint32_t addr, uint8_t* p_data, const uint32_t size)
{
	if(size == 0) return FLASH_ERROR;
	//Read and adjust buffer
	uint16_t start_page = (addr - MCU_FLASH_LOWEST_ADDR) / MCU_FLASH_PAGE_DIFF; // xác định page đầu
	uint32_t start_page_addr = start_page * MCU_FLASH_PAGE_DIFF + MCU_FLASH_LOWEST_ADDR; // địa chỉ bắt đầu của page
	uint16_t end_page = (addr + size - MCU_FLASH_LOWEST_ADDR) / MCU_FLASH_PAGE_DIFF; // xác định pagr kết thúc
	uint16_t page_number = end_page - start_page + 1; // số page cần dùng
	if(page_number>2) return FLASH_ERROR;

	uint8_t page12_buffer[(MCU_FLASH_PAGE_DIFF*2)] = {0};
	flash_read(page12_buffer, (uint8_t*)start_page_addr, MCU_FLASH_PAGE_DIFF*page_number);

	uint32_t start_write_pos;
	start_write_pos = addr - start_page_addr;
	memcpy(page12_buffer + start_write_pos, p_data, size);

	//Erase page
	if(flash_erase_pages(start_page, page_number) == FLASH_ERROR)
	{
		return FLASH_ERROR;
	}
	//Write
	return flash_write(start_page_addr, page12_buffer, page_number * MCU_FLASH_PAGE_DIFF);
}

FLASH_STATUS flash_write(uint32_t addr, uint8_t* p_data, const uint32_t size)
{
	if ((size / 8) * 8 - size != 0)	return FLASH_ERROR; //kiểm tra xem kích thước dữ liệu (size) có phải là bội số của 8 byte hay không

	uint64_t temp_data;
	uint32_t i = 0;
	for (; i < size; i = i + 8)
	{
		temp_data = *(uint64_t*) (p_data + i);
		if (flash_write_uint64(addr + i, temp_data) == FLASH_ERROR)
		{
			return FLASH_ERROR;
		}
	}
	return FLASH_NONE_ERROR;
}
