@echo off
set /a cnt = 0
g++ good.cpp -o good.exe -std=c++17
g++ bad.cpp -o bad.exe -std=c++17
g++ make.cpp -o make.exe -std=c++17

:loop
set /a cnt += 1
make.exe > in.txt
good.exe < in.txt > good.txt
bad.exe < in.txt > bad.txt
fc bad.txt good.txt
if errorlevel 1 (
    echo wa on test %cnt%
    exit /b
) else (
    echo ac on test %cnt%
)
goto loop