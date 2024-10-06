#include "main.h"
#include "usart.h"
extern uint8_t receivemessage[2];
extern GPIO_PinState pinstate;
uint8_t pinstatemessage[1];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART6)
    {
        // HAL_UART_Transmit_IT(&huart6, &receivemessage[1], 1);
        // HAL_UART_Transmit_IT(&huart6, receivemessage, 2);

        if(receivemessage[1]=='0')
        {
            pinstate=GPIO_PIN_RESET;
					//HAL_UART_Transmit_IT(&huart6, receivemessage, 2);
        }
        else if(receivemessage[1]=='1')
        {
            pinstate=GPIO_PIN_SET;
        }
        if(receivemessage[0]=='G')
        {
            HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, pinstate);
            //HAL_UART_Transmit_IT(&huart6, receivemessage, 2);
        }
        else if(receivemessage[0]=='R')
        {
            HAL_GPIO_WritePin(LED_R_GPIO_Port,LED_R_Pin,pinstate);
        }
        HAL_UART_Receive_IT(&huart6, receivemessage, 2);
    }
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    //HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    //HAL_UART_Transmit_IT(&huart6, receivemessage, 2);
}

