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

add_executable(Defining_Classes_That_Use_Shared_Representation_Objects
"${PROJECT_SOURCE_DIR}/Iterators/Defining_Classes/That_Use_Shared_Representation_Objects.cpp"
${COMMON_FILES}
)

add_executable(Defining_Classes_Reference_Counted_Strings
"${PROJECT_SOURCE_DIR}/Iterators/Defining_Classes/Reference_Counted_Strings.cpp"
${COMMON_FILES}
)

add_executable(Defining_Classes_Defining_Smart_Pointers_For_Garbage_Collection
"${PROJECT_SOURCE_DIR}/Iterators/Defining_Classes/Defining_Smart_Pointers_For_Garbage_Collection.cpp"
${COMMON_FILES}
)

add_executable(Function_Pointers_Implementing_Callbacks_using_Function_Pointers
"${PROJECT_SOURCE_DIR}/Patterns/Function_Pointers/Implementing_Callbacks_using_Function_Pointers.cpp"
${COMMON_FILES}
)

add_executable(Function_Pointers_The_Command_Pattern
"${PROJECT_SOURCE_DIR}/Patterns/Function_Pointers/The_Command_Pattern.cpp"
${COMMON_FILES}
)

add_executable(Function_Pointers_Member_Function_Pointers
"${PROJECT_SOURCE_DIR}/Patterns/Function_Pointers/Member_Function_Pointers.cpp"
${COMMON_FILES}
)

add_executable(Defining_Interfaces_Defining_Interfaces
"${PROJECT_SOURCE_DIR}/Patterns/Defining_Interfaces/Defining_Interfaces.cpp"
${COMMON_FILES}
)

add_executable(Defining_Interfaces_Multiple_Inheritance
"${PROJECT_SOURCE_DIR}/Patterns/Defining_Interfaces/Multiple_Inheritance.cpp"
${COMMON_FILES}
)

add_executable(Base_Classes_Virtual_Base_Classes
"${PROJECT_SOURCE_DIR}/Patterns/Base_Classes/Virtual_Base_Classes.cpp"
${COMMON_FILES}
)

add_executable(Base_Classes_Mixin_Classes
"${PROJECT_SOURCE_DIR}/Patterns/Base_Classes/Mixin_Classes.cpp"
${COMMON_FILES}
)

add_executable(Base_Classes_Run_Type_Type_Information
"${PROJECT_SOURCE_DIR}/Patterns/Base_Classes/Run_Type_Type_Information.cpp"
${COMMON_FILES}
)

add_executable(Inheritance_Private_And_Protected_Inheritance
"${PROJECT_SOURCE_DIR}/Patterns/Inheritance/Private_And_Protected_Inheritance.cpp"
${COMMON_FILES}
)

add_executable(Inheritance_Class_Adapter_Pattern
"${PROJECT_SOURCE_DIR}/Patterns/Inheritance/Class_Adapter_Pattern.cpp"
${COMMON_FILES}
)

add_executable(Inheritance_Static_Class_Members
"${PROJECT_SOURCE_DIR}/Patterns/Inheritance/Static_Class_Members.cpp"
${COMMON_FILES}
)

add_executable(Singleton_Pattern_Singleton_Pattern
"${PROJECT_SOURCE_DIR}/Patterns/Singleton_Pattern/Singleton_Pattern.cpp"
${COMMON_FILES}
)

add_executable(Singleton_Pattern_Defining_Nested_Classes
"${PROJECT_SOURCE_DIR}/Patterns/Singleton_Pattern/Defining_Nested_Classes.cpp"
${COMMON_FILES}
)

add_executable(Singleton_Pattern_Handle_Body_Idiom
"${PROJECT_SOURCE_DIR}/Patterns/Singleton_Pattern/Handle_Body_Idiom.cpp"
${COMMON_FILES}
)

add_executable(Namespaces_Using_Namespaces_Effectively
"${PROJECT_SOURCE_DIR}/Patterns/Namespaces/Using_Namespaces_Effectively.cpp"
${COMMON_FILES}
)

add_executable(Namespaces_Association_And_Delegation_Recap
"${PROJECT_SOURCE_DIR}/Patterns/Namespaces/Association_And_Delegation_Recap.cpp"
${COMMON_FILES}
)

add_executable(Patterns_Object_Adapter
"${PROJECT_SOURCE_DIR}/Patterns/Patterns/Object_Adapter.cpp"
${COMMON_FILES}
)

add_executable(Patterns_Proxy
"${PROJECT_SOURCE_DIR}/Patterns/Patterns/Proxy.cpp"
${COMMON_FILES}
)

add_executable(Patterns_Null_Object
"${PROJECT_SOURCE_DIR}/Patterns/Patterns/Null_Object.cpp"
${COMMON_FILES}
)

add_executable(Smart_Pointers_Defining_Smart_Pointers
"${PROJECT_SOURCE_DIR}/Patterns/Smart_Pointers/Defining_Smart_Pointers.cpp"
${COMMON_FILES}
)

add_executable(Smart_Pointers_Lazy_Loading
"${PROJECT_SOURCE_DIR}/Patterns/Smart_Pointers/Lazy_Loading.cpp"
${COMMON_FILES}
)