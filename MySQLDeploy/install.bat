@echo off

rem **********************************MySQL环境变量部署*****************************************
cd /d %~dp0
echo.>my.ini 
del /F my.ini 
echo 删除完成
echo [client]>> my.ini 
echo port = 3306>> my.ini 
echo default-character-set=utf8>>my.ini
echo [mysqld]>> my.ini 
echo collation-server=utf8_general_ci>>my.ini
echo log-error=%cd:\=\\%\\error>>my.ini
echo character_set_server=utf8>>my.ini
echo default_storage_engine=MYISAM>> my.ini 
echo basedir=%cd:\=\\%\\>>my.ini 
echo datadir=%cd:\=\\%\\data>> my.ini 

echo transaction-isolation=READ-COMMITTED>> my.ini 
echo port=3306>> my.ini 
echo max_allowed_packet=64M>> my.ini 
echo tmp_table_size=64M>> my.ini  
echo my.ini生成成功
cd /d %~dp0


echo 注册MySql服务开始
echo 停止已存在的服务MySQL
net stop MySQL
echo 删除已存在的服务MySQL
sc delete MySQL


echo 删除服务执行文件项
REG Delete HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\MySQL /v ImagePath /f
"%~dp0"\bin\mysqld.exe  -install
echo 添加服务执行文件项
REG add HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\MySQL /v ImagePath /t REG_EXPAND_SZ /d "%cd%\bin\MySqld.exe --defaults-file=\"%cd%\my.ini\" MySQL" /f
echo 删除原初始化的数据库目录
rmdir /s /q Data
echo 初始化数据库目录
cd "%~dp0"bin\
.\mysqld.exe  --initialize-insecure
net start mysql
.\mysqladmin.exe -u root password "root"
