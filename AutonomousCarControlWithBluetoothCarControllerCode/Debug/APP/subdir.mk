################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main.c 

OBJS += \
./APP/main.o 

C_DEPS += \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\APP" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\HAL\LCD" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\HAL\MTR" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\HAL\ULTRASONIC" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\HAL\SERVO" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\LIB" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\DIO" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\EXTINT" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\GIE" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\TMR0" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\TMR1" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\TMR2" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\Autonomous-Car-control-with-bluetooth\AutonomousCarControlWithBluetoothCarControllerCode\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


