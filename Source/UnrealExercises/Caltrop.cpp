// Fill out your copyright notice in the Description page of Project Settings.


#include "Caltrop.h"
#include "Engine.h"
#include "UnrealExercisesCharacter.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ACaltrop::ACaltrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	CollisionBox->SetSimulatePhysics(true);
	RootComponent = BaseMesh;
}

// Called when the game starts or when spawned
void ACaltrop::BeginPlay()
{
	Super::BeginPlay();
	CaltropMaterial = BaseMesh->CreateDynamicMaterialInstance(0);
}

void ACaltrop::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (Cast<AUnrealExercisesCharacter>(OtherActor) != nullptr)
	{
		auto player = Cast<AUnrealExercisesCharacter>(OtherActor);
		if (player != nullptr)
		{
			player->Hp -= Damage;
			Destroy();
		}
	}
}


// Called every frame
void ACaltrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateMaterial();
}

void ACaltrop::UpdateMaterial()
{
	CaltropMaterial->SetScalarParameterValue(TEXT("Blue"), Blue);
}

