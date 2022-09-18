################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EXTINT0.c \
../GIE.c \
../LCD.c \
../LCD_cfg.c \
../TIM0.c \
../main.c \
../uart.c \
../uart_cfg.c \
../ultrasonic.c 

OBJS += \
./DIO.o \
./EXTINT0.o \
./GIE.o \
./LCD.o \
./LCD_cfg.o \
./TIM0.o \
./main.o \
./uart.o \
./uart_cfg.o \
./ultrasonic.o 

C_DEPS += \
./DIO.d \
./EXTINT0.d \
./GIE.d \
./LCD.d \
./LCD_cfg.d \
./TIM0.d \
./main.d \
./uart.d \
./uart_cfg.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


