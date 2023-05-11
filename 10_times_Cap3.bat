@echo off

echo iniciando

for /l %%i in (0,1,2) do (
  echo -------------------------------- Rodando 3-1:  %%i --------------------------------
  Capitulo3\GoingFaster3-1_8000.exe
)

for /l %%i in (0,1,9) do (
  echo -------------------------------- Rodando 3-2:  %%i --------------------------------
  Capitulo3\GoingFaster3-2_8000.exe
)

echo acabou;