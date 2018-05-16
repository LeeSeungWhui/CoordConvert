################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../CMake/CMakeFiles/feature_tests.cxx 

C_SRCS += \
../CMake/CMakeFiles/feature_tests.c 

CXX_DEPS += \
./CMake/CMakeFiles/feature_tests.d 

OBJS += \
./CMake/CMakeFiles/feature_tests.o 

C_DEPS += \
./CMake/CMakeFiles/feature_tests.d 


# Each subdirectory must supply rules for building sources it contributes
CMake/CMakeFiles/%.o: ../CMake/CMakeFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMake/CMakeFiles/%.o: ../CMake/CMakeFiles/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


