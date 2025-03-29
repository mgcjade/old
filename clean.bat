for /d /r .. %%d in (output) do @if exist "%%d" rd /s /q "%%d"
for /d /r .. %%d in (.cph) do @if exist "%%d" rd /s /q "%%d"