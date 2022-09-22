################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Driver/GPIO_Driver/STM32F103C6_Driver.c 

OBJS += \
./STM32F103C6_Driver/GPIO_Driver/STM32F103C6_Driver.o 

C_DEPS += \
./STM32F103C6_Driver/GPIO_Driver/STM32F103C6_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Driver/GPIO_Driver/STM32F103C6_Driver.o: ../STM32F103C6_Driver/GPIO_Driver/STM32F103C6_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Drivers/HAL/Inc" -I"F:/Drivers/STM32F103C6_Driver/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Driver/GPIO_Driver/STM32F103C6_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

