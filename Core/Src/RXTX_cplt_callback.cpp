#include "main.h"
#include "usart.h"
extern uint8_t receivemessage[2];
extern GPIO_PinState pinstate;
uint8_t pinstatemessage[1];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART6)
    {
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
				HAL_UART_Receive_IT(&huart6,receivemessage,2);
    	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
    //     while(HAL_UART_Receive_IT(&huart6,receivemessage,2)!=HAL_OK)
				// {
				// 	HAL_UART_Transmit(&huart6,(uint8_t*)"HELLO WORLD",11,100);
				// 	HAL_Delay(1000);
				// }
    //         HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_RESET);
    }
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    //HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    //HAL_UART_Transmit_IT(&huart6, receivemessage, 2);
}

