/* BSD 3-Clause License
 *
 * Copyright © 2008-2023, Jice and the libtcod contributors.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _TCOD_TREE_HPP
#define _TCOD_TREE_HPP

#include "tree.h"

class TCODLIB_API TCODTree {
 public:
  TCODTree* next{};
  TCODTree* father{};
  TCODTree* sons{};

  TCODTree() = default;
  TCODTree(const TCODTree&) = delete;
  TCODTree& operator=(const TCODTree&) = delete;
  TCODTree(TCODTree&& rhs) noexcept { (*this) = std::move(rhs); };
  TCODTree& operator=(TCODTree&& rhs) noexcept {
    swap(*this, rhs);
    return *this;
  };

  void addSon(TCODTree* data) {
    data->father = this;
    TCODTree* last_son = sons;
    while (last_son && last_son->next) last_son = last_son->next;
    if (last_son) {
      last_son->next = data;
    } else {
      sons = data;
    }
  }

  friend void swap(TCODTree& lhs, TCODTree& rhs) noexcept {
    std::swap(lhs.next, rhs.next);
    std::swap(lhs.father, rhs.father);
    std::swap(lhs.sons, rhs.sons);
  };
};

#endif
