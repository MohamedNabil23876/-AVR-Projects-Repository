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
POT_DC.lss \

FLASH_IMAGE += \
POT_DC.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: POT_DC.elf secondary-outputs

# Tool invocations
POT_DC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,POT_DC.map -mmcu=atmega32 -o "POT_DC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

POT_DC.lss: POT_DC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S POT_DC.elf  >"POT_DC.lss"
	@echo 'Finished building: $@'
	@echo ' '

POT_DC.hex: POT_DC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex POT_DC.elf  "POT_DC.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: POT_DC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 POT_DC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) POT_DC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
