@ECHO OFF
ECHO # Compiling ...
cl /nologo /EHsc /Idisphelper_081\single_file_source main.cpp disphelper_081\single_file_source\disphelper.lib user32.lib /Fe:main.exe
ECHO Finished. 
ECHO # Cleaning ...
DEL main.obj main.pdb vc140.pdb
ECHO Finished. 
