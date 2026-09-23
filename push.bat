@echo off
chcp 65001 >nul
title Push Code len GitHub - raykhoaitay/codecuabeHung

echo =======================================================
echo             DANG PUSH CODE LEN GITHUB
echo =======================================================
echo.

REM 1. Tu dong tao file .gitignore neu chua co
if not exist ".gitignore" (
    echo *.exe > .gitignore
    echo *.o >> .gitignore
    echo *.inp >> .gitignore
    echo *.out >> .gitignore
    echo push_code.bat >> .gitignore
    echo pull_code.bat >> .gitignore
)

REM 2. Khoi tao Git neu chua co
if not exist ".git" (
    git init
)

REM 3. Set nhanh main va Remote URL
git branch -M main
git remote | findstr "origin" >nul
if %errorlevel% neq 0 (
    git remote add origin https://github.com/raykhoaitay/codecuabeHung.git
) else (
    git remote set-url origin https://github.com/raykhoaitay/codecuabeHung.git
)

REM 4. Chi gom file moi/sua, IGNORE TOAN BO thao tac xoa file o local
echo [*] Dang gom file moi va file chinh sua (Bo qua file thieu/xoa)...
git add --ignore-removal .

echo.
REM 5. Nhap noi dung commit
set "msg="
set /p "msg=--> Nhap noi dung commit (Enter de dung mac dinh): "
if "%msg%"=="" set "msg=Update code: %date% %time%"

echo [*] Dang tao commit: "%msg%"...
git commit -m "%msg%"
echo.

REM 6. Push code len GitHub
echo [*] Dang push code len GitHub...
git push -u origin main

REM Kiem tra neu push loi thi dung lai, khong xoa file
if %errorlevel% neq 0 (
    echo.
    echo [!] CO LOI XAY RA KHI PUSH CODE!
    echo [!] He thong se KHONG xoa file de bao ve an toan du lieu.
    echo.
    pause
    exit
)

REM 7. Dọn dẹp thư mục sau khi push thành công
echo.
echo [*] Push code thanh cong! Dang don dep file local...
del /q *.cpp *.exe 2>nul

echo.
echo =======================================================
echo       DA PUSH VA DON DEP FILE LOCAL THANH CONG!
echo =======================================================
echo.
echo Bam phim bat ky de thoat...
pause >nul
exit