///*
// * flash_hardware.h
// *
// *  Created on: Jan 18, 2025
// *      Author: vanlo
// */
//
//#ifndef BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_FLASH_HARDWARE_H_
//#define BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_FLASH_HARDWARE_H_
//
//#include "stm32_config.h"
//
//// use page
//#define MCU_FLASH_LOWEST_PAGE 			0
//#define MCU_FLASH_HIGHEST_PAGE 			255
//#define MCU_FLASH_LOWEST_ADDR 			0x08000000
//#define MCU_FLASH_HIGHEST_ADDR 			0x0807FFFF
//#define MCU_FLASH_PAGE_DIFF				0x800
//#define MCU_FLASH_PAGE_SIZE				(0x800)
////#define MCU_FLASH_PAGE_SIZE_8_BYTE		(0x256)	//=size/8
//
//// use sector stm32f411
//#define MCU_FLASH_LOWEST_SECTOR 			0
//#define MCU_FLASH_HIGHEST_SECTOR 			7
//#define MCU_FLASH_SECTOR_0_3_DIFF			0x4000
//#define MCU_FLASH_SECTOR_4_DIFF			    0x10000
//#define MCU_FLASH_SECTOR_4_7_DIFF			0x20000
//
//typedef enum{
//	FLASH_NONE_ERROR=0,
//	FLASH_ERROR		=-1
//}FLASH_STATUS;
//
//FLASH_STATUS flash_check_valid_page_erase(uint32_t start_page,uint32_t number_pages);
//FLASH_STATUS flash_hardware_erase_pages(uint32_t start_page, uint32_t number_pages);
//FLASH_STATUS flash_hardware_write_double_words(uint32_t address,uint64_t data);
//
//#endif /* BOARD_STM32F411CEUX_BOARD_CORE_EXTENSION_FLASH_HARDWARE_H_ */
