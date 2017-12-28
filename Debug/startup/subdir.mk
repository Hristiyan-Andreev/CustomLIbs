################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32l1xx_xl.s 

OBJS += \
./startup/startup_stm32l1xx_xl.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"G:/Documents and stuff/Project Avalanche/Workspace 4/nucleo-l152re_stdperiph_lib" -I"G:/Documents and stuff/Project Avalanche/Workspace 4/CustomLIbs/inc" -I"G:/Documents and stuff/Project Avalanche/Workspace 4/nucleo-l152re_stdperiph_lib/CMSIS/core" -I"G:/Documents and stuff/Project Avalanche/Workspace 4/nucleo-l152re_stdperiph_lib/CMSIS/device" -I"G:/Documents and stuff/Project Avalanche/Workspace 4/nucleo-l152re_stdperiph_lib/StdPeriph_Driver/inc" -I"G:/Documents and stuff/Project Avalanche/Workspace 4/nucleo-l152re_stdperiph_lib/Utilities" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


