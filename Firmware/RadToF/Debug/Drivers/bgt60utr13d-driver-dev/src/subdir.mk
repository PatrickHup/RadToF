################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.c 

OBJS += \
./Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.o 

C_DEPS += \
./Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/bgt60utr13d-driver-dev/src/%.o Drivers/bgt60utr13d-driver-dev/src/%.su Drivers/bgt60utr13d-driver-dev/src/%.cyclo: ../Drivers/bgt60utr13d-driver-dev/src/%.c Drivers/bgt60utr13d-driver-dev/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H562xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Patrick/patrick_hupertz_401/Firmware/RadToF/Drivers/bgt60utr13d-driver-dev/inc" -I"C:/Users/Patrick/patrick_hupertz_401/Firmware/RadToF/Drivers/BSP/Components/VL53L8CX_ULD_API/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-bgt60utr13d-2d-driver-2d-dev-2f-src

clean-Drivers-2f-bgt60utr13d-2d-driver-2d-dev-2f-src:
	-$(RM) ./Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.cyclo ./Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.d ./Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.o ./Drivers/bgt60utr13d-driver-dev/src/bgt60utr13d.su

.PHONY: clean-Drivers-2f-bgt60utr13d-2d-driver-2d-dev-2f-src

