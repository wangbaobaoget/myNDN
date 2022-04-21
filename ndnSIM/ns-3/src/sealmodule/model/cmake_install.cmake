# Install script for directory: /home/wbb/sela/SEAL-3.3.1/native/src/seal

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/seal" TYPE FILE FILES
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/batchencoder.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/biguint.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/ciphertext.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/ckks.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/modulus.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/context.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/decryptor.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/intencoder.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/encryptionparams.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/encryptor.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/evaluator.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/galoiskeys.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/intarray.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/keygenerator.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/kswitchkeys.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/memorymanager.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/modulus.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/plaintext.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/publickey.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/randomgen.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/randomtostd.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/relinkeys.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/seal.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/secretkey.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/smallmodulus.h"
    "/home/wbb/sela/SEAL-3.3.1/native/src/seal/valcheck.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/wbb/sela/SEAL-3.3.1/native/src/seal/util/cmake_install.cmake")

endif()

