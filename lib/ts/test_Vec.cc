/* -*-Mode: c++;-*-
  Various vector related code.

  @section license License

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

/* UnionFind after Tarjan */

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "Vec.h"

int main(int argc, char **argv) {
  Vec<void *> v, vv, vvv;
  int tt = 99 * 50, t = 0;
  
  for (int i = 0; i < 100; i++)
    v.add((void*)(intptr_t)i);
  for (int i = 0; i < 100; i++)
    t += (int)(intptr_t)v.v[i];
  assert(t == tt);

  t = 0;
  for (int i = 1; i < 100; i++)
    vv.set_add((void*)(intptr_t)i);
  for (int i = 1; i < 100; i++)
    vvv.set_add((void*)(intptr_t)i);
  for (int i = 1; i < 100; i++)
    vvv.set_add((void*)(intptr_t)(i * 1000));
  vv.set_union(vvv);
  for (int i = 0; i < vv.n; i++)
    if (vv.v[i])
      t += (int)(intptr_t)vv.v[i];
  assert(t == tt + 1000 * tt);

  v.clear();
  v.reserve(1000);
  t = 0;
  for (int i = 0; i < 1000; i++)
    v.add((void*)(intptr_t)i);
  for (int i = 0; i < 1000; i++)
    t += (int)(intptr_t)v.v[i];
  assert(t == 999 * 500);
  printf("%d %d\n", v.n, v.i);

  Intervals in;
  in.insert(1);
  assert(in.n == 2);
  in.insert(2);
  assert(in.n == 2);
  in.insert(6);
  assert(in.n == 4);
  in.insert(7);
  assert(in.n == 4);
  in.insert(9);
  assert(in.n == 6);
  in.insert(4);
  assert(in.n == 8);
  in.insert(5);
  assert(in.n == 6);
  in.insert(3);
  assert(in.n == 4);
  in.insert(8);
  assert(in.n == 2);

  UnionFind uf;
  uf.size(4);
  uf.unify(0,1);
  uf.unify(2,3);
  assert(uf.find(2) == uf.find(3));
  assert(uf.find(0) == uf.find(1));
  assert(uf.find(0) != uf.find(3));
  assert(uf.find(1) != uf.find(3));
  assert(uf.find(1) != uf.find(2));
  assert(uf.find(0) != uf.find(2));
  uf.unify(1,2);
  assert(uf.find(0) == uf.find(3));
  assert(uf.find(1) == uf.find(3));
  printf("test_Vec PASSED\n");
}
