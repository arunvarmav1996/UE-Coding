// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPosition = GetActorLocation();
	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	/* Move Platform forwards
			Get Current Location*/
	FVector CurrentLocation = GetActorLocation();
			/*Add vector to that location*/
	CurrentLocation = CurrentLocation + (PlatformVelocity* DeltaTime);			
			/*Set the location*/
	SetActorLocation(CurrentLocation);			
	 // Send platform back if gone too far
	 FVector :: Dist(StartPosition,CurrentLocation);
	  		//Check how far we've moved
	float DistanceMoved = FVector :: Dist(StartPosition,CurrentLocation);
			//Reverse direction of motion if gone too far */

	if(DistanceMoved > MovedDistance)
	{
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartPosition = StartPosition + MoveDirection*MovedDistance;
		SetActorLocation(StartPosition);
		PlatformVelocity = -PlatformVelocity;
		
	}
	
			

			
	

};

