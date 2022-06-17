@echo off
REM =========================================
REM Sprawdzian S6. Polecenia DOS/Windows
REM Zadanie nr 8
REM Autor: 
REM Damian Roszak, I rok
REM Data opracowania:
REM 2020-11-27
REM -----------------------------------------
REM Funkcja:
REM 	(skrótowy opis funkcji wykonywanej przez plik wsadowy)
REM Skrypt zaczyna od wyczyszczenia okna poleceń, następnie wczytuje numer dnia tygodnia, ilość dni i wyświetla napis napis określający ile i jakich dni zostało podane, np. pięć piątków. Oprócz tego skrypt może wyświetlić pomoc dotyczącą obsługi jego wywołania, na koniec zamyka okno wiersza poleceń.
REM Przeznaczenie:
REM 	(szczegółowy opis funkcji pliku wsadowego)
REM Funkcją wywołania jest wyświetlić pomoc, wczytać parametry wejściowe lub ich brak.
REM Skrypt najpierw sprawdza czy podane zostały parametry przy jego wywołaniu, następnie czy są zgodne z założonym zakresem każdego z nich, jeśli tak wyświetla odpowiedź: ile i jakie dni wskazują te parametry. Jeśli nie są zgodne z założonym zakresem i formatem (dla przypadkowego ciągu również), to: albo wyświetla komunikat jak uzyskać pomoc i kończy działanie (pytając wcześniej czy zakończyć) albo w przypadku braku drugiego parametru w wywołaniu dopytuje użytkownika o niego wykonuje wyświetlenie dni jak w przypadku powyżej. W przypadku braku parametrów wejściowych, pyta o nie sprawdzając czy są poprawne jeśli nie ponawia zapytanie. Dalej wykonuje się jak powyżej podając dni i ich ilość następnie kończy pytając "KONIEC?" i zamyka okno poleceń.
REM Wywołanie:
REM 	nazwa [/?] lub [ parametr1 parametr2 ] lub bez parametrów
REM Opis parametrów:
REM "/?" 		 -  wyświetla tę informację
REM parametr1	 -  numer dnia tygodnia z przedziału 1..7 (1=poniedziałek, 2=wtorek, 3=środa, itd.).
REM parametr2	 -  liczba dni z przedziału 1..10
REM bez parametrów   - pobiera parametry w trakcie wykonywania skryptu
REM =========================================
REM Treść pliku wsadowego skryptu
REM (poniżej znajdują się polecenia tworzące plik wsadowy)

 cls
 set numerTygodnia=
 set liczbaDni=
if "%1" == "/?" goto info
if "%1" =="" goto menu
if not %1 LSS 1 cls && if not %1 GTR 7 set numerTygodnia=%1
if %1 LSS 1 cls && goto komunikatEntry
if %1 GTR 7 cls && goto komunikatEntry

if "%2" == "" goto liczDni
if not %2 LSS 1 echo. && if not %2 GTR 10 set liczbaDni=%2 && goto jeden

:komunikatEntry
if not "%1" =="" echo ABY POZNAĆ FUNKCJĘ PLIKU WSADOWEGO, UŻYJ PARAMETRU /? && goto koniec

:menu
 set numerTygodnia=
 set liczbaDni=
echo     PODAJ DANE
set /p  numerTygodnia="PODAJ NUMER DNIA TYGODNIA: "
if %numerTygodnia% LSS 1 goto menu
if %numerTygodnia% GTR 7 goto menu
:liczDni
set /p liczbaDni="PODAJ LICZBĘ DNI: "
if  %liczbaDni% LSS 1 goto menu
if  %liczbaDni% GTR 10 goto menu


:jeden
if not %numerTygodnia% EQU 1 goto dwa
if %liczbaDni% EQU 1 echo JEDEN PONIEDZIAŁEK 
if %liczbaDni% EQU 2 echo DWA PONIEDZIAŁKI
if %liczbaDni% EQU 3 echo TRZY PONIEDZIAŁKI 
if %liczbaDni% EQU 4 echo CZTERY PONIEDZIAŁKI 
if %liczbaDni% EQU 5 echo PIĘĆ PONIEDZIAŁKÓW 
if %liczbaDni% EQU 6 echo SZEŚĆ PONIEDZIAŁKÓW 
if %liczbaDni% EQU 7 echo SIEDEM PONIEDZIAŁKÓW
if %liczbaDni% EQU 8 echo OSIEM PONIEDZIAŁKÓW
if %liczbaDni% EQU 9 echo DZIEWIĘĆ PONIEDZIAŁKÓW
if %liczbaDni% EQU 10 echo DZIESIĘĆ PONIEDZIAŁKÓW
goto pytaj

:dwa
if not %numerTygodnia% EQU 2 goto trzy
if %liczbaDni% EQU 1 echo JEDEN WTOREK 
if %liczbaDni% EQU 2 echo DWA WTORKI
if %liczbaDni% EQU 3 echo TRZY WTORKI 
if %liczbaDni% EQU 4 echo CZTERY WTORKI 
if %liczbaDni% EQU 5 echo PIĘĆ WTORKÓW 
if %liczbaDni% EQU 6 echo SZEŚĆ WTORKÓW 
if %liczbaDni% EQU 7 echo SIEDEM WTORKÓW
if %liczbaDni% EQU 8 echo OSIEM WTORKÓW
if %liczbaDni% EQU 9 echo DZIEWIĘĆ WTORKÓW
if %liczbaDni% EQU 10 echo DZIESIĘĆ WTORKÓW
goto pytaj

:trzy
if not %numerTygodnia% EQU 3 goto cztery
if %liczbaDni% EQU 1 echo JEDNA ŚRODA 
if %liczbaDni% EQU 2 echo DWIE ŚRODY
if %liczbaDni% EQU 3 echo TRZY ŚRODY 
if %liczbaDni% EQU 4 echo CZTERY ŚRODY 
if %liczbaDni% EQU 5 echo PIĘĆ ŚRÓD 
if %liczbaDni% EQU 6 echo SZEŚĆ ŚRÓD 
if %liczbaDni% EQU 7 echo SIEDEM ŚRÓD
if %liczbaDni% EQU 8 echo OSIEM ŚRÓD
if %liczbaDni% EQU 9 echo DZIEWIĘĆ ŚRÓD
if %liczbaDni% EQU 10 echo DZIESIĘĆ ŚRÓD
goto pytaj

:cztery
if not %numerTygodnia% EQU 4 goto piec
if %liczbaDni% EQU 1 echo JEDEN CZWARTEK 
if %liczbaDni% EQU 2 echo DWA CZWARTKI
if %liczbaDni% EQU 3 echo TRZY CZWARTKI 
if %liczbaDni% EQU 4 echo CZTERY CZWARTKI 
if %liczbaDni% EQU 5 echo PIĘĆ CZWARTKÓW 
if %liczbaDni% EQU 6 echo SZEŚĆ CZWARTKÓW 
if %liczbaDni% EQU 7 echo SIEDEM CZWARTKÓW
if %liczbaDni% EQU 8 echo OSIEM CZWARTKÓW
if %liczbaDni% EQU 9 echo DZIEWIĘĆ CZWARTKÓW
if %liczbaDni% EQU 10 echo DZIESIĘĆ CZWARTKÓW
goto pytaj

:piec
if not %numerTygodnia% EQU 5 goto szesc
if %liczbaDni% EQU 1 echo JEDEN PIĄTEK 
if %liczbaDni% EQU 2 echo DWA PIĄTKI
if %liczbaDni% EQU 3 echo TRZY PIĄTKI 
if %liczbaDni% EQU 4 echo CZTERY PIĄTKI 
if %liczbaDni% EQU 5 echo PIĘĆ PIĄTKÓW 
if %liczbaDni% EQU 6 echo SZEŚĆ PIĄTKÓW 
if %liczbaDni% EQU 7 echo SIEDEM PIĄTKÓW
if %liczbaDni% EQU 8 echo OSIEM PIĄTKÓW
if %liczbaDni% EQU 9 echo DZIEWIĘĆ PIĄTKÓW
if %liczbaDni% EQU 10 echo DZIESIĘĆ PIĄTKÓW
goto pytaj

:szesc
if not %numerTygodnia% EQU 6 goto siedem
if %liczbaDni% EQU 1 echo JEDNA SOBOTA 
if %liczbaDni% EQU 2 echo DWIE SOBOTY
if %liczbaDni% EQU 3 echo TRZY SOBOTY 
if %liczbaDni% EQU 4 echo CZTERY SOBOTY 
if %liczbaDni% EQU 5 echo PIĘĆ SOBÓT 
if %liczbaDni% EQU 6 echo SZEŚĆ SOBÓT 
if %liczbaDni% EQU 7 echo SIEDEM SOBÓT
if %liczbaDni% EQU 8 echo OSIEM SOBÓT
if %liczbaDni% EQU 9 echo DZIEWIĘĆ SOBÓT
if %liczbaDni% EQU 10 echo DZIESIĘĆ SOBÓT
goto pytaj

:siedem
if %liczbaDni% EQU 1 echo JEDNA NIEDZIELA 
if %liczbaDni% EQU 2 echo DWIE NIEDZIELE
if %liczbaDni% EQU 3 echo TRZY NIEDZIELE 
if %liczbaDni% EQU 4 echo CZTERY NIEDZIELE 
if %liczbaDni% EQU 5 echo PIĘĆ NIEDZIEL 
if %liczbaDni% EQU 6 echo SZEŚĆ NIEDZIEL 
if %liczbaDni% EQU 7 echo SIEDEM NIEDZIEL
if %liczbaDni% EQU 8 echo OSIEM NIEDZIEL
if %liczbaDni% EQU 9 echo DZIEWIĘĆ NIEDZIEL
if %liczbaDni% EQU 10 echo DZIESIĘĆ NIEDZIEL
goto pytaj


:info
echo Skrypt Sprawdzian 6. Składnia wywołania
echo Nazwa_Skryptu [/?] lub {parametr1] [parametr2] lub bez parametrów
echo 	"/?" 		 -  wyświetla tę informację
echo 	parametr1	 -  numer dnia tygodnia z przedziału 1..7 
echo 			(1=poniedziałek, 2=wtorek, 3=środa, itd.).
echo 	parametr2	 -  liczba dni z przedziału 1..10
echo 	bez parametrów   - pobiera parametry w trakcie wykonywania skryptu



:pytaj
set kon=
set /p kon="KONIEC? "
if "%kon%" =="t" goto koniec
if "%kon%" =="T" goto koniec
goto menu

:koniec
exit