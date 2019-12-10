// Fill out your copyright notice in the Description page of Project Settings.


#include "Lootbox.h"
#include "Engine.h"

// Sets default values
ALootbox::ALootbox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALootbox::BeginPlay()
{
	Super::BeginPlay();
	if (Player != nullptr)
	{
		Player->InputComponent->BindAction("Loot", IE_Pressed, this, &ALootbox::Loot);
	}
}

// Called every frame
void ALootbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ALootbox::Loot()
{
	FMath Random;
	float temp = Random.FRandRange(0, 1);
	if (temp >= Common) //if between 0.4 and 1 (60%)
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Green, TEXT("Congratulations ! You have acquired a Common Object !"));
	if (temp < Common && temp > Rare) //if between 0.1 and 0.4 (30%)
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Green, TEXT("Congratulations ! You have acquired a Rare Object !"));
	if (temp <= Legendary) //if between 0 and 0.1 (10%)
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Green, TEXT("Congratulations ! You have acquired a Legendary Object !"));
}