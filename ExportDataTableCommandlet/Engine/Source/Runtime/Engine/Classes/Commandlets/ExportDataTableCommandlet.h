#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Commandlets/Commandlet.h"
#include "ExportDataTableCommandlet.generated.h"

UCLASS()
class UExportDataTableCommandlet : public UCommandlet
{
	GENERATED_BODY()

		virtual int32 Main(const FString& Params) override;
};
