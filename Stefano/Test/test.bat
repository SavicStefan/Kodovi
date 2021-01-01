@echo off
gen >ulaz
sol <ulaz >izlaz1
stu <ulaz >izlaz2
fc izlaz1 izlaz2
if errorlevel 1 exit
test

