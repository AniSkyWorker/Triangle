chcp 1251
triangle.exe
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 2
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe -2 2 10
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 5 234344534534545324 16
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 1 2 3
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 1 5 3
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 0 2 10
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 0 0 0
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 1 0 1
IF NOT ERRORLEVEL 1 GOTO err

SET firstType=�������
SET secondType=��������������
SET thirdType=��������������

FOR /f %%i IN ('triangle.exe 2 4 5') DO SET result=%%i
IF NOT "%result%" == "%firstType%" GOTO err

FOR /f %%i IN ('triangle.exe 5 5 5') DO SET result=%%i
IF NOT "%result%" == "%secondType%" GOTO err

FOR /f %%i IN ('triangle.exe 2 3 2') DO SET result=%%i
IF NOT "%result%" == "%thirdType%" GOTO err

ECHO Program testing succeeded :-) 
EXIT
  
:err
ECHO Program testing failed :-( 
EXIT