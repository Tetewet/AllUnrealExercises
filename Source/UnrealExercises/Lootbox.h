// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InputComponent.h"
#include "UnrealExercisesCharacter.h"
#include "Lootbox.generated.h"

UCLASS()
class UNREALEXERCISES_API ALootbox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootbox();

	const float Common = 0.4;
	const float Rare = 0.1;
	const float Legendary = 0.1;

	UPROPERTY(EditAnywhere)
		AUnrealExercisesCharacter* Player;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Loot();

};
