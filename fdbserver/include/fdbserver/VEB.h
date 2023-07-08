/*
 * VEB.h
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2023 Apple Inc. and the FoundationDB project authors
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

#ifndef FLOW__VEB_H
#define FLOW__VEB_H
#pragma once

#include <cassert>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <functional>
#include <map>
#include <stdexcept>

#include "fdbserver/IKeyValueContainer.h"
#include "flow/Arena.h"

// The van Emde Boas tree (https://en.wikipedia.org/wiki/Van_Emde_Boas_tree) is a tree data structure  
// which implements an associative array with m-bit integer keys. It performs all operations in 
// O(log m) time assuming an m-bit operation can be completed in constant time.
//
// The VEB tree supports the following operations:
//  Insert: insert key/value pair with an m-bit key
//  Delete: remove the key/value pair with a given key
//  Lookup: find the value associated with a given key
//  FindNext: find the key/value pair with the smallest key which is greater than a given k
//  FindPrevious: find the key/value pair with the largest key which is smaller than a given k
//  Min: Returns the minimum element stored in a tree (operates in O(n) time)
//  Max: Returns the maximum element stored in a tree (operates in O(n) time)
//
// Insert(T, x):
//  Inserts value x in to tree T. 
//  - If T is empty then T.min = x and T.max = x
//  - If x < T.min then insert T.min into subtree i responsible for T.min. Set T.min = x.

class veb {
public:
	typedef std::size_t size_type;

};

#endif