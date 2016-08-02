/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011-2014, Willow Garage, Inc.
 *  Copyright (c) 2014-2016, Open Source Robotics Foundation
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Open Source Robotics Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/** \author Jia Pan */

#ifndef FCL_TRAVERSAL_DISTANCERAVERSALNODEBASE_H
#define FCL_TRAVERSAL_DISTANCERAVERSALNODEBASE_H

#include "fcl/traversal/traversal_node_base.h"

namespace fcl
{

/// @brief Node structure encoding the information required for distance traversal.
template <typename Scalar>
class DistanceTraversalNodeBase : public TraversalNodeBase<Scalar>
{
public:
  DistanceTraversalNodeBase();

  virtual ~DistanceTraversalNodeBase();

  /// @brief BV test between b1 and b2
  virtual Scalar BVTesting(int b1, int b2) const;

  /// @brief Leaf test between node b1 and b2, if they are both leafs
  virtual void leafTesting(int b1, int b2) const;

  /// @brief Check whether the traversal can stop
  virtual bool canStop(Scalar c) const;

  /// @brief Whether store some statistics information during traversal
  void enableStatistics(bool enable);

  /// @brief request setting for distance
  DistanceRequest<Scalar> request;

  /// @brief distance result kept during the traversal iteration
  DistanceResult<Scalar>* result;

  /// @brief Whether stores statistics
  bool enable_statistics;
};

//============================================================================//
//                                                                            //
//                              Implementations                               //
//                                                                            //
//============================================================================//

//==============================================================================
template <typename Scalar>
DistanceTraversalNodeBase<Scalar>::DistanceTraversalNodeBase()
  : result(NULL), enable_statistics(false)
{
  // Do nothing
}

//==============================================================================
template <typename Scalar>
DistanceTraversalNodeBase<Scalar>::~DistanceTraversalNodeBase()
{
  // Do nothing
}

//==============================================================================
template <typename Scalar>
Scalar DistanceTraversalNodeBase<Scalar>::BVTesting(int b1, int b2) const
{
  return std::numeric_limits<Scalar>::max();
}

//==============================================================================
template <typename Scalar>
void DistanceTraversalNodeBase<Scalar>::leafTesting(int b1, int b2) const
{
  // Do nothing
}

//==============================================================================
template <typename Scalar>
bool DistanceTraversalNodeBase<Scalar>::canStop(Scalar c) const
{
  return false;
}

//==============================================================================
template <typename Scalar>
void DistanceTraversalNodeBase<Scalar>::enableStatistics(bool enable)
{
  enable_statistics = enable;
}

} // namespace fcl

#endif
