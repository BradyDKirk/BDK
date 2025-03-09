@echo off

set ProjectDir=%~dp0

:: Options
set BaseName=run_tests
set Source=main.c

set Defines=
set IncDirs=/I %ProjectDir%..
set LibDirs=
set Libs=

:: Setup Flags
set CommonFlags=/nologo /Oi /FC /EHa- /WX /W4

:: Release Flags
::set CompilerFlags=/O2 /MT
:: Debug Flags
set CompilerFlags=/Od /MTd /Z7

:: Enable ASan
::set CompilerFlags=%CompilerFlags% /fsanitize=address

set LinkerFlags=/INCREMENTAL:NO /OPT:REF 

set OutFiles=/Fe%BaseName%.exe /Fo%BaseName%.obj

:: Create Settings
set CompilerSettings=%CommonFlags% %CompilerFlags% %IncDirs% %Defines% %OutFiles%
set LinkerSettings=%LinkerFlags% %LibDirs% %Libs%

:: Setup Directories
if not exist build mkdir build

:: Build
pushd build

del *.pdb > NUL 2> NUL
cl %CompilerSettings% %ProjectDir%\src\%Source% /link %LinkerSettings%

popd
