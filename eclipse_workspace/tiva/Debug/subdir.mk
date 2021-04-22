################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp.c \
../main.c \
../startup_TM4C123.c \
../system_TM4C123.c 

OBJS += \
./bsp.o \
./main.o \
./startup_TM4C123.o \
./system_TM4C123.o 

C_DEPS += \
./bsp.d \
./main.d \
./startup_TM4C123.d \
./system_TM4C123.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mlittle-endian -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DTM4C123GH6PM -std=gnu11 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


