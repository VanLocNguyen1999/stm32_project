///*
// * flash_hardware.c
// *
// *  Created on: Jan 18, 2025
// *      Author: vanlo
// */
//
//
//#include "flash_hardware.h"
//
//FLASH_STATUS flash_check_valid_page_erase(uint32_t start_page,uint32_t number_pages)
//{
//	if((start_page>MCU_FLASH_HIGHEST_PAGE)||(start_page<MCU_FLASH_LOWEST_PAGE))
//	{
//		return FLASH_ERROR;
//	}
//	if(start_page+number_pages>MCU_FLASH_HIGHEST_PAGE+1)
//	{
//		return FLASH_ERROR;
//	}
//	return FLASH_NONE_ERROR;
//}
//
//FLASH_STATUS flash_hardware_erase_pages(uint32_t start_page, uint32_t number_pages)
//{
//	if(flash_check_valid_page_erase(start_page,number_pages)!=FLASH_NONE_ERROR)
//	{
//		return FLASH_ERROR;
//	}
//	HAL_FLASH_Unlock();
//	FLASH_EraseInitTypeDef pEraseInit;
//	pEraseInit.Banks=1;
//	pEraseInit.Page=start_page;
//	pEraseInit.NbPages=number_pages;
//	pEraseInit.TypeErase=FLASH_TYPEERASE_PAGES;
//	uint32_t PageError;
//	if(HAL_FLASHEx_Erase(&pEraseInit, &PageError)!=HAL_OK)
//	{
//		return FLASH_ERROR;
//	}
//	HAL_FLASH_Lock();
//	if(PageError!=0xFFFFFFFF)
//	{
//		return FLASH_ERROR;
//	}
//	return FLASH_NONE_ERROR;
//}
//
//static inline uint8_t flash_hardware_addr_is_valid(const uint32_t address)
//{
//	return (((address / 8) * 8 - address) == 0) ? 1 : 0;
//}
//
//FLASH_STATUS flash_hardware_write_double_words(uint32_t address,uint64_t data)
//{
//	if (!flash_hardware_addr_is_valid(address))
//	{
//		return FLASH_ERROR;
//	}
//	HAL_FLASH_Unlock();
//	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, address, data) != HAL_OK)
//	{
//		return FLASH_ERROR;
//	}
//	HAL_FLASH_Lock();
//	if ((*(uint64_t*)address) != data)
//	{
//		return FLASH_ERROR;
//	}
//	return FLASH_NONE_ERROR;
//}
