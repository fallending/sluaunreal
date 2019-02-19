// Tencent is pleased to support the open source community by making sluaunreal available.

// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the BSD 3-Clause License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at

// https://opensource.org/licenses/BSD-3-Clause

// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.


#pragma once
#include "CoreMinimal.h"
#include "LuaState.h"
#include "LuaBase.h"
#include "GameFramework/Actor.h"
#include "LuaActor.generated.h"


using slua_Luabase = slua::LuaBase;

UCLASS()
class SLUA_UNREAL_API ALuaActor : public AActor, public slua_Luabase {
    GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALuaActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua|LuaActor")
	FString LuaFilePath;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua|LuaActor")
	FString LuaStateName;

	virtual void ProcessEvent(UFunction* func, void* params) override;
};