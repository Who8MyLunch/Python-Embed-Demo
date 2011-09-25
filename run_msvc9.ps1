#
# Simple PowerShell script to build my project. 
#

# Go down into the build directory.
$build_dir = "build_VS2008_x64"

# if ( !(test-Path $build_dir) )
# {
    # # Raise an error message here??
# }

cd $build_dir

# Build it.
C:\Windows\Microsoft.NET\Framework64\v3.5\MSBuild.exe .\run_demo.vcproj

# Done, go back to starting folder.
cd ..

