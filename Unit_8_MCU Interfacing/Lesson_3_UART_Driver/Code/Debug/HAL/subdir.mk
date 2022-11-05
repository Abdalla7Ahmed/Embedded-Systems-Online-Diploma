################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Kaypad.c \
../HAL/Seven_segment.c \
../HAL/lcd.c 

OBJS += \
./HAL/Kaypad.o \
./HAL/Seven_segment.o \
./HAL/lcd.o 

C_DEPS += \
./HAL/Kaypad.d \
./HAL/Seven_segment.d \
./HAL/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Kaypad.o: ../HAL/Kaypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"F:/Drivers/STM32F103C6_Drivers/MCAL/Inc" -I"F:/Drivers/STM32F103C6_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Kaypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Seven_segment.o: ../HAL/Seven_segment.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"F:/Drivers/STM32F103C6_Drivers/MCAL/Inc" -I"F:/Drivers/STM32F103C6_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Seven_segment.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/lcd.o: ../HAL/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"F:/Drivers/STM32F103C6_Drivers/MCAL/Inc" -I"F:/Drivers/STM32F103C6_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

