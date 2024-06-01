/**
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "platform.h"
#include "main.h"

/* Macros defined for SPI communication */
#define VL53L8CX_COMMS_CHUNK_SIZE 4096
#define SPI_WRITE_MASK(x) (uint16_t)(x | 0x8000)  // 1
#define SPI_READ_MASK(x)  (uint16_t)(x & ~0x8000) // 0

#define TOF_1_CS_PORT  GPIOC
#define TOF_1_CS_PIN   GPIO_PIN_6
#define TOF_2_CS_PORT  GPIOB
#define TOF_2_CS_PIN   GPIO_PIN_15

extern SPI_HandleTypeDef hspi3;

uint8_t RdByte(
		VL53L8CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_value)
{
	return RdMulti(p_platform, RegisterAdress, p_value, 1);
}

uint8_t WrByte(
		VL53L8CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t value)
{
	return WrMulti(p_platform, RegisterAdress, &value, 1);
}

uint8_t WrMulti(
		VL53L8CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size)
{
	uint8_t status = 0;
	int32_t i = 0;
	uint32_t position = 0;
	uint32_t data_size = 0;
	uint16_t    temp;
	uint8_t data_write[VL53L8CX_COMMS_CHUNK_SIZE + 2];

	for (position = 0; position < size; position += VL53L8CX_COMMS_CHUNK_SIZE)
	{
		if (size > VL53L8CX_COMMS_CHUNK_SIZE)
		{
			if ((position + VL53L8CX_COMMS_CHUNK_SIZE) > size)
			{
				data_size = size - position;
			} else
			{
				data_size = VL53L8CX_COMMS_CHUNK_SIZE;
			}
		} else
		{
			data_size = size;
		}

		temp = RegisterAdress+position;

		data_write[0] = SPI_WRITE_MASK(temp) >> 8;
		data_write[1] = SPI_WRITE_MASK(temp) & 0xFF;

		for (i=0; i<data_size; i++)
		{
			data_write[i+2] = p_values[position + i];
		}


		data_size += 2;

		HAL_GPIO_WritePin(TOF_1_CS_PORT, TOF_1_CS_PIN, GPIO_PIN_RESET);
		status |= HAL_SPI_Transmit(&hspi3, data_write, data_size, 100*data_size);
		HAL_GPIO_WritePin(TOF_1_CS_PORT, TOF_1_CS_PIN, GPIO_PIN_SET);
	}

	return status;
}

uint8_t RdMulti(
		VL53L8CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size)
{
	uint8_t status = 0;


	uint32_t position = 0;
	uint32_t data_size = 0;
	uint16_t    temp;
	uint8_t data_write[VL53L8CX_COMMS_CHUNK_SIZE + 2];

	for (position = 0; position < size; position += VL53L8CX_COMMS_CHUNK_SIZE)
	{
		if (size > VL53L8CX_COMMS_CHUNK_SIZE)
		{
			if ((position + VL53L8CX_COMMS_CHUNK_SIZE) > size)
			{
				data_size = size - position;
			} else
			{
				data_size = VL53L8CX_COMMS_CHUNK_SIZE;
			}
		} else
		{
			data_size = size;
		}

		temp = RegisterAdress+position;

		data_write[0] = SPI_READ_MASK(temp) >> 8;
		data_write[1] = SPI_READ_MASK(temp) & 0xFF;



		HAL_GPIO_WritePin(TOF_1_CS_PORT, TOF_1_CS_PIN, GPIO_PIN_RESET);
		status |= HAL_SPI_Transmit(&hspi3, data_write, 2, 0x1000);
		status |= HAL_SPI_Receive(&hspi3, p_values + position, data_size, 100*data_size);
		HAL_GPIO_WritePin(TOF_1_CS_PORT, TOF_1_CS_PIN, GPIO_PIN_SET);
	}

	return status;
}

uint8_t Reset_Sensor(VL53L8CX_Platform *p_platform)
{
	HAL_GPIO_WritePin(TOF_1_CS_PORT, TOF_1_CS_PIN, GPIO_PIN_RESET);
  
	return 0;
}

void SwapBuffer(
		uint8_t 		*buffer,
		uint16_t 	 	 size)
{
	uint32_t i, tmp;

	/* Example of possible implementation using <string.h> */
	for(i = 0; i < size; i = i + 4)
	{
		tmp = (
		  buffer[i]<<24)
		|(buffer[i+1]<<16)
		|(buffer[i+2]<<8)
		|(buffer[i+3]);

		memcpy(&(buffer[i]), &tmp, 4);
	}
}

uint8_t WaitMs(
		VL53L8CX_Platform *p_platform,
               uint32_t TimeMs)
{
	HAL_Delay(TimeMs);
	return 0;
}
