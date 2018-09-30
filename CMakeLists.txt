cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(WIN32)
	set(CMAKE_GENERATOR_PLATFORM "x64")
	set(CMAKE_GENERATOR "Visual Studio 15 2017")
endif()

project(CPP_ADVANCED LANGUAGES CXX)

# Don't use compile flags, let CMake figure out what to use.
set(CMAKE_CXX_STANDARD 17)

file(GLOB COMMON_FILES
${PROJECT_SOURCE_DIR}/Common/*.h*
)

add_executable(Casting_Examples
"${PROJECT_SOURCE_DIR}/Exceptions/Casting/Examples.cpp"
${COMMON_FILES})

add_executable(Casting_Copy_Constructors_And_Assignment
"${PROJECT_SOURCE_DIR}/Exceptions/Casting/Copy_Constructors_And_Assignment.cpp"
${COMMON_FILES})

add_executable(Allocation_Bad_Alloc
"${PROJECT_SOURCE_DIR}/Exceptions/Allocation/Bad_Alloc.cpp"
${COMMON_FILES})

add_executable(Allocation_Customising_Memory_Allocation 
"${PROJECT_SOURCE_DIR}/Exceptions/Allocation/Customising_Memory_Allocation.cpp"
${COMMON_FILES}
)

add_executable(Allocation_Caching 
"${PROJECT_SOURCE_DIR}/Exceptions/Allocation/Caching.cpp"
${COMMON_FILES}
)

add_executable(Template_Functions_Template_Functions
"${PROJECT_SOURCE_DIR}/Templates/Template_Functions/Template_Functions.cpp"
${COMMON_FILES}
)

add_executable(Template_Functions_Implementing_Generic_Algorithms
"${PROJECT_SOURCE_DIR}/Templates/Template_Functions/Implementing_Generic_Algorithms.cpp"
${COMMON_FILES}
)

add_executable(Template_Functions_Overview
"${PROJECT_SOURCE_DIR}/Templates/Template_Functions/Overview.cpp"
${COMMON_FILES}
)

add_executable(Template_Functions_Standard_Container_Classes
"${PROJECT_SOURCE_DIR}/Templates/Template_Functions/Standard_Container_Classes.cpp"
${COMMON_FILES}
)

add_executable(Template_Functions_Defining_Non_Type_Template_Parameters
"${PROJECT_SOURCE_DIR}/Templates/Template_Functions/Defining_Non_Type_Template_Parameters.cpp"
${COMMON_FILES}
)

add_executable(Template_Adapters_Defining_Template_Adapters
"${PROJECT_SOURCE_DIR}/Templates/Template_Adapters/Defining_Template_Adapters.cpp"
${COMMON_FILES}
)

add_executable(Template_Adapters_Specifying_Default_Template_Parameters
"${PROJECT_SOURCE_DIR}/Templates/Template_Adapters/Specifying_Default_Template_Parameters.cpp"
${COMMON_FILES}
)

add_executable(Template_Adapters_Specializing_Templates
"${PROJECT_SOURCE_DIR}/Templates/Template_Adapters/Specializing_Templates.cpp"
${COMMON_FILES}
)

add_executable(Template_Adapters_Defining_Trait_Classes
"${PROJECT_SOURCE_DIR}/Templates/Template_Adapters/Defining_Trait_Classes.cpp"
${COMMON_FILES}
)

add_executable(Standard_Iterators_Standard_Iterators
"${PROJECT_SOURCE_DIR}/Iterators/Standard_Iterators/Standard_Iterators.cpp"
${COMMON_FILES}
)

add_executable(Standard_Iterators_Creating_Generic_Algorithms
"${PROJECT_SOURCE_DIR}/Iterators/Standard_Iterators/Creating_Generic_Algorithms.cpp"
${COMMON_FILES}
)

add_executable(Functions_Function_Objects
"${PROJECT_SOURCE_DIR}/Iterators/Functions/Function_Objects.cpp"
${COMMON_FILES}
)

add_executable(Functions_Overloading_Indexing_Operator
"${PROJECT_SOURCE_DIR}/Iterators/Functions/Overloading_Indexing_Operator.cpp"
${COMMON_FILES}
)

add_executable(Functions_Creating_Multidimensional_Containers
"${PROJECT_SOURCE_DIR}/Iterators/Functions/Creating_Multidimensional_Containers.cpp"
${COMMON_FILES}
)