################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clientes_lib.c \
../src/Pedidos_lib.c \
../src/PrimerParcial.c 

OBJS += \
./src/Clientes_lib.o \
./src/Pedidos_lib.o \
./src/PrimerParcial.o 

C_DEPS += \
./src/Clientes_lib.d \
./src/Pedidos_lib.d \
./src/PrimerParcial.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


