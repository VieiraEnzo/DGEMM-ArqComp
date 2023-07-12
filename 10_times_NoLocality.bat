@echo off

echo iniciando

for /l %%i in (0,1,9) do (
  echo -------------------------------- Rodando NoLocality:  %%i --------------------------------
  NoLocality.exe

)

echo acabou;