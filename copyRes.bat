IF NOT EXIST "$(TargetDir)res" (
CD $(TargetDir)
MKDIR res

CD res

XCOPY "$(SolutionDir)\res"  "$(TargetDir)res"
)