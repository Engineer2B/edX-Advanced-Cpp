Get-ChildItem -Path $PSScriptRoot -Recurse -exclude Remove-Build.ps1 |
Select-Object -ExpandProperty FullName |
Sort-Object length -Descending |
Remove-Item -force