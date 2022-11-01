set first_directory = %~1
set second_directory = %~2

IF exist first_directory rd first_directory
MKDIR first_directory
XCOPY 