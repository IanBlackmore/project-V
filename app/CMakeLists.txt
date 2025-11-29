cmake_minimum_required(VERSION 3.7)

project(proj_v)

set(CMAKE_CXX_STANDARD 20)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIRS})

# format for adding libraries (cpp and h files)
add_library(Transaction OBJECT Transaction.cpp Transaction.h)
add_library(TransactionReporter OBJECT TransactionReporter.cpp TransactionReporter.h)
add_library(TransactionAPI OBJECT TransactionAPI.cpp TransactionAPI.h)
add_library(MoneyFormatter OBJECT MoneyFormatter.cpp MoneyFormatter.h)
#add_library(TestTransactionAPI OBJECT TransactionAPI.cpp TransactionAPI.h TransactionAPITests.cpp)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)



add_executable(proj_v main.cpp)
#if adding libraries
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads Transaction)
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads TransactionAPI)
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads TransactionReporter)
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads MoneyFormatter)

# format for adding tests. formatting may be mangled from importing from another project
add_executable(apiTests TransactionAPITests.cpp
        TransactionTests.cpp)
target_link_libraries(apiTests Transaction)
target_link_libraries(apiTests TransactionAPI)
add_test(NAME apiTests COMMAND apiTests)
target_link_libraries(apiTests
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}		      
                      )

add_executable(MoneyFormatterTests moneyFormatterTests.cpp)
target_link_libraries(MoneyFormatterTests MoneyFormatter)
add_test(NAME MoneyFormatterTests COMMAND MoneyFormatterTests)
target_link_libraries(MoneyFormatterTests
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}		      
                      )
