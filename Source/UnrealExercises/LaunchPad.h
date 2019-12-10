// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Components/BoxComponent.h"
#include "LaunchPad.generated.h"

UCLASS()
class UNREALEXERCISES_API ALaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchPad();

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere)
		float Forward;

	UPROPERTY(EditAnywhere)
		FVector Up;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
