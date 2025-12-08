#include <stdint.h>
#include <sys/time.h>
#include "stm32f4xx_hal.h"

uint8_t *buf;

HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
    buf = pData;
    return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size)
{
    return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart)
{
    return HAL_OK;
}

uint32_t HAL_GetTick(void)
{
    struct timeval tick;
    static uint64_t first_tick_ms = 0;
    gettimeofday(&tick, NULL);
    if(first_tick_ms == 0) {
        first_tick_ms = tick.tv_sec * 1000 + tick.tv_usec / 1000;
    }
    
    return (tick.tv_sec * 1000 + tick.tv_usec / 1000) - first_tick_ms;
}

void HAL_Delay(uint32_t Delay)
{
    return;
}
