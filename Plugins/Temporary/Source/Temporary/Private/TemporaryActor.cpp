#include "TemporaryActor.h"

#include "Engine/Engine.h"

ATemporaryActor::ATemporaryActor()
{
	// 시작 메시지만 출력하므로 매 프레임 Tick을 실행하지 않습니다.
	PrimaryActorTick.bCanEverTick = false;
}

void ATemporaryActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Temporary plugin: ATemporaryActor BeginPlay"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Cyan,
			TEXT("Temporary plugin: ATemporaryActor BeginPlay")
		);
	}
}
