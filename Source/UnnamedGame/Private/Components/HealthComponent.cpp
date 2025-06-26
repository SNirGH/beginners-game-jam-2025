// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UHealthComponent::TakeDamage(float Damage)
{
	Health = FMath::Clamp(Health - Damage, 0.0F, MaxHealth);
	OnDamageTaken.Broadcast();

	if (Health <= 0.0F)
	{
		OnDeath.Broadcast();
	}
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
}

