################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/23092/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/User" -I"C:/Users/23092/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang" -I"C:/Users/23092/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"User/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


