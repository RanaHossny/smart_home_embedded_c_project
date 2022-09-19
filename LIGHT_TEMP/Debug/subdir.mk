################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO.c \
../LCD.c \
../LCD_cfg.c \
../LED.c \
../LED_cfg.c \
../Relay.c \
../Relay_cfg.c \
../SPI.c \
../TIM1.c \
../TIM1_cfg.c \
../main.c \
../servo.c \
../servo_cfg.c 

OBJS += \
./ADC.o \
./DIO.o \
./LCD.o \
./LCD_cfg.o \
./LED.o \
./LED_cfg.o \
./Relay.o \
./Relay_cfg.o \
./SPI.o \
./TIM1.o \
./TIM1_cfg.o \
./main.o \
./servo.o \
./servo_cfg.o 

C_DEPS += \
./ADC.d \
./DIO.d \
./LCD.d \
./LCD_cfg.d \
./LED.d \
./LED_cfg.d \
./Relay.d \
./Relay_cfg.d \
./SPI.d \
./TIM1.d \
./TIM1_cfg.d \
./main.d \
./servo.d \
./servo_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


