################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Event.cpp \
../FillEvent.cpp \
../Main.cpp \
../MarketEvent.cpp \
../OrderEvent.cpp \
../SignalEvent.cpp 

OBJS += \
./Event.o \
./FillEvent.o \
./Main.o \
./MarketEvent.o \
./OrderEvent.o \
./SignalEvent.o 

CPP_DEPS += \
./Event.d \
./FillEvent.d \
./Main.d \
./MarketEvent.d \
./OrderEvent.d \
./SignalEvent.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


