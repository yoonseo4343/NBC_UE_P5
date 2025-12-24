// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//FVector start = GetActorLocation();

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine) {
		/*GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Hi"));*/
		for (int i = 1; i <= 100; i++) {
			Move();
			Turn();
			GEngine->AddOnScreenDebugMessage(
				-1, 
				10.0f,
				FColor::Blue, 
				FString::Printf(
					TEXT("Location: %s, Count: %d"), *GetActorLocation().ToString(),i
				)
			);
			if (i % 10 == 0) {
				//10번마다 이벤트 랜덤
				int rn = FMath::RandRange(0, 1);
				if (rn)
					RandEvent();
			}

		}
	}
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyActor::Move() {
	SetActorLocation(GetActorLocation() + FVector(FMath::RandRange(0.f, 45.f), 0.f, 0.f));
}

void AMyActor::Turn() {
	SetActorRotation(GetActorRotation() + FRotator(0.f, FMath::RandRange(0.f, 45.f), 0.f));
}
void AMyActor::RandEvent() {
	GEngine->AddOnScreenDebugMessage(
		-1,
		10.0f,
		FColor::Blue,
		TEXT("Random Event!")
	);
}