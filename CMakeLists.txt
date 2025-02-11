cmake_minimum_required (VERSION 3.20)

project (cpp_learnings)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED True)

option (BUILD_TARGET_ALL "Build all targets")
option (BUILD_TARGET_CACHE "Build the Cache target")
option (BUILD_TARGET_CPP_THREADS "Build the Cpp-Threads target")
option (BUILD_TARGET_STL "Build the STL target")
option (BUILD_TARGET_GENERICS "Build the generics target")

if (BUILD_TARGET_ALL OR BUILD_TARGET_CACHE)
    add_executable (Cache "Cache/LRUCache.cpp")
endif()

if (BUILD_TARGET_ALL OR BUILD_TARGET_CPP_THREADS)
    add_library (Cpp-Threads-lib SHARED 
        "Cpp-Threads/concurrent_helloWorld.cpp"
        "Cpp-Threads/mutex.cpp"
        "Cpp-Threads/threadCreation.cpp"
        "Cpp-Threads/threadWait.cpp"
        "Cpp-Threads/thread_sync_part1.cpp"
    )
    add_executable (Cpp-Threads "Cpp-Threads/cpp_threads.cpp")
    target_link_libraries (Cpp-Threads PRIVATE Cpp-Threads-lib)
endif()

if (BUILD_TARGET_ALL OR BUILD_TARGET_STL)
    add_library (STL-lib SHARED
        "STL/iterator_methods.cpp"
        "STL/vectors.cpp"
    )
    add_executable (STL "STL/STL.cpp")
    target_link_libraries (STL PRIVATE STL-lib)
endif()

if (BUILD_TARGET_ALL OR BUILD_TARGET_GENERICS)
    add_executable (generics "generics/template.cpp")
endif()


