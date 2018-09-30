# Install CMake.
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=User'
# Refresh path variables.
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")