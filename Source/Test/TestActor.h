#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class TEST_API ATestActor : public AActor
{
	GENERATED_BODY()

public:
	ATestActor();

protected:
	// 액터가 월드에서 플레이를 시작할 때 한 번 호출됩니다.
	virtual void BeginPlay() override;
};
