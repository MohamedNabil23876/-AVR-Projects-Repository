################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_Prog.c \
../DIO_Prog.c \
../EXIT_Prog.c \
../GIE_Prog.c \
../KPD_Prog.c \
../TIMER_Prog.c \
../main.c 

OBJS += \
./CLCD_Prog.o \
./DIO_Prog.o \
./EXIT_Prog.o \
./GIE_Prog.o \
./KPD_Prog.o \
./TIMER_Prog.o \
./main.o 

C_DEPS += \
./CLCD_Prog.d \
./DIO_Prog.d \
./EXIT_Prog.d \
./GIE_Prog.d \
./KPD_Prog.d \
./TIMER_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


