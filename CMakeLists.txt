cmake_minimum_required(VERSION 3.7)

project(networks_Final)

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

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)



add_executable(proj_v main.cpp)
#if adding libraries
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads Transaction)
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads TransactionAPI)
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads TransactionReporter)
target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads MoneyFormatter)

# format for adding tests. formatting may be mangled from importing from another project
#target_link_libraries(proj_v ${Boost_LIBRARIES} Threads::Threads TEST_LIB_NAME)
#target_link_libraries(TEST_LIB_NAME PRIVATE LIB_NAME ${Boost_LIBRARIES})
#add_test(NAME TEST_LIB_NAME COMMAND TEST_LIB_NAME)

#add_executable(TEST_LIB_NAME tests.cpp)
#add_test(TEST_LIB_NAME TEST_LIB_NAME)


#target_link_libraries(TEST_LIB_NAME
#                      ${Boost_FILESYSTEM_LIBRARY}
#                      ${Boost_SYSTEM_LIBRARY}
#                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}		      
#                      )
