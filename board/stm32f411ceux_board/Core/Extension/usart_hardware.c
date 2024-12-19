/*
 * usart_hardware.c
 *
 *  Created on: Dec 17, 2024
 *      Author: vanlo
 */
#include "usart_hardware.h"

void uart_change_baudrate(uint32_t baudrate){
	LL_USART_SetBaudRate(USART3, SYS_CLK, 0, 0, baudrate);
}
uint32_t uart_write_one(uint8_t data){
	uint32_t result = 1;
	uint32_t wait_tick1 = 0;
	uint32_t wait_tick2 = 0;
	while (LL_USART_IsActiveFlag_TXE(USART3) == 0) {
		wait_tick1++;
		if (wait_tick1 > UART_BUSY_TICK) {
			result = 0;
			break;
		}
	}

	LL_USART_TransmitData8(USART3, data);
#if 1
	while (LL_USART_IsActiveFlag_TC(USART3) == 0) {
		wait_tick2++;
		if (wait_tick2 > UART_BUSY_TICK) {
			result = 0;
			break;
		}
	}
#endif
	return result;
}

uint32_t uart_read_one(uint8_t *data) {
    uint32_t result = 1;
    uint32_t wait_tick = 0;

    // Chờ dữ liệu sẵn sàng (RXNE - Receive Data Register Not Empty)
    while (LL_USART_IsActiveFlag_RXNE(USART3) == 0) {
        wait_tick++;
        if (wait_tick > UART_BUSY_TICK) { // Timeout
            result = 0;
            return result;
        }
    }

    // Đọc dữ liệu từ thanh ghi nhận
    *data = LL_USART_ReceiveData8(USART3);
    return result;
}

uint32_t uart_receive_data(uint8_t *buffer, uint32_t buffer_size) {
	uint32_t index = 0;
	uint8_t received_data;

	while (1) {
		// Gọi hàm nhận 1 byte dữ liệu
		if (uart_read_one(&received_data) == 1) {
			buffer[index++] = received_data; // Lưu byte vào buffer

			// Kiểm tra ký tự kết thúc hoặc kích thước vượt quá
			if (received_data == '\n' || index >= buffer_size - 1) {
				buffer[index] = '\0'; // Kết thúc chuỗi
				return 1; // Nhận hoàn thành
			}
		} else {
			// Timeout xảy ra
			buffer[index] = '\0'; // Đảm bảo buffer luôn có chuỗi hợp lệ
			return 0;
		}
	}
}
