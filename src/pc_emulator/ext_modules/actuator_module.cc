#include <assert.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <regex>
#include <vector>
#include <queue>
#include <fstream>
#include <cstdio>

#include "include/actuator_module.h"

using namespace std;
using namespace pc_emulator;
using namespace pc_specification;
using MemType  = pc_specification::MemType;
using DataTypeCategory = pc_specification::DataTypeCategory;
using FieldIntfType = pc_specification::FieldInterfaceType;



std::unique_ptr<PCVariableContainer> ActuatorModule::GetVariableContainer(
    string ResourceName, int MemType, int ByteOffset, int BitOffset,
    string VariableDataTypeName) {


    if (MemType != pc_specification::MemType::OUTPUT_MEM) {
        std::domain_error("Actuator cannot access INPUT memory!");
    }
    auto V = __ConfigInterface.GetVariablePointerToResourceMem(
                ResourceName, MemType, ByteOffset, BitOffset,
                VariableDataTypeName);
    if (V == nullptr)
        return nullptr;
    return std::unique_ptr<PCVariableContainer>(new PCVariableContainer(V));
};
