################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TMR2/subdir.mk
-include MCAL/TMR1/subdir.mk
-include MCAL/TMR0/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTINT/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/ULTRASONIC/subdir.mk
-include HAL/MTR/subdir.mk
-include HAL/LCD/subdir.mk
-include APP/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AutonomousCarControlWithBluetoothCarControllerCode
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AutonomousCarControlWithBluetoothCarControllerCode.lss \

FLASH_IMAGE += \
AutonomousCarControlWithBluetoothCarControllerCode.hex \

EEPROM_IMAGE += \
AutonomousCarControlWithBluetoothCarControllerCode.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: AutonomousCarControlWithBluetoothCarControllerCode.elf secondary-outputs

# Tool invocations
AutonomousCarControlWithBluetoothCarControllerCode.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AutonomousCarControlWithBluetoothCarControllerCode.map -mmcu=atmega32 -o "AutonomousCarControlWithBluetoothCarControllerCode.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AutonomousCarControlWithBluetoothCarControllerCode.lss: AutonomousCarControlWithBluetoothCarControllerCode.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AutonomousCarControlWithBluetoothCarControllerCode.elf  >"AutonomousCarControlWithBluetoothCarControllerCode.lss"
	@echo 'Finished building: $@'
	@echo ' '

AutonomousCarControlWithBluetoothCarControllerCode.hex: AutonomousCarControlWithBluetoothCarControllerCode.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AutonomousCarControlWithBluetoothCarControllerCode.elf  "AutonomousCarControlWithBluetoothCarControllerCode.hex"
	@echo 'Finished building: $@'
	@echo ' '

AutonomousCarControlWithBluetoothCarControllerCode.eep: AutonomousCarControlWithBluetoothCarControllerCode.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AutonomousCarControlWithBluetoothCarControllerCode.elf  "AutonomousCarControlWithBluetoothCarControllerCode.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AutonomousCarControlWithBluetoothCarControllerCode.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AutonomousCarControlWithBluetoothCarControllerCode.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AutonomousCarControlWithBluetoothCarControllerCode.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
