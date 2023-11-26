# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CS003A_final_new_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CS003A_final_new_autogen.dir\\ParseCache.txt"
  "CS003A_final_new_autogen"
  )
endif()
