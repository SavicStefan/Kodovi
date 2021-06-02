@echo off
gen > in
sol < in > out1
stu < in > out2
fc out1 out2
if errorlevel 1 exit
test

