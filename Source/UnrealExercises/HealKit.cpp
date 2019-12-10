// Fill out your copyright notice in the Description page of Project Settings.


#include "HealKit.h"
#include "Engine.h"
#include "TimerManager.h"
#include "UnrealExercisesCharacter.h"
#include "Materials/MaterialInstanceDynamic.h"


// Sets default values
AHealKit::AHealKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = BaseMesh;
}

// Called when the game starts or when spawned
void AHealKit::BeginPlay()
{
	Super::BeginPlay();
	
	Rotation.Add(0, 1, 0);
}

// Called every frame
void AHealKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsHealing)
	{
		HealOvertime();
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Emerald, TEXT("okOKOKOKOKOK"));
	}
	
	if (MaxAmountHealed <= 0)
	{
		Destroy();
	}
	BaseMesh->AddLocalRotation(Rotation);
}

void AHealKit::HealOvertime()
{
	auto player = Cast<AUnrealExercisesCharacter>(Player);
	player->Hp += Heal;
	MaxAmountHealed -= Heal;
}

void AHealKit::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (Cast<AUnrealExercisesCharacter>(OtherActor) != nullptr)
	{
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AHealKit::HealOvertime, Time, true);
		auto player = Cast<AUnrealExercisesCharacter>(OtherActor);
		if (player != nullptr)
		{
			IsHealing = true;
			if (player->Hp >= 1 || player->Hp <= 0)
			{
				IsHealing = false;
				GetWorld()->GetTimerManager().PauseTimer(TimerHandle);
			}
			if (HealSound != nullptr && IsHealing == true)
			{
				UGameplayStatics::PlaySoundAtLocation(this, HealSound, GetActorLocation());
			}
		}
	}
}
