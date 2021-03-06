/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "hbase/client/cell.h"
#include "hbase/client/mutation.h"

namespace hbase {

class Increment : public Mutation {
 public:
  /**
   * Constructors
   */
  explicit Increment(const std::string& row) : Mutation(row) {}
  Increment(const Increment& cincrement) : Mutation(cincrement) {}
  Increment& operator=(const Increment& cincrement) {
    Mutation::operator=(cincrement);
    return *this;
  }

  ~Increment() = default;

  /**
   *  @brief Increment the column from the specific family with the specified qualifier
   * by the specified amount.
   *  @param family family name
   *  @param qualifier column qualifier
   *  @param amount amount to increment by
   */
  Increment& AddColumn(const std::string& family, const std::string& qualifier, int64_t amount);
  Increment& Add(std::unique_ptr<Cell> cell);
};

}  // namespace hbase
