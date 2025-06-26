// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDamageTaken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Health), meta=(BlueprintSpawnableComponent) )
class UNNAMEDGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDamageTaken OnDamageTaken;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeath OnDeath;

	UPROPERTY(EditAnywhere, Category = "health")
	float MaxHealth;

	void TakeDamage(float Damage);

	FORCEINLINE float GetHealth() const { return Health; }
protected:
	virtual void BeginPlay() override;

private:
	float Health;
};
