// Shoot Them Up Game. All Rights Resrved.

#include "AI/Services/STUFindenemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUAIPerceptionComponent.h"

USTUFindenemyService::USTUFindenemyService()
{
    NodeName = "Find Enemy";
}

void USTUFindenemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    UE_LOG(LogTemp, Display, TEXT("find enemy"));
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    if (Blackboard)
    {
        const auto Controller = OwnerComp.GetAIOwner();
        const auto PerceptionComponent = STUUtils::GetSTUPlayerComponent<USTUAIPerceptionComponent>(Controller);
        if (PerceptionComponent)
        {
            Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClossestEnemy());
        }
    }
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
