# UE4ExportDataTableCommandlet

Usage

The **`** (backtick) is for running this via PowerShell

```powershell
"<UnrealEnginePath>\UE4Editor-Cmd.exe" "<ProjectPath>\MyProject.uproject" `
-run=ExportDataTable `
-DataTableInput="<DataTablePath>/MyDataTable.MyDataTable" `
-DataTableOutput="<ExportPath>/MyData.<ExportFormat>"
```

`<UnrealEnginePath>` - Path to the UE4Editor

`<ProjectPath>` - Path to your game project

`<DataTablePath>` - Path to your data table (right click your DataTable in UnrealEditor and Copy Reference)

 eg: `DataTable'Game/***/MyDataTable.MyDataTable'` _without `'DataTable'` in front_)

`<ExportPath>` - Path for your exported datatable

`<ExportFormat>` - Only `.csv` or `.json`. Use either one.


