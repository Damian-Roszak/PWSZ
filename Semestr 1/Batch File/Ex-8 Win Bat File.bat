@echo off
REM =========================================
REM Ćwiczenie 6. Pliki wsadowe DOS/Windows
REM Autor: 
REM Damian Roszak, I rok
REM Data opracowania:
REM 2020-11-17
REM -----------------------------------------
REM Funkcja:
REM (skrótowy opis funkcji wykonywanej przez plik wsadowy)
REM Plik wsadowy zamienia miejscami dwa pliki, kopiuje zawartość jednego do drugiego, usuwa wskazane pliki oraz wyszukuje w jednym pliku wzrorzec zawarty w drugim 
REM Przeznaczenie:
REM (szczegółowy opis funkcji pliku wsadowego
REM 1 Wymiana zawartości dwóch plików = pliki są zamieniane z sobą miejscami, poprzez polecenie move pierwszy plik trafia do katalogu drugiego pliku, a drugi do katalogu pierwszego
REM 2 Kopiowanie pierwszego pliku do drugiego = zawartość pliku pierwszego jest kopiowana do drugiego pliku zastępując jego poprzednią zawartość za pomocą polecenia copy
REM 3 Usuwanie dwóch plików =  oba pliki zostają usunięte za pomocą polecenia erase /p /f, funkcja monituje o potwierdzenie usunięcia i wymusza usuwanie plików z atrybutem tylko do odczytu
REM 4 Wyszukiwanie wzorca w pliku = pliku pierwszym wyszukiwane są wszystkie wystąpienia ciągów podanych jako wzorce w pliku drugim, bez rozróżniania dużych i małych liter, za pomocą poleceń: findstr /n /i /g:%param2% %param1% > tmp.txt funkcja wyszukuje w pierwszym pliku wzrorce z pliku drugiego, dla poprawy obsługi Polskich znaków i zmniejszenia ilości błędów funkcja zapisuje wynik do pliku tymczasowego, następnie wyświetla wyniki wyszukiwania z pliku tymczasowego poleceniem type tmp.txt i na koniec usuwa plik tymczasowy poleceniem erase tmp.txt
REM K Zakończenie pracy programu = kończy działanie skryptu, poprzez skok do etykiety kończącej plik skryptu i jego działanie
REM Wywołanie:
REM nazwa [/?] lub [/ver2] lub [parametr1 parametr2 parametr3 parametr4]
REM Opis parametrów:
REM parametr1 = ścieżka do katalogu zawierającego plik pierwszy
REM parametr2 = nazwa pliku pierwszego 
REM parametr3 = ścieżka do katalogu zawierającego plik drugi
REM parametr4 = nazwa pliku drugiego 
REM "/?" = wyświetla pomoc wywołania skryptu
REM /ver2 = druga wersja rozwiązania zadania realizuje je bez pobierania parametrów z wywołania, a pyta o nie po wybraniu opcji z menu, następnie realizując te same funkcje co wersja pobierająca parametry z wywołania skryptu
REM 
REM =========================================
REM Treść pliku wsadowego skryptu
REM (poniżej znajdują się polecenia tworzące plik wsadowy)

 cls

if "%1" =="/?" goto informacja
if "%1" =="/ver2" goto ver2
if "%1" =="" echo 1 ZA MAŁO PARAMETRÓW && goto koniec
if "%2" =="" echo 2 ZA MAŁO PARAMETRÓW && goto koniec
if "%3" =="" echo 3 ZA MAŁO PARAMETRÓW && goto koniec
if "%4" =="" echo 4 ZA MAŁO PARAMETRÓW && goto koniec

if "%1" == "\" set param1=%2 
if not "%1" == "\" set param1=%1\%2
if not exist "%param1%" echo BRAK PLIKU %2 && goto koniec

if "%2" == "\" set param2=%4 
if not "%2" == "\" set param2=%3\%4
if not exist "%param2%" echo BRAK PLIKU %4 && goto koniec

:menu

echo          1 Wymiana zawartości dwóch plików
echo          2 Kopiowanie pierwszego pliku do drugiego
echo          3 Usuwanie dwóch plików
echo          4 Wyszukiwanie wzorca w pliku
echo          K Zakończenie pracy programu

set /p wybor="Wybierz numer polecenia: "

if %wybor% EQU 1 goto %wybor%
if %wybor% EQU 2 goto %wybor%
if %wybor% EQU 3 goto %wybor%
if %wybor% EQU 4 goto %wybor%
if %wybor% EQU k goto koniec
if %wybor% EQU K goto koniec
echo Nie ma takiej opcji, spróbuj ponownie
goto menu


:1
 
if "%1" =="" echo 1 ZA MAŁO PARAMETRÓW && goto koniec
if "%2" =="" echo 2 ZA MAŁO PARAMETRÓW && goto koniec
if "%3" =="" echo 3 ZA MAŁO PARAMETRÓW && goto koniec
if "%4" =="" echo 4 ZA MAŁO PARAMETRÓW && goto koniec

if "%1" == "\" set param1=%2 
if not "%1" == "\" set param1=%1\%2
if not exist "%param1%" echo BRAK PLIKU %2 && goto koniec

if "%2" == "\" set param2=%4 
if not "%2" == "\" set param2=%3\%4
if not exist "%param2%" echo BRAK PLIKU %4 && goto koniec

@move %param1% %3
@move %param2% %1
goto menu

:2
 
if "%1" =="" echo 1 ZA MAŁO PARAMETRÓW && goto koniec
if "%2" =="" echo 2 ZA MAŁO PARAMETRÓW && goto koniec
if "%3" =="" echo 3 ZA MAŁO PARAMETRÓW && goto koniec
if "%4" =="" echo 4 ZA MAŁO PARAMETRÓW && goto koniec

if "%1" == "\" set param1=%2 
if not "%1" == "\" set param1=%1\%2
if not exist "%param1%" echo BRAK PLIKU %2 && goto koniec

if "%2" == "\" set param2=%4 
if not "%2" == "\" set param2=%3\%4
if not exist "%param2%" echo BRAK PLIKU %4 && goto koniec

copy %param1% %param2%
goto menu

:3
 
if "%1" =="" echo 1 ZA MAŁO PARAMETRÓW && goto koniec
if "%2" =="" echo 2 ZA MAŁO PARAMETRÓW && goto koniec
if "%3" =="" echo 3 ZA MAŁO PARAMETRÓW && goto koniec
if "%4" =="" echo 4 ZA MAŁO PARAMETRÓW && goto koniec

if "%1" == "\" set param1=%2 
if not "%1" == "\" set param1=%1\%2
if not exist "%param1%" echo BRAK PLIKU %2 && goto koniec

if "%2" == "\" set param2=%4 
if not "%2" == "\" set param2=%3\%4
if not exist "%param2%" echo BRAK PLIKU %4 && goto koniec

erase /p /f %param1% %param2%
goto menu

:4
 
if "%1" =="" echo 1 ZA MAŁO PARAMETRÓW && goto koniec
if "%2" =="" echo 2 ZA MAŁO PARAMETRÓW && goto koniec
if "%3" =="" echo 3 ZA MAŁO PARAMETRÓW && goto koniec
if "%4" =="" echo 4 ZA MAŁO PARAMETRÓW && goto koniec

if "%1" == "\" set param1=%2 
if not "%1" == "\" set param1=%1\%2
if not exist "%param1%" echo BRAK PLIKU %2 && goto koniec

if "%2" == "\" set param2=%4 
if not "%2" == "\" set param2=%3\%4
if not exist "%param2%" echo BRAK PLIKU %4 && goto koniec

findstr /n /i /g:%param2% %param1% > tmp.txt
type tmp.txt
erase tmp.txt
echo. 


goto menu


:ver2
echo ver2

echo          1 Wymiana zawartości dwóch plików
echo          2 Kopiowanie pierwszego pliku do drugiego
echo          3 Usuwanie dwóch plików
echo          4 Wyszukiwanie wzorca w pliku
echo          K Zakończenie pracy programu

set /p wybor="Wybierz numer polecenia: "

if %wybor% EQU 1 goto ver2_1
if %wybor% EQU 2 goto ver2_2
if %wybor% EQU 3 goto ver2_3
if %wybor% EQU 4 goto ver2_4
if %wybor% EQU k goto koniec
if %wybor% EQU K goto koniec
echo Nie ma takiej opcji, spróbuj ponownie
goto ver2


:ver2_1
 
set par1=
set par1a=
set par2=
set par2a=
set parametr1=
set parametr2=

set /p par1="Podaj ścieżkę dostępu do katalogu zawierającego plik 1: "
set /p par1a="Podaj nazwę pliku 1: "
if "%par1%" == "\" set parametr1=%par1a% 
if not "%par1%" == "\" set parametr1=%par1%\%par1a% 
if "%parametr1%" =="" echo ZA MAŁO PARAMETRÓW && goto koniec
if not exist "%parametr1%" echo BRAK PLIKU %par1a% && goto koniec

set /p par2="Podaj ścieżkę dostępu do katalogu zawierającego plik 2: "
set /p par2a="Podaj nazwę pliku 2: "
if "%par2%" == "\" set parametr2=%par2a% 
if not "%par2%" == "\" set parametr2=%par2%\%par2a%
if "%parametr2%" =="" echo ZA MAŁO PARAMETRÓW  && goto koniec
if not exist "%parametr2%" echo BRAK PLIKU %par2a% && goto koniec

@move /-y %parametr1% %par2%
@move /-y %parametr2% %par1%

goto ver2


:ver2_2
 
set par1=
set par1a=
set par2=
set par2a=
set parametr1=
set parametr2=

set /p par1="Podaj ścieżkę dostępu do katalogu zawierającego plik 1: "
set /p par1a="Podaj nazwę pliku: 1 "
if "%par1%" == "\" set parametr1=%par1a% 
if not "%par1%" == "\" set parametr1=%par1%\%par1a% 
if "%parametr1%" =="" echo ZA MAŁO PARAMETRÓW && goto koniec
if not exist "%parametr1%" echo BRAK PLIKU %par1a% && goto koniec

set /p par2="Podaj ścieżkę dostępu do katalogu zawierającego plik 2: "
set /p par2a="Podaj nazwę pliku 2: "
if "%par2%" == "\" set parametr2=%par2a% 
if not "%par2%" == "\" set parametr2=%par2%\%par2a%
if "%parametr2%" =="" echo ZA MAŁO PARAMETRÓW  && goto koniec
if not exist "%parametr2%" echo BRAK PLIKU %par2a% && goto koniec

copy %parametr1% %parametr2%

goto ver2

:ver2_3
 
set par1=
set par1a=
set par2=
set par2a=
set parametr1=
set parametr2=

set /p par1="Podaj ścieżkę dostępu do katalogu zawierającego plik 1: "
set /p par1a="Podaj nazwę pliku 1: "
if "%par1%" == "\" set parametr1=%par1a% 
if not "%par1%" == "\" set parametr1=%par1%\%par1a% 
if "%parametr1%" =="" echo ZA MAŁO PARAMETRÓW && goto koniec
if not exist "%parametr1%" echo BRAK PLIKU %par1a% && goto koniec

set /p par2="Podaj ścieżkę dostępu do katalogu zawierającego plik 2: "
set /p par2a="Podaj nazwę pliku 2: "
if "%par2%" == "\" set parametr2=%par2a% 
if not "%par2%" == "\" set parametr2=%par2%\%par2a%
if "%parametr2%" =="" echo ZA MAŁO PARAMETRÓW  && goto koniec
if not exist "%parametr2%" echo BRAK PLIKU %par2a% && goto koniec

erase /p /f %parametr1% %parametr2%

goto ver2

:ver2_4
 
set par1=
set par1a=
set par2=
set par2a=
set parametr1=
set parametr2=

set /p par1="Podaj ścieżkę dostępu do katalogu zawierającego plik 1: "
set /p par1a="Podaj nazwę pliku 1: "
if "%par1%" == "\" set parametr1=%par1a% 
if not "%par1%" == "\" set parametr1=%par1%\%par1a% 
if "%parametr1%" =="" echo ZA MAŁO PARAMETRÓW && goto koniec
if not exist "%parametr1%" echo BRAK PLIKU %par1a% && goto koniec

set /p par2="Podaj ścieżkę dostępu do katalogu zawierającego plik 2: "
set /p par2a="Podaj nazwę pliku 2: "
if "%par2%" == "\" set parametr2=%par2a% 
if not "%par2%" == "\" set parametr2=%par2%\%par2a%
if "%parametr2%" =="" echo ZA MAŁO PARAMETRÓW  && goto koniec
if not exist "%parametr2%" echo BRAK PLIKU %par2a% && goto koniec

findstr /n /i /g:%parametr2% %parametr1% > tmp.txt
type tmp.txt
erase tmp.txt
echo. 

goto ver2


:informacja
echo Składnia polecenia
echo   Nazwa_Skryptu [/?] lub [ver2] lub [parametr1 parametr2 parametr3 parametr4]
echo.
echo     "/?"  -  wyświetla tę informację
echo     parametr 1 i 3    -  ścieżka do katalogu zawierającego plik
echo                          dla katalogu bieżącego ukośnik "\" 
echo     parametr 2 i 4 - nazwa pliku wraz z rozszerzeniem
echo     ver2  -  skrypt używa drugiej wersji rozwiązania zadania
echo _
echo _

:koniec
echo KONIEC PRACY
PAUSE
