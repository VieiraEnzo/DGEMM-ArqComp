@echo off

echo iniciando

for /l %%i in (0,1,9) do (
  echo -------------------------------- Rodando 4:  %%i --------------------------------
  Capitulo4\GoingFaster4-OO_8000.exe
  echo -------------------------------- Rodando 4-O3:  %%i --------------------------------
  Capitulo4\GoingFaster4-O3_8000.exe
  echo -------------------------------- Rodando 5:  %%i --------------------------------
  Capitulo5\GoingFaster5-OO_8000.exe
  echo -------------------------------- Rodando 5-O3:  %%i --------------------------------
  Capitulo5\GoingFaster5-O3_8000.exe
  echo -------------------------------- Rodando 6:  %%i --------------------------------
  Capitulo6\GoingFaster6-OO_8000.exe
  echo -------------------------------- Rodando 6-O3:  %%i --------------------------------
  Capitulo6\GoingFaster6-O3_8000.exe
)

echo acabou;