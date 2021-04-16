################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
tiva.hex \

SECONDARY_SIZE += \
tiva.siz \


# All Target
all: tiva.elf secondary-outputs

# Tool invocations
tiva.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Arm Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mlittle-endian -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -T "/home/vksalian/Desktop/Practice_2021/baremetal_tiva_TM4C123GH6PM_IDE/eclipse_workspace/tiva/tm4c123gh6pm.ld" -nostdlib -Wl,-Map,"tiva.map" -o "tiva.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

tiva.hex: tiva.elf
	@echo 'Invoking: GNU Arm Cross Create Flash Image'
	arm-none-eabi-objcopy -O ihex "tiva.elf"  "tiva.hex"
	@echo 'Finished building: $@'
	@echo ' '

tiva.siz: tiva.elf
	@echo 'Invoking: GNU Arm Cross Print Size'
	arm-none-eabi-size --format=berkeley "tiva.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) tiva.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
