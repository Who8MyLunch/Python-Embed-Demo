#
# Simple PowerShell script to run CMake for my project. 
#

# Go down into the build directory.
$build_dir = "build_VS2008_x64"

if ( !(test-Path $build_dir) )
{
    new-item  $build_dir -type directory
}

cd $build_dir

# CMake the project.
cmake -G "Visual Studio 9 2008 Win64" ..

# Done, go back to starting folder.
cd ..

