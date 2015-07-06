// Fill out your copyright notice in the Description page of Project Settings.

#include "Test2.h"
#include "CameraDirector.h"
#include "EnemyCharacter.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	ACharacter* characher1 = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	TArray<AActor*> arr;
	//ACharacter* characher2 = 
	UGameplayStatics::GetAllActorsOfClass(this, AEnemyCharacter::StaticClass(), arr);
	FVector CameraPosition = Camera->GetActorLocation();
	if (characher1 && arr.Num() != 0)
	{
		FVector pos1 = characher1->GetActorLocation();
		FVector pos2 = arr[0]->GetActorLocation();
		FVector NewPos = (pos1 + pos2) / 2.0;
		Camera->SetActorLocation(FVector(CameraPosition.X, NewPos.Y, NewPos.Z));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString("1: " )+ pos1.ToString());
	}

	if (OurPlayerController)
	{
		OurPlayerController->SetViewTarget(Camera);
	}

}

