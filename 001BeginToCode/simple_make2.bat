@echo off
g++ -c people.cpp -o people.obj
g++ -c main.cpp -o main.obj
g++ people.obj main.obj -o test_people.exe
del *.obj