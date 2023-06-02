#include "Commandlets/ExportDataTableCommandlet.h"
#include "Logging/LogMacros.h"
#include "Containers/Ticker.h"
#include "UObject/UObjectGlobals.h"
#include "Engine/DataTable.h"
#include "Misc/FileHelper.h"

DEFINE_LOG_CATEGORY_STATIC(ExportDataTableCommandlet, Log, All);

void ExportDataTableToCSV(const FString& DataTableInput, const FString& DataTableOutput)
{
	if (UDataTable* DataTable = LoadObject<UDataTable>(NULL, *DataTableInput))
	{
		FFileHelper::SaveStringToFile(DataTable->GetTableAsCSV(), *DataTableOutput);
	}
}

void ExportDataTableToJson(const FString& DataTableInput, const FString& DataTableOutput)
{
	if (UDataTable* DataTable = LoadObject<UDataTable>(NULL, *DataTableInput))
	{
		FFileHelper::SaveStringToFile(DataTable->GetTableAsJSON(), *DataTableOutput);
	}
}

int32 UExportDataTableCommandlet::Main(const FString& Params)
{
	UE_LOG(ExportDataTableCommandlet, Display, TEXT("ExportDataTableCommandlet is running!"));

	FString DataTableInput, DataTableOutput;
	int32 NumParamsParsed = FParse::Value(*Params, TEXT("DataTableInput="), DataTableInput);
	NumParamsParsed += FParse::Value(*Params, TEXT("DataTableOutput="), DataTableOutput);

	if (NumParamsParsed >= 2)
	{
		FString FileExtension = FPaths::GetExtension(DataTableOutput, true);
		FString FilePath = DataTableOutput;

		if (FileExtension.IsEmpty())
		{
			UE_LOG(ExportDataTableCommandlet, Error, TEXT("No file extension provided in the destination path!"));
			return 0;
		}

		DataTableInput = DataTableInput.Replace(TEXT("\""), TEXT("")); // Remove any quotation marks from the object path

		UE_LOG(ExportDataTableCommandlet, Display, TEXT("Parsed Parameters: DataTableInput=%s, DataTableOutput=%s"),
			*DataTableInput, *DataTableOutput);

		if (FileExtension.Equals(TEXT(".csv"), ESearchCase::IgnoreCase))
		{
			ExportDataTableToCSV(DataTableInput, FilePath);
			UE_LOG(ExportDataTableCommandlet, Display, TEXT("Exported DataTable to CSV: %s"), *FilePath);
		}
		else if (FileExtension.Equals(TEXT(".json"), ESearchCase::IgnoreCase))
		{
			ExportDataTableToJson(DataTableInput, FilePath);
			UE_LOG(ExportDataTableCommandlet, Display, TEXT("Exported DataTable to JSON: %s"), *FilePath);
		}
		else
		{
			UE_LOG(ExportDataTableCommandlet, Error, TEXT("Invalid file extension specified! Use '.csv' or '.json'."));
			return 0;
		}
	}
	else
	{
		UE_LOG(ExportDataTableCommandlet, Error, TEXT("Invalid parameters! Usage: -DataTableInput=<object_path> -DataTableOutput=<full_destination_path>"));
	}

	return 0;
}


