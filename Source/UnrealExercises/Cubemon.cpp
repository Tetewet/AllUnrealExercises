// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubemon.h"
#include "EnnemyHp.h"
#include "Engine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UnrealExercisesProjectile.h"

// Sets default values
ACubemon::ACubemon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	DoubleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	RootComponent = BaseMesh;

	DoubleMesh->AttachTo(BaseMesh);
	HealthBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HP"));
	HealthBar->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ACubemon::BeginPlay()
{
	Super::BeginPlay();

	CubemonMaterial = BaseMesh->CreateDynamicMaterialInstance(0);
	CubemonHeadMaterial = DoubleMesh->CreateDynamicMaterialInstance(0);
	auto widget = HealthBar->GetUserWidgetObject();
	auto hp = Cast<UEnnemyHp>(widget);
	hp->Cubemon = this;
}

// Called every frame
void ACubemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Hp <= 0)
	{
		Destroy();
	}
	auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	HealthBar->SetWorldRotation(camera->GetCameraRotation());
	HealthBar->AddLocalRotation(FRotator(0, 180, 0));
	UpdateMaterial();
}

void ACubemon::NotifyHit(class UPrimitiveComponent* MyComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector Hitlocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, OtherActor, OtherComp, bSelfMoved, Hitlocation, HitNormal, NormalImpulse, Hit);
	if (Cast<AUnrealExercisesProjectile>(OtherActor) != nullptr)
	{
		Hp -= 0.1;
		OtherActor->Destroy();
	}

}

void ACubemon::UpdateMaterial()
{
	if (CubemonMaterial != nullptr && CubemonHeadMaterial != nullptr)
	{
		CubemonMaterial->SetScalarParameterValue(TEXT("Color"), Hp);
		CubemonHeadMaterial->SetScalarParameterValue(TEXT("Color"), Hp);
	}
}