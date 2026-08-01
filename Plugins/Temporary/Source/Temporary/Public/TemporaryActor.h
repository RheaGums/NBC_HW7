#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TemporaryActor.generated.h"

UCLASS(Blueprintable)
class TEMPORARY_API ATemporaryActor : public AActor
{
	GENERATED_BODY()

public:
	ATemporaryActor();

protected:
	// 플러그인 액터가 월드에서 플레이를 시작할 때 호출됩니다.
	virtual void BeginPlay() override;
};
