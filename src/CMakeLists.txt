add_executable(${PROJECT_NAME}
  main.cpp
  CAoJia.cpp
  Helper.cpp
  Log.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    BIN_VERSION="${PROJECT_VERSION}"
)
