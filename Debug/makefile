################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: CustomLIbs.elf

# Tool invocations
CustomLIbs.elf: $(OBJS) $(USER_OBJS) D:\Docs\ and\ stuff\STM32\ Mats\Workspace1\CustomLIbs\LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -L"D:\Docs and stuff\STM32 Mats\Workspace1\nucleo-l152re_stdperiph_lib\Debug" -T"D:\Docs and stuff\STM32 Mats\Workspace1\CustomLIbs\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "CustomLIbs.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "CustomLIbs.elf" "CustomLIbs.bin"
	arm-none-eabi-size "CustomLIbs.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
