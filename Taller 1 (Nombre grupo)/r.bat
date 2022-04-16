REM
echo "Running \m"
gcc -c -o main.o main.cpp -I\"C:/msys64/mingw64/x86_64-w64-mingw32/include\"
cls
echo "Compiling Graphic"
gcc -o main.exe  main.o -L\"C:/msys64/mingw64/x86_64-w64-mingw32/lib -lopengl32 -lglu32 -lfreeglut
rm main.o
cls
echo "App Running"
main.exe
