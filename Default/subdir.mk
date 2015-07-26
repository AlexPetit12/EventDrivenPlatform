################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Bar.cpp \
../DataHandler.cpp \
../Event.cpp \
../FillEvent.cpp \
../HistoricCSVDataHandler.cpp \
../Main.cpp \
../MarketEvent.cpp \
../OrderEvent.cpp \
../Portfolio.cpp \
../SignalEvent.cpp \
../Strategy.cpp 

OBJS += \
./Bar.o \
./DataHandler.o \
./Event.o \
./FillEvent.o \
./HistoricCSVDataHandler.o \
./Main.o \
./MarketEvent.o \
./OrderEvent.o \
./Portfolio.o \
./SignalEvent.o \
./Strategy.o 

CPP_DEPS += \
./Bar.d \
./DataHandler.d \
./Event.d \
./FillEvent.d \
./HistoricCSVDataHandler.d \
./Main.d \
./MarketEvent.d \
./OrderEvent.d \
./Portfolio.d \
./SignalEvent.d \
./Strategy.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


