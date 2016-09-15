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

triangle.exe 1,2 1,3 0,1
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 1E 1WW 1.3
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 1W E3R 3.4
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe . . .
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe , E, 3,4
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe  ,5 3 3,4
IF NOT ERRORLEVEL 1 GOTO err
                            
triangle.exe 5, 3 4,4
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe  , 3 3,4
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe  3,, 3 3,4
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe  3,4, 3 3,4
IF NOT ERRORLEVEL 1 GOTO err

SET firstType=Обычный
SET secondType=Равносторонний
SET thirdType=Равнобедренный

FOR /f %%i IN ('triangle.exe 2 4 5') DO SET result=%%i
IF NOT "%result%" == "%firstType%" GOTO err

FOR /f %%i IN ('triangle.exe 5 5 5') DO SET result=%%i
IF NOT "%result%" == "%secondType%" GOTO err

FOR /f %%i IN ('triangle.exe 2 3 2') DO SET result=%%i
IF NOT "%result%" == "%thirdType%" GOTO err

FOR /f %%i IN ('triangle.exe "1,1" 4 5') DO SET result=%%i
IF NOT "%result%" == "%firstType%" GOTO err

FOR /f %%i IN ('triangle.exe "1,1" "1,2" "1,3"') DO SET result=%%i
IF NOT "%result%" == "%firstType%" GOTO err

FOR /f %%i IN ('triangle.exe 2 3 2') DO SET result=%%i
IF NOT "%result%" == "%thirdType%" GOTO err

FOR /f %%i IN ('triangle.exe "1,1" "1,1" "1,1"') DO SET result=%%i
IF NOT "%result%" == "%secondType%" GOTO err

FOR /f %%i IN ('triangle.exe "1.1" "1.1" "1.1"') DO SET result=%%i
IF NOT "%result%" == "%secondType%" GOTO err

ECHO Program testing succeeded :-) 
EXIT
  
:err
ECHO Program testing failed :-( 
EXIT