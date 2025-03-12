# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/XMLWriting_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/XMLWriting_autogen.dir/ParseCache.txt"
  "XMLWriting_autogen"
  )
endif()
