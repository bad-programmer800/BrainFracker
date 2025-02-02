@echo off
pushd %~dp0\..\
call C:\premake\premake5.exe vs2022
popd
PAUSE