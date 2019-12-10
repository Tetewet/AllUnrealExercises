// Fill out your copyright notice in the Description page of Project Settings.


#include "ProximityMine.h"
#include "UnrealExercisesCharacter.h"
#include "UnrealExercisesProjectile.h"
#include "Engine.h"

// Sets default values
AProximityMine::AProximityMine()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Distance = 500;
	Time = 5;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = BaseMesh;
}

// Called when the game starts or when spawned
void AProximityMine::BeginPlay()
{
	Super::BeginPlay();
	ProximityMineMaterial = BaseMesh->CreateDynamicMaterialInstance(0);
}

// Called every frame
void AProximityMine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TicTac();
	UpdateMaterial();
}

void AProximityMine::TicTac()
{
	if (this->GetActorLocation().Distance(this->GetActorLocation(), Player->GetActorLocation()) <= Distance)
	{
		Red = 1;
		IsInRadius = true;
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AProximityMine::Boum, Time, true);
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Emerald, TEXT("TIC TAC"));
	}
	else
	{
		IsInRadius = false;
	}
}

void AProximityMine::Boum()
{
	auto player = Cast<AUnrealExercisesCharacter>(Player);
	if (player != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Emerald, TEXT("BOUM"));
		Seconds--;
		if (Seconds < 0)
		{
			if (IsInRadius)
			{
				player->Hp -= Damage;
			}
			//particle systems to popup;
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetTransform());
			Destroy();
		}
		//Player->Hp -= Damage;
	}
}

void AProximityMine::UpdateMaterial()
{
	ProximityMineMaterial->SetScalarParameterValue(TEXT("Red"), Red);
}

void AProximityMine::NotifyHit(class UPrimitiveComponent* MyComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector Hitlocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, OtherActor, OtherComp, bSelfMoved, Hitlocation, HitNormal, NormalImpulse, Hit);
	if (Cast<AUnrealExercisesProjectile>(OtherActor) != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Emerald, TEXT("BoumSHOT"));
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetTransform());
		Destroy();
	}
}