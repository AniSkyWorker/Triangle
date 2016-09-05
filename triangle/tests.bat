chcp 1251
triangle.exe
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 2
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe -2 2 10
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 0 2 10
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe A 234344534534545324 16
IF NOT ERRORLEVEL 1 GOTO err

SET firstType=Разносторонний
SET secondType=Равносторонний
SET thirdType=Равнобедренный

FOR /f %%i IN ('triangle.exe 2 37 10') DO SET result=%%i
IF NOT "%result%" == "%firstType%" GOTO err

FOR /f %%i IN ('triangle.exe 5 5 5') DO SET result=%%i
IF NOT "%result%" == "%secondType%" GOTO err

FOR /f %%i IN ('triangle.exe 2 37 2') DO SET result=%%i
IF NOT "%result%" == "%thirdType%" GOTO err

ECHO Program testing succeeded :-) 
EXIT
  
:err
ECHO Program testing failed :-( 
EXIT