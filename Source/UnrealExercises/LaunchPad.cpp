// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "UnrealExercisesCharacter.h"

// Sets default values
ALaunchPad::ALaunchPad()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = BaseMesh;
	Forward = 250000;
	Up = { 0,0,25000 };
}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaunchPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto player = Cast<ACharacter>(OtherActor);
	if (player != nullptr)
	{
		//UStaticMeshComponent* SM = Cast<UStaticMeshComponent>(OtherActor->GetRootComponent());
		OtherActor->GetComponentByClass(UCharacterMovementComponent::StaticClass());
		player->GetCharacterMovement()->AddImpulse((player->GetActorForwardVector() * Forward) + Up);
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Emerald, TEXT("yeeeeha"));
	}
}
