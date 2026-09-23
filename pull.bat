@echo off
chcp 65001 >nul
title Pull Code tu GitHub - raykhoaitay/codecuabeHung

echo =======================================================
echo             DANG TAI CODE TU GITHUB VE MAY
echo =======================================================
echo.

REM 1. Khoi tao Git neu chua co
if not exist ".git" (
    git init
)

REM 2. Set nhanh main va Remote URL
git branch -M main
git remote | findstr "origin" >nul
if %errorlevel% neq 0 (
    git remote add origin https://github.com/raykhoaitay/codecuabeHung.git
) else (
    git remote set-url origin https://github.com/raykhoaitay/codecuabeHung.git
)

REM 3. Pull code tu GitHub ve local
echo [*] Dang tai tat ca file moi nhat tu GitHub...
git pull origin main

echo.
echo =======================================================
echo            DA TAI CODE VE MAY THANH CONG!
echo =======================================================
echo.
echo Bam phim bat ky de thoat...
pause >nul
exit