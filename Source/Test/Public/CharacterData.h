#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterData.generated.h"

UCLASS(BlueprintType)
class TEST_API UCharacterData : public UObject
{
	GENERATED_BODY()

public:
	UCharacterData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	int32 MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	float MoveSpeed;
};
