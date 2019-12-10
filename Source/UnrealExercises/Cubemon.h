// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WidgetComponent.h"
#include "Cubemon.generated.h"

UCLASS()
class UNREALEXERCISES_API ACubemon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubemon();

	UPROPERTY(BlueprintReadWrite)
		float Hp = 1;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* DoubleMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UWidgetComponent* HealthBar;

	UPROPERTY(EditAnywhere)
		ACharacter* Player;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* CubemonMaterial;
	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* CubemonHeadMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector Hitlocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	void UpdateMaterial();
};
