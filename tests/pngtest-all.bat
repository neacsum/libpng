@echo off
rem
rem Scenarios for pngtest
rem Command:
rem   pngtest-all <path to pngtest.exe>
rem

set BINDIR=%1
set DATADIR=tests\crashers
%BINDIR%\pngtest.exe --strict data\pngtest.png

rem various crashers
rem using --relaxed because some come from fuzzers that don't maintain CRC's

%BINDIR%\pngtest.exe --relaxed %DATADIR%\badcrc.png
%BINDIR%\pngtest.exe --relaxed %DATADIR%\badadler.png
%BINDIR%\pngtest.exe --xfail %DATADIR%\bad_iCCP.png
%BINDIR%\pngtest.exe --xfail %DATADIR%\empty_ancillary_chunks.png
for /f "delims=" %%a in ('dir /b %DATADIR% ^| findstr /R "huge_[a-z]*_chunk\.png" ') do  %BINDIR%\pngtest.exe --xfail %DATADIR%\%%a

%BINDIR%\pngtest.exe --xfail %DATADIR%\huge_IDAT.png

