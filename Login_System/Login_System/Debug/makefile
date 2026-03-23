################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Timer/subdir.mk
-include KeyPad/subdir.mk
-include DIO/subdir.mk
-include CLCD/subdir.mk
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
Buzzer_Pass.lss \

FLASH_IMAGE += \
Buzzer_Pass.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Buzzer_Pass.elf secondary-outputs

# Tool invocations
Buzzer_Pass.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Buzzer_Pass.map -mmcu=atmega32 -o "Buzzer_Pass.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Buzzer_Pass.lss: Buzzer_Pass.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Buzzer_Pass.elf  >"Buzzer_Pass.lss"
	@echo 'Finished building: $@'
	@echo ' '

Buzzer_Pass.hex: Buzzer_Pass.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Buzzer_Pass.elf  "Buzzer_Pass.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Buzzer_Pass.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Buzzer_Pass.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Buzzer_Pass.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
