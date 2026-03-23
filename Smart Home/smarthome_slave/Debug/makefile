################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART/subdir.mk
-include TIMER/subdir.mk
-include SPI/subdir.mk
-include KPD/subdir.mk
-include GIE/subdir.mk
-include DIO/subdir.mk
-include CLCD/subdir.mk
-include ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
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
LSS += \
smarthome_slave.lss \

FLASH_IMAGE += \
smarthome_slave.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: smarthome_slave.elf secondary-outputs

# Tool invocations
smarthome_slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,smarthome_slave.map -mmcu=atmega32 -o "smarthome_slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

smarthome_slave.lss: smarthome_slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S smarthome_slave.elf  >"smarthome_slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

smarthome_slave.hex: smarthome_slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex smarthome_slave.elf  "smarthome_slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: smarthome_slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 smarthome_slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) smarthome_slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
