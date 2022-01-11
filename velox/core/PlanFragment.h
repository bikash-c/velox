/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#include <memory>
#include <vector>
#include "velox/core/PlanNode.h"

namespace facebook::velox::core {

/// Gives hints on how to execute the fragment of a plan.
enum class ExecutionStrategy {
  /// Process splits as they come in any available driver.
  kUngrouped,
  /// Process splits from each split group only in one driver.
  kGrouped,
};

/// Contains some information on how to execute the fragment of a plan.
/// Used to construct Task.
struct PlanFragment {
  std::shared_ptr<const core::PlanNode> planNode; /// Top level Plan Node.
  ExecutionStrategy executionStrategy{ExecutionStrategy::kUngrouped};
  std::vector<core::PlanNodeId> groupedExecutionScanNodes;
  int numSplitGroups{0};
};

} // namespace facebook::velox::core
