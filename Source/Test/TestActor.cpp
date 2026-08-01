#include "TestActor.h"

#include "Engine/Engine.h"

ATestActor::ATestActor()
{
	// 이 액터는 매 프레임 실행할 작업이 없으므로 Tick을 비활성화합니다.
	PrimaryActorTick.bCanEverTick = false;
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Test module: ATestActor BeginPlay"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Green,
			TEXT("Test module: ATestActor BeginPlay")
		);
	}
}
