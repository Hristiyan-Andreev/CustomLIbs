################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hGPIO_LIB.c \
../src/main.c \
../src/syscalls.c \
../src/system_stm32l1xx.c 

OBJS += \
./src/hGPIO_LIB.o \
./src/main.o \
./src/syscalls.o \
./src/system_stm32l1xx.o 

C_DEPS += \
./src/hGPIO_LIB.d \
./src/main.d \
./src/syscalls.d \
./src/system_stm32l1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32L1 -DSTM32L152RETx -DNUCLEO_L152RE -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32L1XX_XL -I"D:/Docs and stuff/STM32 Mats/Workspace1/nucleo-l152re_stdperiph_lib" -I"D:/Docs and stuff/STM32 Mats/Workspace1/CustomLIbs/inc" -I"D:/Docs and stuff/STM32 Mats/Workspace1/nucleo-l152re_stdperiph_lib/CMSIS/core" -I"D:/Docs and stuff/STM32 Mats/Workspace1/nucleo-l152re_stdperiph_lib/CMSIS/device" -I"D:/Docs and stuff/STM32 Mats/Workspace1/nucleo-l152re_stdperiph_lib/StdPeriph_Driver/inc" -I"D:/Docs and stuff/STM32 Mats/Workspace1/nucleo-l152re_stdperiph_lib/Utilities" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


