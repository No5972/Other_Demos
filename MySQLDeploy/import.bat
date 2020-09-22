@echo off
set input=
set /p input=输入数据库名称:
set username=
set /p username=输入数据库用户名:
set "psCommand=powershell -Command "$pword = read-host '输入数据库密码' -AsSecureString ; ^
    $BSTR=[System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($pword); ^
        [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)""
for /f "usebackq delims=" %%p in (`%psCommand%`) do set password=%%p
echo.>init.sql 
del /F init.sql
echo 删除临时SQL完成
echo DROP DATABASE IF EXISTS %input%;>> init.sql
echo CREATE DATABASE %input%;>> init.sql
echo 已生成临时SQL
echo 开始创建数据库
mysql -h localhost -uroot -proot < .\init.sql 2>&1
echo 开始导入SQL
mysql -h localhost -u%username% -p%password% %input% < .\%input%.sql 2>&1
echo 删除临时SQL
del /F init.sql
echo 导入数据库完成
@echo on
