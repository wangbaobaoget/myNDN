# Install script for directory: /home/wbb/sela/SEAL-3.3.1/native/src/seal/util

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/wbb/sela/mylibs")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/seal/util" TYPE FILE FILES
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/aes.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/baseconverter.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/clang.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/clipnormal.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/common.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/config.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/defines.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/gcc.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/globals.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/hash.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/hestdparms.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/locks.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/mempool.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/msvc.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/numth.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/pointer.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/polyarith.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/polyarithmod.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/polyarithsmallmod.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/polycore.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/rlwe.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/smallntt.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/uintarith.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/uintarithmod.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/uintarithsmallmod.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/uintcore.h"
    )
endif()

