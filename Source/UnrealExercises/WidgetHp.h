// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cubemon.h"
#include "UnrealExercisesCharacter.h"
#include "Components/WidgetComponent.h"
#include "WidgetHp.generated.h"

/**
 * 
 */
UCLASS()
class UNREALEXERCISES_API UWidgetHp : public UWidgetComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
		ACubemon* Cubemon;

	UPROPERTY(BlueprintReadWrite)
		AUnrealExercisesCharacter* Player;
};
