################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EEPROM.c \
../EXTINT0.c \
../EXTINT1.c \
../EXTINT2.c \
../GIE.c \
../KEYPAD.c \
../KEYPAD_cfg.c \
../LCD.c \
../LCD_cfg.c \
../LOCK.c \
../LOCK_confg.c \
../Master_TWI.c \
../PWM.c \
../TIM0.c \
../TIM1.c \
../TIM1_cfg.c \
../TIM2.c \
../main.c \
../pwm_cfg.c \
../servo.c \
../servo_cfg.c \
../uart.c \
../uart_cfg.c 

OBJS += \
./DIO.o \
./EEPROM.o \
./EXTINT0.o \
./EXTINT1.o \
./EXTINT2.o \
./GIE.o \
./KEYPAD.o \
./KEYPAD_cfg.o \
./LCD.o \
./LCD_cfg.o \
./LOCK.o \
./LOCK_confg.o \
./Master_TWI.o \
./PWM.o \
./TIM0.o \
./TIM1.o \
./TIM1_cfg.o \
./TIM2.o \
./main.o \
./pwm_cfg.o \
./servo.o \
./servo_cfg.o \
./uart.o \
./uart_cfg.o 

C_DEPS += \
./DIO.d \
./EEPROM.d \
./EXTINT0.d \
./EXTINT1.d \
./EXTINT2.d \
./GIE.d \
./KEYPAD.d \
./KEYPAD_cfg.d \
./LCD.d \
./LCD_cfg.d \
./LOCK.d \
./LOCK_confg.d \
./Master_TWI.d \
./PWM.d \
./TIM0.d \
./TIM1.d \
./TIM1_cfg.d \
./TIM2.d \
./main.d \
./pwm_cfg.d \
./servo.d \
./servo_cfg.d \
./uart.d \
./uart_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


